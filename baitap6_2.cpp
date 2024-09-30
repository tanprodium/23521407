#include <bits/stdc++.h>
using namespace std;

struct HocSinh {
    string ten;
    double diemToan, diemVan, diemAnh, diemTrungBinh;
    string phanLoai;

    HocSinh(string ten, double diemToan, double diemVan, double diemAnh)
        : ten(ten), diemToan(diemToan), diemVan(diemVan), diemAnh(diemAnh) {
        if (min({diemToan, diemVan, diemAnh}) < 0 || max({diemToan, diemVan, diemAnh}) > 10) {
            throw "Diem khong hop le";
        }
        for (char ch : ten) {
            if (ch != ' ' && (ch < 'A' || ch > 'z')) {
                throw "Ten khong hop le";
            }
        }
        diemTrungBinh = (2 * diemToan + diemVan + diemAnh) / 4;
        phanLoai = (diemTrungBinh < 5) ? "Yeu" :
                   (diemTrungBinh < 6.5) ? "Trung binh" :
                   (diemTrungBinh < 8) ? "Kha" :
                   (diemTrungBinh < 9) ? "Gioi" : "Xuat sac";
    }

    void show() const {
        cout << "Ten hoc sinh: " << ten << endl;
        cout << "Diem toan: " << diemToan << ", Diem van: " << diemVan
             << ", Diem anh: " << diemAnh << endl;
        cout << "Diem trung binh: " << diemTrungBinh << endl;
        cout << "Phan loai: " << phanLoai << endl;
    }

    double getDiemToan() const { return diemToan; }
    double getDiemTrungBinh() const { return diemTrungBinh; }
    string getTen() const { return ten; }
    int namePoint(const string& s) const;
};

int HocSinh::namePoint(const string& s) const {
    int pts = 0;
    for (int i = 0; i < ten.size(); i++) {
        int curpts = 0;
        for (int j = 0; j < s.size(); j++) {
            if (i + j >= ten.size()) break;
            if (tolower(ten[i + j]) == tolower(s[j])) curpts++;
        }
        pts = max(pts, curpts);
    }
    return pts;
}

HocSinh nhap() {
    string ten;
    double diemToan, diemVan, diemAnh;
    cout << "Nhap ten hoc sinh: ";
    cin.ignore();
    getline(cin, ten);
    cout << "Nhap diem toan, van, anh: ";
    cin >> diemToan >> diemVan >> diemAnh;
    return HocSinh(ten, diemToan, diemVan, diemAnh);
}

void timHSCaoNhat(const vector<HocSinh>& ds) {
    int highestAverageId = 0;
    for (int i = 1; i < ds.size(); i++) {
        if (ds[i].getDiemTrungBinh() > ds[highestAverageId].getDiemTrungBinh()) {
            highestAverageId = i;
        }
    }
    cout << "Hoc sinh co DTB cao nhat la: " << ds[highestAverageId].getTen() << endl;
}

void timHSTimKiem(const vector<HocSinh>& ds) {
    string searchString;
    cout << "Nhap hoc sinh can tim kiem: ";
    cin.ignore();
    getline(cin, searchString);

    int matchId = 0;
    for (int i = 1; i < ds.size(); i++) {
        if (ds[i].namePoint(searchString) > ds[matchId].namePoint(searchString)) {
            matchId = i;
        }
    }
    cout << "Hoc sinh co ten phu hop nhat voi " << searchString << " la: " << ds[matchId].getTen() << endl;
}

void danhSachHSThanhPhanThapNhat(const vector<HocSinh>& ds) {
    double lowestMathPoint = 10;
    for (const auto& hs : ds) {
        lowestMathPoint = min(lowestMathPoint, hs.getDiemToan());
    }

    cout << "Danh sach hoc sinh co diem toan thap nhat la: \n";
    for (const auto& hs : ds) {
        if (hs.getDiemToan() == lowestMathPoint) {
            cout << hs.getTen() << '\n';
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;
    vector<HocSinh> danhSachHocSinh;

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin hoc sinh thu " << i + 1 << endl;
        danhSachHocSinh.push_back(nhap());
    }

    for (int i = 0; i < n; i++) {
        cout << "Thong tin hoc sinh thu " << i + 1 << endl;
        danhSachHocSinh[i].show();
    }

    timHSCaoNhat(danhSachHocSinh);
    timHSTimKiem(danhSachHocSinh);
    danhSachHSThanhPhanThapNhat(danhSachHocSinh);

    return 0;
}
