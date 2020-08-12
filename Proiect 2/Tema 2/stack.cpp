#include <iostream>
#include <cstdlib>
#include "stack.h"
using namespace std;
///Vidare stiva
void stack::operator-()
{
    while(!!*this)
    {
        int x;
        (*this)>>x;
    }
}
///Verificare daca doua stive sunt egale
bool stack::operator==(stack &s)
{
    int *copie_s,*copie_this,i=0,j=0;
    copie_s=(int*)malloc(0*sizeof(int));
    copie_this=(int*)malloc(0*sizeof(int));
    int *v1=copie_s;
    int *v2=copie_this;
    // Copiem stiva s
    while(!(!s))
    {
        copie_s=(int*)realloc(copie_s,(i+1)*sizeof(int));
        if(copie_s==NULL)
        {
            for(int k=i-1; k>=0; k--)
                s<<v1[k];
            delete[] v1;
            return false;
        }
        v1=copie_s;
        s>>copie_s[i];
        i++;
    }
    // Copiem stiva lui this
    while(!(!(*this)))
    {
        copie_this=(int*)realloc(copie_this,(j+1)*sizeof(int));
        if(copie_this==NULL)
        {
            for(int k=j-1; k>=0; k--)
                (*this)<<v2[k];
            delete[] v2;
            return false;
        }
        v2=copie_this;
        (*this)>>copie_this[j];
        j++;
    }
    // Refacem stivele
    for(int k=i-1; k>=0; k--)
        s<<copie_s[k];
    for(int k=j-1; k>=0; k--)
        (*this)<<copie_this[k];
    // Daca numarul de elemente din stive difera return false
    if(i!=j)
    {
        delete[] copie_s;
        delete[] copie_this;
        return false;
    }
    else
    {
        for(int k=0; k<i; k++)
        {
            if(copie_s[k]!=copie_this[k])
            {
                delete[] copie_s;
                delete[] copie_this;
                return false;
            }
        }
    }
    delete[] copie_s;
    delete[] copie_this;
    return true;
}
///Verificare daca doua stive sunt diferite
bool stack::operator!=(stack &s)
{
    return !(*this==s);
}
///Operatorul de atribuire
stack& stack::operator=(stack &s)
{
    int *copie_s,i=0;
    copie_s=(int*)malloc(0*sizeof(int));
    int *v=copie_s;
    // Clonam stiva
    while(!(!s))
    {
        copie_s=(int*)realloc(copie_s,(i+1)*sizeof(int));
        if(copie_s==NULL)
        {
            for(int k=i-1; k>=0; k--)
                s<<v[k];
            delete[] v;
            return (*this);
        }
        v=copie_s;
        s>>copie_s[i];
        i++;
    }
    // Stergem stiva veche
    -(*this);
    // Reintroducem elementele in stiva s si in stiva lui this
    for(int k=i-1; k>=0; k--)
    {
        s<<copie_s[k];
        (*this)<<copie_s[k];
    }
    delete[] copie_s;
    return (*this);
}
stack::~stack() {}
