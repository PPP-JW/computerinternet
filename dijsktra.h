#ifndef DIJSKTRA_H_INCLUDED
#define DIJSKTRA_H_INCLUDED
#include <iostream>
#include "class.h"
void CreatNet::ShortminPath(char*v, int distance[], int minPath[])
{
    int n =Num;	//�������
    bool *S = new bool[n];

    int i, j, k, len,A;
    A=FindAddr(v);
    for (i = 0; i < n; i++)//��ʼ��
    {

        S[i] = false;

        distance[i] = getWeight(v, head[i].Routename);
        //cout<<distance[i]<<endl;

        if (i!= A&& distance[i] < maxValue)

            minPath[i] = A;

        else minPath[i] = -1;

    }

    S[A] = true;		//�ӵ�
    distance[A] = 0;
    for (i = 0; i < n - 1; i++)//����������·��
    {
        int B = maxValue;//*************************************
        int u=A;//ѡ����S�о������·���Ķ���u
        for (int j = 0; j < n; j++)
        {
//***********************************************
            if (S[j] == false && distance[j] < B)
            {
                u = j;
                B = distance[j];
            }
        }

        S[u] = true;
        for (k = 0; k < n; k++)
        {
            len = getWeight(head[u].Routename, head[k].Routename);

            if (S[k] == false && len < maxValue&&distance[u] + len< distance[k])//************************
            {
                distance[k] = distance[u] + len;
                minPath[k] = u;
            }
        }

//********}***************************************
        // }
    }
}


#endif // DIJSKTRA_H_INCLUDED
