#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED
#include <iostream>
using namespace std;
const int NumRoute=100;
template <class T,class E>
struct RouteNet     //��Ϊ�߱���
{
    int dest;
    T dis;
    RouteNet<T,E> *Link;
};
template <class T,class E>
struct RouteList      //�������
{
    E *Routename;
    string Netname;
    RouteNet<T,E> *next;
};
template <class T,class E>
class CreatNet
{
public:
    ~CreatNet();
    CreatNet(int sz=NumRoute);
    void ReadRoute();
    void ReadNet();
    void Printf();                       //���Ժ����������ֵ
    void Print();              //���Ժ����������ֵ
    bool InsertRoute(const E *Routename,string A);     //����վ��
    bool InsertLine(char *a,char *b,T d);  //����·��
    bool DeleteLine(char *a,char *b);
    bool DeleteRoute(char *a);
    bool IsNear(int a,int b)
    {
        RouteNet<T,E> *p=head[a].next;
        while(p!=NULL)
        {
            if(p->dest==b)
                return true;
            else
                p=p->Link;
        }
        return false;
    }
    int FindAddr(char*a);
    T getWeight(char*a,char*b);
    void ShortminPath(char*v, int distance[], int minPath[]);
    void create_RouteTable(int path[],char*m);
    E* GetValue(E *i)//����վ��i��ֵ
    {
        if(i==NULL)
        {
            return NULL;
        }
        else
            return i;
    }
protected:
    RouteNet<T,E> *ptr;
    RouteList<T,E> *head;
    T Num=0;
    T NumLine=0;
    E x=1;
};
#endif // CLASS_H_INCLUDED
