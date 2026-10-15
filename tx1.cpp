#include<bits/stdc++.h>
using namespace std;
class DICHVU{
	private:
		char MADICHVU[50];
		char TENDICHVU[50];
		double GIACUOC;
	public:
		void Nhap(){
			cout<<"Nhap ma dich vu:";
			cin.ignore();
			cin.getline(MADICHVU,50);
			cout<<"Nhap ten dich vu:";
			cin.getline(TENDICHVU,50);
			cout<<"Nhap gia cuoc:"; cin>>GIACUOC;
		}
		void XUAT(){
			cout<<"Ma dich vu:"<<MADICHVU<<endl;
			cout<<"Ten dich vu:"<<TENDICHVU<<endl;
			cout<<"Gia cuoc:"<<GIACUOC<<endl;
		}
		double getGIACUOC(){
			return GIACUOC;
		}
};
class NGUOI{
	protected:
		char HOVATEN[50];
		char DIACHI[50];
		char SODIENTHOAI[15];
	public:
		void Nhap(){
			cout<<"Nhap ho va ten:";
			cin.getline(HOVATEN,50);
			cout<<"Nhap dia chi:";
			cin.getline(DIACHI,50);
			cout<<"Nhap so dien thoai:";
			cin.getline(SODIENTHOAI,50);
		}
		void Xuat(){
			cout<<"Ho va ten:"<<HOVATEN<<endl;
			cout<<"Dia chi:"<<DIACHI<<endl;
			cout<<"So dien thoai:"<<SODIENTHOAI<<endl;
		}
};
class KHACHHANG:public NGUOI{
	private:
		DICHVU *y;
		int n;
	public:
		KHACHHANG(){
			y=NULL;
			n=0;
		}
		~KHACHHANG(){
			delete[] y;
		}
		void Nhap(){
			cout<<"\n===NHAP THONG TIN KHACH HANG===\n";
			NGUOI::Nhap();
			cout<<"Nhap so luong dich vu:";
			cin>>n;
			y=new DICHVU[n];
			for(int i=0;i<n;i++){
				cout<<"\nNhap dich vu thu "<<i+1<<":\n";
				y[i].Nhap();
			}
		}
		void XUAT(){
			cout<<"\n===THONG TIN KHACH HANG===\n";
			NGUOI::Xuat();
			cout<<"\n===DANH SACH DICH VU===\n";
			for(int i=0;i<n;i++){
				y[i].XUAT();
			}
		}
		void SuaDiaChi() {
    		cout << "Nhap dia chi moi: ";
    		cin.ignore();
    		cin.getline(DIACHI, 50);
		}
		void Sapxep(){
			for(int i=0;i<n-1;i++){
				for(int j=i+1;j<n;j++){
					if(y[i].getGIACUOC()<y[j].getGIACUOC()){
						DICHVU temp=y[i];
						y[i]=y[j];
						y[j]=temp;
					}
				}
			}
		}
};
int main(){
	KHACHHANG kh;
	kh.Nhap();
	kh.Xuat();
	kh.SuaDiaChi();
	cout<<"\nTHONG TIN SAU KHI SUA DIA CHI:";
	kh.XUAT();
	kh.Sapxep();
	cout<<"\nTHONG TIN SAU KHI SAP XEP:";
	kh.XUAT();
	return 0;
}
