#include<iostream>
#include<cmath>
using namespace std;
class DaThuc{
	public:
		int n;
		int a[100];
		DaThuc(){
		}
		void nhap(){
			cout<<"Nhap n la bac cua da thuc: ";
			cin>>n;
			cout<<"Nhap he so cho da thuc: ";
			for(int i=0; i<=n; i++){
				cout<<"Nhap he so thu "<<i;
				cin>>a[i];
			}
		}
		void xuat(){
			cout<<"Da thuc la: ";
			for(int i=0; i<=n; i++){
				cout<<a[i]<<"x^"<<i;
				if(i!=n){
					cout<<"+";
				}
			}
			cout<<"=0"<<endl;
		}
		DaThuc operator+(DaThuc&dt){
			DaThuc ketqua;
			ketqua.n=max(n,dt.n);
			for(int i=0; i<=ketqua.n; i++){
				if(i<=n&& i<=dt.n ){
					ketqua.a[i]=a[i]+dt.a[i];
				}
				else if(i<=n){
					ketqua.a[i]=a[i];
				}
				else if(i<=dt.n){
					ketqua.a[i]=dt.a[i];
				}	
			}
			return ketqua;
		}
};
int main(){
	int n;
	DaThuc P;
	cout<<"Nhap da thuc thu 1: ";
	P.nhap();
	cout<<"Da thuc la: ";
	P.xuat();
	DaThuc Q;
	cout<<"Nhap da thuc 2: ";
	Q.nhap();
	cout<<"Da thuc thu 2 la: ";
	Q.xuat();
	DaThuc S;
	S=P+Q;
	cout<<"Da thuc tong la: ";
	S.xuat();
}
