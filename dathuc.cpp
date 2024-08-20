#include<iostream>
#include<cmath>
using namespace std;

class DaThuc {
public:
    int n;
    int a[100];
    
    DaThuc() {
    }
    
    friend istream& operator>>(istream& is, DaThuc& dt) {
        cout << "Nhap bac cua da thuc: ";
        is >> dt.n;
        for (int i = 0; i <= dt.n; i++) {
            cout << "Nhap he so " << i << ": ";
            is >> dt.a[i];
        }
        return is;
    }
    
    friend ostream& operator<<(ostream& os, DaThuc& dt) {
        os << "Da thuc vua nhap la: ";
        for (int i = 0; i <= dt.n; i++) {
            os << dt.a[i] << "x^" << i;
            if (i != dt.n) {
                os << " + ";
            }
        }
        return os;
    }
    
    DaThuc operator+(DaThuc& dt) {
        DaThuc ketqua;
        ketqua.n = max(n, dt.n);
        for (int i = 0; i <= ketqua.n; i++) {
            if (i <= n && i <= dt.n) {
                ketqua.a[i] = a[i] + dt.a[i];
            } else if (i <= n) {
                ketqua.a[i] = a[i];
            } else {
                ketqua.a[i] = dt.a[i];
            }
        }
        return ketqua;
    }
    
    float tinh(float x) {
        float s = 0;
        for (int i = 0; i <= n; i++) {
            s += a[i] * pow(x, i);
        }
        return s;
    }
};

int main() {
    DaThuc P;
    cout << "Nhap thong so da thuc P: ";
    cin >> P;
    cout << "P(x) = " << P << endl;
    
    DaThuc Q;
    cout << "Nhap thong so da thuc Q: ";
    cin >> Q;
    cout << "Q(x) = " << Q << endl;
    
    DaThuc S;
    S = P + Q;
    cout << "Tong cua hai da thuc la: " << S << endl;
    
    float x;
    cout << "Nhap giá tri x: ";
    cin >> x;
    cout << "Gia tri cua P(x) la: " << P.tinh(x) << endl;
    cout << "Gia tri cua Q(x) la: " << Q.tinh(x) << endl;
    
    return 0;
}
