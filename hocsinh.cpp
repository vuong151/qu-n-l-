#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
class HocSinh{
	private:
		int MHS;
		string hoTen;
		int UT;
		int DRL;
	public:
		HocSinh(){
		}
		friend istream&operator>>(istream&is , HocSinh&hs){
			cout<<"Nhap ma hoc sinh: ";
			is>>hs.MHS;
			cout<<"Nhap ho ten: ";
			is.ignore();
			getline(is,hs.hoTen);
			cout<<"Nhap loai uu tien: ";
			is>>hs.UT;
			cout<<"Nhap diem ren luyen: ";
			is>>hs.DRL;
		}
		friend ostream&operator<<(ostream& os , HocSinh&hs){
			os<<hs.MHS<<" , "<<hs.hoTen<<" , "<<hs.UT<<" , "<<hs.DRL;
		}
		int tongDRL(){
			return UT+DRL;
		}
		bool operator<(HocSinh&hs){
			return tongDRL()<hs.tongDRL();
		}
		int getut(){
			return UT;
		}
		string HoTen(){
			return hoTen;
		}
};
int main (){
	int n;
	HocSinh a[100];
	cout<<"Nhap vao so hoc sinh: ";
	cin>>n;
	for( int i=0 ; i<n ; i++){
		cout<<"Nhap du lieu: ";
		cin>>a[i];
	}
	for(int i=0 ; i<n-1 ;i++){
		for(int j=i+1 ; j<n ; j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	cout<<"Danh sach hoc sinh theo thu tu giam dan la: ";
	for(int i=0 ; i<n ;i++){
		cout<<a[i]<<endl;
	}
	int sutl1=0,sutl2=0,sutl3=0,sutl4=0;
	for(int i=0 ; i<n ;i++){
		if(a[i].getut()==1){
			sutl1++;
		}
	}
	cout<<"So hoc sinh uu tien loai 1 la: "<<sutl1<<endl;
	for(int i=0 ; i<n ;i++){
		if(a[i].getut()==2){
			sutl2++;
		}
	}
	cout<<"So hoc sinh uu tien loai 2 la: "<<sutl2<<endl;
	for(int i=0 ; i<n ;i++){
		if(a[i].getut()==3){
			sutl3++;
		}
	}
	cout<<"So hoc sinh uu tien loai 3 la: "<<sutl3<<endl;
	for(int i=0 ; i<n ;i++){
		if(a[i].getut()==4){
			sutl4++;
		}
	}
	cout<<"So hoc sinh uu tien loai 4 la: "<<sutl4<<endl;
	string timten;
	bool timthay=false;
	cout<<"Nhap ten hoc sinh can tim: ";
	cin.ignore();
	getline(cin,timten);
	for(int i=0 ; i<n ;i++){
		if(a[i].HoTen()==timten){
			timthay=true;
			cout<<"Hoc sinh can tim la: "<<a[i]<<endl;
		}
	}
	if(!timthay){
		cout<<"Khong co hoc sinh nao nhu the.";
	}
}
