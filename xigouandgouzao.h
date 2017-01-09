#ifndef XIGOUANDGOUZAO_H_INCLUDED
#define XIGOUANDGOUZAO_H_INCLUDED
#include <iostream>
#include "class.h"
using namespace std;
template <class T,class E>
CreatNet<T,E>::~CreatNet()
{
    for(int i=0; i<Num; i++)
        delete []head;
}
template <class T,class E>
CreatNet<T,E>::CreatNet(int sz)            //¹¹Ôìº¯Êý
{
    head=new RouteList<T,E>[sz];
    for(int i=0; i<sz; i++)
    {
        head[i].Routename=new E[Maxsize];
        head[i].next=NULL;
    }
    ptr=new RouteNet<T,E>;
    ptr->Link=NULL;
}
#endif // XIGOUANDGOUZAO_H_INCLUDED
