#ifndef STUDENTIDPLUSMARK_H
#define STUDENTIDPLUSMARK_H
#include "ALLHeaders.h"


class StudentIDplusMark
{
    public:
        StudentIDplusMark( int = 1105081,int = 20 );
        void setStudentID( int );
        int getStudentID() const;
        void setStudentMark( int );
        int getStudentMark() const;
        void setStudentIDplusMark();
        void displayStudentIDplusMark();
        virtual ~StudentIDplusMark();
        StudentIDplusMark(const StudentIDplusMark& other);
        StudentIDplusMark& operator=(const StudentIDplusMark& other);
    protected:
    private:
        int ID;
        int Mark;
};

#endif // STUDENTIDPLUSMARK_H
