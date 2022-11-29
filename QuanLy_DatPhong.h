#ifndef QUANLYDATPHONG_H
#define QUANLYDATPHONG_H
#include <string>
#include <iostream>
#include "DatPhong.h"
#include "List.h"
#include "QuanLy_KhachHang.h"
#include "QuanLy_NhanVien.h"
#include "QuanLY_Phong.h"

using namespace std;

class QuanLy_DatPhong: public  QuanLy<DatPhong>
{
    private:
    	List<DatPhong> list;
    public:
    	QuanLy_DatPhong();
        void Show();
        void ShowByID(const string&) ; // Hiển thị bằng ID
        DatPhong SearchID(const string&) ; // Tìm bằng ID
        bool DeleteByID(const string&) ;
        void add(DatPhong); // Thêm vào danh sách
        bool Delete(const DatPhong) ; // Xóa
        bool updateByID(const DatPhong, const string&) ;
        
        
        bool datphong();
    	bool TraPhong();
    	int getVT(string id);
    	int getvtidPhong(string id, string ds[], int n);
    	void run();
    	void Menu();
    	void save();
    	bool update();
};

#endif
