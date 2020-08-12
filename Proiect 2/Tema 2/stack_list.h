#ifndef _STACK_LIST_H
#define _STACK_LIST_H
#include "stack.h"
#include "list.h"
class stack_list:public stack, private list
{
public:
    stack& operator<<(int);
    stack& operator>>(int&);
    bool operator!();
    virtual void reset()=0;
    virtual bool next()=0;
    virtual bool end()=0;
    virtual bool ins_next(int)=0;
    virtual bool del_next()=0;
    virtual bool get_next(int&)=0;
    virtual ~stack_list();
};
#endif
