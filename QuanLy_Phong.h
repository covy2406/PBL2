#ifndef QuanLy_Phong_H
#define QuanLy_Phong_H
#include "QuanLy.h"
#include "List.h"
#include "Phong.h"

class QuanLy_Phong : public QuanLy<Phong>
{
private:
    List<Phong> list;

public:
    QuanLy_Phong();
    
    ~QuanLy_Phong();
    void Show();
    void add(Phong);
    bool Delete(const Phong);
    int indexOf(const Phong);
    void ShowByID(const string&);   
    Phong SearchID(const string &); 
    bool DeleteByID(const string &);
    bool updateByID(const Phong, const string &);
    
    void save();
    void read();
    void menu();
    void run();
};
#endif
