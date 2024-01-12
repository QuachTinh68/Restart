def nhap_ma_tran_ke(n):
    ma_tran = []
    print("Nhập ma trận kề có kích thước", n, "x", n)
    for i in range(n):
        hang = []
        for j in range(n):
            gia_tri = int(input(f"Nhập giá trị a[{i+1},{j+1}]: "))
            hang.append(gia_tri)
        ma_tran.append(hang)
    return ma_tran

def la_do_thi_vo_huong(ma_tran_ke):
    for i in range(len(ma_tran_ke)):
        for j in range(len(ma_tran_ke)):
            if ma_tran_ke[i][j] != ma_tran_ke[j][i]:
                return False
    return True

n_dinh = int(input("Nhập số đỉnh của đồ thị (n): "))


ma_tran_ke = nhap_ma_tran_ke(n_dinh)

print("Ma trận kề vừa nhập:")
for hang in ma_tran_ke:
    print(hang)

if la_do_thi_vo_huong(ma_tran_ke):
    print("Đồ thị là đồ thị vô hướng.")
else:
    print("Đồ thị là đồ thị có hướng.")