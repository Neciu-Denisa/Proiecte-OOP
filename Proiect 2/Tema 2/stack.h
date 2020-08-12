#ifndef _STACK_H
#define _STACK_H
class stack
{
public:
    void operator-();
    bool operator==(stack&);
    bool operator!=(stack&);
    stack& operator=(stack&);
    virtual stack& operator<<(int)=0;
    virtual stack& operator>>(int&)=0;
    virtual bool operator!()=0;
    virtual ~stack();
};
#endif
