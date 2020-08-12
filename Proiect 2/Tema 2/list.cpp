#include <iostream>
#include "list.h"
using namespace std;
///Vidarea listei
void list::operator-()
{
    reset();
    while(!end())
        del_next();
}
///Verificare daca doua liste sunt egale
bool list::operator==(list& l)
{
    // CURSOR this
    int poz1,dim_poz_crt1=0,dim_total1=0;
    while(!this->end())
    {
        this->next();
        dim_poz_crt1++;
    }
    this->reset();
    while(!this->end())
    {
        this->next();
        dim_total1++;
    }
    poz1=dim_total1-dim_poz_crt1;
    // CURSOR l
    int poz2,dim_poz_crt2=0,dim_total2=0;
    while(!l.end())
    {
        l.next();
        dim_poz_crt2++;
    }
    l.reset();
    while(!l.end())
    {
        l.next();
        dim_total2++;
    }
    poz2=dim_total2-dim_poz_crt2;
    // ==
    this->reset();
    l.reset();
    while(!this->end())
    {
        if(l.end())
        {
            this->reset();
            for(int k=0; k<poz1; k++)
                this->next();
            l.reset();
            for(int k=0; k<poz2; k++)
                l.next();
            return false;
        }
        int i,j;
        this->get_next(i);
        l.get_next(j);
        if(i!=j)
        {
            this->reset();
            for(int k=0; k<poz1; k++)
                this->next();
            l.reset();
            for(int k=0; k<poz2; k++)
                l.next();
            return false;
        }
        this->next();
        l.next();
    }
    if(this->end() && !l.end())
    {
        this->reset();
        for(int k=0; k<poz1; k++)
            this->next();
        l.reset();
        for(int k=0; k<poz2; k++)
            l.next();
        return false;
    }
    this->reset();
    for(int k=0; k<poz1; k++)
        this->next();
    l.reset();
    for(int k=0; k<poz2; k++)
        l.next();
    return true;
}
///Verificare daca doua liste sunt diferite
bool list::operator!=(list& l)
{
    return !(*this==l);
}
///Operatorul de atribuire
list& list::operator=(list& l)
{
    -(*this);
    // CURSOR l
    int poz2,dim_poz_crt2=0,dim_total2=0;
    while(!l.end())
    {
        l.next();
        dim_poz_crt2++;
    }
    l.reset();
    while(!l.end())
    {
        l.next();
        dim_total2++;
    }
    poz2=dim_total2-dim_poz_crt2;
    // =
    l.reset();
    while(!l.end())
    {
        int i;
        l.get_next(i);
        this->ins_next(i);
        l.next();
        this->next();
    }
    l.reset();
    (*this).reset();
    for(int k=0; k<poz2; k++)
    {
        l.next();
        (*this).next();
    }
    return *this;
}
list::~list(){}
