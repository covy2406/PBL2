#ifndef QuanLy_NhanVien_H
#define QuanLy_NhanVien_H
#include "QuanLy.h"
#include "List.h"
#include "NhanVien.h"

class QuanLy_NhanVien : public QuanLy<NhanVien>
{
    private:
        List<NhanVien> list;
    public:
        QuanLy_NhanVien();
        ~QuanLy_NhanVien();

        void Show();
        void add(NhanVien);
        void addhead(NhanVien);
        void addAt(NhanVien, int);
        bool Delete(const NhanVien);
        int indexOf(const NhanVien);
        void ShowByID(const string&); // Hiển thị bằng ID
        NhanVien SearchID(const string&); // Tìm bằng ID
        bool DeleteByID(const string&);
        void DeleteHead(const NhanVien);
        void DeleteTail(const NhanVien);
        bool updateByID(const NhanVien, const string&);
        //void listByName(const string&);
        void save();
        
       
	    void read();
	   
	    void menu();
	    void run();
};
#endif
