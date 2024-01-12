class Date:
    def __init__(self,date):
        self.date=date
    def tach(self):
        a=self.date.split('/')
        self.ngay=int(a[0])
        self.thang=int(a[1])
        self.nam=int(a[2])
    def __str__(self):
        return f'{self.ngay}/{self.thang}/{self.nam}'
class CongNhan:
    def __init__(self,ma,ten,bac,snlv,nkhd):
        self.ten=ten
        self.ma=ma
        self.bac=bac
        self.snlv=snlv
        self.nkhd= Date(nkhd)
        self.nkhd.tach()
    def tiencongnhat(self):
        if self.bac==1:
            return 300000
        if self.bac==2:
            return 350000
        return 400000
    def tienluong(self):
        return self.snlv * self.tiencongnhat()
    def __gt__(self, other):
        if self.nkhd.nam!= other.nkhd.nam:
            return self.nkhd.nam>other.nkhd.nam
        elif self.nkhd.thang!=other.nkhd.thang:
            return self.nkhd.thang>other.nkhd.thang
        return self.nkhd.ngay>other.nkhd.ngay
    def __repr__(self):
        return f'{self.ma},{self.ten},{self.snlv},{self.tienluong()}'
    def __str__(self):
        return f'{self.ma} {self.ten} {self.bac} {self.snlv} {self.nkhd} {self.tienluong()}'

setma=set()
A=[]
while 2:
    try:
        ma = input("nhap ma")
        if ma=='':
            break
        if ma not in setma:
            ten = input("nhap ten")
            bac = int(input("nhap bac luong"))
            snlv = int(input("nhap so ngay lam viec"))
            ngaykihopdong = input("nhap ngay ki hop dong")
            setma.add(ma)
            x= CongNhan(ma,ten,bac,snlv,ngaykihopdong)
            A.append(x)
        else:
            continue
    except:
        break
file = open("CNBac1.txt",'w')
for x in A:
    if x.bac==1:
        file.write(x.__repr__()+'\n')
file.close()
A.sort(key=lambda x:(x.nkhd.nam,x.nkhd.thang,x.nkhd.ngay))
for x in A:
    print(x.__str__())