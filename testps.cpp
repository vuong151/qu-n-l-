#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int ucln(int x, int y){
	if(y==0)
		return x;
	return ucln(y,x%y);
}
class PhanSo{
	private:
		float tu;
		float mau;
	public:
		PhanSo(){
			tu=0;
			mau=1;
		}
		PhanSo(float a, float b){
			tu=a;
			mau=b;
			if(mau==0){
				cout<<"Phan so nao co mau=0 ?????";
				exit(0);
			}
			rutgon();
		}
		void rutgon(){
			int UCLN=ucln(tu,mau);
			tu/=UCLN;
			mau/=UCLN;
		}
		friend istream&operator>>(istream&is, PhanSo&ps){
			cout<<"Nhap phan so: ";
			is>>ps.tu>>ps.mau;
			if(ps.mau==0){
				cout<<"Phan so nao co mau=0???, cut me may di.";
				exit(0);
			}
			ps.rutgon();
		}
		friend ostream&operator<<(ostream&os, PhanSo&ps){
			os<<"Phan so la: "<<ps.tu<<"/"<<ps.mau;
		}
};
int main(){
	float a,b;
	cout<<"Nhap tu so va mau so phan so 1: ";
	cin>>a>>b;
	PhanSo ps1(a,b);
	cout<<"Phan so 1 la: "<<ps1;
	PhanSo ps2;
	cout<<"nhap phan so 2: ";
	cin>>ps2;
	cout<<"Phan so 2 la: "<<ps2;
}
