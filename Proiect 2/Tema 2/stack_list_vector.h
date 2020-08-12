#ifndef _STACK_LIST_VECTOR_H
#define _STACK_LIST_VECTOR_H
#include "stack_list.h"
#include "vector.h"

class stack_list_vector:public stack_list, private vector
{
    int k;
public:
    stack_list_vector();
    ~stack_list_vector();
    void reset();
    bool next();
    bool end();
    bool ins_next(int);
    bool del_next();
    bool get_next(int&);
    //void operator-();
    bool operator==(stack_list_vector&);
    bool operator!=(stack_list_vector&);
    stack_list_vector& operator=(stack_list_vector&);
};
#endif
