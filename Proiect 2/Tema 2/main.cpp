#include <iostream>
#include <cstdlib>
#include "stack_list_vector.h"
using namespace std;
istream& operator>>(istream& i, stack& s)
{
    int n,k;
    -s;
    cout<<"Introduceti numarul de elemente: ";
    i>>n;
    cout<<"Introduceti cele "<<n<<" elemente: ";
    for(int j=0; j<n; j++)
    {
        i>>k;
        s<<k;
    }
    return i;
}
ostream& operator<<(ostream& o, stack& s)
{
    int *v,*v1,i=0;
    v=(int*)malloc(0*sizeof(int));
    v1=v;
    // Clonam stiva
    while(!(!s))
    {
        v=(int*)realloc(v,(i+1)*sizeof(int));
        if(v!=NULL)
        {
            s>>v[i];
            o<<v[i]<<"\n";
            i++;
            v1=v;
        }
        else
        {
            for(int k=i-1; k>=0; k++)
                s<<v1[k];
            delete[] v1;
            return o;
        }

    }
    // Reintroducem elementele in stiva s
    for(int k=i-1; k>=0; k--)
        s<<v[k];
    delete[] v;
    return o;
}

int main()
{
    stack_list_vector s;
    cin>>s;
    stack_list_vector t;
    t=s;
    cout<<"Stiva initiala este:\n";
    cout<<t;
    cout<<"Stiva initiala este:\n";
    cout<<t;
    stack_list_vector r;
    while(!(!t))
    {
        int x;
        t>>x;
        r<<x;
    }
    cout<<"Stiva inversata este:\n";
    cout<<r;
    if(s==r)
        cout<<"Cele doua stive SUNT EGALE.\n";
    else
        cout<<"Cele doua stive NU SUNT EGALE.\n";
    return 0;
}
