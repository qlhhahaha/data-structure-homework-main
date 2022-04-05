/*****************
�������������huffman�ı������ͽ�����
����Ҫ�������ַ���Ȩ�أ�����huffman�������б���������
���ݽṹ������ͽ�㶼����ͨ�ṹ�����洢�����������Ȩ������һ�ù�������
******************/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"database.h"
#include"huffman.h"

//������ز����ı߽�
#define MAXBIT      100
#define MAXVALUE  10000
#define MAXLEAF     30 //Ҷ�ӽ����=�������
#define MAXNODE    MAXLEAF*2 -1


int main(void)
{

	HNodeType HuffNode[MAXNODE];            /* ����һ�����ṹ������ */
	HCodeType HuffCode[MAXLEAF],  cd;       /* ����һ������ṹ�����飬 ͬʱ����һ����ʱ���������������ʱ����Ϣ */
	int i, j, c, p, n;
	char pp[100];
	printf ("�������ĸ���:\n");
	scanf ("%d", &n);
	HuffmanTree (HuffNode, n);


	for (i=0; i < n; i++)
	{
		cd.start = n-1;
		c = i;
		p = HuffNode[c].parent;
		while (p != -1)   /* �������� */
		{
			if (HuffNode[p].lchild == c)
				cd.bit[cd.start] = 0;
			else
				cd.bit[cd.start] = 1;
			cd.start--;        /* �����ĵ�һλ */
			c=p;
			p=HuffNode[c].parent;    /* ������һѭ������ */
		} 

		/* ���������ÿ��Ҷ���Ĺ���������ͱ������ʼλ */
		for (j=cd.start+1; j<n; j++)
		{
			HuffCode[i].bit[j] = cd.bit[j];
		}
		HuffCode[i].start = cd.start;
	}

	/* ����ѱ���õ����д��ڱ���Ĺ��������� */
	for (i=0; i<n; i++)
	{
		printf ("%c��huffman������: ", i+65);
		for (j=HuffCode[i].start+1; j < n; j++)
		{
			printf ("%d", HuffCode[i].bit[j]);
		}
		printf(" start:%d",HuffCode[i].start);

		printf ("\n");

	}

	printf("��������Ҫ�Ľ�����Ϣ:\n");
	scanf("%s",&pp);
	decodeing(pp,HuffNode,n);
	getchar();
	return 0;
}

/* ����һ�Ź������� */
void HuffmanTree (HNodeType HuffNode[MAXNODE],int n)
{
	/*m1��m2���������������ͬ������������СȨֵ����Ȩֵ��
	  x1��x2���������������ͬ������������СȨֵ����������е���š�*/
	int i, j, m1, m2, x1, x2;
	/* ��ʼ����Ź����������� HuffNode[] �еĽ�� */
	for (i=0; i<2*n-1; i++)
	{
		HuffNode[i].weight = 0;//Ȩֵ
		HuffNode[i].parent =-1;
		HuffNode[i].lchild =-1;
		HuffNode[i].rchild =-1;
		HuffNode[i].value=i; //ʵ��ֵ���ɸ�������滻Ϊ��ĸ
	} 

	/* ���� n ��Ҷ�ӽ���Ȩֵ */
	for (i=0; i<n; i++)
	{
		printf ("��������������Ȩ��(������һ�����س�ȷ��һ��) \n%c: ", i+65);
		scanf ("%d", &HuffNode[i].weight);
	}

	/* ѭ������ Huffman �� */
	for (i=0; i<n-1; i++)
	{
		m1=m2=MAXVALUE;     /* m1��m2�д�������޸�����ҽ��Ȩֵ��С��������� */
		x1=x2=0;
		/* �ҳ����н����Ȩֵ��С���޸�����������㣬���ϲ�֮Ϊһ�Ŷ����� */
		for (j=0; j<n+i; j++)
		{
			if (HuffNode[j].weight < m1 && HuffNode[j].parent==-1)
			{
				m2=m1;
				x2=x1;
				m1=HuffNode[j].weight;
				x1=j;
			}
			else if (HuffNode[j].weight < m2 && HuffNode[j].parent==-1)
			{
				m2=HuffNode[j].weight;
				x2=j;
			}
		}
		/* �����ҵ��������ӽ�� x1��x2 �ĸ������Ϣ */
		HuffNode[x1].parent  = n+i;
		HuffNode[x2].parent  = n+i;
		HuffNode[n+i].weight = HuffNode[x1].weight + HuffNode[x2].weight;
		HuffNode[n+i].lchild = x1;
		HuffNode[n+i].rchild = x2;

		printf ("x1.weight and x2.weight in round %d: %d, %d\n", i+1, HuffNode[x1].weight, HuffNode[x2].weight);  /* ���ڲ��� */
		printf ("\n");
	}
} 

//����
void decodeing(char string[],HNodeType Buf[],int Num)
{
	int i,tmp=0,code[1024];
	int m=2*Num-1;
	char *nump;
	char num[1024];
	for(i=0; i<strlen(string); i++)
	{
		if(string[i]=='0')
			num[i]=0;
		else
			num[i]=1;
	}
	i=0;
	nump=&num[0];

	while(nump<(&num[strlen(string)]))
	{
		tmp=m-1;
		while((Buf[tmp].lchild!=-1)&&(Buf[tmp].rchild!=-1))
		{

			if(*nump==0)
			{
				tmp=Buf[tmp].lchild ;
			}
			else tmp=Buf[tmp].rchild;
			nump++;

		}

		printf("%c",Buf[tmp].value + 65);
	}
}
