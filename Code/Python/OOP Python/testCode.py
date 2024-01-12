def tinh_xac_suat(s):
    s = s.lower()
    tu = s.split()
    so_lan_xuat_hien = {}
    for t in tu:
        if t:
            if t in so_lan_xuat_hien:
                so_lan_xuat_hien[t] += 1
            else:
                so_lan_xuat_hien[t] = 1
    tong_so_tu = len(tu)
    xac_suat = {}
    for tu, so_lan in so_lan_xuat_hien.items():
        xac_suat[tu.title()] = (so_lan / tong_so_tu)*100
    return xac_suat

van_ban = input("Nhap van ban: ")
d = tinh_xac_suat(van_ban)
for t, pt in d.items():
    print(f"p({t}): {pt:.1f}%", end=', ') 