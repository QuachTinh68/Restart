class CongNhan:
    def __init__(self, ma_cong_nhan, ho_ten, bac, so_ngay_lam_viec, ngay_ki_hop_dong):
        self.ma_cong_nhan = ma_cong_nhan
        self.ho_ten = ho_ten
        self.bac = bac
        self.so_ngay_lam_viec = so_ngay_lam_viec
        self.ngay_ki_hop_dong = ngay_ki_hop_dong

    def tien_luong(self):
        if self.bac == 1:
            tien_cong = 300000
        elif self.bac == 2:
            tien_cong = 350000
        else:
            tien_cong = 400000
        return self.so_ngay_lam_viec * tien_cong

    def hien_thi_thong_tin(self):
        print("Thông tin công nhân:")
        print(f"Mã công nhân: {self.ma_cong_nhan}")
        print(f"Họ tên: {self.ho_ten}")
        print(f"Bậc: {self.bac}")
        print(f"Số ngày làm việc: {self.so_ngay_lam_viec}")
        print(f"Tiền lương: {self.tien_luong()} VND")

    def __gt__(self, other):
        ngay_ki_hd_self = date(self.ngay_ki_hop_dong["year"], self.ngay_ki_hop_dong["month"], self.ngay_ki_hop_dong["day"])
        ngay_ki_hd_other = date(other.ngay_ki_hop_dong["year"], other.ngay_ki_hop_dong["month"], other.ngay_ki_hop_dong["day"])
        
        return ngay_ki_hd_self > ngay_ki_hd_other

danh_sach_cong_nhan = []

while True:
    ma_cong_nhan = input("Nhập mã công nhân (rỗng để kết thúc nhập): ")
    if ma_cong_nhan == "":
        break
    
    # Kiểm tra xem mã công nhân đã tồn tại trong danh sách hay chưa
    found = False
    for cn in danh_sach_cong_nhan:
        if ma_cong_nhan == cn.ma_cong_nhan:
            found = True
            print("Mã công nhân đã tồn tại trong danh sách. Vui lòng nhập lại.")
            break
    
    if not found:
        ho_ten = input("Nhập họ tên: ")
        bac = int(input("Nhập bậc (1-3): "))
        so_ngay_lam_viec = int(input("Nhập số ngày làm việc: "))
        ngay_ki_hop_dong = {
            "day": int(input("Nhập ngày kí hợp đồng: ")),
            "month": int(input("Nhập tháng kí hợp đồng: ")),
            "year": int(input("Nhập năm kí hợp đồng: "))
        }
        
        cong_nhan_moi = CongNhan(ma_cong_nhan, ho_ten, bac, so_ngay_lam_viec, ngay_ki_hop_dong)
        danh_sach_cong_nhan.append(cong_nhan_moi)

# In danh sách công nhân đã nhập
print("\nDanh sách công nhân:")
for cn in danh_sach_cong_nhan:
    cn.hien_thi_thong_tin()

# Chúng ta sẽ mở file ở chế độ ghi và ghi thông tin vào file
with open("CNBac1.txt", "w") as file:
    for cn in danh_sach_cong_nhan:
        if cn.bac == 1:
            ngay_ki_hop_dong = f"{cn.ngay_ki_hop_dong['day']}/{cn.ngay_ki_hop_dong['month']}/{cn.ngay_ki_hop_dong['year']}"
            tien_luong = cn.tien_luong()
            # Ghi thông tin của từng công nhân có bậc = 1 vào file
            file.write(f"{cn.ma_cong_nhan}, {cn.ho_ten}, {ngay_ki_hop_dong}, {cn.so_ngay_lam_viec}, {tien_luong}\n")
