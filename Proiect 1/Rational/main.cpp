#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "rational.h"
#include "rational.cpp"
int main(){
rat a,c,d,e,f,x,y, b;
 std::cout<<"Datele pentru sistem: a,b,c,d,e,f:";
 std::cin>>a>>b>>c>>d>>e>>f;
if( a==0 && b==0 && d==0 && e==0 && f==0 && c==0)

std::cout<<"Orice numar e solutie"<<std::endl;
if(a==0 && b==0 && d==0 && e==0 && f!=0 && c!=0 )
    std::cout<<"Sistem incompatibil"<<std::endl;
else {
        if((a*e-b*d)!=0)
           {   if((a*e)==0)
             {x=f/d;
              std::cout<<"x= "<<x<<std::endl;
               y=c/b;
               std::cout<<"y= "<<y<<std::endl;
               exit(1);
              }
              else{ y=(f*a-d*c)/(e*a-b*d);
             std::cout<<"y= "<<y<<std::endl;
            x=(c-b*y)/a;
            std::cout<<"x= "<<x;
            exit(1);}
           }

         else{if(a!=0)
                if(b!=0)
                {x=c/a;
                 std::cout<<"x="<<x<<"-("<<b/a<<")"<<"*y, pentru orice y"<<std::endl;
                   exit(1);
                }
                else {x=c/a;
                     std::cout<<"x="<<x<<"pentru orice y";
                     }
               if(d!=0)
                       if(e!=0)
               {x=f/d;
               std::cout<<"x="<<x<<"-("<<e/d<<")*y, pentru orice y"<<std::endl;
               exit(1);

               }
               else {x=f/d; std::cout<<"x="<<x<<"orice y ";}

         if(b!=0)
            if(a!=0)
         {x=c/a;
         std::cout<<"x="<<x<<"-("<<b/a<<")*y pentru orice y ";

         }
         else {y=c/b;
         std::cout<<"y="<<y<<"pentru orice x";
              }
          if(e!=0)
                if(d!=0)
          {x=f/d;
          std::cout<<"x="<<x<<"-("<<e/d<<")*y pentru orice y";

          }
          else {y=f/e; std::cout<<"y="<<y<<" pentru orice x";}
         }

      }

 return 0;
}

//ecuatie:  2x+3y=5 5x+2y=-2 solutie : x=-16/11; y=29/11
