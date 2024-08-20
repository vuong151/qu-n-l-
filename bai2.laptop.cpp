#include<iostream>
#include<cmath>
using namespace std;
class LapTop{
	private:
		int maLT;
		string tenLT;
		float giatien;
	public:
		LapTop(){
		}
		void nhap(){
			cout<<"Nhap ma laptop: ";
			cin>>maLT;
			cout<<"Nhap ten laptop(loai A,B,C): ";
			cin.ignore();
			getline(cin,tenLT);
			cout<<"Nhap gia tien: ";
			cin>>giatien;
		}
		void xuat(){
			cout<<"Ma laptop: "<<maLT<<" , ten laptop: "<<tenLT<<" , gia tien: "<<giatien<<endl;
		}
		string gettenLT(){
			return tenLT;
		}
		float getGiaTien(){
			return giatien;
		}
};
int main(){
	int n;
	LapTop a[100];
	cout<<"Nhap vao so laptop: ";
	cin>>n;
	for( int i=1;i<=n;i++){
		cout<<"Laptop thu "<<i<<" la: "<<endl;
		a[i].nhap();
	}
	for( int i=1;i<=n;i++){
		a[i].xuat();
	}
	cout<<"Cac laptop loai A la: "<<endl;
	for( int i=1;i<=n;i++){
		if(a[i].gettenLT()=="A"){
			a[i].xuat();
		}
	}
	float b=a[1].getGiaTien();
	for( int i=1;i<=n;i++){
		if(b<a[i].getGiaTien()){
			b=a[i].getGiaTien();
		}
	}
	cout<<"laptop co gia tien cao nhat la: ";
	for( int i=1;i<=n;i++){
		if(b==a[i].getGiaTien()){
			a[i].xuat();
		}
	}
	float giatienminC=a[1].getGiaTien();
	cout << "Laptop loai C co gia tien thap nhat la: ";
	bool timC = false; 

	for (int i = 1; i <= n; i++) {
    	if (a[i].gettenLT() == "C") {
        	timC = true;
        	if (giatienminC > a[i].getGiaTien()) {
            	giatienminC = a[i].getGiaTien();
        	}
    	}
	}

	if (timC) {
    	for (int i = 1; i <= n; i++) {
        	if (a[i].gettenLT() == "C" && a[i].getGiaTien() == giatienminC) {
            	a[i].xuat();
        	}
    	}
	}
}
