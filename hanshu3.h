#ifndef HANSHU3_H_INCLUDED
#define HANSHU3_H_INCLUDED
#include <iostream>
#include "class.h"
using namespace std;
template <class T,class E>
void CreatNet<T,E>::Print()
{
    RouteNet<T,E> *p;
    cout<<"Â·ÓÉÆ÷    ÍøÂçºÅ  ÏàÁÚÂ·ÓÉÆ÷  dest  ¾àÀë"<<endl;
    for(int i=0; i<Num; i++)
    {
        p=head[i].next;
        cout<<head[i].Routename<<endl;
        while(p!=NULL)
        {
            cout<<"     ----"<<head[i].Netname<<"----"<<head[p->dest].Routename<<" ---"<<p->dest<<"---"<<p->dis<<endl;
            p=p->Link;
        }
    }
}
template <class T,class E>
void CreatNet<T,E>::ReadRoute()
{
    char *cho="end";
    ifstream infile;
    infile.open("GetRoute.txt");
    cout << "Reading from the file......." << endl;
    for(int i=0; i<NumRoute; i++)
    {
        infile >> head[i].Routename;
        infile >>head[i].Netname;
        if(strcmp(head[i].Routename,cho)==0)
            break;
        Num++;
    }
    infile.close();
}
template <class T,class E>
void CreatNet<T,E>::ReadNet()
{
    char *cho="end";
    char data1[10],data2[10];
    int i;
    ifstream infile;
    infile.open("GetNet.txt");
    cout << "Reading from the file ........" << endl;
    for(int i=0; i<NumRoute; i++)
    {
        infile >> data1;
        infile >>data2;
        infile >>i;
        if(i==0)
            break;
        else
            InsertLine(data1,data2,i);
        NumLine++;
    }
    infile.close();
}
template<class T,class E>
T CreatNet<T,E>::getWeight(char*a,char*b)
{
    int i=FindAddr(a);
    int j=FindAddr(b);
    if(i!=-1&&j!=-1)
    {
        RouteNet<T,E>*p=head[i].next;
        while(p!=NULL&&p->dest!=j)
        {
            p=p->Link;
        }
        if(p!=NULL)return p->dis;
    }
    return maxValue;
}
#endif // HANSHU3_H_INCLUDED
