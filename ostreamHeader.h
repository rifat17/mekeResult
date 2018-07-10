#ifndef OSTREAMHEADER_H_INCLUDED
#define OSTREAMHEADER_H_INCLUDED
//#include "ALLHeaders.h"

#include <iostream>
using namespace std;
ostream &welcome(ostream &Out);
ostream &line(ostream &Out);
ostream &EndMain(ostream &Out);
ostream &Dotted(ostream &Out);
ostream &EnterChoice(ostream &Out);


ostream &welcome(ostream &Out)
{
    Out << "\n ========= Welcome to Main Page =========\n";
    return Out;
}
ostream &line(ostream &Out)
{
    Out << "\n == == == == == == = == == == == == == ==\n";
    return Out;
}
ostream &EndMain(ostream &Out)
{
    Out << "\n =========== End of Main Page ===========\n";
    return Out;
}
ostream &Dotted(ostream &Out)
{
    Out << "\n ........................................\n";
    return Out;
}
ostream &EnterChoice(ostream &Out)
{
    Out << "\n Enter your choice\n";
    return Out;
}


#endif // OSTREAMHEADER_H_INCLUDED
