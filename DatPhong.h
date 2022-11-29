#pragma once
#include <string>
#include "Phong.h"
#include "KhachHang.h"
#include "Date.h"

#include "QuanLy_KhachHang.h"
#include "QuanLy_NhanVien.h"
#include "QuanLy_Phong.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class DatPhong
{
private:
   string Id; // id phong
   Date ngaythue;
   Date ngaytra;
   string MaNV;
   string MaKH;
   int tongtien;

public:
   DatPhong();
   ~DatPhong();

   void setMaNV(string ma);
   string getMaNV();
   void setMaKH(string ma);
   string getMaKH();
   void setId(string id);

   void setngaythue(Date ngay);
   void setngaytra(Date ngay);
   void DocFile(ifstream &in);
   void GhiFile(ostream &);
   string getId();
   void out(ostream &os);
   void Show();

   void DeleteAt(int vt);
};

