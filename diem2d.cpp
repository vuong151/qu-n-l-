#include<iostream>
#include<cmath>
using namespace std;
class Diem2D{
	private:
		float toadox;
		float toadoy;
	public:
		Diem2D(){
		}
		friend istream&operator>>(istream&is , Diem2D&2d){
			cout<<"Nhap vao toa do x ,y : ";
			is>>2d.toadox>>2d.toadoy;
			return is;
		}
		friend ostream&operator<<(ostream&os , Diem2D&2d){
			os<<2d.toadox<<2d.toadoy;
			return os;
		}
		float tinhkc(){
			return sqrt(pow(toadox-2d.toadox)+pow(toadoy-2d.toadoy));
		}
};
class Diem3D : public Diem2D{
	private:
		float toadoz;
	public:
		Diem3D(){
		}
		
};
