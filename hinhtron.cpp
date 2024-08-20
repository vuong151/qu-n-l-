#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
class HinhTron{
	private:
		float hoanhDo;
		float tungDo;
		float r;
	public:
		HinhTron(){
		}
		HinhTron( float x , float y , float r){
			hoanhDo=x;
			tungDo=y;
			r=r;
		}
		void nhap(){
			cout<<"Nhap hoanh do: ";
			cin>>hoanhDo;
			cout<<"Nhap tung do: ";
			cin>>tungDo;
			cout<<"Nhap ban kinh: ";
			cin>>r;
		}
		friend ostream&operator <<(ostream&os , HinhTron&ht){
			os<<"Hoanh do la: "<<ht.hoanhDo<<", tung do la:"<<ht.tungDo<<" , ban kinh la: "<<ht.r;
			return os;
		}
		float tinhdientich(){
			return 3.14*r*r;
		}
		float HoanhDo(){
			return hoanhDo;
		}
		float TungDo(){
			return tungDo;
		}
		float R(){
			return r;
		}
};
class Mau: public HinhTron{
	private:
		string mau;
	public:
		Mau(){
		}
		void nhap(){
			HinhTron::nhap();
			cout<<"Nhap mau (Do , Xanh , Vang): ";
			cin.ignore();
			getline(cin,mau);
		}
		friend ostream&operator<<(ostream&os , Mau&ht){
			HinhTron& hinhtron= ht;
			os<<hinhtron<<" , mau la: "<<ht.mau;
			return os;
		}
		string MAU(){
			return mau;
		}
};
int main(){
	int n;
	Mau a[100];
	cout<<"Nhap so hinh tron: ";
	cin>>n;
	for( int i=0; i<n; i++){
		cout<<"Nhap du lieu cho hinh tron thu"<<i+1<<" : ";
		a[i].nhap();
	}
	for( int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[i].tinhdientich()<a[j].tinhdientich()){
				swap(a[i],a[j]);
			}
		}
	}
	for( int i=0; i<n; i++){
		cout<<"Du lieu hinh tron sap xep giam dan theo dien tich la: "<<a[i]<<endl;
	}
	int thuocgocphantuthu2=0;
	for( int i=0; i<n; i++){
		if(a[i].HoanhDo()<0&&a[i].TungDo()>0&&a[i].TungDo()>a[i].R()){
			thuocgocphantuthu2++;
		}
	}
	cout<<"So hinh tron thuoc tron ven goc phan tu thu 2 la: "<<thuocgocphantuthu2++;
	int timdo=0;
	int timxanh=0;
	int timvang=0;
	float b=a[0].tinhdientich();
	cout<<"\nDien tich hinh tron do lon nhat la: ";
	for( int i=0; i<n; i++){
		if(a[i].MAU()=="Do"){
			timdo++;
			if(b<a[i].tinhdientich()){
				b=a[i].tinhdientich();
			}
			if(b==a[i].tinhdientich()){
				cout<<a[i];
			}
		}
	}
	for( int i=0; i<n; i++){
		if(a[i].MAU()=="Xanh"){
			timxanh++;
		}
	}
		for( int i=0; i<n; i++){
		if(a[i].MAU()=="Vang"){
			timvang++;
		}
	}
	float c=timxanh-timvang;
	if(c<0){
		cout<<"\nxanh it hon vang";
	}
	if(c>0){
		cout<<"\nxanh nhieu hon vang";
	}
	if(c==0){
		cout<<"\nxanh bang vang";
	}
}

