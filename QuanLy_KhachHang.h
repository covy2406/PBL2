#ifndef QuanLy_KhachHang_H
#define QuanLy_KhachHang_H
#include"QuanLy.h"
#include"List.h"
#include"KhachHang.h"

class QuanLy_KhachHang : public QuanLy<KhachHang>
{
    private:
        List<KhachHang> list;
    public:
        QuanLy_KhachHang();
        ~QuanLy_KhachHang();

        void Show();
        void add(KhachHang);
        void addhead(KhachHang);
        void addAt(KhachHang, int);
        bool Delete(const KhachHang);
        void DeleteHead(const KhachHang);
        void DeleteTail(const KhachHang);
        int indexOf(const KhachHang);
        void ShowByID(const string&); 
        KhachHang SearchID(const string&);
        bool DeleteByID(const string&);
        bool updateByID(const KhachHang, const string&);
        
        void save();
        
       
	    void read();
	    void menu();
	    void run();
};
#endif
