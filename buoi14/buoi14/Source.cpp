#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 100
struct PhanSo // đối tượng
{
	int tu, mau;
};
PhanSo cong(PhanSo a, PhanSo b)
{
	PhanSo kq;
	kq.tu = a.tu * b.mau + a.mau * b.tu;
	kq.mau = a.mau*b.mau;
	return kq;
}

// Hướng đối tượng
class CPhanSo
{
public:
	int tu, mau;
	CPhanSo cong(CPhanSo a)
	{
		CPhanSo kq;
		kq.tu = tu * a.mau + mau * a.tu;
		kq.mau = mau * a.mau;
		return kq;
	}
	// In ra giá trị phân số
	void in()
	{
		cout << tu << "/" << mau;
	}
	void nhap()
	{
		cout << "Nhap tu: ";
		cin >> tu;
		cout << "Nhap mau: ";
		cin >> mau;
	}
};
// Đóng gói, bao đóng
class CHinhChuNhat
{
private: // Ngăn sự truy xuất từ bên ngoài lớp
	// Bảo bọc, che chắn dữ liệu
	int chieuDai, chieuRong;
	// void abc(); // main() khong goi dc
public:
	//int chieuDai, chieuRong;
	void setChieuDai(int d)
	{
		if (d > 0)
			chieuDai = d;
	}
	void setChieuRong(int r)
	{
		chieuRong = r;
	}
	int getChieuDai()
	{
		return chieuDai;
	}
	int getChieuRong()
	{
		return chieuRong;
	}
	void nhap()
	{
		cout << "Nhap chieu dai: ";
		cin >> chieuDai;
		cout << "Nhap chieu rong: ";
		cin >> chieuRong;
	}
	int tinhChuVi()
	{
		return 2 * (chieuDai + chieuRong);
	}
	int tinhDienTich()
	{
		return chieuDai * chieuRong;
	}

};

class CPoint2D
{
private:
	float hoanhDo;
	float tungDo;
public:
	void set(float x, float y)
	{
		hoanhDo = x;
		tungDo = y;
	}
	void xuat()
	{
		cout << "(" << hoanhDo << ", " << tungDo << ")";
	}
	void move(float dx, float dy)
	{
		hoanhDo = hoanhDo + dx;
		tungDo = tungDo + dy;
	}
};
class CCircle
{
	float banKinh;
	CPoint2D tam;
public:
	void set(CPoint2D x, float r)
	{
		tam = x;
		if (r > 0)
			banKinh = r;
	}
	void move(float dx, float dy)
	{
		tam.move(dx, dy);
	}
	void xuat()
	{
		cout << "Tam: ";
		tam.xuat();
		cout << ", Ban kinh: " << banKinh << endl;
	}
	float getArea()
	{
		return 3.14*banKinh*banKinh;
	}
};
/*
Hãy định nghĩa class của các object Laptop. Biết rằng, thông tin của một Laptop
bao gồm: mã sản phẩm (số nguyên dương), tên sản phẩm, giá bán, cấu hình.
Trong đó, cấu hình người dùng quan tâm gồm: Dung lượng RAM, dung lượng ổ cứng,
kích thước của màn hình.

Bổ sung các phương thức dùng để:
1. Lấy dữ liệu, truyền dữ liệu (get, set).
2. Nhập, xuất thông tin laptop.
3. Kiểm tra xem Laptop có đạt chuẩn cho Devloper ko? Biết lap đạt chuẩn phải
có dung lượng RAM tối thiểu là 4GB và dụng lượng ổ cứng tối thiểu là 500GB.
*/
class CCauHinh
{
private:
	int dungLuongRAM;
	int dungLuongOCung;
	int wManHinh;
	int hManHinh;
public:
	int getDungLuongRAM()
	{
		return dungLuongRAM;
	}
	int getDungLuongOCung()
	{
		return dungLuongOCung;
	}
	int getWManHinh()
	{
		return wManHinh;
	}
	int getHManHinh()
	{
		return hManHinh;
	}
	void setDungLuongRAM(int x)
	{
		if (x > 0)
			dungLuongRAM = x;
	}
	void setDungLuongOCung(int x)
	{
		if (x > 0)
			dungLuongOCung = x;
	}
	void setWManHinh(int w)
	{
		if (w > 0)
			wManHinh = w;
	}
	void setHManHinh(int h)
	{
		if (h > 0)
			hManHinh = h;
	}
	void nhap()
	{
		cout << "+ Nhap dung luong RAM: ";
		cin >> dungLuongRAM;
		cout << "+ Nhap dung luong o cung: ";
		cin >> dungLuongOCung;
		cout << "+ Nhap do rong man hinh: ";
		cin >> wManHinh;
		cout << "+ Nhap do cao man hinh: ";
		cin >> hManHinh;
	}
	void xuat()
	{

	}

};
class CLaptop
{
private:
	int maSP;
	char tenSP[30];
	int giaBan;
	CCauHinh cauHinh;
public:
	int getMaSP()
	{
		return maSP;
	}
	char* getTenSP()
	{
		return tenSP;
	};
	int getGiaBan()
	{
		return giaBan;
	}
	CCauHinh getCauHinh()
	{
		return cauHinh;
	}
	void setMaSP(int m)
	{
		maSP = m;
	}
	void setTenSP(char t[])
	{
		strcpy(tenSP, t);
	}
	void setCauHinh(CCauHinh c)
	{
		cauHinh = c;
	}
	void nhap()
	{
		do
		{
			cout << "+ Nhap ma: ";
			cin >> maSP;
			if (maSP <= 0)
				cout << "Ma SP phai la mot so nguyen duong. Vui long nhap lai";
		} while (maSP <= 0);

		cout << "+ Nhap ten: ";
		fflush(stdin); // rewind(stdin)
		gets(tenSP);
		do
		{
			cout << "+ Nhap gia ban: ";
			cin >> giaBan;
			if (giaBan < 0)
				cout << "Gia ban phai la mot so khong am. Vui long nhap lai";
		} while (giaBan < 0);
		cout << "+ Nhap cau hinh: ";
		cauHinh.nhap(); // Phai hieu duoc
	}
	void xuat()
	{
		/* // Xuat theo chieu doc
		cout << "+ Ma san pham: " << maSP << endl;
		cout << "+ Ten san pham: " << tenSP << endl;
		cout << "+ Gia ban: " << giaBan << endl;
		cout << "+ Cau hinh: " << endl;

		//cauHinh.xuat(); // Cach 1

		// Cach 2
		cout << "    - Dung luong RAM: " << cauHinh.getDungLuongRAM() << endl;
		cout << "    - Dung luong o cung: " << cauHinh.getDungLuongOCung() << endl;
		cout << "    - Do rong man hinh: " << cauHinh.getWManHinh() << endl;
		cout << "    - Do cao man hinh: " << cauHinh.getHManHinh() << endl;
		*/

		cout << setw(5) << maSP;
		cout << setw(10) << tenSP;
		cout << setw(7) << giaBan;

	}
	bool kiemTraChuanDev()
	{
		if (cauHinh.getDungLuongRAM() >= 4 && cauHinh.getDungLuongOCung() >= 500)
			return true;
		else
			return false;
	}
	int tinhDiem()
	{
		int diem;
		diem = 3 * cauHinh.getDungLuongRAM() + cauHinh.getDungLuongOCung();
		return diem;
	}
};
/* BTVN:
Bài 1: Cải tiến phương thức nhập của lớp CLaptop để đảm bảo dữ liệu phải được
nhập hợp lệ.
Bài 2: Cải tiến hàm xuất để xuất thông tin laptop theo chiều ngang. (dùng setw)
Bài 3:
Viết chương trình quản lý Laptop cho một cửa hàng bán laptop.
Thông tin của một chiếc laptop được mô tả như trên. Chương trình cho phép
quản lý nhiều laptop trong một danh sách, với các chức năng sau:
1. Thêm một laptop vào danh sách.
2. Hiển thị danh sách các laptop.
3. Tính giá trung bình của các laptop.
4. Tìm laptop có cấu hình khủng nhất, biết độ khủng được đo dựa theo điểm cấu hình.
Điểm cấu hình càng cao thì cấu hình càng khủng.
Điểm cấu hình = 3*Dung lượng RAM + Dung lượng ổ cứng
5. Hãy cho biết có chiếc laptop nào không đạt chuẩn Developer không?
*/
class CCuaHangLatop
{
private:
	CLaptop danhSachLaptop[MAX];
	int soLuongLaptop = 0;
public:
	// Phương thức cài đặt chức năng
	void them(CLaptop lap)
	{
		danhSachLaptop[soLuongLaptop] = lap; // a[n] = x
		soLuongLaptop++;
	}
	void xuat()
	{
		for (int i = 0; i < soLuongLaptop; i++)
		{
			danhSachLaptop[i].xuat();
			cout << endl;
		}
	}
	int tinhGiaTB()
	{
		int s = 0;
		for (int i = 0; i < soLuongLaptop; i++)
		{
			s = s + danhSachLaptop[i].getGiaBan();
		}
		return s / soLuongLaptop;
	}
	CLaptop timLapTopKhungNhat()
	{
		/*int maxDiem = danhSachLaptop[0].getCauHinh().getDungLuongRAM() * 3 + danhSachLaptop[0].getCauHinh().getDungLuongOCung();*/
		//int maxDiem = danhSachLaptop[0].tinhDiem();
		CLaptop kq = danhSachLaptop[0];
		for (int i = 0; i < soLuongLaptop; i++)
		{
			if (danhSachLaptop[i].tinhDiem() > kq.tinhDiem())
			{
				//maxDiem = danhSachLaptop[i].tinhDiem();
				kq = danhSachLaptop[i];
			}
		}
		return kq;
	}
	bool coLapTopKhongDatChuan()
	{
		for (int i = 0; i < soLuongLaptop; i++)
		{
			if (danhSachLaptop[i].kiemTraChuanDev() == false)
				return true;
		}
		return false;
	}
};
class CChuongTrinh
{
private:
	CCuaHangLatop cuaHang;
public:
	void inMenu()
	{
		cout << "1. Them laptop" << endl;
		cout << "2. ..." << endl;
	}
	void chay()
	{
		bool tiepTuc = true;
		while (tiepTuc)
		{
			system("cls");
			inMenu();
			int luaChon;
			cout << "Ban chon chuc nang: ";
			cin >> luaChon;
			switch (luaChon)
			{
			case 1:
				CLaptop lap;
				lap.nhap();
				cuaHang.them(lap);
				break;
			case 2:
				cuaHang.xuat();
				break;
			case 4:{
					   CLaptop kq = cuaHang.timLapTopKhungNhat();
					   kq.xuat();
					   break;
			}
			default:
				cout << "Khong ton tai chuc nang nay.";
			}
			cout << "Ban co muon tiep tuc khong? ";
			cin >> tiepTuc;
		}

	}
};
int main()
{
	CPoint2D a;
	a.set(5, 2);
	a.move(4, 3);
	cout << "Thong tin cua diem a: ";
	a.xuat();
	cout << endl;

	CPoint2D b;
	b.set(3, 8);
	cout << "Thong tin cua diem b: ";
	b.xuat();
	cout << endl;

	CCircle c;
	c.set(a, 7);
	cout << "Thong tin cua hinh tron: ";
	c.xuat();
	cout << endl;
	cout << "Dien tich hinh tron: " << c.getArea() << endl;

	cout << "==================================\n";
	/*
	CLaptop m;
	m.nhap();
	m.xuat();
	if (m.kiemTraChuanDev() == true)
	cout << "Laptop dat chuan developer.";
	else
	cout << "Laptop chua dat chuan developer.";
	*/

	CChuongTrinh ct;
	ct.chay();
	return 0;
}