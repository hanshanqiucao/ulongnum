/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: str.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has str class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef str_H
#define str_H

#include "darray.h"

/*----------------------------------------------------------------
Declaration of str class
-----------------------------------------------------------------*/
class str {
public:
    //WRITE CODE HERE
    str();
    str(const char c);
    str(const char c, const bool verbose);   //for char
    str(const char* j);
    str(const char* j , const bool verbose); //for string
    void _copy(const str & from);
    str(const str & s);
    str& operator=(const str& rhs);
    str& operator=(const char* c);
    friend ostream& operator <<(ostream& o, const str & a);
    friend bool operator ==(const str& s1, const str & s2);
    friend bool operator !=(const str& s1, const str & s2);
    friend str operator+(const char & c, const str & s);
    friend str operator+(const str & s,const char c);
    friend str operator+(const str & s,const char* c);
    friend str operator+(const str & s1,const str & s2);
    friend int string_compare(const str& s1,const str & s2);
    char gt(const int index)const;
    int len()const;
    void reverse();
private:
    bool _display;
    //Cannot use any STL OBJECT
    //MUST USE darray
    //Can have any number of private functions
    darray<char> _string;
    int _length; //how many characters
};
#endif
//EOF



/*
darray<int> a(3,verbose);
for (int i = 0; i < N; i++) {
    a[i] = i * 10;
}
darray<int>b(a);
for (int i = 0; i < N; i++) {
    cout << " b[" << i << "]=" << b[i];
    }
*/
