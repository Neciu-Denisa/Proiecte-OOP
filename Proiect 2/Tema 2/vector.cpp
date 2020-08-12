#include <iostream>
#include <cstdlib>
#include "vector.h"
using namespace std;
vector::vector()
{
    buf=NULL;
    n=0;
}
vector::vector(int i)
{
    buf=(int*)malloc(sizeof(int));
    if(buf!=NULL)
    {
        buf[0]=i;
        n=1;
    }
    else
        n = 0;
}
vector::vector(vector& v)
{
    buf=(int*)malloc(v.n*sizeof(int));
    if(buf!=NULL)
    {
        n=v.n;
        for(int i=0; i<n; i++)
            buf[i]=v.buf[i];
    }
    else
        n=0;
}
vector::~vector()
{
    delete[] buf;
    n=0;
}
///Operator de atribuire
vector& vector::operator=(vector& v)
{
    delete[] buf;
    buf=(int*)malloc(v.n*sizeof(int));
    if(buf==NULL)
    {
        n=0;
        return *this;
    }
    n=v.n;
    for(int i=0; i<n; i++)
        buf[i]=v.buf[i];
    return *this;
}
///Operatorul [] de indexare
int& vector::operator[](int i)
{
    int *v=buf;
    if(i>=this->n)
    {
        buf=(int*)realloc(buf,(i+1)*sizeof(int));
        if(buf!=NULL)
            this->n=i;
        else
        {
            buf=v;
            return buf[this->n-1];
        }
    }
    return buf[i];
}
///Metoda de truncare
bool vector::truncate(int t)
{
    int *v=buf;
    buf=(int*)realloc(buf,t*sizeof(int));
    if(buf==NULL)
    {
        if(t==0)
        {
            this->n=0;
            return true;
        }
        else
            buf=v;
        return false;
    }
    else
    {
        this->n=t;
        return true;
    }
}
///Metoda returnare lungime
int vector::length()
{
    return this->n;
}
