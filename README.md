# homework

> 실습 과제 모음

## Contents

+ Python Programming
+ C/C++ Programming
+ Java Programming
+ [System Programming](#system-programming)
+ Programming Language
+ [Data Mining and Analysis](#datamining-and-analysis)

 ## System Programming
 
 ### ls_cmd
 
  + #### **Description** 
    ls  -s  -i  -o  -F  -l 명령어 구현
    
    
    - -s 옵션 : 파일 이름과 크기를 출력
    - -i 옵션 : 파일 이름과 i-노드 번호를 출력
    - -o 옵션 : l 옵션과 비슷하나, 그룹 정보를 제외하고 리스트
    - -F 옵션 : 파일의 종류를 기호로 표시(* : 실행파일, / : 디렉터리, @ : 심볼릭 링크)
    - -l 옵션 : long, 파일 속성 출력(파일 이름, 종류, 접근권한, 소유자 등)


  + #### **File**
    - list.c
    - stat.c
    - type.c
    - perm.c
    - makefile
  
  ### bank
  + #### **Description** 
    은행 계좌 관리 프로그램 - 계좌 생성, 입금, 출금, 잔액 조회
  + #### **File**
    - bank.c
    - bank.h
    - makefile

## Datamining and Analysis
### datamining.py
 
  + #### **Description** 
    - 1 : Titanic Survivor Predictor (Random Forest)
    - 2 : Market Basket Analyzer (FP Growth)

  + #### **File**
    - datamining.py
    - test.csv
    - train.csv
    - Market_Basket_Optimisatino.csv