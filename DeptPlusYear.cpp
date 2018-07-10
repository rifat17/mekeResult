//#include "DeptPlusYear.h"
//#include <string>
//#include <cstring>
//#include <cstdio>
//#include <iostream>
//
//using namespace std;
#include "ALLHeaders.h"

DeptPlusYear::DeptPlusYear( string DeptNameValue,string YearValue , char SessionValue )
{
    //ctor
    setDeptName( DeptNameValue );
    setYear( YearValue );
    setSession( SessionValue );

}

void DeptPlusYear::setDeptName( string DeptNameValue )
{
    int length = DeptNameValue.length();
    length = ( length < 4 ? length : 3 );
    DeptNameValue.copy(dept,length );
    dept[ length ] = '\0';
}
string DeptPlusYear::getDeptName() const
{
    return dept;
}


void DeptPlusYear::setSession( char SessionValue )
{
    if(SessionValue == 'f' || SessionValue == 'F'){
        Session = 'F';
    }
    else if(SessionValue == 's' || SessionValue == 'S'){
        Session = 'S';
    }
    else Session = 'S';
}

char DeptPlusYear::getSessionSHORT() const
{
    return Session;
}

string DeptPlusYear::getSessionFULL() const
{
    if('S' == getSessionSHORT() ){
        return "Spring";
    }
    else return "Fall";
}


void DeptPlusYear::setYear( string YearValue )
{
    int length = YearValue.length();
    length = ( length < 6 ? length : 5 );
    YearValue.copy(year,length );
    year[ length ] = '\0';
}
string DeptPlusYear::getYear() const
{
    return year;
}


void DeptPlusYear::setDeptPlusYear()
{
    string aDeptNameValue;
    string aYearValue;
    int ch;

    cout << "\n Dept ( i.e CSE ) : ";
    cin >> aDeptNameValue;
    setDeptName( aDeptNameValue );

    do{
        cout << "\n Choose Session : ";
        cout << "\n\t 1. Spring\n\t 2. Fall\n";
        scanf("%d",&ch);
    }while (ch < 1 || ch > 2);
    switch(ch)
    {
    case 1:
        Session = 'S';
        break;
    case 2:
        Session = 'F';
        break;
    default:
        scanf("%d",&ch);
    }

    cout << "\n Session Year ( i.e 2018 ) : ";
    cin >> aYearValue;
    setYear( aYearValue );

}

void DeptPlusYear::displayDeptPlusYear()
{
    cout << getDeptName() << " " << getSessionFULL() << " " << getYear() << "\n";
}

DeptPlusYear::~DeptPlusYear()
{
    //dtor
}

DeptPlusYear::DeptPlusYear(const DeptPlusYear& other)
{
    //copy ctor
    this->setDeptName( other.getDeptName() );
    this->setSession( other.getSessionSHORT() );
    this->setYear( other.getYear() );
}

DeptPlusYear& DeptPlusYear::operator=(const DeptPlusYear& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->setDeptName( rhs.getDeptName() );
    this->setSession( rhs.getSessionSHORT() );
    this->setYear( rhs.getYear() );
    return *this;
}
bool DeptPlusYear::operator==(const DeptPlusYear& other)
{
    bool result = false;

    if( this->getDeptName() == other.getDeptName() ){
        if( this->getSessionSHORT() == other.getSessionSHORT() ){
            if( this->getYear() == other.getYear() ){
                result = true;
                return result;
            }
        }
    }
    return result;
}
