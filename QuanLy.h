#ifndef QUANLY_H
#define QUANLY_H
#include <string>
using namespace std;
template<class T>
class QuanLy
{
    private:
    public:
        virtual void Show() = 0;
        virtual bool updateByID(const T, const string&) = 0;

        virtual void ShowByID(const string&) = 0; 
        virtual T SearchID(const string&) = 0; 
        virtual bool DeleteByID(const string&) = 0;
        virtual void add(T) = 0; 
        virtual bool Delete(const T) = 0;
        
};
#endif