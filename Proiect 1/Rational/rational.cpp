#include "rational.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
void rat::simplificare()
{
    if(numitor==0) {std::cin>>*this;}
    if(numarator==0)
    {
        numitor=1;
        return;
    }
    int a=numarator>0?numarator:-numarator, b=numitor>0?numitor:-numitor;
    while(a!=b) if(a>b) a-=b;
        else b-=a;
    numarator/=a;
    numitor/=a;
    if(numitor<0)
    {
        numarator=-numarator;
        numitor=-numitor;
    }
}
void rat::set (int x, int y)
{
    numarator=x;
    numitor=y;
    simplificare();
}
int rat::getnumarator ()
{
    return numarator;
}
int rat::getnumitor ()
{
    return numitor;
}
rat::rat(const rat& x)
{
    numarator=x.numarator;
    numitor=x.numitor;
    simplificare();
}

rat::rat()
{
    numarator=1;
    numitor=1;

}
rat rat::operator+(rat r2)
{
    numarator=numarator*r2.numitor+r2.numarator*numitor;
    numitor=numitor*r2.numitor;
    return *this;
}

rat rat::operator+(int n)
{
    numarator=numarator+n*numitor;
    numitor=numitor;
    return *this;
}
rat rat::operator-(rat r2)
{
    numarator=numarator*r2.numitor-r2.numarator*numitor;
    numitor=numitor*r2.numitor;
    return *this;

}
rat rat::operator+()
{
    return *this;
}

rat rat::operator-()
{  rat r1;
r1=*this;
    r1.numarator=-numarator;
return r1;

}
rat rat::operator-(int n)
{
    numarator=numarator-n*numitor;
    numitor=numitor;
    return *this;
}
rat rat::operator*(rat r2)
{
numarator=numarator*r2.numarator;
numitor=numitor*r2.numitor;
return *this ;
}
rat rat::operator*(int n)
{
    numarator=numarator*n;
    numitor=numitor;
    return *this;
}
rat rat ::operator/(rat r2)
{
    numarator=numarator*r2.numitor;
    numitor=numitor*r2.numarator;
    return *this;
}
rat rat::operator/(int n)
{
    numarator=numarator;
    numitor=numitor*n;
    return *this;
}
rat rat::operator^(int n)
{
    int i;
    int numito=numitor;
    int numara=numarator;
    if(n==0){numara=1; numito=1;};
     if(n!=1)
        for(i=2; i<=n; i++)
    {
         numito=numitor*numito;
        numara=numara*numarator;
    }
    numarator=numara;
    numitor=numito;

    return *this;
}
rat& rat::operator=(const rat &f1)
{
    numarator=f1.numarator;
    numitor=f1.numitor;
    return *this;
}

rat& rat::operator+=(const rat &r2)
{
    numarator=numarator*r2.numitor+numitor*r2.numarator;
    numitor=numitor*r2.numitor;
    simplificare();
    return *this;
}
rat& rat::operator-=(const rat &r2)
{
    numarator=numarator*r2.numitor-r2.numarator*numitor;
    numitor=numitor*r2.numitor;
    simplificare();
    return *this;
}
rat& rat::operator*=(const rat &r2)
{
    numarator=numarator*r2.numarator;
    numitor=numitor*r2.numitor;
    simplificare();
    return *this;
}
rat& rat::operator/=(const rat &r2)
{
    numarator=numarator*r2.numitor;
    numitor=numitor*r2.numarator;
    simplificare();
    return *this;
}
rat& rat::operator =(int n)
{numarator=n;
numitor=1;
return *this;

}
bool rat::operator==(rat x)
{
    return(x.numarator==numarator && x.numitor==numitor);

}
bool rat::operator==(int x)
{
    return(numarator==x && numitor==1);

}
bool rat::operator!=(rat x)
{
    return(x.numarator!=numarator || x.numitor!=numitor);
}
bool rat::operator!=(int x)
{
    return(numarator!=x || numitor!=1);
}
bool rat::operator<(rat x)
{
    return (numarator*x.numitor<x.numarator*numitor);
}
bool rat::operator<(int n)
{
    return (numarator<numitor*n);
}
bool rat::operator<=(rat x)
{
    return(numarator*x.numitor<=x.numarator*numitor);
}
bool rat::operator<=(int n)
{
    return (numarator<=numitor*n);
}
bool rat::operator>(rat x)
{
  return(numarator*x.numitor>x.numarator*numitor);

}
bool rat::operator>(int n)
{
    return (numarator>numitor*n);
}
bool rat::operator>=(rat x)
{
    return (numarator*x.numitor>=x.numarator*numitor);
}
bool rat::operator>=(int n)
{
    return(numarator>=numitor*n);
}
rat operator+(int n,rat r2)
{
    r2.numarator=n*r2.numitor+r2.numarator;
    r2.numitor=r2.numitor;
    return r2;
}
rat operator-(int n,rat r2)
{
    r2.numarator=n*r2.numitor-r2.numarator;
    r2.numitor=r2.numitor;
    return r2;

}
rat operator*(int n,rat r2)
{
    r2.numarator=n*r2.numarator;
    r2.numitor=r2.numitor;
    return r2;
}
rat operator/(int n, rat r2)
{
    r2.numarator=n*r2.numitor;
    r2.numitor=r2.numarator;
    return r2;
}
bool operator==(int n,rat x)
{
    return (n==x.numarator && 1==x.numitor);
}
bool operator!=(int n,rat x)
{
    return (n!=x.numarator ||1!=x.numitor);
}
bool operator<(int n,rat x)
{
    return (x.numarator<x.numitor*n);
}

bool operator<=(int n,rat x)
{
    return (x.numarator<=x.numitor*n);
}
bool operator>(int n,rat x)
{
    return (x.numarator>x.numitor*n);
}
bool operator>=(int n,rat x)
{
    return (x.numarator>=x.numitor*n);
}
rat abs(rat x)
{
    if(x.numarator<0)
    {
        ;
        x.numarator=-x.numarator;
        x.numitor=x.numitor;
        return x;
    }
    else {x.numarator=x.numarator;x.numitor=x.numitor;return x;}
}
rat::operator double()
{
    return numarator/(double)numitor;
}
std::istream& operator>>(std::istream& s,rat &r)
{
    s>>r.numarator;
    s>>r.numitor;
    r.simplificare();
    return s;
}
std::ostream& operator<<(std::ostream& s,rat r)
{
    s<<r.numarator;
    if(r.numitor!=1)s<<"/"<<r.numitor;
    return s;
}
