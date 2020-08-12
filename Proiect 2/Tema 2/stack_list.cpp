#include "stack_list.h"
#include <iostream>
using namespace std;
///Operatorul push
stack& stack_list::operator<<(int i)
{
    this->reset();
    this->ins_next(i);
    return *this;
}
///Operatorul pop
stack& stack_list::operator>>(int& i)
{
    this->reset();
    this->get_next(i);
    this->del_next();
    return *this;
}
///Operatorul de verificare stiva vida
bool stack_list::operator!()
{
    this->reset();
    return (this->end()) ? true : false;
}
stack_list::~stack_list(){}
