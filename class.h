#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED
#include <iostream>
using namespace std;
const int NumRoute=100;
struct RouteNet     //��Ϊ�߱���
{
    int dest;
    int dis;
    RouteNet *Link;
};
struct RouteList      //�������
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
    void Printf();                       //���Ժ����������ֵ
    void Print();              //���Ժ����������ֵ
    bool InsertRoute(const char *Routename,string A);     //����վ��
    bool InsertLine(char *a,char *b,int d);  //����·��
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
    char* GetValue(char *i)//����վ��i��ֵ
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
