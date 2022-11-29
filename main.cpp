#include <iostream>
#include "Phong.h"
#include "QuanLy_Phong.h"
#include "QuanLy_KhachHang.h"
#include "QuanLy_NhanVien.h"
#include "QuanLy_DatPhong.h"
//#include <ctime>
#include <stdlib.h>
using namespace std;

QuanLy_Phong PH;
QuanLy_KhachHang KH;
QuanLy_NhanVien NV;
QuanLy_DatPhong DP;
void Menu()
{
	cout << "\t\t\t===============QUAN LY KHACH SAN===============\n";
	cout << "\t\t\t|1. QUAN LY PHONG KHACH SAN                   |\n";
	cout << "\t\t\t|2. QUAN LY THONG TIN NHAN VIEN               |\n";
	cout << "\t\t\t|3. QUAN LY THONG TIN KHACH HANG              |\n";
	cout << "\t\t\t|4. QUAN LY DAT TRA PHONG KHACH SAN           |\n";
	cout << "\t\t\t|0. Thoat!!!                                  |\n";
	cout << "\t\t\t===============================================\n";

}
int main()
{
	int luachon;
	
	while(1)
	{
		system("cls");
		Menu();
		cout << "lua chon = ";
		cin >> luachon;
		cin.ignore();
		
		switch(luachon)
		{
			case 1:
				{
					PH.read();
					PH.run();
					break;
				}
			case 2:
				{
					NV.run();
					break;
				}
			case 3:
				{
					KH.run();
					break;
				}
			case 4:
				{
					DP.run();
				
					break;
				}
			case 0:
				{
					
				  	return 0;
				}
			
		}
	}

    return 0;
}
