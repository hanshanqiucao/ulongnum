/*----------------------------------------------------------------
Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
file: str.cpp

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "str.h"


/*----------------------------------------------------------------
 Definition of routines of str class
 
 WRITE CODE IN THIS FILE
 -----------------------------------------------------------------*/
str::str(){
    _string=darray<char> (1,false);
    _string[0]='\0';
    _length=0;
}

str::str(const char c){
    _string=darray<char> (2,false);
    _string[0]=c;
    _string[1]='\0';
    _length=1;
}



str::str(const char c,const  bool verbose){
    _string=darray<char> (2,verbose);
    _string[0]=c;
    _string[1]='\0';
    _length=1;
}

str::str(const char* j){
    for(int i=0;i<strlen(j);++i){
        _string[i] = j[i];
    }
    _length=strlen(j);
    _string[_length]='\0';
}

str::str(const char* j ,const bool verbose) {
    _string=darray<char> (verbose);
    _length = strlen(j);
    for(int i=0;i<_length;++i){
        _string[i]=j[i];
    }
    _string[_length]='\0';
}


void str::reverse(){
    char c;
    for(int i=0;i<(_length-1)/2;++i){
        c = _string[i];
        _string[i]=_string[_length-1-i];
        _string[_length-1-i]=c;
    }
}

/*----------------------------------------------------------------
 Helper: copy function
 -----------------------------------------------------------------*/
void str::_copy(const str & from){
    //cout<<"In str copy constructor"<<endl;
    _string = from._string;
    _length = from._length;
    _display= from._display;
    _string[_length]='\0';
}

/*----------------------------------------------------------------
 Copy constructor
 -----------------------------------------------------------------*/
str::str(const str & s){
    _copy(s);
}


/*----------------------------------------------------------------
 equal operator
 -----------------------------------------------------------------*/
str& str::operator=(const str& rhs){
    if(this!=&rhs){
        _copy(rhs);
    }
    return *this;
}

str& str::operator=(const char* c){
    for(int i=0;i<strlen(c);++i){
        this->_string[i]=c[i];
    }
    this->_length=strlen(c);
    this->_string[_length] = '\0';
    //cout<<"_length="<<this->_length<<endl;
    return *this;
}

/*----------------------------------------------------------------
 Equal Equal operator
 -----------------------------------------------------------------*/

bool operator==(const str& s1, const str& s2){
    if(s1._display){
        cout << "in str == operator \n";
    }
    bool eq = true;
    if(s1._length!=s2._length) eq=false;
    else {
        bool eq=true;
        for (int i=0;i<s1._length;++i){
            if(s1._string[i]!=s2._string[i]) {eq = false;break;}
        }
    }
    return eq;
}

/*----------------------------------------------------------------
 NOT Equal operator
 -----------------------------------------------------------------*/

bool operator!=(const str& s1, const str& s2){
    if (s1._display) {
        cout << "in complex != operator \n";
    }
    return (!(s1==s2));
}


/*----------------------------------------------------------------
 Cout Print Overload
 -----------------------------------------------------------------*/

ostream& operator <<(ostream& o,const str & s){
    int i =0;
    while(s._string[i]!='\0'){
        o<<s._string[i];
        i++;
    }
    return o;
}
/*----------------------------------------------------------------
 + Overload
 -----------------------------------------------------------------*/
str operator+(const char &c, const str & s){
    str s1(c,false);
    int i=0;
    while(s._string[i]!='\0'){
        s1._string[i+1] = s._string[i];
        i++;
    }
    s1._string[i+1] = '\0';
    s1._length = i+1;
    return s1;
}


str operator+(const str & s,const char c){
    str s1(c,false);
    for (int i=0;i<s._length;++i){
        s1._string[i] = s._string[i];
    }
    s1._length=s._length;
    s1._string[s._length] = c;
    s1._string[s._length+1] = '\0';
    s1._length=s._length+1;
    return s1;
    
}

str operator+(const str & s,const char* c){
    str s1('\0',false);
    for (int i=0;i<s._length;++i){
        s1._string[i] = s._string[i];
    }
    for (int j=0;j<strlen(c);++j){
        s1._string[s._length+j] = c[j];
    }
    s1._length = s._length + strlen(c);
    s1._string[s1._length] = '\0';
    return s1;
}

str operator+(const str & s1,const str & s2){
    str s3('\0',false);
    for (int i=0;i<s1._length;++i){
        s3._string[i] = s1._string[i];
    }
    for (int j=0;j<s2._length;++j){
        s3._string[s1._length+j] = s2._string[j];
    }
    s3._length = s1._length + s2._length;
    s3._string[s3._length] = '\0';
    return s3;
}

int string_compare(const str& s1,const  str& s2){
    if(s1._length>s2._length) return (s1._length-s2._length);
    else return (s2._length-s1._length);
}

char str::gt(const int index)const{
    return _string[index];
}

int str::len()const{
    return _length;
}

//EOF



