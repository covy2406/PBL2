#include "QuanLy_DatPhong.h"

QuanLy_DatPhong::QuanLy_DatPhong()
{
	ifstream input;
	input.open("BookRoom.txt", ios::in);
	
	
		DatPhong data;
		int n;
		input >> n;
		for (int i = 1; i <= n; i++)
		{
			data.DocFile(input);
			this->list.AddTail(data);
		}
		input.close();
	
}

bool QuanLy_DatPhong::update()
{
	QuanLy_KhachHang KH;
	QuanLy_Phong PH;
	QuanLy_NhanVien NV;
	KhachHang khachhang;
	Phong s;
	NhanVien nhanvien;
	DatPhong br;
	Date ngaythue, ngaytra;
	string idKH, idNV, idPhong;
	// nhap id cua khach hang
	cout << "\t> Nhap ma phong: ";
	cin >> idPhong;

	int vt = getVT(idPhong);
	while (vt == -1)
	{
		cout << "\t Ma phong vua nhap khong co trong danh sach phong duoc dat. Vui long nhap lai\n";
		cout << "\t Nhap ma phong: ";
		cin >> idPhong;
		vt = getVT(idPhong);
	}
	s = PH.SearchID(idPhong);
	br = this->SearchID(idPhong);
	// cout << "\t\t\t\t\tTHONG TIN\n";
	//  in hoa don
	cout << "\t\t\t\t\t\tTHONG TIN DAT PHONG KHACH SAN\n";
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "|" << setw(12) << "Ma KH";
	cout << "|" << setw(17) << "Ten KH";
	cout << "|" << setw(12) << "Ma NV";
	cout << "|" << setw(17) << "Ten NV";
	cout << "|" << setw(12) << "Ma Phong";
	cout << "|" << setw(12) << "Gia Phong";
	cout << "|" << setw(20) << "Ngay thue";
	cout << "|" << setw(20) << "Ngay tra";

	cout << "|" << setw(12) << "So ngay";
	cout << "|" << setw(12) << "Tong tien    |" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	br.Show();
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

	string chon;
	cout << "Ban muon cap nhat khach hang khong (c/k)?";
	cin >> chon;

	if (chon == "c" || chon == "C")
	{
		cout << "\t> Nhap ma khach hang: ";
		cin >> idKH;

		khachhang = KH.SearchID(idKH);
		vt = KH.indexOf(khachhang);
		while (vt < 0)
		{
			cout << "Ma khach hang vua nhap khong dung. Vui long nhap lai id\n";
			cout << "Nhap id cua Khach hang: ";
			cin >> idKH;
			khachhang = KH.SearchID(idKH);
			// kiem tra id co trung trong danh sach va co trong danh sach ql
			vt = KH.indexOf(khachhang);
		}
		br.setMaKH(idKH);
	}
	else 
	{
		cout<< "\tBan da nhap sai cu phap. Chi nhap c/k\n";
		return 0;
	};
	cout << "Ban muon cap nhat nhan vien khong(c/k)?";
	cin >> chon;
	if (chon == "c" || chon == "C")
	{
		cout << "\t> Nhap ma nhan vien:  ";
		cin >> idNV;

		nhanvien = NV.SearchID(idNV);
		vt = NV.indexOf(nhanvien);
		while (vt < 0)
		{
			cout << "Ma nhan vien vua nhap khong dung. Vui long nhap lai id\n";
			cout << "\t> Nhap id cua nhan vien: ";
			cin >> idNV;
			nhanvien = NV.SearchID(idNV);
			// kiem tra id nay co trung trong danh sach va co trong danh sach ql khong
			vt = NV.indexOf(nhanvien);
		}
		br.setMaNV(idNV);
	}
	else 
	{
		cout<< "\tBan da nhap sai cu phap. Chi nhap c/k\n";
		return 0;
	};
	cout << "Ban muon cap nhat ngay thue phong khong(c/k)?";
	cin >> chon;
	if (chon == "c" || chon == "C")
	{

		cout << "\t> Nhap ngay thue phong: ";
		cin >> ngaythue;

		br.setngaythue(ngaythue);
	}
	else 
	{
		cout<< "\tBan da nhap sai cu phap. Chi nhap c/k\n";
		return 0;
	};
	cout << "Ban muon cap nhat ngay tra phong khong(c/k)?";
	cin >> chon;
	if (chon == "c" || chon == "C")
	{

		cout << "\t> Nhap ngay tra phong: ";
		cin >> ngaytra;

		br.setngaytra(ngaytra);
	}
	else 
	{
		cout<< "\tBan da nhap sai cu phap. Chi nhap c/k\n";
		return 0;
	};
	this->updateByID(br, idPhong);
	save();
	cout << "Cap nhat thanh cong!!\n";
	return 0;
}

bool QuanLy_DatPhong::datphong()
{
	QuanLy_KhachHang KH;
	QuanLy_Phong PH;
	QuanLy_NhanVien NV;

	KhachHang khachhang;
	Phong s;
	NhanVien nhanvien;
	DatPhong br;
	Date ngaythue, ngaytra;
	string idKH, idNV, idPhong;
	// nhap id cua khach hang
	cout << "\t> Nhap ma khach hang: ";
	cin >> idKH;

	khachhang = KH.SearchID(idKH);
	int vt = KH.indexOf(khachhang);
	while (vt < 0)
	{
		cout << "Ma khach hang vua nhap khong dung. Vui long nhap lai id\n";
		cout << "Nhap id cua Khach hang: ";
		cin >> idKH;
		khachhang = KH.SearchID(idKH);
		
		vt = KH.indexOf(khachhang);
	}

	// nhap id nhan vien
	cout << "\t> Nhap ma nhan vien:  ";
	cin >> idNV;

	nhanvien = NV.SearchID(idNV);
	vt = NV.indexOf(nhanvien);
	while (vt < 0)
	{
		cout << "Ma nhan vien vua nhap khong dung. Vui long nhap lai id\n";
		cout << "\t> Nhap id cua nhan vien: ";
		cin >> idNV;
		nhanvien = NV.SearchID(idNV);
		
		vt = NV.indexOf(nhanvien);
	}
	// nhap vao ma phong

	cout << "\t> Nhap Ma phong thue: ";
	cin >> idPhong;
	s = PH.SearchID(idPhong);
	vt = PH.indexOf(s);
	while (vt == -1 || s.getTrangthai() == true)
	{
		cout << "Id Phong nhap sai hoac dang co khach khac thue va khong khong the dat phong nay\n";
		cout << "\t> Nhap Ma phong thue: ";
		cin >> idPhong;
		s = PH.SearchID(idPhong);
		vt = PH.indexOf(s);
	};
	cout << "\t> Nhap ngay thue phong: ";
	cin >> ngaythue;

	br.setngaythue(ngaythue);

	cout << "\t> Nhap ngay tra phong: ";
	cin >> ngaytra;
	br.setngaytra(ngaytra);
	br.setId(idPhong);
	br.setMaKH(idKH);
	br.setMaNV(idNV);

	s.setTrangthai(true);
	
	PH.updateByID(s, idPhong);
	PH.save();
	list.AddTail(br);
	
	return true;
}
bool QuanLy_DatPhong::TraPhong()
{
	QuanLy_KhachHang KH;
	QuanLy_Phong PH;
	QuanLy_NhanVien NV;
	KhachHang khachhang;
	DatPhong br;
	Phong s;
	NhanVien nhanvien;
	Date ngaythue, ngaytra;
	string idKH, idNV, idPhong;
	// nhap id cua khach hang
	cout << "\t> Nhap ma phong: ";
	cin >> idPhong;

	int vt = getVT(idPhong);
	while (vt == -1)
	{
		cout << "\t Ma phong vua nhap khong co trong danh sach phong da thue. Vui long nhap lai\n";
		cout << "\t  Nhap ma phong: ";
		cin >> idPhong;
		vt = getVT(idPhong);
	}
	s = PH.SearchID(idPhong);
	br = this->SearchID(idPhong);
	string chon;
	cout << "Ban chac chan muon tra phong (c/k)?";
	cin >> chon;
	if (chon == "c" || chon == "C")
	{
		s.setTrangthai(false);
		PH.updateByID(s, idPhong);
		PH.save();
		// in hoa don
		cout << "\t\t\t\t\t\tTHONG TIN HOA DON PHONG DAT\n";
		cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		cout << "|" << setw(12) << "Ma KH";
		cout << "|" << setw(17) << "Ten KH";
		cout << "|" << setw(12) << "Ma NV";
		cout << "|" << setw(17) << "Ten NV";
		cout << "|" << setw(12) << "Ma Phong";
		cout << "|" << setw(12) << "Gia Phong";
		cout << "|" << setw(20) << "Ngay thue";
		cout << "|" << setw(20) << "Ngay tra";

		cout << "|" << setw(12) << "So ngay";
		cout << "|" << setw(12) << "Tong tien    |" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		br.Show();
		cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		cout << "\t\t\t\t\t\tCAM ON QUY KHACH\n";
		// Ghi ra file
		Date now;
		now.getToDay();
		ofstream out;
		string filename = br.getMaKH() + "_";
		filename = filename + now.toString1() + ".txt";
		out.open(filename.c_str());

		// in hoa don
		out << "\t\t\t\t\t\tTHONG TIN HOA DON PHONG DAT\n";
		out << "--------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		out << "|" << setw(12) << "Ma KH";
		out << "|" << setw(17) << "Ten KH";
		out << "|" << setw(12) << "Ma NV";
		out << "|" << setw(17) << "Ten NV";
		out << "|" << setw(12) << "Ma Phong";
		out << "|" << setw(12) << "Gia Phong";
		out << "|" << setw(20) << "Ngay thue";
		out << "|" << setw(20) << "Ngay tra";

		out << "|" << setw(12) << "So ngay";
		out << "|" << setw(12) << "Tong tien    |" << endl;
		out << "--------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		br.out(out);
		out << "--------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		out << "\t\t\t\t\t\tCAM ON QUY KHACH\n";
		out.close();

		// cap nhat lai mang list
		// this->list.Delete(br);
		list.DeleteAt(vt);
		save();
	}
	// s.Output();

	return true;
}
int QuanLy_DatPhong::getvtidPhong(string id, string ds[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (ds[i] == id)
			return i;
	}
	return -1;
}
int QuanLy_DatPhong::getVT(string id)
{
	Node<DatPhong> *ptr = list.getHead();
	DatPhong mts;
	int i = 0;
	while (ptr != NULL)
	{
		mts = ptr->getData();
		if (mts.getId() == id)
		{
			return i;
		}
		i++;
		ptr = ptr->getNext();
	}
	return -1;
}
void QuanLy_DatPhong::run()
{
	int luachon;
	while (1)
	{
		system("cls"); // xoa man hinh
		Menu();
		cout << "Lua chon = ";
		cin >> luachon;
		switch (luachon)
		{
		case 1:
		{
			datphong();
			cout<< "Da dat phong thanh cong\n";
			save();
			system("pause");
			break;
		}
		case 2:
		{
			TraPhong();
			system("pause");

			break;
		}
		case 3:
		{

			update();
			system("pause");
			break;
		}
		case 4:
		{
			string id;
			cout << "Nhap ma phong : ";
			cin >> id;
			ShowByID(id);
			system("pause");
			break;
		}
		case 5:
		{

			Show();
			system("pause");
			break;
		}
		case 0:
		{
			return;
		}
		}
	}
}
void QuanLy_DatPhong::Menu()
{
	cout << "\t\t\t=================MENU DAT PHONG================\n";
	cout << "\t\t\t|1. Dat Phong Khach San                       |\n";
	cout << "\t\t\t|2. Tra Phong Khach San                       |\n";
	cout << "\t\t\t|3. Chinh sua thong tin                       |\n";
	cout << "\t\t\t|4. Hien thi danh sach theo Ma Phong          |\n";
	cout << "\t\t\t|5. Hien thi toan bo danh sach                |\n";
	cout << "\t\t\t|0. Thoat                                     |\n";
	cout << "\t\t\t===============================================\n";
}
void QuanLy_DatPhong::Show()
{
	Node<DatPhong> *ptr = list.getHead();
	DatPhong mts;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "|" << setw(12) << "Ma KH";
	cout << "|" << setw(17) << "Ten KH";
	cout << "|" << setw(12) << "Ma NV";
	cout << "|" << setw(17) << "Ten NV";
	cout << "|" << setw(12) << "Ma Phong";
	cout << "|" << setw(12) << "Gia Phong";
	cout << "|" << setw(20) << "Ngay thue";
	cout << "|" << setw(20) << "Ngay tra";

	cout << "|" << setw(12) << "So ngay";
	cout << "|" << setw(12) << "Tong tien    |" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	while (ptr != NULL)
	{
		mts = ptr->getData();
		mts.Show();
		ptr = ptr->getNext();
		cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	}
}
void QuanLy_DatPhong::ShowByID(const string &id) // Hiển thị bằng ID
{
	Node<DatPhong> *ptr = list.getHead();
	DatPhong mts;
	while (ptr != NULL)
	{
		mts = ptr->getData();
		if (mts.getId() == id)
		{
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			cout << "|" << setw(12) << "Ma KH";
			cout << "|" << setw(17) << "Ten KH";
			cout << "|" << setw(12) << "Ma NV";
			cout << "|" << setw(17) << "Ten NV";
			cout << "|" << setw(12) << "Ma Phong";
			cout << "|" << setw(12) << "Gia Phong";
			cout << "|" << setw(20) << "Ngay thue";
			cout << "|" << setw(20) << "Ngay tra";

			cout << "|" << setw(12) << "So ngay";
			cout << "|" << setw(12) << "Tong tien    |" << endl;
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

			mts.Show();
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

			return;
		}

		ptr = ptr->getNext();
	}
	cout << "ID vua nhap khong co trong danh sach\n";
}

DatPhong QuanLy_DatPhong::SearchID(const string &id) // Tìm bằng ID
{
	Node<DatPhong> *ptr = list.getHead();
	DatPhong mts;
	int i = 0;
	while (ptr != NULL)
	{
		mts = ptr->getData();
		if (mts.getId() == id)
		{
			return mts;
		}
		ptr = ptr->getNext();
	}
	DatPhong trave;
	return trave;
}
void QuanLy_DatPhong::save()
{
	// Ghi ra file
	Node<DatPhong> *ptr = this->list.getHead();
	ofstream out;
	out.open("BookRoom.txt");
	out << this->list.getcount() << endl;
	while (ptr != NULL)
	{
		ptr->getData().GhiFile(out);
		ptr = ptr->getNext();
	}
	out.close();
}
bool QuanLy_DatPhong::DeleteByID(const string &)
{
	return true;
}
void QuanLy_DatPhong::add(DatPhong) // Thêm vào danh sách
{
}
bool QuanLy_DatPhong::Delete(const DatPhong br) // Xóa
{
	return true;
}
bool QuanLy_DatPhong::updateByID(const DatPhong R, const string &ID)
{
	Node<DatPhong> *ptr = this->list.getHead();
	while (ptr != NULL)
	{
		if (ptr->getData().getId() == ID)
		{
			ptr->setData(R);
			return true;
		}
		ptr = ptr->getNext();
	}
	return false;
}
