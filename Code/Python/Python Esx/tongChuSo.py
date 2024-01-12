# Câu 1. (Tổng các chữ số) Cho 1 số tự nhiên n (n<=10^1000). Tính tổng các chữ số của n.
# Ví dụ: với n=123, thì tổng các chữ số của n là 1+2+3=6.

# def tinhTong(n):
#     tong=0
#     while (n!=0):
#         tong+=n%10
#         n=n//10
#     print(tong)
# n=int(input())
# tinhTong(n)

# Câu 3. (Kiểm tra số nguyên tố) Cho 1 số tự nhiên n (n<=10^12) Kiểm tra xem n 
# có phải là 1 số nguyên tố hay không?
# from math import *
# def checkNT(n):
#     if n < 2: return 0
#     for i in range(2, int(sqrt(n)+1)):
#         if (n%i==0): return 0
#     return 1
# n = int(input())
# if checkNT(n):  print("Yes")
# else: print("No")

# Câu 4. (Số hoàn hảo) Kiểm tra xem 1 số tự nhiên cho trước có phải là số 
# hoàn hảo không? Số hoàn hảo (hay còn gọi là số hoàn chỉnh, 
# số hoàn thiện hoặc số hoàn thành) là một số nguyên dương mà tổng các ước
#  nguyên dương thực sự của nó (các số nguyên dương bị nó chia hết ngoại trừ nó)
#  bằng chính nó.

# def checkHH(n):
#     dem=0
#     for i in range(1,n):
#         if n%i==0: dem+=i
#     if dem==n: return 1
#     else: return 0

# n=int(input())
# if checkHH(n): print("Yes")
# else: print("No")