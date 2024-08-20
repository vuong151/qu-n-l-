#include <iostream>
#include <cmath>
using namespace std;
class HCN
{
  private:
	float chieudai;
	float chieurong;

  public:
	HCN()
	{
	}
	void nhap()
	{
		cout << "Nhap chieu dai va chieu rong: ";
		cin >> chieudai >> chieurong;
	}
	void xuat()
	{
		cout << "Chieu dai va rong la: " << chieudai << " , " << chieurong << endl;
	}
	float tinhdt()
	{
		return chieudai * chieurong;
	}
};
int main()
{
	int n;
	float dttb = 0, tongdt = 0;
	HCN a[100];
	cout << "Nhap so HCN: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "Nhap HCN thu " << i << " : ";
		a[i].nhap();
	}
	for (int i = 1; i <= n; i++)
	{
		cout << "HCN thu " << i << " co ";
		a[i].xuat();
	}
	for (int i = 1; i <= n; i++)
	{
		tongdt = tongdt + a[i].tinhdt();
	}
	dttb = tongdt / n;
	cout << "Dien tich trung binh la: " << dttb;
	float b = a[1].tinhdt();
	for (int i = 1; i <= n; i++)
	{
		if (b > a[i].tinhdt())
		{
			b = a[i].tinhdt();
		}
	}
	cout << "\nCac HCN co dien tich nho nhat la: " << endl;
	for (int i = 1; i <= n; i++)
	{
		if (b == a[i].tinhdt())
		{
			cout << "HCN thu " << i << " : ";
			a[i].xuat();
		}
	}
}
