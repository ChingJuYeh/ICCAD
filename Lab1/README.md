# Lab01

## 實驗內容:

 • Test the chip failures through assuming that all failures cause nodes to be 
“stuck-at” 0 or 1

 • Step1: 寫一個程式找出所有可偵測到A3SA1(亦即S1)的InputPatterns
 
 • Step2: 使用Step1的程式找出每一個Stuck-AtFault(亦即 S1~S16)對應的
Input Patterns

 • Step3: 撰寫程式找出可偵測到所有Stuck-AtFaults的Minimum Test
 Pattern Set

## 實驗過程:
![image](https://github.com/user-attachments/assets/c37a393c-a679-4fec-ad01-b0ab1e14b6ee)

1. 按照電路寫出 bool same() function​

以A3SA1為例，​測試輸入的值所得的輸出(Y)和A3SA1所得輸出(y)是否相同，若不同便記錄下來​


![image](https://github.com/user-attachments/assets/ba207809-0fe8-4047-ac40-51532edac718)

2. 計算全部Stuck-At Fault對應的Input Patterns
   
3. 得出其中一個Minimum Test Pattern Set
 ​
4. 先把只能找到一個Stuck-At Fault的input抓出來，再把其可算到的Stuck-At Fault記錄下來​

![image](https://github.com/user-attachments/assets/9fdf0147-e9ef-48ea-b29f-50342cd9bea0)

5.如果16個Stuck-At Fault還沒被測完，重複以下過程：​

* 計算input可測Stuck-At Fault的頻率，取最高值加入min set​

* 記錄其可測出的Stuck-At Fault​

 ![image](https://github.com/user-attachments/assets/83fa68c5-fcbc-4827-927e-8afa074e19b2)

 ## 結果​:
 
 Min set = { 6, 8, 10, 11, 14}

## 心得:

上課聽講的時候還不能真正理解什麼是 "Stuck-at" 0 or 1 ，經過這次實驗就恍然大悟，原來只是一個基礎的測試錯誤的方法，而且 Minimun Set 不只有一種可能。​
