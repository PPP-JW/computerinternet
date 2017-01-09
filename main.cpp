#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <fstream>
#include "hanshu1.h"
#include "hanshu2.h"
#include "hanshu3.h"
#include "xigouandgouzao.h"
#include "dijsktra.h"
using namespace std;
int main( )
{
    char ch;
    CreatNet  X;
    X.ReadRoute();
    X.ReadNet();
    cout<<"已构建路由网络图："<<endl;
    X.Print();
    cout<<"我在更新数据！！！"<<endl;
    while(ch!='F'||ch!='f')
    {
        cout<<"************************************"<<endl;
        cout<<"           请选择你的选择           "<<endl;
        cout<<"           A：增设路由;             "<<endl;
        cout<<"           B：增设网络;             "<<endl;
        cout<<"           C: 删除网络;             "<<endl;
        cout<<"           D：删除路由;             "<<endl;
        cout<<"           E：查看路由表;           "<<endl;
        cout<<"           F: 退出浏览              "<<endl;
        cout<<"************************************"<<endl;
        cin>>ch;
        if(ch=='A'||ch=='a')
        {
            cout<<"请输入要增设的路由名：(end：结束)"<<endl;
            char *cho="end";
            string A;
            char *arr=new char[10];
            cin>>arr;
            cout<<"请输入路由器所在网络号："<<endl;
            cin>>A;
            while(strcmp(arr,cho)!=0)
            {
                if(X.InsertRoute(arr,A)==false)
                    cout<<"插入失败！"<<endl;
                else
                    cout<<"插入成功！"<<endl;
                cout<<"请输入要增设的路由名：(end：结束)"<<endl;
                cin>>arr;
                cout<<"请输入路由器所在网络号："<<endl;
                cin>>A;
            }
            X.Print();
        }
        if(ch=='B'||ch=='b')
        {
            char *name=new char[Maxsize];
            string Routename;
            char *a=new char[10];
            char *b=new char[10];
            int c;
            cout<<"请输入要增设网络的两个路由:"<<endl;
            cin>>a>>b;
            cout<<"请输入两站点距离(0：结束增设)"<<endl;
            cin>>c;
            while(c!=0)
            {
                if(X.InsertLine(a,b,c)==false)
                    cout<<"增设失败！"<<endl;
                else
                    cout<<"增设成功！"<<endl;
                cout<<"请输入要增设网络的两个路由:"<<endl;
                cin>>a>>b;
                cout<<"请输入两站点距离(0：结束增设)"<<endl;
                cin>>c;
            }
            X.Print();
        }
        if(ch=='C'||ch=='c')
        {
            char *a=new char[10];
            char *b=new char[10];
            char *cho="end";
            cout<<"请输入要删除网络的两个路由:(输入end即退出)"<<endl;
            cin>>a>>b;
            while((strcmp(a,cho)!=0)||(strcmp(b,cho)!=0))
            {
                if(X.DeleteLine(a,b)==false)
                    cout<<"删除失败！"<<endl;
                else
                    cout<<"删除成功！"<<endl;
                cout<<"请输入要删除路线的两个路由:(输入end即退出)"<<endl;
                cin>>a>>b;
            }
            X.Print();
        }
        if(ch=='D'||ch=='d')
        {
            char *cho="end";
            cout<<"请输入要删除的路由：(输入end即退出)"<<endl;
            char *i=new char[10];
            cin>>i;
            while(strcmp(i,cho)!=0)
            {
                if(X.DeleteRoute(i)==false)
                    cout<<"删除失败!"<<endl;
                else
                    cout<<"删除成功！"<<endl;
                cout<<"请输入要删除的路由：(输入end即退出)"<<endl;
                cin>>i;
            }
            X.Print();
        }
        if(ch=='E'||ch=='e')
        {
            char *cho="end";
            cout<<"请输入要查看其路由表的路由器名：(输入end即退出)"<<endl;
            char *i=new char[10];
            cin>>i;
            int distance[NumRoute];
            int minPath[NumRoute];
            while(strcmp(i,cho)!=0)
            {
                X.ShortminPath(i,distance,minPath);
                X.create_RouteTable(minPath,i);
                cout<<"请输入要查看其路由表的路由器名：(输入end即退出)"<<endl;
                cin>>i;
            }
        }
    }
    return 0;
}
