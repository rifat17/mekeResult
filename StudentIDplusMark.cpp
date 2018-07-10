//#include "StudentIDplusMark.h"
//#include <string>
//#include <iostream>
//
//using namespace std;
#include "ALLHeaders.h"

StudentIDplusMark::StudentIDplusMark(int id,int mark)
{
    //ctor
    setStudentID( id );
    setStudentMark( mark );
}

void StudentIDplusMark::setStudentID( int id )
{
    ID = id;
}
int StudentIDplusMark::getStudentID() const
{
    return ID;
}
void StudentIDplusMark::setStudentMark( int mark )
{
    Mark = mark;
}
int StudentIDplusMark::getStudentMark() const
{
    return Mark;
}
void StudentIDplusMark::setStudentIDplusMark()
{
    int id,marks;
    cout << "\n Enter ID : ";
    cin >> id;
    setStudentID( id );
    cout << "\n Enter Mark : ";
    cin >> marks;
    setStudentMark( marks );
}
void StudentIDplusMark::displayStudentIDplusMark()
{
    cout << getStudentID() << " " << getStudentMark() << "\n";
}


StudentIDplusMark::~StudentIDplusMark()
{
    //dtor
}

StudentIDplusMark::StudentIDplusMark(const StudentIDplusMark& other)
{
    //copy ctor
    this->setStudentID( other.getStudentID() );
    this->setStudentMark( other.getStudentMark() );
}

StudentIDplusMark& StudentIDplusMark::operator=(const StudentIDplusMark& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->setStudentID( rhs.getStudentID() );
    this->setStudentMark( rhs.getStudentMark() );

    return *this;
}
