#ifndef PHONG_H
#define PHONG_H
#include<fstream>
#include<string>
#include<iostream>
#include <iomanip>
#include "List.h"

using namespace std;
class Phong
{
    private:
       string MaPhong;
       string LoaiPhong;
       int GiaPhong;
       bool Trangthai;
    public:
       Phong();
       Phong(string mp, string loaiphong,int Gia, bool TT);
       Phong(const Phong& S);
 
    //Getter:
       string getId();
       string getLoaiPhong();
       int getGiaPhong();   
       bool getTrangthai();
       string getStrTrangThai();
    //Setter:
       void setMaPhong(string );
       void setLoaiPhong(string name);
       void setGiaPhong(int Gia);
       void setTrangthai(bool TT);

      static bool isValidId(const string&);
      void update(const Phong&);

       void Input(string mp);
       void Update(string mp);
       void Output();
       void DocFile(ifstream&);
       void GhiFile(ostream&);
       bool operator==(const Phong&);
       const Phong& operator=(const Phong&);
       bool checkMaPhong(List<Phong> list, string maphong);
};
#endif
