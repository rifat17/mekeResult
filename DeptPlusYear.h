#ifndef DEPTPLUSYEAR_H
#define DEPTPLUSYEAR_H
#include "ALLHeaders.h"

#include <string>
using namespace std;

class DeptPlusYear
{
    public:
        //DeptPlusYear(string = "CSE",int = 2018 , char = 'S' );
        DeptPlusYear(string = "CSE",string = "2018" , char = 'S' );
        void setDeptName( string );
        string getDeptName() const;

        //void setYear( int );
        //int getYear() const;
        void setYear( string );
        string getYear() const;

        void setDeptPlusYear();
        void displayDeptPlusYear();

        void setSession( char );
        char getSessionSHORT() const;
        string getSessionFULL() const;

        bool operator==(const DeptPlusYear& other);

        virtual ~DeptPlusYear();
        DeptPlusYear(const DeptPlusYear& other);
        DeptPlusYear& operator=(const DeptPlusYear& other);
    protected:
    private:
        char dept[ 4 ];
        char Session;
        //int year;
        char year[ 6 ];
};

#endif // DEPTPLUSYEAR_H
