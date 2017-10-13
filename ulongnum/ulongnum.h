/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: ulongnum.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ulongnum class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef ulongnum_H
#define ulongnum_H

#include "str.h"

/*--------------------------------------------------------
class ulongnum
----------------------------------------------------------*/
class ulongnum {
public:
  //WRITE CODE HERE
    ulongnum();
    ulongnum(const int a,const bool verbose);
    ulongnum(const char* c,const bool verbose);
    ulongnum(const char c,const bool verbose);
    ulongnum(const str& s);
    ulongnum(const ulongnum& n);
    void _copy(const ulongnum& n);
    int numDigits(const int s)const;
    char* num2string(const int n)const;
    friend ostream& operator<<(ostream& o,const ulongnum& n);
    ulongnum& operator=(const ulongnum& n);
    friend ulongnum operator+(const ulongnum& n1,const ulongnum& n2);
    friend ulongnum operator+(const ulongnum& n1,const int& n2);
    friend ulongnum operator+(const int& n1,const ulongnum& n2);
    friend ulongnum operator*(const ulongnum& n1,const ulongnum& n2);
    friend bool operator==(const ulongnum& n1,const int& n2);
    friend bool operator==(const ulongnum& n1,const ulongnum& n2);
    //int len() const;
    //char gt(const int index)const;
private:
  bool _display;
  str _num;
  //Cannot use any STL object
  //must use str object

  //Can have any private functions here
};

#endif
//EOF

