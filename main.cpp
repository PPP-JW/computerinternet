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
    cout<<"�ѹ���·������ͼ��"<<endl;
    X.Print();
    cout<<"���ڸ������ݣ�����"<<endl;
    while(ch!='F'||ch!='f')
    {
        cout<<"************************************"<<endl;
        cout<<"           ��ѡ�����ѡ��           "<<endl;
        cout<<"           A������·��;             "<<endl;
        cout<<"           B����������;             "<<endl;
        cout<<"           C: ɾ������;             "<<endl;
        cout<<"           D��ɾ��·��;             "<<endl;
        cout<<"           E���鿴·�ɱ�;           "<<endl;
        cout<<"           F: �˳����              "<<endl;
        cout<<"************************************"<<endl;
        cin>>ch;
        if(ch=='A'||ch=='a')
        {
            cout<<"������Ҫ�����·������(end������)"<<endl;
            char *cho="end";
            string A;
            char *arr=new char[10];
            cin>>arr;
            cout<<"������·������������ţ�"<<endl;
            cin>>A;
            while(strcmp(arr,cho)!=0)
            {
                if(X.InsertRoute(arr,A)==false)
                    cout<<"����ʧ�ܣ�"<<endl;
                else
                    cout<<"����ɹ���"<<endl;
                cout<<"������Ҫ�����·������(end������)"<<endl;
                cin>>arr;
                cout<<"������·������������ţ�"<<endl;
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
            cout<<"������Ҫ�������������·��:"<<endl;
            cin>>a>>b;
            cout<<"��������վ�����(0����������)"<<endl;
            cin>>c;
            while(c!=0)
            {
                if(X.InsertLine(a,b,c)==false)
                    cout<<"����ʧ�ܣ�"<<endl;
                else
                    cout<<"����ɹ���"<<endl;
                cout<<"������Ҫ�������������·��:"<<endl;
                cin>>a>>b;
                cout<<"��������վ�����(0����������)"<<endl;
                cin>>c;
            }
            X.Print();
        }
        if(ch=='C'||ch=='c')
        {
            char *a=new char[10];
            char *b=new char[10];
            char *cho="end";
            cout<<"������Ҫɾ�����������·��:(����end���˳�)"<<endl;
            cin>>a>>b;
            while((strcmp(a,cho)!=0)||(strcmp(b,cho)!=0))
            {
                if(X.DeleteLine(a,b)==false)
                    cout<<"ɾ��ʧ�ܣ�"<<endl;
                else
                    cout<<"ɾ���ɹ���"<<endl;
                cout<<"������Ҫɾ��·�ߵ�����·��:(����end���˳�)"<<endl;
                cin>>a>>b;
            }
            X.Print();
        }
        if(ch=='D'||ch=='d')
        {
            char *cho="end";
            cout<<"������Ҫɾ����·�ɣ�(����end���˳�)"<<endl;
            char *i=new char[10];
            cin>>i;
            while(strcmp(i,cho)!=0)
            {
                if(X.DeleteRoute(i)==false)
                    cout<<"ɾ��ʧ��!"<<endl;
                else
                    cout<<"ɾ���ɹ���"<<endl;
                cout<<"������Ҫɾ����·�ɣ�(����end���˳�)"<<endl;
                cin>>i;
            }
            X.Print();
        }
        if(ch=='E'||ch=='e')
        {
            char *cho="end";
            cout<<"������Ҫ�鿴��·�ɱ��·��������(����end���˳�)"<<endl;
            char *i=new char[10];
            cin>>i;
            int distance[NumRoute];
            int minPath[NumRoute];
            while(strcmp(i,cho)!=0)
            {
                X.ShortminPath(i,distance,minPath);
                X.create_RouteTable(minPath,i);
                cout<<"������Ҫ�鿴��·�ɱ��·��������(����end���˳�)"<<endl;
                cin>>i;
            }
        }
    }
    return 0;
}
