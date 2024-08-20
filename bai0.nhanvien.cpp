#include<iostream>
#include<cmath>
using namespace std;
class NhanVien{
	private:
		int maNV;
		string tenNV;
		int snct;
		float hsl;
	public:
		NhanVien(){
		}
		void nhap(){
			cout<<"Nhap ma nv:";
			cin>>maNV;
			cout<<"Nhap ten nv: ";
			cin.ignore();
			getline(cin,tenNV);
			cout<<"Nhap snct: ";
			cin>>snct;
			cout<<"Nhap hsl: ";
			cin>>hsl;
		}
		void xuat(){
			cout<<"Ma nv: "<<maNV<<" , ten nv: "<<tenNV<<" , snct: "<<snct<<" , hsl: "<<hsl<<endl;
		}
		float tinhluong(){
			return 1.8*snct*hsl;
		}
		string gettenNV(){
			return tenNV;
		}
};
int main(){
	int n;
	NhanVien a[100];
	cout<<"Nhap vao so nhan vien: ";
	cin>>n;
	for( int i=1;i<=n;i++){
		cout<<"Nhap du lieu cho nhan vien thu "<<i<<" : "<<endl;
		a[i].nhap();
	}
	for( int i=1;i<=n;i++){
		cout<<"Du lieu nhan vien thu "<<i<<" la: ";
		a[i].xuat();
	}
	for( int i=1;i<=n;i++){
		cout<<"Luong cua nhan vien "<<i<<" la: "<<a[i].tinhluong()<<endl;
	}
	float b=a[1].tinhluong();
	for( int i=1;i<=n;i++){
		if(b<a[i].tinhluong()){
			b=a[i].tinhluong();
		}
	}
	cout<<"Nhan vien co luong cao nhat la: ";
	for( int i=1;i<=n;i++){
		if(b==a[i].tinhluong()){
			a[i].xuat();
		}
	}
	string tennhanvien;
	cout<<"Nhap ten nhan vien can tim: ";
	cin.ignore();
	getline(cin,tennhanvien);
	for( int i=1;i<=n;i++){
		if(tennhanvien==a[i].gettenNV()){
			cout<<"nhan vien can tim la: ";
			a[i].xuat();
		}
	}
	return 0;
}
