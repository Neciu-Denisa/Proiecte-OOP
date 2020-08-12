#include <iostream>
#include "stack_list_vector.h"
using namespace std;
stack_list_vector::stack_list_vector()
{
    this->k=-1;
}
stack_list_vector::~stack_list_vector()
{
    k = 0;
}
void stack_list_vector::reset()
{
    this->k=-1;
}
///Pozitionare cursor pe urmatoarea pozitie
bool stack_list_vector::next()
{
    if(this->length()>this->k+1)
    {
        this->k++;
        return true;
    }
    else
        return false;
}
///Verifica daca e final
bool stack_list_vector::end()
{
    if(this->k+1==this->length())
        return true;
    else
        return false;
}
///Inserare pe pozitia urmatoare
bool stack_list_vector::ins_next(int i)
{
    //Apelam operatorul [] din <vector> care este clasa de baza si ii cerem realocarea vectorului cu "lungimea()" + 1
    int length_v=this->length();
    //Verficam daca realocarea a avut loc cu succes si lugimea vectorului s-a modificat
    (*this)[this->length()+1];
    if(this->length()==length_v) return false;
    // Mutam elementele de pe pozitiile > cursorul
    for(int j=this->length()-1; j>this->k+1; j--)
        (*this)[j]=(*this)[j-1];
    // Adaugam elementul de adaugat pe pozitia k+1
    (*this)[k+1]=i;
    return true;
}
///Stergere element urmator
bool stack_list_vector::del_next()
{
    for(int i=this->k+1; i<this->length()-1; i++)
        (*this)[i]=(*this)[i+1];
    return this->truncate(this->length()-1);
}
///Primire element urmator
bool stack_list_vector::get_next(int &i)
{
    if(this->k+1<this->length())
    {
        i=(*this)[this->k+1];
        return true;
    }
    else
    {
        i=(*this)[this->length()-1];
        return true;
    }
    return false;
}
///Verificare stack_list_vector egale
bool stack_list_vector::operator==(stack_list_vector& l)
{
    return ((*this).stack::operator==(l));
}
///Verificare stak_list_vector diferite
bool stack_list_vector::operator!=(stack_list_vector& l)
{
    return !(*this==l);
}
///Operatorul de atribuire
stack_list_vector& stack_list_vector::operator=(stack_list_vector& l)
{
    (*this).stack::operator=(l);
    return *this;
}

