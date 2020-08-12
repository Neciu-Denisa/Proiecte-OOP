#ifndef _LIST_H
#define _LIST_H
class list
{
public:
    void operator-();
    bool operator==(list&);
    bool operator!=(list&);
    list& operator=(list&);
    virtual void reset()=0;
    virtual bool next()=0;
    virtual bool end()=0;
    virtual bool ins_next(int)=0;
    virtual bool del_next()=0;
    virtual bool get_next(int&)=0;
    virtual ~list();
};
#endif
