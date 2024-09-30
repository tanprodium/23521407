#include <bits/stdc++.h>
using namespace std;

struct DayInYear {
    int d, m, y;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    DayInYear(int d, int m, int y) : d(d), m(m), y(y) {
        if (d < 1 || m < 1 || d > 31 || m > 12) {
            throw invalid_argument("Ngay thang khong hop le");
        }
        if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) days[1] = 29; // nam nhuan
    }

    DayInYear PreviousDay() {
        int dd = d, mm = m, yy = y;
        if (dd > 1) dd -= 1;
        else {
            if (mm > 1) {
                mm -= 1; dd = days[mm - 1];
            } else {
                yy -= 1; mm = 12; dd = 31;
            }
        }
        return DayInYear(dd, mm, yy);
    }

    DayInYear NextDay() {
        int dd = d, mm = m, yy = y;
        if (dd < days[mm - 1]) dd += 1;
        else {
            if (mm < 12) {
                mm += 1; dd = 1;
            } else {
                yy += 1; mm = 1; dd = 1;
            }
        }
        return DayInYear(dd, mm, yy);
    }

    int DayTh() {
        int res = d;
        for (int i = 0; i < m - 1; i++) res += days[i];
        return res;
    }

    static void Show(DayInYear day) {
        cout << day.d << "/" << day.m << "/" << day.y << endl;
    }
};

int main() {
    int d, m, y;
    cout << "Nhap ngay thang nam: "; cin >> d >> m >> y;
    DayInYear day(d, m, y);
    cout << "Ngay truoc la: "; DayInYear::Show(day.PreviousDay());
    cout << "Ngay sau la: ";   DayInYear::Show(day.NextDay());
    cout << "Day la ngay thu: " << day.DayTh() << endl;
}
