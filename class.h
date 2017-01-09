#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED
#include <iostream>
using namespace std;
const int NumRoute=100;
struct RouteNet     //作为边表结点
{
    int dest;
    int dis;
    RouteNet *Link;
};
struct RouteList      //顶点表结点
{
    char *Routename;
    string Netname;
    RouteNet *next;
};
class CreatNet
{
public:
    ~CreatNet();
    CreatNet(int sz=NumRoute);
    void ReadRoute();
    void ReadNet();
    void Printf();                       //测试函数，输出数值
    void Print();              //测试函数，输出数值
    bool InsertRoute(const char *Routename,string A);     //增添站点
    bool InsertLine(char *a,char *b,int d);  //增设路线
    bool DeleteLine(char *a,char *b);
    bool DeleteRoute(char *a);
    bool IsNear(int a,int b)
    {
        RouteNet *p=head[a].next;
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
    int getWeight(char*a,char*b);
    void ShortminPath(char*v, int distance[], int minPath[]);
    void create_RouteTable(int path[],char*m);
    char* GetValue(char *i)//返回站点i的值
    {
        if(i==NULL)
        {
            return NULL;
        }
        else
            return i;
    }
protected:
    RouteNet *ptr;
    RouteList *head;
    int Num=0;
    int NumLine=0;
};
#endif // CLASS_H_INCLUDED
