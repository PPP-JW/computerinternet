#ifndef HANSHU2_H_INCLUDED
#define HANSHU2_H_INCLUDED
#include <iostream>
#include "class.h"
using namespace std;
template<class T,class E>
void CreatNet<T,E>::create_RouteTable(int path[],char*m)
{
    int v=FindAddr(m);
    int j=0,k=0;
    cout<<"目的主机所在的网络号   下一跳地址"<<endl;
    for(int i=0; i<Num; i++)
    {
        int z=1;
        if(i!=v)
        {
            k=i;
            cout<<"   "<<head[i].Netname;
            if(IsNear(v,i)==true)
            {
                cout<<"              直接交付"<<endl;
            }
            else
            {
                while(1)
                {
                    if(path[i]==v)
                    {
                        if(z!=1)
                        {
                            cout<<"              "<<head[i].Netname<<endl;
                            break;
                        }
                        else
                        {
                            cout<<"              直接交付"<<endl;
                            break;
                        }
                    }
                    else if(path[i]!=v)
                    {
                        i=path[i];//cout<<i<<endl;
                        z++;
                        //cout<<z<<endl;
                    }
                }
                i=k;
            }

        }
    }
}
#endif // HANSHU2_H_INCLUDED
