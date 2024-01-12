def tinh_xac_suat(van_ban):
    van_ban = van_ban.lower()  #

    tu_trong_van_ban = van_ban.split()  

    so_lan_xuat_hien = {}
    for tu in tu_trong_van_ban:
        tu = ''.join(e for e in tu if e.isalnum())
        if tu: 
            if tu in so_lan_xuat_hien:
                so_lan_xuat_hien[tu] += 1
            else:
                so_lan_xuat_hien[tu] = 1
    tong_so_tu = len(tu_trong_van_ban)
    xac_suat = {}
    for tu, so_lan in so_lan_xuat_hien.items():
        xac_suat[tu] = (so_lan / tong_so_tu) * 100  
    return xac_suat

van_ban_input = input("Nhập vào chuỗi cần kiểm tra: ")

xac_suat = tinh_xac_suat(van_ban_input)
for tu, prob in xac_suat.items():
    print(f"p({tu}): {prob:.1f}%")
