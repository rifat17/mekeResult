#ifndef COURSECODEPLUSTITLE_H
#define COURSECODEPLUSTITLE_H
#include "ALLHeaders.h"
#include <string>
using namespace std;

class CourseCodePlusTitle
{
    public:
        CourseCodePlusTitle(string = "CSE101",string = "Fundamental" );
        void setCourseCode(string);
        string getCourseCode() const;
        void setCourseTitle(string);
        string getCourseTitle() const;

        void setCourseCodePlusTitle();
        void disPlayCourseCodePlusTitle() const;

        bool operator==(const CourseCodePlusTitle& other);

        virtual ~CourseCodePlusTitle();
        CourseCodePlusTitle(const CourseCodePlusTitle& other);
        CourseCodePlusTitle& operator=(const CourseCodePlusTitle& other);
    protected:
    private:
        char courseCode [ 10 ];
        char courseTitle [ 30 ];
};

#endif // COURSECODEPLUSTITLE_H
