#ifndef XIGOUANDGOUZAO_H_INCLUDED
#define XIGOUANDGOUZAO_H_INCLUDED
#include <iostream>
#include "class.h"
const int Maxsize=20;
using namespace std;
CreatNet::~CreatNet()
{
    for(int i=0; i<Num; i++)
        delete []head;
}
CreatNet::CreatNet(int sz)            //¹¹Ôìº¯Êý
{
    head=new RouteList[sz];
    for(int i=0; i<sz; i++)
    {
        head[i].Routename=new char[Maxsize];
        head[i].next=NULL;
    }
    ptr=new RouteNet;
    ptr->Link=NULL;
}
#endif // XIGOUANDGOUZAO_H_INCLUDED
