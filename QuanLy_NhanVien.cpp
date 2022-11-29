#include "QuanLy_NhanVien.h"
QuanLy_NhanVien::QuanLy_NhanVien()
{
	ifstream input;
	input.open("NhanVien.txt", ios::in);
		NhanVien data;
		int n;
		input >> n;
		for (int i = 1; i <= n; i++)
		{
			data.DocFile(input);
			this->list.AddTail(data);
		}
		input.close();
	
}
void QuanLy_NhanVien::read()
{
	ifstream input;
	input.open("NhanVien.txt", ios::in);
	if (input.fail())
	{
		cout << "Failed to open this file" << endl;
	}
	else
	{
		NhanVien data;
		int n;
		input >> n;
		for (int i = 1; i <= n; i++)
		{
			data.DocFile(input);
			this->list.AddTail(data);
		}
		input.close();
	}
}

void QuanLy_NhanVien::menu()
{
	cout << "\t\t\t----------------------------------------------\n";
	cout << "\t\t\t| 1. Them nhan vien vao dau danh sach       |\n";
	cout << "\t\t\t| 2. Them nhan vieng vao cuoi danh sach     |\n";
	cout << "\t\t\t| 3. Them nhan vien vao vi tri nhap vao     |\n";
	cout << "\t\t\t| 4. Sua thong tin nhan vien                |\n";
	cout << "\t\t\t| 5. Xoa nhan vien dau danh sach            |\n";
	cout << "\t\t\t| 6. Xoa nhan vien theo vi tri bat ky       |\n";
	cout << "\t\t\t| 7. Xoa nhan vien cuoi danh sach           |\n";
	cout << "\t\t\t| 8. Tim kiem thong tin theo ma nhan vien   |\n";
	cout << "\t\t\t| 9. Hien thi toan bo danh sach nhan vien   |\n";
	cout << "\t\t\t| 0. Thoat                                  |\n";
	cout << "\t\t\t----------------------------------------------\n";
	cout << "\t\t\t\tLua chon = ";
}
void QuanLy_NhanVien::run()
{
int luachon;
	string id;
	while (1)
	{
		system("cls");
		menu();
		cin >> luachon;
		NhanVien newNV;

		switch (luachon)
		{
		case 1:
		{
			cout << "\t\t\tTHEM NHAN VIEN VAO DAU DANH SACH\n";
			cout << "Nhap Ma Khach hang: ";
			cin >> id;
			NhanVien T = this->list.SearchID(id);

			while (T.getId() == id || id == "" || !NhanVien::isValidID(id))
			{
				cout << "Ma nhan vien da ton tai hoac khong hop le vui long nhap lai\nNhap Ma nhan vien: ";
				cin >> id;
				T = this->list.SearchID(id);
			}

			newNV.Input(id);

			this->addhead(newNV);
			system("pause");
			break;
		}
		case 2:
		{
			cout << "\t\t\tTHEM NHAN VIEN VAO CUOI DANH SACH\n";
			cout << "Nhap Ma Nhan vien: ";
			cin >> id;
			NhanVien T = this->list.SearchID(id);

			while (T.getId() == id || id == "" || !NhanVien::isValidID(id))
			{
				cout << "Ma nhan vien da ton tai hoac khong hop le vui long nhap lai\nNhap Ma nhan vien: ";
				cin >> id;
				T = this->list.SearchID(id);
			}

			newNV.Input(id);

			this->add(newNV);

			system("pause");
			break;
		}
		case 3:
		{
			cout << "\t\t\tTHEM NHAN VIEN VAO VI TRI NHAP VAO\n";
			cout << "Nhap Ma Khach hang: ";
			cin >> id;
			NhanVien T = this->list.SearchID(id);

			while (T.getId() == id || id == "" || !NhanVien::isValidID(id))
			{
				cout << "Ma nha vien da ton tai hoac khong hop le vui long nhap lai\nNhap Ma nhan vien: ";
				cin >> id;
				T = this->list.SearchID(id);
			}

			newNV.Input(id);
			cout << "Nhap vi tri them vao: ";
			int vt;
			cin >> vt;
			while (vt < 0 || vt > this->list.getcount())
			{
				cout << "Nhap sai vi tri\nNhap vi tri them vao: ";
				cin >> vt;
			}
			this->addAt(newNV, vt);

			system("pause");
			break;
		}
		case 4:
		{
			cout << "Nhap Ma Nhan vien muon cap nhat: ";
			cin >> id;
			NhanVien T = this->list.SearchID(id);

			while (T.getId() != id)
			{
				cout << "Ma nhan vien khong co trong danh sach\nNhap Ma nhan vien: ";
				cin >> id;
				T = this->list.SearchID(id);
			}

			newNV.update(id);

			this->updateByID(newNV, id);
			cout << "Cap nhat thanh cong\n";
			system("pause");
			break;
		}
		case 5:
		{
			cout << "\t\t\tXOA NHAN VIEN DAU DANH SACH\n";

			NhanVien T;

			this->DeleteHead(T);
			cout << " Xoa Thanh Cong\n";
			system("pause");
			break;
		}
		case 6:
		{
			cout << "Nhap Ma Nhan vien muon xoa \n";
            cin >> id;
            if (this->DeleteByID(id))
                cout << "xoa thanh cong\n";
            else
                cout << "Xoa khong thanh cong\n";
            system("pause");
            break;

		}
		case 7:
		{
			cout << "\t\t\tXOA NHAN VIEN CUOI DANH SACH\n";

			NhanVien T;

			this->DeleteTail(T);
			cout << " Xoa Thanh Cong\n";
			system("pause");
			break;
		}
		case 8:
		{
			cout << "Nhap Ma Nhan vien muon tim kiem : ";
			cin >> id;
			NhanVien T;
			T = this->SearchID(id);
			if (T.getId() != "")
			{
				Node<NhanVien> *ptr = this->list.getHead();
				cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
				cout << "|" << setw(10) << "Ma NV";
				cout << "|" << setw(20) << "Ten NV";
				cout << "|" << setw(20) << "Gioi tinh";
				cout << "|" << setw(27) << "Ngay Sinh";
				cout << "|" << setw(20) << "Dia chi";
				cout << "|" << setw(15) << "So DT";
				cout << "|" << setw(17) << "CCCD|\n";
				cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
				T.Output();
				cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
			}
			else
			{
				cout << "KHong co thong tin ma nhan vien vua nhap\n";
			}
			system("pause");
			break;
		}
		case 9:
		{
			this->Show();
			system("pause");
			break;
		}
		case 0:
		{
			this->save();
			return;
		}
		}
	}
}
void QuanLy_NhanVien::save()
{
	// Ghi ra file
	Node<NhanVien> *ptr = this->list.getHead();
	ofstream out;
	out.open("KhachHang.txt");
	out << this->list.getcount() << endl;
	while (ptr != NULL)
	{
		ptr->getData().GhiFile(out);
		ptr = ptr->getNext();
	}
	out.close();
}
QuanLy_NhanVien::~QuanLy_NhanVien()
{
}
void QuanLy_NhanVien::Show()
{
	Node<NhanVien> *ptr = this->list.getHead();
	cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "|" << setw(10) << "Ma NV";
	cout << "|" << setw(20) << "Ten NV";
	cout << "|" << setw(20) << "Gioi tinh";
	cout << "|" << setw(27) << "Ngay Sinh";
	cout << "|" << setw(20) << "Dia chi";
	cout << "|" << setw(15) << "So DT";
	cout << "|" << setw(17) << "CCCD|\n";
	cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
	while (ptr != NULL)
	{
		ptr->getData().Output();
		ptr = ptr->getNext();
		cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
	}
}
void QuanLy_NhanVien::add(NhanVien R)
{
	if (this->indexOf(R) != -1)
		cout << "ID da ton tai" << endl;
	else
		this->list.AddTail(R);
	cout << "Them Thanh Cong !! " << endl;
}
void QuanLy_NhanVien::addhead(NhanVien R)
{
	if (this->indexOf(R) != -1)
		cout << "ID da ton tai" << endl;
	else
		this->list.AddHead(R);
	cout << "Them Thanh Cong !! " << endl;
}
void QuanLy_NhanVien::addAt(NhanVien R, int vt)
{
	if (this->indexOf(R) != -1)
		cout << "ID da ton tai" << endl;
	else
		this->list.AddAt(R, vt);
	cout << "Them Thanh Cong !! " << endl;
}
bool QuanLy_NhanVien::Delete(const NhanVien R)
{
	int index = this->list.indexOf(R);
	if (index == -1)
		return false;
	return this->list.DeleteAt(index);
}
void QuanLy_NhanVien::DeleteHead(const NhanVien R)
{
	this->list.DeleteHead(R);
}
void QuanLy_NhanVien::DeleteTail(const NhanVien R)
{
	this->list.DeleteTail(R);
}
int QuanLy_NhanVien::indexOf(const NhanVien R)
{
	return this->list.indexOf(R);
}
void QuanLy_NhanVien::ShowByID(const string &ID)
{
	NhanVien temp = this->list.SearchID(ID);
	temp.Output();
}
NhanVien QuanLy_NhanVien::SearchID(const string &ID)
{
	// return this->list.SearchID(ID);
	Node<NhanVien> *ptr = this->list.getHead();
	while (ptr)
	{
		if (ptr->getData().getId() == ID)
		{
			return ptr->getData();
		}
		ptr = ptr->getNext();
	}
	return NhanVien();
}
bool QuanLy_NhanVien::DeleteByID(const string &ID)
{
	NhanVien temp = this->list.SearchID(ID);
	return this->Delete(temp);
}
bool QuanLy_NhanVien::updateByID(const NhanVien R, const string &ID)
{
	Node<NhanVien> *ptr = this->list.getHead();
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
