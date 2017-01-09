#ifndef HANSHU1_H_INCLUDED
#define HANSHU1_H_INCLUDED
#include <iostream>
#include "class.h"
using namespace std;

bool CreatNet::InsertRoute(const char *name,string A)      //创建站点
{
    if(Num==NumRoute)
        return false;
    else
        strcpy(head[Num].Routename,name);
    head[Num].Netname=A;
    Num++;
    return true;
}
int CreatNet::FindAddr(char*a)
{
    int i=0;
    for(i=0; i<Num; i++)
    {
        if(strcmp(a,head[i].Routename)==0)
            return i;
    }
    return -1;
}
bool CreatNet::DeleteRoute(char *a)           //删除站点
{
    int v;
    v=FindAddr(a);
    if(Num==1||v<0||v>NumRoute)
        return false;
    RouteNet *p,*s,*t;
    int k;
    while(head[v].next!=NULL)
    {
        p=head[v].next;
        k=p->dest;
        s=head[k].next;
        t=NULL;
        while(s!=NULL&&s->dest!=v)
        {
            t=s;
            s=s->Link;
        }
        if(s!=NULL)
        {
            if(t==NULL)
                head[k].next=s->Link;
            else
                t->Link=s->Link;
            delete s;
        }
        head[v].next=p->Link;
        delete p;
        NumLine--;
    }
    strcpy(head[v].Routename,head[Num-1].Routename);
    head[v].Netname=head[Num-1].Netname;
    head[v].next=head[Num-1].next;head[Num-1].next=NULL;
     p=head[v].next;
    while(p!=NULL)
    {
        s=head[p->dest].next;
        while(s!=NULL){
            if(s->dest==Num-1)
            {
                s->dest=v;
                break;

            }
            else
                s=s->Link;
        }
        p=p->Link;
    }
     Num--;
    return true;
}
bool CreatNet::DeleteLine(char *a,char *b)     //删除顶点边（模拟取消两站点通车路线）
{
    int j,i;
    j=FindAddr(a);
    i=FindAddr(b);
    if(i!=-1&&j!=-1)
    {
        RouteNet *p=head[j].next;
        RouteNet *q=NULL;
        RouteNet *s=p;
        while(p!=NULL&&p->dest!=i)
        {
            q=p;
            p=p->Link;
        }
        if(p!=NULL)
        {
            if(p==s)
                head[j].next=p->Link;
            else
                q->Link=p->Link;
            delete p;
        }
        else
            return false;
        p=head[i].next;
        q=NULL;
        s=p;
        while(p->dest!=j)
        {
            q=p;
            p=p->Link;
        }
        if(p==s)
            head[i].next=p->Link;
        else
            q->Link=p->Link;
        delete p;
        return true;
    }
    return false;
}
bool CreatNet::InsertLine(char *a,char *b,int d)     //建立邻接表(模拟创建各地通车情况)
{
    int j=0;
    int i=0;
    j=FindAddr(a);
    i=FindAddr(b);
    if(j>=0&&j<Num&&i>=0&&i<Num)
    {
        RouteNet *q;
        RouteNet *p=head[j].next;
        while(p!=NULL&&p->dest!=i)
        {
            p=p->Link;
        }
        if(p!=NULL)
            return false;
        p=new RouteNet;
        q=new RouteNet;
        p->dis=d;
        p->dest=i;
        p->Link=head[j].next;
        head[j].next=p;
        q->dis=d;
        q->dest=j;
        q->Link=head[i].next;
        head[i].next=q;
        NumLine++;
        return true;
    }
    return 0;
}
#endif // HANSHU1_H_INCLUDED
