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
    cout<<"Ŀ���������ڵ������   ��һ����ַ"<<endl;
    for(int i=0; i<Num; i++)
    {
        int z=1;
        if(i!=v)
        {
            k=i;
            cout<<"   "<<head[i].Netname;
            if(IsNear(v,i)==true)
            {
                cout<<"              ֱ�ӽ���"<<endl;
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
                            cout<<"              ֱ�ӽ���"<<endl;
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
