### Câu 1. (Tách ký tự số và ký tự chữ) NHập vào 1 chuỗi gồm các ký tự số 
# và ký tự chữ cái la tinh thường. Hãy viết 1 CT tách chuỗi được nhập vào 
# thành 2 chuỗi, 1 chuỗi chỉ gồm các ký tự chữ số, chuỗi còn lại gồm các kỹ tự chữ cái.
#  Ví dụ "1236hhd92a" tách thành 2 chuỗi "123692" và "hhda".

# s=input()
# chu=""
# so=""
# for i in s:
#     if i.isdigit():
#         so+=i
#     else:
#         chu+=i
# print(so,chu)

# Câu 2. (Chuỗi đối xứng) Viết CT nhập vào 1 chuỗi và kiểm tra xem chuỗi đó có
# phải là chuỗi đối xứng hay không? Ví dụ chuỗi madam, 1221 là các chuỗi đối xứng
# , 1234 không phải là chuỗi đối xứng.

# s=input()
# sNguoc=s[::-1]
# if (sNguoc==s): print("Yes")
# else: print("No")

s=input()
n=len(s)//2
print(n)
print(s[::-1] )