/*****************
�������������һ��ϡ�����������
����Ҫ��������󣬿��Խ���ת�á��Ӽ������
���ݽṹ������Ԫ�鴢��ÿһ������Ԫ������Ԫ�����ϡ�����
******************/

#include<stdio.h>
#include"matrix.h"
#include"database.h"

#define MAXSIZE 50

int main()
{
	int i;
	printf("ϡ�����������:\n");
	printf("1-����ת��\n");
	printf("2-����ӷ�\n");
	printf("3-�������\n");
	printf("4-����˷�\n");
	printf("0-�˳�\n");
	printf("������ѡ��0,1,2,3,4:\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
			Transfer();
			break;
		case 2:
			Count(i);
			break;
		case 3:
			Count(i);
			break;
		case 4:
			Multiplication();
			break;
		case 0:
			break;
	}
	return 0;
}

void Input(RLSMatrix &M)
{
	//��Ԫ�����뺯��
	printf("*********************\n");
	printf("��������������:");
	scanf("%d",&M.mu);
	printf("�������������:");
	scanf("%d",&M.nu);
	printf("������Ϊ���򣨴�1��ʼ��������Ԫ�鷽ʽ�������Ԫ�أ��ո�������س�ȷ�ϣ���'0 0 0'��������:\n");
	for(M.tu=0; ; M.tu++)
	{
		printf("%d : ",M.tu+1);
		scanf("%d%d%d",&M.data[M.tu].i,&M.data[M.tu].j,&M.data[M.tu].e);
		if((M.data[M.tu].i==0)&&(M.data[M.tu].j==0)&&(M.data[M.tu].e==0))  break;
	}
}

void Transfer()
{
	//����ת������
	int row,line,col,p,q,k,h;
	RLSMatrix M,T;//����ԭ�����ת�þ���
	printf("�����ת��:\n");
	Input(M);
	printf("ת�ú�ľ���Ϊ:\n");
	T.mu=M.nu;
	T.nu=M.mu;
	T.tu=M.tu;//���н�������������

	if(T.tu)
	{
		q=0;
		for(col=1; col<=M.nu; ++col)
			for(p=0; p<=M.tu; ++p)
				if(M.data[p].j==col)//�ҵ�M������һ���ϵ�Ԫ�أ������Ǹ���T��ӦԪ��
				{
					T.data[q].i=M.data[p].j;
					T.data[q].j=M.data[p].i;
					T.data[q].e=M.data[p].e;
					++q;
				}
	}

	for(row=1; row<=T.mu; row++)
	{
		for(line=1; line<=T.nu; line++)
		{
			for(k=0,h=0; k<T.tu; k++)
			{
				if((T.data[k].i==row)&&(T.data[k].j==line))
				{
					printf("%d ",T.data[k].e);
					h++;
					break;
				}
			}
			if(h==0) printf("0 ");
		}
		printf("\n");
	}
}//Transfer

void Count(int i)
{
	//����ӷ��ͼ����ĺ���
	int row,line,p,q,k,h;
	RLSMatrix M1,M2;

	if(i==2)  printf("����ļӷ�:\n");
	else printf("����ļ���:\n");

	printf("=================\n");
	printf("�������һ������:\n");
	Input(M1);
	printf("������ڶ�������:\n");
	Input(M2);

	if(i==2)  printf("����ӷ��Ľ��Ϊ:\n");
	else printf("��������Ľ��Ϊ:\n");
	if(M1.nu!=M2.nu||M1.mu!=M2.mu)
	{
		printf("ERROR!\n");
		return;
	}
	else
	{
		for(row=1; row<=M1.mu; row++)
		{
			for(line=1; line<=M1.nu; line++)
			{
				for(k=0,h=0; k<M1.tu; k++)
				{
					if((M1.data[k].i==row)&&(M1.data[k].j==line))
					{
						p=M1.data[k].e;
						h++;
						break;
					}
				}
				if(h==0)  p=0;
				for(k=0,h=0; k<M2.tu; k++)
				{
					if((M2.data[k].i==row)&&(M2.data[k].j==line))
					{
						q=M2.data[k].e;
						h++;
						break;
					}
				}
				if(h==0)q=0;
				if(i==2)printf("%d ",p+q);
				else printf("%d ",p-q);
			}
			printf("\n");
		}
	}
}//Add

int Find(RLSMatrix M,int i,int j)
{
	//����Ԫ�����ҵ�ָ��λ���ϵ�Ԫ����������
	int t;
	for(t=0; t<M.tu; t++)
	{
		if((M.data[t].i==i)&&(M.data[t].j==j))return M.data[t].e;
	}
	return 0;
}//Find

void Multiplication()
{
	int row,line,p,q,k,L;
	RLSMatrix M1,M2;
	printf("����˷�:\n");
	printf("======================\n");
	printf("�������һ������:\n");
	Input(M1);
	printf("������ڶ�������:\n");
	Input(M2);
	printf("����˷��Ľ��Ϊ:\n");
	if(M1.nu!=M2.mu)
	{
		printf("ERROR!\n");
		return;1
	}
	else
	{
		for(row=1; row<=M1.mu; row++)
		{
			for(line=1; line<=M2.nu; line++)
			{
				L=0;
				for(k=1; k<=M1.nu; k++)
				{
					p=Find(M1,row,k);
					q=Find(M2,k,line);
					L=L+p*q;
				}
				printf("%d ",L);
			}
			printf("\n");
		}
	}
}
