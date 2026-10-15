#include<bits/stdc++.h>
using namespace std;
class SANPHAM{
	private:
		char MASP[50];
		char TENSP[50];
		int SOLUONG;
		double DONGIA;
	public:
		void Nhap(){
			cout<<"Nhap ma san pham:";
			cin.ignore();
			cin.getline(MASP,50);
			
			cout<<"Nhap ten san pham:";
			cin.getline(TENSP,50);
			
			cout<<"Nhap so luong:"; cin>>SOLUONG;
			
			cout<<"Nhap don gia:"; cin>>DONGIA;
		}
		void Xuat(){
			cout << left << setw(15) << MASP
             << setw(25) << TENSP
             << setw(15) << SOLUONG
             << setw(15) << DONGIA
             << setw(15) << SOLUONG * DONGIA
             << endl;
		}
		double ThanhTien(){
			return SOLUONG*DONGIA;
		}
		void SuaSoLuong(int sl){
			SOLUONG=sl;
		}
		char* getTENSP(){
			return TENSP;
		}
};
class PHIEU{
	private:
		char MAPHIEU[50];
		char MANCC[50];
		char DIACHI[100];
		char NGAYLAP[20];
		char TENNCC[50];
		char SDT[15];
		SANPHAM *x;
		int n;
	public:
		PHIEU(){
			x=NULL;
			n=0;
		}
		~PHIEU(){
			delete[] x;
		}
		void Nhap(){
			cout<<"Nhap ma phieu:";
			cin.getline(MAPHIEU,50);
			
			cout<<"Nhap ma nha cung cap:";
			cin.getline(MANCC,50);
			
			cout<<"Nhap ten nha cung cap:";
			cin.getline(TENNCC,50);
			
			cout<<"Nhap dia chi:";
			cin.getline(DIACHI,100);
			
			cout<<"Nhap ngay lap:";
			cin.getline(NGAYLAP,20);
			
			cout<<"Nhap so dien thoai:";
			cin.getline(SDT,15);
			
			cout<<"Nhap so luong san pham:";
			cin>>n;
			x=new SANPHAM[n];
			for(int i=0;i<n;i++){
				cout<<"\nNhap san pham thu "<<i+1<<":\n";
				x[i].Nhap();
			}
		}
		void Xuat(){
			cout<<"\n===PHIEU NHAP VAN PHONG PHAM===\n";
			cout << "Ma phieu: " << MAPHIEU << endl;
        	cout << "Ma nha cung cap: " << MANCC << endl;
        	cout << "Dia chi: " << DIACHI << endl;
        	cout << "Ngay lap: " << NGAYLAP << endl;
        	cout << "Ten nha cung cap: " << TENNCC << endl;
        	cout << "SDT: " << SDT << endl;
        	cout<<"\n";
        	cout<<left<<setw(15)<<"Ma san pham"
        		<<setw(25)<<"Ten san pham"
        		<<setw(15)<<"So luong"
        		<<setw(15)<<"Don gia"
        		<<setw(15)<<"Thanh tien"
        		<<endl;
        	double tong=0;
        	for(int i=0;i<n;i++){
        		x[i].Xuat();
        		tong+=x[i].ThanhTien();
			}
			cout<<"\nTong tien:"<<tong<<endl;
		}
		void TimSanPham(){
			int dem=0;
			cout<<"\nCac san pham co thanh tien >=450.000:\n";
			for(int i=0;i<n;i++){
				if(x[i].ThanhTien()>450000){
					x[i].Xuat();
					dem++;
					
				}
			}
			cout<<"So san pham thoa man:"<<dem<<endl;
		}
		void SuaSanPham(){
			for(int i=0;i<n;i++){
				if(strcmp(x[i].getTENSP(),"But da bang")==0){
					x[i].SuaSoLuong(85);
			}
		}
	}
};
int main(){
	PHIEU p;
	p.Nhap();
	cout<<"\nPHIEU VUA NHAP:";
	p.Xuat();
	p.TimSanPham();
	p.SuaSanPham();
	cout<<"\nPHIEU SAU KHI DA SUA SO LUONG:";
	p.Xuat();
	return 0;
}
