#include <iostream>

using namespace std;

class DaySo {
private:
    int n;
    int* cacphantucuaday;

public:
    DaySo(int n) {
        this->n = n;
        cacphantucuaday = new int[n];
    }
    
    ~DaySo() {
        delete[] cacphantucuaday;
    }

    void NhapDaySo() {
        cout << "Nhap " << n << " phan tu cua day so: ";
        for (int i = 0; i < n; i++) {
            cin >> cacphantucuaday[i];
        }
    }

    void XuatDaySo() {
        cout << "Cac phan tu cua day so la: ";
        for (int i = 0; i < n; i++) {
            cout << cacphantucuaday[i] << " ";
        }
        cout << endl;
    }

    int TimMaxPhanTuChan() {
        int maxChan = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (cacphantucuaday[i] % 2 == 0 && cacphantucuaday[i] > maxChan) {
                maxChan = cacphantucuaday[i];
            }
        }
        return maxChan;
    }

    int TinhTichPhanTu(int a, int b) {
        int tich = 1;
        for (int i = a; i <= b; i++) {
            tich *= cacphantucuaday[i];
        }
        return tich;
    }

    bool KiemTraSoAm() {
        for (int i = 0; i < n; i++) {
            if (cacphantucuaday[i] >= 0) {
                return false;
            }
        }
        return true;
    }

    void SapXepTangDan() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (cacphantucuaday[i] > cacphantucuaday[j]) {
                    swap(cacphantucuaday[i], cacphantucuaday[j]);
                }
            }
        }
    }
};

int main() {
    int n;
    cout << "Nhap so phan tu cua day so: ";
    cin >> n;

    DaySo daySo(n);

    daySo.NhapDaySo();
    daySo.XuatDaySo();

    int maxChan = daySo.TimMaxPhanTuChan();
    cout << "Gia tri lon nhat trong cac phan tu chan: " << maxChan << endl;

    int a, b;
    cout << "Nhap hai so nguyen a va b: ";
    cin >> a >> b;
    int tich = daySo.TinhTichPhanTu(a, b);
    cout << "Tich cac phan tu tu vi tri " << a << " den " << b << ": " << tich << endl;

    bool toanSoAm = daySo.KiemTraSoAm();
    if (toanSoAm) {
        cout << "Day so toan so am" << endl;
    } else {
        cout << "Day so chua so duong" << endl;
    }

    daySo.SapXepTangDan();
    cout << "Day so sau khi sap xep tang dan: ";
    daySo.XuatDaySo();

    return 0;
}
