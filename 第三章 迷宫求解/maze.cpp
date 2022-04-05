/*****************
�������������һ���Թ����·������
����Ҫ�󣺸����Թ���ں��յ㣬���·��
		  �߲�ͨʱ����
		  ��Ҫ�����·��
���ݽṹ����ͨ�ṹ���ʾ�Թ��е�ÿ��С������˳��ջ������·��
******************/

#include <stdio.h>
#include<stdlib.h>
#include"database.h"
#include"maze.h"

#define M 8//����
#define N 8//����

int mg[10][10]= {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,0,0,0,0,1,1},
	{1,1,0,1,1,0,0,1,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,0,1,0,1,1,0,1},
	{1,1,0,1,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};//��ͼ
	
int main()
{
	if(mgpath(1,1,M,N) == 0)
		printf("�޽�");
	return 0;
}

int mgpath(int xi,int yi,int xe,int ye)//���·��Ϊ��(xi,yi)->(xe,ye)
{
	int i,j,k,di,find;
	StType st;//����ջst
	st.top=-1;//��ʼ��ջ��ָ��
	st.top++;//��ʼ�����ջ��topָ���1
	st.data[st.top].i=xi;
	st.data[st.top].j=yi;
	st.data[st.top].di=-1;//di��ʼ��Ϊ-1����ʾ��û�п�ʼ����һ�����ߵķ���
	mg[xi][yi]=-1;//��㲻���ظ�����
	while(st.top>-1)//ջ��Ϊ��ʱѭ��
	{
		i=st.data[st.top].i;
		j=st.data[st.top].j;
		di=st.data[st.top].di;//ȡջ������
		if(i==xe&&j==ye)//�ҵ����ڣ����·��
		{
			printf("�Թ�·�����£�\n");
			for(k=0; k<=st.top; k++)
			{
				printf("\t(%d,%d)",st.data[k].i,st.data[k].j);
				if((k+1)%6==0)
					printf("\n");
			}
			printf("\n");
			return 1;
		}
		find=0;//��û�ҵ���һ�����߷���
		while(di<4&&find==0)//����һ�����߷���
		{
			di++;
			switch(di)
			{
				/*��Ȼ�����㷨ֻ���յ����������·�ʱΪ��С·�����������ʱ����
				��Ϊÿ�ζ�������ȿ�ʼ�ң��������·����յ���˵��Ȼ��������*/
				case 0://��
					i=st.data[st.top].i-1;
					j=st.data[st.top].j;
					break;
				case 1://��
					i=st.data[st.top].i;
					j=st.data[st.top].j+1;
					break;
				case 2://��
					i=st.data[st.top].i+1;
					j=st.data[st.top].j;
					break;
				case 3://��
					i=st.data[st.top].i;
					j=st.data[st.top].j-1;
					break;
			}
			if(mg[i][j]==0)
				find=1;//����һ���������ڷ���
		}
		if(find==1)//�ҵ�����һ�����߷���
		{
			st.data[st.top].di=di;//�޸�ԭջ��Ԫ�ص�diֵ
			st.top++;//��һ�����߷����ջ
			st.data[st.top].i=i;
			st.data[st.top].j=j;
			st.data[st.top].di=-1;
			mg[i][j]=-1;//�����ظ��ߵ��÷���
		}
		else//û��·����������ջ
		{
			mg[st.data[st.top].i][st.data[st.top].j]=0;//�ø�λ�ñ�Ϊ����·�����߷���
			st.top--;//���÷�����ջ
		}
	}
	return 0;
}
