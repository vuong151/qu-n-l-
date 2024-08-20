#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
class DiemThi{
	public:
		int mamon;
		string tenmon;
		int sotinchi;
		float diemthi;
		float diemQT;
		DiemThi(){
		}
		friend istream&operator>>(istream&is , DiemThi&dt){
			cout<<"Nhap ma mon: ";
			is>>dt.mamon;
			cout<<"Nhap ten mon: ";
			is.ignore();
			getline(is,dt.tenmon);
			cout<<"Nhap so tin chi: ";
			is>>dt.sotinchi;
			cout<<"Nhap diem thi va diem qua trinh: ";
			is>>dt.diemthi>>dt.diemQT;
			return is;
		}
		friend ostream&operator<<(ostream&os , DiemThi&dt){
			os<<"Ma mon: "<<dt.mamon<<" , "<<"Ten mon: "<<dt.tenmon<<" , "<<"So tin chi: "<<dt.sotinchi<<" , "<<"Diem thi: "<<dt.diemthi<<" , "<<"Diem qua trinh: "<<dt.diemQT<<endl;
			return os;
		}
		float diemTB(){
			return 0.4*diemQT+0.6*diemthi;
		}
		bool operator<(DiemThi&dt){
			return diemTB()<dt.diemTB();
		}
		int getSotinchi(){
			return sotinchi;
		}
		float tongDiem(){
			return diemTB()*sotinchi;
		}
};
int main(){
	int n;
	DiemThi a[100];
	cout<<"Nhap vao so mon hoc: ";
	cin>>n;
	for( int i=0;i<n;i++){
		cout<<"Nhap du lieu diem thi cho mon hoc thu"<<i+1<<" : ";
		cin>>a[i];
	}
	for( int i=0;i<n-1;i++){
		for( int j=i+1 ; j<n ; j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for( int i=0;i<n;i++){
		cout<<"Du lieu: "<<a[i];
	}
	float diemBQ=0;
	for( int i=0;i<n;i++){
		if(a[i].diemTB()<4){
			diemBQ++;
		}
	}
	cout<<"Sinh vien co so diem binh quan nho hon 4 la: "<<diemBQ;
	float tongtinchi=0;
	float tongdiem1=0;
	float diemTK=0.0;
	for( int i=0;i<n;i++){
		tongdiem1+= a[i].tongDiem();
		tongtinchi+= a[i].getSotinchi();
	}
	//cout<<"tongdiem1"<<tongdiem1;
	//cout<<"\n"<<tongtinchi;
	if(tongtinchi!=0){
		diemTK=tongdiem1/tongtinchi;
	}
	cout<<"\nDiem tong ket sinh vien la: "<<diemTK;
	return 0;
}
