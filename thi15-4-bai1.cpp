#include <iostream>

using namespace std;

class HCN {
private:
    double chieuDai;
    double chieuRong;

public:
    void nhap() {
        cout << "Nhap chieu dai: ";
        cin >> chieuDai;

        cout << "Nhap chieu rong: ";
        cin >> chieuRong;
    }

    void xuat() {
        cout << "Chieu dai: " << chieuDai << endl;
        cout << "Chieu rong: " << chieuRong << endl;
    }

    double tinhDienTich() {
        return chieuDai * chieuRong;
    }
};

int main() {
    const int MAX = 100;
    HCN dsHCN[MAX];
    int n;

    cout << "Nhap so luong hinh chu nhat: ";
    cin >> n;

    // Nh?p kích thu?c cho n hình ch? nh?t
    for (int i = 0; i < n; i++) {
        cout << "Nhap kich thuoc hinh chu nhat " << i + 1 << endl;
        dsHCN[i].nhap();
    }

    // Tính di?n tích trung bình c?a các hình ch? nh?t
    double tongDienTich = 0;
    for (int i = 0; i < n; i++) {
        tongDienTich += dsHCN[i].tinhDienTich();
    }

    double dienTichTrungBinh = tongDienTich / n;
    cout << "Dien tich trung binh cua cac hinh chu nhat: " << dienTichTrungBinh << endl;

    // Tìm nh?ng hình có di?n tích nh? nh?t
    double dienTichNhoNhat = dsHCN[0].tinhDienTich();
    for (int i = 1; i < n; i++) {
        double dienTich = dsHCN[i].tinhDienTich();
        if (dienTich < dienTichNhoNhat) {
            dienTichNhoNhat = dienTich;
        }
    }

    cout << "Cac hinh co dien tich nho nhat: " << endl;
    for (int i = 0; i < n; i++) {
        if (dsHCN[i].tinhDienTich() == dienTichNhoNhat) {
            dsHCN[i].xuat();
        }
    }

    return 0;
}
