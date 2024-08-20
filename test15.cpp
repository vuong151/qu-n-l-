
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class ThiSinh
{
private:
    string hoTen;
    float diem;

public:
    ThiSinh()
    {
    }
    void nhap()
    {
        cout << "Nhap ho ten thi sinh : ";
        cin >> hoTen;
        cout << "Nhap diem: ";
        cin >> diem;
    }
    void xuat()
    {
        cout << "\nHo ten thi sinh la: " << hoTen << " , diem la: " << diem << " , ";
    }
    float getDiem()
    {
        return diem;
    }
};

class Olympic : public ThiSinh
{
private:
    string truong;

public:
    Olympic()
    {
    }
    void nhap()
    {
        ThiSinh::nhap();
        cout << "Nhap truong cua thi sinh : ";
        cin >> truong;
    }
    void xuat()
    {
        ThiSinh::xuat();
        cout << "truong la: " << truong<<endl;
    }
    string getTruong()
    {
        return truong;
    }
};

int main()
{
    int n;
    Olympic a[100];
    cout << "Nhap so luong thi sinh : ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Thi sinh thu " << i << " la: ";
        a[i].nhap();
    }

    for (int i = 1; i <= n; i++)
    {
        a[i].xuat();
    }

    int soLuongA = 0;
    int soLuongB = 0;
    int soLuongC = 0;
    float diemTruongA = 0;
    float diemTruongB = 0;
    float diemTruongC = 0;
    float diemCaoNhatA = 0;
    int thiSinhCaoNhatA = 0;

    for (int i = 1; i <= n; i++)
    {
        if (a[i].getTruong() == "A")
        {
            diemTruongA += a[i].getDiem();
            soLuongA++;
        }
        else if (a[i].getTruong() == "B")
        {
            diemTruongB += a[i].getDiem();
            soLuongB++;
        }
        else if (a[i].getTruong() == "C")
        {
            diemTruongC += a[i].getDiem();
            soLuongC++;
        }
    }

    cout << "Tong diem truong A la: " << diemTruongA << endl;
    cout << "Tong diem truong B la: " << diemTruongB << endl;
    cout << "Tong diem truong C la: " << diemTruongC << endl;

    float diemMax = max(max(diemTruongA, diemTruongB), diemTruongC);
    if (diemMax == diemTruongA)
    {
        cout << "Truong A co tong diem cao nhat." << endl;
    }
    else if (diemMax == diemTruongB)
    {
        cout << "Truong B co tong diem cao nhat." << endl;
    }
    else if (diemMax == diemTruongC)
    {
        cout << "Truong C co tong diem cao nhat." << endl;
    }

    cout << "So luong thi sinh tham du truong A la: " << soLuongA << endl;
    cout << "So luong thi sinh tham du truong B la: " << soLuongB << endl;
    cout << "So luong thi sinh tham du truong C la: " << soLuongC << endl;

    return 0;
}
