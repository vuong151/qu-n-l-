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
        cout << "Nh?p b?c c?a da th?c: ";
        is >> dt.n;
        for (int i = 0; i <= dt.n; i++) {
            cout << "Nh?p h? s? " << i << ": ";
            is >> dt.a[i];
        }
        return is;
    }
    
    friend ostream& operator<<(ostream& os, DaThuc& dt) {
        os << "Ða th?c v?a nh?p là: ";
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
    cout << "Nh?p thông s? da th?c P: ";
    cin >> P;
    cout << "P(x) = " << P;
    
    return 0;
}
