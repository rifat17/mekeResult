#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstring>
#include <string>
#include "ostreamHeader.h"

#include "ALLHeaders.h"

void OutputLine( ostream&, const StudentIDplusMark & ); //Prototype
void InitialFileFolderCreator();
bool DeptYearFolderCreator(const char* dirDeptYear );
//void DeptYearFolderCreator( string &dirDeptYear );
bool CourseCodeFolderCreator(const char* dirCourseFolder );

void storeAllCourseInfo( CourseCodePlusTitle& );
void displayAllCourseInfo();

void storeAllDeptInfo ( DeptPlusYear& );
void displayAllDeptInfo ();

void storeDeptCourseInfo( CourseCodePlusTitle &, string );
void displayDeptCourseInfo ( DeptPlusYear& );


void DisplayAllFromAfile( const char* aPath , string DeptPlusCourseInfo );

void WriteAfileToPath( const char* aPath ); ///Mark adding into CT.bin file

void IntroMain();
void AddCTNew();

bool searchDept( DeptPlusYear& );
bool searchCourse( CourseCodePlusTitle& );


void OutputLine( std::ostream& output, const StudentIDplusMark& record )
{
    cout << "\t" << left << setw(7) << record.getStudentID() << right << setw(6) << record.getStudentMark() << "\n";
}

void InitialFileFolderCreator()
{
        CreateDirectoryA("F",NULL); ///Idea Drop,No Need Anymore
}

bool DeptYearFolderCreator(const char* dirDeptYear )
{
    bool is_created = false;
    if( CreateDirectory( dirDeptYear,NULL ) ){
        cerr << "\n\tCreating Dir " << dirDeptYear << "\n";
        is_created = true;
        return is_created;
    }
    return is_created;

}

bool CourseCodeFolderCreator(const char* dirCourseFolder )
{
    bool is_created = false;
    if( CreateDirectoryA( dirCourseFolder,NULL ) ){
        cerr << "\n\tCreating Dir " << dirCourseFolder << "\n";
        bool is_created = true;
        return is_created;
    }
    return is_created;
}

void DisplayAllFromAfile( const char* aPath , string DeptPlusCourseInfo )
{
    ifstream In(aPath,ios::binary);
    StudentIDplusMark S;

    cout << line << " Result of " << DeptPlusCourseInfo << line;
    cout << "\t" << left << setw(7) << "ID" << right << setw(6) << "Mark" << "\n";

    In.read( reinterpret_cast< char * >( &S ), sizeof( StudentIDplusMark ) );

    while( In && !In.eof() ){
        if(S.getStudentID() != 0 )
            OutputLine( cout, S );
        In.read( reinterpret_cast< char * >( &S ), sizeof( StudentIDplusMark ) );
    }
    cout << Dotted;
}


void WriteAfileToPath( const char* aPath ) ///Mark adding into CT.bin file
{
    int id,mark;

    ofstream inOut;
    //cout << aPath << "\n";
    inOut.open( aPath,ios::binary ); // | ios::app Problem : Data does not store in sorted manner grrrrrrrrr
    StudentIDplusMark S;

    if(!inOut){
        cerr << "Error to Write! at " << aPath << "\n";
        exit( 1 );
    }

    cout << "\nID : (1 - 100) [ Enter ID 0 to stop ] : ";
    scanf("%d",&id);

    while( id > 0 && id <= 100 ){
        cout << "\nMark : ";
        scanf("%d",&mark);

        S.setStudentID( id );
        S.setStudentMark( mark );

        inOut.seekp( ( S.getStudentID() - 1 ) * sizeof( StudentIDplusMark ) );
        inOut.write( reinterpret_cast< char * >( &S ), sizeof( StudentIDplusMark ) );
        //inOut.flush();

        cout << "\nID : ";
        scanf("%d",&id);
    }
    inOut.close();

}

void IntroMain()
{
    cout << welcome;
    int ch;
    DeptPlusYear inputObj;
    CourseCodePlusTitle inputObjCourse;
    string temp;
    string PATH;
    string DeptPlusCourseInfoValue;


    do{
        cout << EnterChoice << " 1 - Add Marks\n 2 - Update Marks\n 3 - View Marks\n 4 - End Program\n";
        scanf("%d",&ch);
    }while( ( ch < 1 || ch > 4 ) && ( (isalpha(ch) > 0 ? 1 : 0) ));
    switch( ch )
    {
    case 1 :
        cout << line << fixed << "\t -Main -> Add Marks" << line ;
        AddCTNew();
        break;
    case 2:
        cout << "\nSorry Update Not available right now,working on it.Thanks\n";
        break;
    case 3:
        //cout << "\nView\n";
        displayAllDeptInfo();
        cout << "View Result Of ";

            inputObj.setDeptPlusYear( );
            if( searchDept( inputObj ) ){

               displayDeptCourseInfo( inputObj ); ///Available Results Batch and Course Code

                cout << "Enter Course Code ( i.e CSE101 ) to View Results: ";
                cin >> temp;
                inputObjCourse.setCourseCode( temp );


                if(searchCourse ( inputObjCourse ) ){

                    PATH = "bin\\" + inputObj.getDeptName() + '_' + inputObj.getSessionSHORT() + inputObj.getYear() +  "\\" + inputObjCourse.getCourseCode() + "\\" + "CT.bin";
                    DeptPlusCourseInfoValue = inputObj.getDeptName() + " " + inputObj.getSessionFULL() + " " + inputObj.getYear() + ',' + "\n Course :" + inputObjCourse.getCourseCode(); ///promote like CSESpring2019,Course CSE101

                    DisplayAllFromAfile( PATH.c_str() , DeptPlusCourseInfoValue );
                }
            }
        break;
    case 4:
        break;
    default:
        cout << EnterChoice << " 1 - Add Marks\n 2 - Update Marks\n 3 - View Marks\n 4 - End Program\n";
        scanf("%d",&ch);
    }
    cout << EndMain;
}
void AddCTNew()
{
    DeptPlusYear dept;
    CourseCodePlusTitle course;
    StudentIDplusMark Student;

    dept.setDeptPlusYear();  ///promote for department + session + year

    string DeptYearFolderPath = "bin\\" + dept.getDeptName() + '_' + dept.getSessionSHORT() + dept.getYear();

   /// "bin\\" + dept.getDeptName() + '_' + dept.getSessionSHORT() + dept.getYear() +  "\\" + course.getCourseCode() + "\\" + "CT.bin"; path path path

    if(DeptYearFolderCreator( DeptYearFolderPath.c_str() )) ///Create Dir F\CSE_S2018
        storeAllDeptInfo( dept ); ///Storing Course Info for VIEW RESULT CSE Spring 2018 -> Course -> Show result

    course.setCourseCodePlusTitle();  ///promote for Course title+code

    string CourseCodePath = DeptYearFolderPath + "\\" + course.getCourseCode();

   string DeptPlusCourseInfoValue = dept.getDeptName() + dept.getSessionFULL() + dept.getYear() + ',' + "Course " + course.getCourseCode(); ///promote like CSESpring2019,Course CSE101

   string CTmarkFile = CourseCodePath + "\\" + "CT.bin";

    if( DeptYearFolderCreator( CourseCodePath.c_str() ) ) ///Create Dir F\CSE_S2018\CSE101    it creates CSE101
    {

        ///make a file to count CT in folder F\CSE_S2018\CSE101\CT_count.txt

        storeDeptCourseInfo( course , DeptYearFolderPath );

         storeAllCourseInfo( course );  ///Storing Course Info for VIEW RESULT of Dept -> Course

        WriteAfileToPath( CTmarkFile.c_str() ); /// Call F\CSE_S2222\CSE101\CT.txt to add marks

        DisplayAllFromAfile( CTmarkFile.c_str() , DeptPlusCourseInfoValue ); /// display Written file
    }
}


void storeAllCourseInfo( CourseCodePlusTitle &aRecordOfCourse  )
{
    ofstream Out("bin\\Courses.bin", ios::out | ios ::app | ios::binary );

    Out.write( reinterpret_cast< char * >( &aRecordOfCourse ), sizeof( CourseCodePlusTitle ) );

    Out.close();


}

void storeDeptCourseInfo( CourseCodePlusTitle &aRecordOfCourse, string DeptInfo  )
{
    string Path = DeptInfo + "\\Courses.bin"; ///C:\Users\ASUS\Documents\Project_idea_12\bin\EEE_S2999

    ofstream Out( Path.c_str(), ios::out | ios ::app | ios::binary );

    Out.write( reinterpret_cast< char * >( &aRecordOfCourse ), sizeof( CourseCodePlusTitle ) );

    Out.close();


}

void displayDeptCourseInfo( DeptPlusYear& inputObj )
{
    CourseCodePlusTitle aRecordOfCourse;

    string DeptYearFolderPath = "bin\\" + inputObj.getDeptName() + '_' + inputObj.getSessionSHORT() + inputObj.getYear();

    string Path = DeptYearFolderPath + "\\Courses.bin";

    ///cout << Path << "\n"; Checked,its Working

    cout << line << "Main -> View Result -> " << inputObj.getDeptName() << " " << inputObj.getSessionFULL() << " " << inputObj.getYear() << line;

    ifstream In( Path.c_str() , ios::in | ios::binary );

    In.read( reinterpret_cast< char * >( &aRecordOfCourse ), sizeof( CourseCodePlusTitle ) );

    while( In && !In.eof() ){

        cout << "\t" << left << setw(15) << "Course Title" << ":" << aRecordOfCourse.getCourseTitle() << "\n\t" << left << setw(15) << "Course Code"  << ":"<< aRecordOfCourse.getCourseCode() << "\n\n";
        In.read( reinterpret_cast< char * >( &aRecordOfCourse ), sizeof( CourseCodePlusTitle ) );
    }
    cout << Dotted;

    In.close();
}


void displayAllCourseInfo()
{
    CourseCodePlusTitle aRecordOfCourse;

    ifstream In("bin\\Courses.bin", ios::in | ios::binary );

    In.read( reinterpret_cast< char * >( &aRecordOfCourse ), sizeof( CourseCodePlusTitle ) );

    while( In && !In.eof() ){

            aRecordOfCourse.disPlayCourseCodePlusTitle();
        In.read( reinterpret_cast< char * >( &aRecordOfCourse ), sizeof( CourseCodePlusTitle ) );
    }
    cout << Dotted;

    In.close();
}

void storeAllDeptInfo( DeptPlusYear &aRecordOfDept )
{
    ofstream Out("bin\\Batches.bin", ios::out | ios ::app | ios::binary );

    Out.write( reinterpret_cast< char * >( &aRecordOfDept ), sizeof( DeptPlusYear ) );

    Out.close();
}

void displayAllDeptInfo ()
{

    DeptPlusYear aRecordOfDept;

    ifstream In("bin\\Batches.bin", ios::in | ios::binary );

    cout << line << "\tMain -> View Available Results " << line;
    cout << "\t" << left << setw(7) << "Dept" << right << setw(7) << "Session " << setw(7) << "Year" << "\n" << Dotted;

    In.read( reinterpret_cast< char * >( &aRecordOfDept ), sizeof( DeptPlusYear ) );

    while( In && !In.eof() ){

            cout << "\t" << left << setw(7) << aRecordOfDept.getDeptName()  << right << setw(7) << aRecordOfDept.getSessionFULL() << setw(7) << aRecordOfDept.getYear() << "\n";
        In.read( reinterpret_cast< char * >( &aRecordOfDept ), sizeof( DeptPlusYear ) );
    }
    cout << Dotted;

    In.close();

}

bool searchDept( DeptPlusYear& inputObj )
{
    DeptPlusYear searchObj;

    ifstream In("bin\\Batches.bin", ios::in | ios::binary );


    In.read( reinterpret_cast< char * >( &searchObj ), sizeof( DeptPlusYear ) );

    while( In && !In.eof() ){
        if( inputObj == searchObj )
            return true;
        In.read( reinterpret_cast< char * >( &searchObj ), sizeof( DeptPlusYear ) );
    }
    In.close();

    cout << Dotted << "\tNot Found "; inputObj.displayDeptPlusYear(); cout << Dotted;

    return false;

}
bool searchCourse( CourseCodePlusTitle& inputObj )
{
    CourseCodePlusTitle searchObj;

    ifstream In("bin\\Courses.bin", ios::in | ios::binary );


    In.read( reinterpret_cast< char * >( &searchObj ), sizeof( CourseCodePlusTitle ) );

    while( In && !In.eof() ){
        if( inputObj.getCourseCode() == searchObj.getCourseCode() )
            return true;
        In.read( reinterpret_cast< char * >( &searchObj ), sizeof( CourseCodePlusTitle ) );
    }
    In.close();

    cout << Dotted << "\tNot Found "; inputObj.getCourseCode(); cout << Dotted;

    return false;
}



#endif // FUNCTIONS_H_INCLUDED

