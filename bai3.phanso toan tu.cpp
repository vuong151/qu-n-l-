#include<iostream>
using namespace std;
int UCLN(int a, int b){
	if(b==0)
		return a;
	return UCLN(b,a%b);
}
class PhanSo{
	private:
		int tu;
		int mau;
	public:
		PhanSo(){
			tu=0;
			mau=1;
		}
		PhanSo(float a, float b){
			this->tu=a;
			this->mau=b;
			if(mau==0){
				cout<<"phan so nao co mau =0 ??? , moi hoc lai lop 1.";
				exit(0);
			}
			rutgon();
		}
		void rutgon(){
			int ucln=UCLN(tu,mau);
			tu/=ucln;
			mau/=ucln;
		}
		friend istream&operator>>(istream&is,PhanSo&ps){
			cout<<"Nhap tu so va mau so: ";
			is>>ps.tu>>ps.mau;
			if(ps.mau==0){
				cout<<"phan so nao co mau =0 ??? , moi hoc lai lop 1.";
				exit(0);
			}
			ps.rutgon();
			return is;
		}
		friend ostream&operator<<(ostream&os, PhanSo&ps){
			os<<ps.tu<<" / "<<ps.mau;
			return os;
		}
		PhanSo operator+( PhanSo&ps){
			PhanSo tong;
			tong.tu=tu*ps.mau+ps.tu*mau;
			tong.mau= mau*ps.mau;
			tong.rutgon();
			return tong;
		}
		PhanSo operator-(PhanSo&ps){
			PhanSo hieu;
			hieu.tu=tu*ps.mau-ps.tu*mau;
			hieu.mau=mau*ps.mau;
			hieu.rutgon();
			return hieu;
		}
		PhanSo operator*(PhanSo&ps){
			PhanSo tich;
			tich.tu=tu*ps.tu;
			tich.mau=mau*ps.mau;
			tich.rutgon();
			return tich;
		}
		PhanSo operator/(PhanSo&ps){
			PhanSo thuong;
			thuong.tu=tu*ps.mau;
			thuong.mau=mau*ps.tu;
			thuong.rutgon();
			return thuong;
		}
		bool operator >(PhanSo&ps){
			return tu*ps.mau>ps.tu*mau;
		}
		bool operator <(PhanSo&ps){
			return tu*ps.mau<ps.tu*mau;
		}
		bool operator ==(PhanSo&ps){
			return tu*ps.mau==ps.tu*mau;
		}		
};
int main(){
	float a,b;
	cout<<"Nhap vao tu so phan so 1: ";
	cin>>a;
	cout<<"Nhap vao mau so phan so 1: ";
	cin>>b;
	PhanSo ps1(a,b);
	PhanSo ps2;
	cout<<"Phan so thu 2: ";
	cin>>ps2;
	cout<<"2 phan so vua nhap la: "<<ps1<<" , "<<ps2;
	PhanSo tong=ps1+ps2;
	cout<<"\nTong 2 phan so la: "<<tong<<endl;
	PhanSo hieu=ps1-ps2;
	cout<<"Hieu 2 phan so la: "<<hieu<<endl;
	PhanSo tich=ps1*ps2;
	cout<<"Tich 2 phan so la: "<<tich<<endl;
	PhanSo thuong=ps1/ps2;
	cout<<"Thuong 2 phan so la: "<<thuong<<endl;
	if(ps1>ps2){
		cout<<"Phan so 1 lon hon phan so 2.";
	}
	if(ps1<ps2){
		cout<<"Phan so 1 nho hon phan so 2.";
	}
	if(ps1==ps2){
		cout<<"2 phan so bang nhau.";
	}
}
