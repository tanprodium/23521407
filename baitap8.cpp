#include <bits/stdc++.h>
using namespace std;

struct SoTietKiem {
    string maSo, loaiTK, ten, CMND, ngayMo;
    int dayMo, monthMo, yearMo;
    int dayTrongThang[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    double soTien, laiSuat = 0.1;

    SoTietKiem(string maSo, string loaiTK, string ten, string CMND, string ngayMo, double soTien)
        : maSo(maSo), loaiTK(loaiTK), ten(ten), CMND(CMND), ngayMo(ngayMo), soTien(soTien) {
        if (maSo.size() != 5 || ten.size() > 30 || (CMND.size() != 9 && CMND.size() != 12) || ngayMo.size() != 10) {
            throw "Do dai Input khong hop le";
        }
        for (char ch : maSo) {
            if ((ch < '0' || ch > '9') && (ch < 'A' || ch > 'z')) {
                throw "Ma so khong hop le";
            }
        }
        for (char ch : ten) {
            if (ch != ' ' && (ch < 'A' || ch > 'z')) {
                throw "Ten khong hop le";
            }
        }
        dayMo = stoi(ngayMo.substr(0, 2));
        monthMo = stoi(ngayMo.substr(3, 2));
        yearMo = stoi(ngayMo.substr(6, 4));
        if (yearMo % 4 == 0 && yearMo % 100 != 0 || yearMo % 400 == 0) {
            dayTrongThang[2] = 29;
        }
        if (dayMo < 1 || dayMo > dayTrongThang[monthMo] || monthMo < 1 || monthMo > 12) {
            throw "Ngay thang nam khong hop le";
        }

        int yearPast = 2024 - yearMo;
        if (loaiTK == "Ky han") this->soTien = soTien * pow(1 + laiSuat, yearPast); // Cập nhật số tiền sau yearPast năm
    }

    void CapNhatSoTien() { // Cập nhật số tiền sau 1 năm
        if (loaiTK == "Ky han") soTien += soTien * laiSuat;
    }

    void HienThi() {   // Hiển thị thông tin sổ tiết kiệm
        cout << "Ma so: " << maSo << endl;
        cout << "Loai tiet kiem: " << loaiTK << endl;
        cout << "Ten khach hang: " << ten << endl;
        cout << "CMND: " << CMND << endl;
        cout << "Ngay mo so: " << ngayMo << endl;
        cout << "So tien: " << soTien << endl;
        cout << endl;
    }

    void HienThiThongTinTimKiem() { // Hỗ trợ việc in ra thông tin tìm kiếm
        cout << "Ma so: " << maSo << endl;
        cout << "CMND: " << CMND << endl;
        cout << endl;
    }

    void HienThiSoTien() { // Hiển thị số tiền - hỗ trợ việc in sắp xếp
        cout << "Ma so: " << maSo << endl;
        cout << "So tien: " << soTien << endl;
        cout << endl;
    }

    void HienThiNgay() { // Hiển thị ngày mở sổ - hỗ trợ việc in sắp xếp
        cout << "Ma so: " << maSo << endl;
        cout << "Ngay mo so: " << ngayMo << endl;
        cout << endl;
    }

    void RutTien(double soTienRut) { // Rút tiền
        if (soTienRut > this->soTien) {
            throw "So tien rut vuot qua so tien trong tai khoan";
        }
        this->soTien -= soTienRut;
    }

    void GuiTien(double soTienGui) { // Gửi tiền
        this->soTien += soTienGui;
    }

    bool TimTheoCMND_hoac_MaSo(string s) { // Tìm STK bằng CMND hoặc mã số
        return s == maSo || s == CMND;
    }

    bool TimGiuaHaiNgay(string date1, string date2) { // Tìm STK mở giữa 2 ngày
        int day1 = stoi(date1.substr(0, 2));
        int month1 = stoi(date1.substr(3, 2));
        int year1 = stoi(date1.substr(6, 4));
        int day2 = stoi(date2.substr(0, 2));
        int month2 = stoi(date2.substr(3, 2));
        int year2 = stoi(date2.substr(6, 4));

        if (year1 > yearMo || yearMo > year2) return false;
        if (year1 == yearMo && month1 > monthMo) return false;
        if (year2 == yearMo && monthMo > month2) return false;
        if (year1 == yearMo && month1 == monthMo && day1 > dayMo) return false;
        if (year2 == yearMo && month2 == monthMo && dayMo > day2) return false;

        return true;
    }

    static bool SapXepTheoSoTien(SoTietKiem a, SoTietKiem b) { // Số tiền gửi giảm dần
        return a.soTien > b.soTien;
    }

    static bool SapXepTheoNgay(SoTietKiem a, SoTietKiem b) { // Ngày mở sổ tăng dần
        if (a.yearMo != b.yearMo) return a.yearMo < b.yearMo;
        if (a.monthMo != b.monthMo) return a.monthMo < b.monthMo;
        return a.dayMo < b.dayMo;
    }
};

SoTietKiem Nhap() {
    string maSo, loaiTK, ten, CMND, ngayMo;
    double soTien = 0;
    cout << "Nhap ma so: "; cin >> maSo;
    cout << "Nhap loai tiet kiem: "; cin.ignore(); getline(cin, loaiTK);
    cout << "Nhap ten: "; getline(cin, ten);
    cout << "Nhap CMND: "; cin >> CMND;
    cout << "Nhap ngay mo so: "; cin >> ngayMo;
    cout << "Nhap so tien: ";
    while (soTien <= 0) cin >> soTien;
    return SoTietKiem(maSo, loaiTK, ten, CMND, ngayMo, soTien);
}

int main() {
    int n;
    vector<SoTietKiem> stk;
    cout << "Nhap so luong so tiet kiem: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin so tiet kiem thu " << i + 1 << endl;
        stk.push_back(Nhap());
    }

    cout << "Danh sach so tiet kiem: " << endl;
    for (auto p : stk) p.HienThi();

    string searchString;
    cout << "Nhap ma so hoac CMND can tim: "; cin >> searchString;
    cout << "Cac STK thoa man la: " << endl;
    for (auto p : stk) {
        if (p.TimTheoCMND_hoac_MaSo(searchString)) p.HienThiThongTinTimKiem();
    }

    // sắp xếp theo số tiền giảm dần
    sort(stk.begin(), stk.end(), SoTietKiem::SapXepTheoSoTien);
    cout << "STK sap xep theo so tien giam dan: \n";
    for (auto p : stk) p.HienThiSoTien();

    // sắp xếp theo ngày mở sổ tăng dần
    sort(stk.begin(), stk.end(), SoTietKiem::SapXepTheoNgay);
    cout << "STK sap xep theo ngay mo so tang dan: \n";
    for (auto p : stk) p.HienThiNgay();
}
