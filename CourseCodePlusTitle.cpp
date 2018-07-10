//#include "CourseCodePlusTitle.h"
//#include <string>
//#include <iostream>
//using namespace std;
#include "ALLHeaders.h"

CourseCodePlusTitle::CourseCodePlusTitle( string CourseCode ,string CourseTitle )
{
    //ctor
    setCourseCode( CourseCode );
    setCourseTitle( CourseTitle );
}


void CourseCodePlusTitle::setCourseCode(string CourseCodeValue)
{
    int length = CourseCodeValue.length();
    length = ( length < 10 ? length : 9 );
    CourseCodeValue.copy(courseCode,length );
    courseCode[ length ] = '\0';
}
string CourseCodePlusTitle::getCourseCode() const
{
    return courseCode;
}
void CourseCodePlusTitle::setCourseTitle(string CourseTitleValue )
{
    int length = CourseTitleValue.length();
    length = ( length < 30 ? length : 29 );
    CourseTitleValue.copy(courseTitle,length );
    courseTitle[ length ] = '\0';
}
string CourseCodePlusTitle::getCourseTitle() const
{
    return courseTitle;
}



void CourseCodePlusTitle::setCourseCodePlusTitle()
{
    string acourseTitle,acourseCode;
    cin.ignore();

    cout << "\n Course Title : ";
    getline(cin,acourseTitle);
    setCourseTitle( acourseTitle );

    cout << "\n Course Code ( i.e CSE101 ) : ";
    cin >> acourseCode;
    setCourseCode( acourseCode );

}


void CourseCodePlusTitle::disPlayCourseCodePlusTitle() const
{
    cout << "\n" << getCourseTitle() << " " << getCourseCode() << "\n";

}


CourseCodePlusTitle::~CourseCodePlusTitle()
{
    //dtor
}

CourseCodePlusTitle::CourseCodePlusTitle(const CourseCodePlusTitle& other)
{
    //copy ctor
    this->setCourseCode( other.getCourseCode() );
    this->setCourseTitle( other.getCourseTitle() );
}

CourseCodePlusTitle& CourseCodePlusTitle::operator=(const CourseCodePlusTitle& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator

    this->setCourseCode(rhs.getCourseCode());
    this->setCourseTitle(rhs.getCourseTitle());

    return *this;
}

bool CourseCodePlusTitle::operator==(const CourseCodePlusTitle& other)
{
    bool result = false;

    if( this->getCourseCode() == other.getCourseCode() ){
        //if( this->getCourseTitle() == other.getCourseTitle() ){
                result = true;
                return result;
        //}
    }
    return result;
}

