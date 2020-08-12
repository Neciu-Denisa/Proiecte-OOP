#ifndef _VECTOR_H
#define _VECTOR_H
class vector
{
    int *buf,n;
public:
    vector();
    vector(int);
    vector(vector&);
    ~vector();
    int& operator[](int);
    vector& operator=(vector&);
    bool truncate(int);
    int length();
};
#endif

