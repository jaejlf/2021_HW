import pandas as pd
import numpy as np
from sklearn.ensemble import RandomForestClassifier
from mlxtend.preprocessing import TransactionEncoder
from mlxtend.frequent_patterns import fpgrowth

while True:
    print("1. Titanic Survivor Predictor")
    print("2. Market Basket Analyzer")
    print("3. Quit")
    menu = input(">> ")

    #1. Titanic
    if menu == '1':
        #data Load
        train = pd.read_csv("./Datamining and Analysis/train.csv")
        test = pd.read_csv("./Datamining and Analysis/test.csv")

        #data drop
        train = train.drop(['PassengerId', 'Ticket', 'Cabin', 'Age'], axis=1)
        test = test.drop(['Ticket', 'Cabin', 'Age'], axis=1)

        #preprocessing
        train['Pclass_3'] = (train['Pclass']==3)
        train['Pclass_2'] = (train['Pclass']==2)
        train['Pclass_1'] = (train['Pclass']==1)
        test['Pclass_3'] = (test['Pclass']==3)
        test['Pclass_2'] = (test['Pclass']==2)
        test['Pclass_1'] = (test['Pclass']==1)
        train = train.drop(['Pclass'], axis=1)
        test=test.drop(['Pclass'], axis=1)

        train['Sex'] = train['Sex'].replace('male', 0).replace('female', 1)
        test['Sex'] = test['Sex'].replace('male', 0).replace('female', 1)

        train["Embarked"].fillna('S', inplace=True)
        test["Embarked"].fillna('S', inplace=True)
        train['EmbarkedC'] = (train['Embarked']=='C')
        train['EmbarkedS'] = (train['Embarked']=='S')
        train['EmbarkedQ'] = (train['Embarked']=='Q')
        test['EmbarkedC'] = (test['Embarked']=='C')
        test['EmbarkedS'] = (test['Embarked']=='S')
        test['EmbarkedQ'] = (test['Embarked']=='Q')
        train = train.drop(['Embarked'], axis=1)
        test = test.drop(['Embarked'], axis=1)

        test["Fare"].fillna(0, inplace=True) 

        train["Family"] = train["Parch"]+ train["SibSp"] + 1
        test["Family"] = test["Parch"]+ test["SibSp"] + 1
        train['Family'].astype(int)
        test['Family'].astype(int)
        train['Nuclear'] = (2<=train['Family']) & (train['Family']<=4)
        test['Nuclear'] = (2<=test['Family']) & (test['Family']<=4)
        train = train.drop(['Parch', 'SibSp', 'Family'], axis=1)
        test = test.drop(['Parch', 'SibSp', 'Family'], axis=1)

        train['Name'] = train['Name'].str.split(', ').str[1].str.split('. ').str[0]
        test['Name'] = test['Name'].str.split(', ').str[1].str.split('. ').str[0]
        train['Master'] = (train['Name']=='Master')
        test['Master'] = (test['Name']=='Master')
        train = train.drop(['Name'], axis=1)
        test = test.drop(['Name'], axis=1)

        #Survived
        X_train = train.drop("Survived",axis=1)
        Y_train = train["Survived"]
        X_test  = test.drop("PassengerId",axis=1).copy()

        #random forest
        random_forest = RandomForestClassifier(n_estimators=100)
        random_forest.fit(X_train, Y_train)
        Y_pred = random_forest.predict(X_test)
        random_forest.score(X_train, Y_train)

        #csv file
        submission = pd.DataFrame({
            "PassengerId": test["PassengerId"],
            "Survived": Y_pred
        })
        submission.to_csv('./Datamining and Analysis/submission.csv', index=False)

    #2. Market Basket
    elif menu == '2':
        minsup = float(input("Enter the minimum support: "))
        data = pd.read_csv("./Datamining and Analysis/Market_Basket_Optimisation.csv", header = None)

        trans = []
        for i in range(0, 7501):
            trans.append([str(data.values[i,j]) for j in range(0, 20)])
        trans = np.array(trans)

        te = TransactionEncoder()
        data = te.fit_transform(trans)
        data = pd.DataFrame(data, columns = te.columns_)
        data = data.loc[:, ['mineral water', 'burgers', 'turkey', 'chocolate', 'frozen vegetables', 'spaghetti',
                    'shrimp', 'grated cheese', 'eggs', 'cookies', 'french fries', 'herb & pepper', 'ground beef',
                    'tomatoes', 'milk', 'escalope', 'fresh tuna', 'red wine', 'ham', 'cake', 'green tea',
                    'whole wheat pasta', 'pancakes', 'soup', 'muffins', 'energy bar', 'olive oil', 'champagne', 
                    'avocado', 'pepper', 'butter', 'parmesan cheese', 'whole wheat rice', 'low fat yogurt', 
                    'chicken', 'vegetables mix', 'pickles', 'meatballs', 'frozen smoothie', 'yogurt cake']]

        #fpgrowth
        frequent = fpgrowth(data, min_support=minsup, use_colnames=True)
        print(frequent)
        
    #3. Quit
    elif menu == '3':
        break

    #input error
    else:
        print("input error! input number 1 ~ 3")

    print("")
