def checkSo(n):
    dem=0
    for i in range (1,n):
        if n%i==0: dem+=i
    if dem==n:return 1
    return 0
def checkF(a,b):
    for i in range(a,b):
        if checkSo(i): print(i)

a,b = map(int, input().split())
checkF(a,b)