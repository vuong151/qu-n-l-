#include<iostream>
#include<cmath>
using namespace std;
class DaThuc{
	public:
		int n;
		int a[100];
		DaThuc(){
		}
		friend istream&operator>>(istream&is, DaThuc&dt){
			cout<<"Nhap n la bac cua da thuc: ";
			is>>dt.n;
			for(int i=0; i<=dt.n; i++){
				cout<<"Nhap he so cua da thuc: ";
				cout<<"Nhap he so thu "<<i<<" :";
				is>>dt.a[i];
			}
			return is;
		}
		friend ostream&operator<<(ostream&os, DaThuc&dt){
			for(int i=0; i<=dt.n; i++){
				os<<dt.a[i]<<"x^"<<i;
				if(i!=dt.n){
					os<<"+";
				}
			}
			os<<"=0";
			return os;
		}
		DaThuc operator +(DaThuc&dt){
			DaThuc ketqua;
			ketqua.n=max(n,dt.n);
			for(int i=0; i<=ketqua.n; i++){
				if(i<=n&&i<=dt.n){
					ketqua.a[i]=a[i]+dt.a[i];
				}
				else if(i<=n){
					ketqua.a[i]=a[i];
				}
				if(i<=dt.n){
					ketqua.a[i]=dt.a[i];
				}
			}
			return ketqua;
			
		}
		float tinhP(float x1){
			int tinh1=0;
			for(int i=0; i<=n; i++){
				tinh1+=a[i]*pow(x1,i);
			}
			return tinh1;
		}
		float tinhQ(float x2){
			int tinh2=0;
			for(int i=0; i<=n; i++){
				tinh2+=a[i]*pow(x2,i);
			}
			return tinh2;
		}
		
};
int main(){
	int n;
	DaThuc P;
	cout<<"Nhap da thuc P: ";
	cin>>P;
	cout<<"\nP(x)="<<P;
	DaThuc Q;
	cout<<"\nNhap da thuc Q: ";
	cin>>Q;
	cout<<"\nQ(x)="<<Q;
	DaThuc S;
	S=P+Q;
	cout<<"\ntong 2 da thuc la: "<<Q;
	float x1,x2;
	cout<<"\nNhap x1: ";
	cin>>x1;
	for(int i=0; i<=n; i++){
		cout<<"\nKet qua da thuc P="<<P.tinhP(x1);
	}
	cout<<"\nNhap x2: ";
	cin>>x2;
	for(int i=0; i<=n; i++){
		cout<<"\nKet qua da thuc Q="<<Q.tinhQ(x2);
	}
	return 0;
	
}
