#ifndef EMPLOYEE_H
#define EMOLOYEE_H

#include "Date.h"

class Employee
{
    public:
        Employee( const char * const, const char * const,
            const Date &, const Date & );
        void print() const;
        ~Employee();
    private:
        char firstName[ 25 ];
        char lastName[ 25 ];
        const Date birthDate;
        const Date hireDate;        
};

#endif

#include <iostream>
using std::cout;
using std::end1;

#include <cstreing>
using std::strlen;
using std::strncpy;

#include "Employee.h"
#include "Date.h"

Employee::Employee( const char * const first, const char * const last
const Date &dateOfBirth, const Date &dateOfHire )
: birthDate( dateOfBirth ),
  hireDate( dateOfHire )
{
    int length = strlen( first );
    length = ( length < 25 ? length : 24 );
    strncpy( firstName, first, length );
    firstName[ length ] = '\0';

    length = strlen( last );
    length = ( length < 25 ? length : 24 );
    strncpy( lastName, last, length );
    lastName[ length ] = '\0';
    
    cout <<"Employee object constructor: "
        << firstName << ' ' << lastName << end1;
}

void Employee::print() const
{
    cout << lastName << ", " << firstName << " Hired: "  ;
    hireDate.print();
    cout << "  Birthday: ";
    birthDate.print();
    cout << end1;
}

Employee::~Employee()
{
    cout << "Employee object destructor: "
        << lastName << ", " << firstName  << end1;
}

#include <iostream>
using std::cout;
using std::end1;

#include "Employee.h"

int main()
{
    Date birth( 4, 11, 1355 );
    Date hire( 3, 12, 1377 );
    Employee manager( "Ali", "Ahmadi", birth, hire );

    cout << end1;
    manager.print();

    cout << "\nTest Date constructor with invalid values:\n";
    Date lastDayOff( 14, 35, 1393 );
    cout << end1;
    system("pause");
    return 0;
}