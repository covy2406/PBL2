#include "QuanLy_Phong.h"
QuanLy_Phong::QuanLy_Phong()
{
    ifstream input;
    input.open("phong.txt", ios::in);
        Phong data;
        int n;
        input >> n;
        for (int i = 1; i <= n; i++)
        {
            data.DocFile(input);
            this->list.AddTail(data);
        }
        input.close();
    
}
void QuanLy_Phong::read()
{
	
	this->list.setHead(NULL);
	this->list.setTail(NULL);
	this->list.setcount(0);
	ifstream input;
    input.open("phong.txt", ios::in);
    if (input.fail())
    {
        cout << "Failed to open this file" << endl;
    }
    else
    {
        Phong data;
        int n;
        input >> n;
        for (int i = 1; i <=n; i++)
        {
            data.DocFile(input);
            
            this->list.AddTail(data);
        }
        input.close();
    }
}
void QuanLy_Phong::menu()
{
	cout << "\t\t\t------------QUAN LY PHONG KS---------------\n";
	cout << "\t\t\t| 1. Them phong moi                       |\n";
	cout << "\t\t\t| 2. Sua thong tin phong                  |\n";
	cout << "\t\t\t| 3. Xoa thong tin phong                  |\n";
	cout << "\t\t\t| 4. Tim kiem phong theo ma phong         |\n";
	cout << "\t\t\t| 5. Hien thi danh sach phong             |\n";
	cout << "\t\t\t| 0. Thoat                                |\n";
	cout << "\t\t\t------------------------------------------\n";
	cout << "\t\t\t\tLua chon = ";
}
void QuanLy_Phong::run()
{
	int luachon;
	string id;
	while(1)
	{
		system("cls");
		menu();
		cin >> luachon;
		Phong newPhong;
		
		switch(luachon)
		{
			case 1:
				{
					
					cout << "Nhap Ma phong: ";
					cin >> id; 
					Phong T = this->list.SearchID(id);
				
					
					while(T.getId()==id|| id == "")
					{
						cout << "Ma phong da ton tai vui long nhap lai\nNhap Ma phong: ";
						cin >> id; 
						 T = this->list.SearchID(id);
					}
					
					newPhong.Input(id);
					
					this->add(newPhong);
					
					
					system("pause");
					break;
				}
			case 2:
				{
					cout << "Nhap Ma phong muon cap nhat: ";
					cin >> id; 
					Phong T = this->list.SearchID(id);
				
					
					while(T.getId()!=id)
					{
						cout << "Ma phong khong co trong danh sach\nNhap Ma phong: ";
						cin >> id; 
						 T = this->list.SearchID(id);
					}
					
					newPhong.Update(id);
					
					this->updateByID(newPhong, id);
					cout << "Cap nhat thanh cong\n";
					system("pause");
					break;
				}
			case 3:
				{
					cout << "Nhap Ma phong muon xoa \n";
					cin >> id;
					if(this->DeleteByID(id)) cout << "xoa thanh cong\n";
					else cout << "Xoa khong thanh cong\n";
					system("pause");
					break;
				}
			case 4:
				{
					cout << "Nhap Ma phong muon tim kiem : ";
					cin >> id;
					Phong T;
					T= this->SearchID(id);
					if(T.getId()!="")
					{
						cout << "------------------------------------------------------------------------------------------\n";
						cout <<"|"<< setw(20) << "Ma phong";
						cout <<"|"<< setw(20) << "Loai phong";
						cout <<"|"<< setw(20) << "Gia phong";
						cout <<"|"<< setw(27) << "Trang thai|\n";
						cout << "------------------------------------------------------------------------------------------\n";
						T.Output();
						cout << "------------------------------------------------------------------------------------------\n";
					}
					else
					{
						cout << "KHong co thong tin ma phong vua nhap\n";
					}
					system("pause");
					break;
				}
			case 5:
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
void QuanLy_Phong::save()
{
	// Ghi ra file
    Node<Phong> *ptr = this->list.getHead();
    ofstream out;
    out.open("phong.txt");
    out << this->list.getcount() << endl;
    while (ptr != NULL)
    {
        ptr->getData().GhiFile(out);
        ptr = ptr->getNext();
    }
    out.close();
}
QuanLy_Phong::~QuanLy_Phong()
{
    
}
void QuanLy_Phong::Show()
{
	cout << "------------------------------------------------------------------------------------------\n";
	cout <<"|"<< setw(20) << "Ma phong";
	cout <<"|"<< setw(20) << "Loai phong";
	cout <<"|"<< setw(20) << "Gia phong";
	cout <<"|"<< setw(27) << "Trang thai|\n";
	cout << "------------------------------------------------------------------------------------------\n";
    Node<Phong> *ptr = this->list.getHead();
    while (ptr != NULL)
    {
    	
        ptr->getData().Output();
        cout << "------------------------------------------------------------------------------------------\n";
        ptr = ptr->getNext();
        //cout << "------------------------------" << endl;
    }
}
void QuanLy_Phong::add(Phong S)
{

    if (this->indexOf(S)!=-1) 
    {
    	
    	cout << "Phong da ton tai" << endl; 
	}
        
    else
    {
	
	
        this->list.AddTail(S);
        cout << "Them thanh cong\n";
    }
}

bool QuanLy_Phong::Delete(const Phong S)
{
    int index = this->list.indexOf(S);
    if (index == -1)
        return false;
    return this->list.DeleteAt(index);
}

int QuanLy_Phong::indexOf(const Phong S)
{
    return this->list.indexOf(S);
}

Phong QuanLy_Phong::SearchID(const string &ID)
{
    return this->list.SearchID(ID);
}

void QuanLy_Phong::ShowByID(const string &ID)
{
    Phong temp = this->list.SearchID(ID);
    temp.Output();
}

bool QuanLy_Phong::DeleteByID(const string &ID)
{
    Phong temp = this->list.SearchID(ID);
    return this->Delete(temp);
}

bool QuanLy_Phong::updateByID(const Phong S, const string &ID)
{
    Node<Phong> *ptr = this->list.getHead();
    while (ptr != NULL)
    {
        if (ptr->getData().getId() == ID)
        {
            
            ptr->setData(S);
            return true;
        }
        ptr = ptr->getNext();
    }
    return false;
}

