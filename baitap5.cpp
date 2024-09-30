#include <bits/stdc++.h>
using namespace std;

// Kiểm tra năm nhuận
bool KiemTraNamNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

// Số ngày trong một tháng
int SoNgayTrongThang(int thang, int nam) {
    if (thang == 2) {
        return KiemTraNamNhuan(nam) ? 29 : 28;
    }
    return (thang == 4 || thang == 6 || thang == 9 || thang == 11) ? 30 : 31;
}

// Tìm ngày tiếp theo
void NgayKeTiep(int &ngay, int &thang, int &nam) {
    ngay++;
    if (ngay > SoNgayTrongThang(thang, nam)) {
        ngay = 1;
        thang++;
        if (thang > 12) {
            thang = 1;
            nam++;
        }
    }
}

// Tìm ngày trước
void NgayTruoc(int &ngay, int &thang, int &nam) {
    ngay--;
    if (ngay < 1) {
        thang--;
        if (thang < 1) {
            thang = 12;
            nam--;
        }
        ngay = SoNgayTrongThang(thang, nam);
    }
}

// Tính số thứ tự của ngày trong năm
int SoThuTuTrongNam(int ngay, int thang, int nam) {
    int demNgay = 0;
    for (int m = 1; m < thang; m++) {
        demNgay += SoNgayTrongThang(m, nam);
    }
    demNgay += ngay;
    return demNgay;
}

int main() {
    int ngay, thang, nam;
    cout << "Nhap ngay (dd mm yyyy): ";
    cin >> ngay >> thang >> nam;

    // Tính ngày kế tiếp
    int keTiepNgay = ngay, keTiepThang = thang, keTiepNam = nam;
    NgayKeTiep(keTiepNgay, keTiepThang, keTiepNam);
    cout << "Ngay ke tiep: " << keTiepNgay << "/" << keTiepThang << "/" << keTiepNam << endl;

    // Tính ngày trước
    int truocNgay = ngay, truocThang = thang, truocNam = nam;
    NgayTruoc(truocNgay, truocThang, truocNam);
    cout << "Ngay truoc: " << truocNgay << "/" << truocThang << "/" << truocNam << endl;

    // Tính số thứ tự trong năm
    int soThuTu = SoThuTuTrongNam(ngay, thang, nam);
    cout << "Ngay " << ngay << "/" << thang << "/" << nam << " la ngay thu: " << soThuTu << " trong nam." << endl;

    return 0;
}
