#ifndef HANSHU1_H_INCLUDED
#define HANSHU1_H_INCLUDED
#include <iostream>
#include "class.h"
#include "main.cpp"
using namespace std;
template <class T,class E>
bool CreatNet<T,E>::InsertRoute(const E *name,string A)      //����վ��
{
    if(Num==NumRoute)
        return false;
    else
        strcpy(head[Num].Routename,name);
    head[Num].Netname=A;
    Num++;
    return true;
}
template <class T,class E>
int CreatNet<T,E>::FindAddr(char*a)
{
    int i=0;
    for(i=0; i<Num; i++)
    {
        if(strcmp(a,head[i].Routename)==0)
            return i;
    }
    return -1;
}
template <class T,class E>
bool CreatNet<T,E>::DeleteRoute(char *a)           //ɾ��վ��
{
    int v;
    v=FindAddr(a);
    if(Num==1||v<0||v>NumRoute)
        return false;
    RouteNet<T,E> *p,*s,*t;
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
template <class T,class E>
bool CreatNet<T,E>::DeleteLine(char *a,char *b)     //ɾ������ߣ�ģ��ȡ����վ��ͨ��·�ߣ�
{
    int j,i;
    j=FindAddr(a);
    i=FindAddr(b);
    if(i!=-1&&j!=-1)
    {
        RouteNet<T,E> *p=head[j].next;
        RouteNet<T,E> *q=NULL;
        RouteNet<T,E> *s=p;
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
template <class T,class E>
bool CreatNet<T,E>::InsertLine(char *a,char *b,T d)     //�����ڽӱ�(ģ�ⴴ������ͨ�����)
{
    int j=0;
    int i=0;
    j=FindAddr(a);
    i=FindAddr(b);
    if(j>=0&&j<Num&&i>=0&&i<Num)
    {
        RouteNet<T,E> *q;
        RouteNet<T,E> *p=head[j].next;
        while(p!=NULL&&p->dest!=i)
        {
            p=p->Link;
        }
        if(p!=NULL)
            return false;
        p=new RouteNet<T,E>;
        q=new RouteNet<T,E>;
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
