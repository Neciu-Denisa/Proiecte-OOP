#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

class rat
{
    int numitor,numarator;
    void simplificare();  //simplificarerea
public:
    void set(int x, int y);
    int getnumarator();
     int getnumitor();
    rat(int, int);  //constructor de initializare
    rat(); //constructor fara parametrii
    rat (const rat&);
    rat operator+(rat);//ambele rationale
    rat operator+(int);//primul rat al doilea int
    rat operator+();
    rat operator-();
    rat operator-(rat);//ambele rationale
    rat operator-(int);//primul rat si al doilea int
    rat operator*(rat);
    rat operator*(int);
    rat operator/(rat);
    rat operator/(int);
    rat operator^(int);//ridicare la o putere naturala
    rat& operator =(const rat&);//supraincarcarea operatorului de atribuire
    rat& operator =(int);
    rat& operator +=(const rat&);//a+=b -> a=a+b se modifica asadar valoarea returnata
    rat& operator -=(const rat&);
    rat& operator *=(const rat&);
    rat& operator /=(const rat&);
    bool operator==(rat);//test intre 2 rat
    bool operator==(int);//test intre un rat si un intreg
    bool operator!=(rat);
    bool operator!=(int);
    bool operator<(rat);
    bool operator<(int);
    bool operator>(rat);
    bool operator>(int);
    bool operator<=(int);
    bool operator<=(rat);
    bool operator>=(int);
    bool operator>=(rat);
    friend rat operator+(int,rat);//adunarea unui intreg cu un rational
    friend rat operator-(int,rat);//idem
    friend rat operator*(int,rat);
    friend rat operator/(int,rat);
    friend bool operator==(int,rat);
    friend bool operator!=(int,rat);
    friend bool operator>(int,rat);
    friend bool operator<(int,rat);
    friend bool operator<=(int,rat);
    friend bool operator>=(int,rat);
    friend rat abs(rat);//modulul
    operator double();//conversie
    friend std::istream& operator>>(std::istream&,rat&);//citire
    friend std::ostream& operator<<(std::ostream&,rat);//scriere
};


#endif // RATIONAL_H_INCLUDED
