 #include "DatPhong.h"

 DatPhong::DatPhong()
 {
 }

 DatPhong::~DatPhong()
 {
 }
 void  DatPhong::setId(string id)
 {
 	this->Id = id;
 }

void  DatPhong::setngaythue(Date ngay)
{
    	this->ngaythue= ngay;
}
void  DatPhong::setngaytra( Date ngay)
{
    	this->ngaytra = ngay;
}
void DatPhong::setMaKH(string ma)
{
	this->MaKH = ma;
}
string DatPhong::getMaKH()
{
	return MaKH;
}
void DatPhong::GhiFile(ostream& os)
{
    
    os << MaKH << endl;
    os << MaNV << endl;
    os << Id<<" " << ngaythue.Get_day() << " " << ngaythue.Get_month() << " " << ngaythue.Get_year() << " ";
    os << ngaytra.Get_day() << " " << ngaytra.Get_month() << " " << ngaytra.Get_year() << " ";
    os << "\n-------------------------------\n";
	
}

void DatPhong::DocFile(ifstream &in)
{
    int month, day, year;
    string str;
    getline(in >> ws, this->MaKH);
	getline(in >> ws, this->MaNV);
	in >> this->Id;
	in >> day >> month >> year;
    this -> ngaythue = Date(day, month, year);
	in >> day >> month >> year;
    this -> ngaytra = Date(day, month, year);
	getline(in, str);
	getline(in, str);
    
}
void DatPhong::setMaNV(string ma)
{
	this->MaNV = ma;
}
string DatPhong::getMaNV()
{
	return MaNV;
}
    
string DatPhong::getId()
{
	return Id;
}



void DatPhong::out(ostream& os)
{
	QuanLy_KhachHang KH;
	QuanLy_Phong PH;
	QuanLy_NhanVien NV;
	
	KhachHang khachhang = KH.SearchID(MaKH);
	Phong  phong = PH.SearchID(Id);
	NhanVien nhanvien = NV.SearchID(MaNV);
	

	os<<"|" << setw(12) << MaKH;
	os<<"|" << setw(17) << khachhang.getName();
	os<<"|"<< setw(12) << MaNV;
	os<<"|" << setw(17) << nhanvien.getName();
	os<<"|" << setw(12) << Id;
	os<<"|" << setw(12) << phong.getGiaPhong();
	os<<"|" << setw(12) << ngaythue;
	os<<"|" << setw(12) << ngaytra;

	int songay = ngaytra.daysBetweenDates(ngaythue);
	os<<"|" << setw(12) <<songay; 
	int tongtien = songay * phong.getGiaPhong();
	os<<"|" << setw(12) << tongtien << " |" << endl;
}
void DatPhong::Show()
{
	QuanLy_KhachHang KH;
	QuanLy_Phong PH;
	QuanLy_NhanVien NV;
	
	KhachHang khachhang = KH.SearchID(MaKH);
	Phong  phong = PH.SearchID(Id);
	NhanVien nhanvien = NV.SearchID(MaNV);
	

	cout<<"|" << setw(12) << MaKH;
	cout<<"|" << setw(17) << khachhang.getName();
	cout<<"|"<< setw(12) << MaNV;
	cout<<"|" << setw(17) << nhanvien.getName();
	cout<<"|" << setw(12) << Id;
	cout<<"|" << setw(12) << phong.getGiaPhong();
	cout<<"|" << setw(12) << ngaythue;
	cout<<"|" << setw(12) << ngaytra;

	int songay = ngaytra.daysBetweenDates(ngaythue);
	cout<<"|" << setw(12) <<songay; 
	int tongtien = songay * phong.getGiaPhong();
	cout<<"|" << setw(12) << tongtien << " |" << endl;

}
