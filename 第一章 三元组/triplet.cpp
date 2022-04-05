#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"triplet.h"

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int elemtype;//����Ԫ�����಻һ��Ҫ��int�����ڴ˴�ֱ���޸�
typedef elemtype* triplet;//triplet����Ϊһ��ָ�뼴�ɣ����弸Ԫ��malloc����

int main(void)
{
	triplet T;
	init_triplet(T, 3, 4, 2);
	int num1, num2, num3; //������ų���������������Ԫ��
	get(T, 1, num1);
	get(T, 2, num2);
	get(T, 3, num3);
	print_triplet(T);//��ӡ��Ԫ��
	put(T, 2, 1);
	print_triplet(T); 
	if (is_ascending(T))
		printf("������������triplet��С�������У�\n");
	else if (is_descending(T))
		printf("������������triplet�ɴ�С���У�\n");
	else
		printf("���д�С�޹���\n");
	int big, small;//��¼���ֵ����Сֵ
	max(T, big);
	min(T, small);
	printf("���ֵΪ��%d����СֵΪ��%d\n", big, small);
	printf("�û����������Ԫ���������\n"); 
	getchar();
	destory_triplet(T);
	return 0;
}

int init_triplet(triplet &T,elemtype v1,elemtype v2,elemtype v3)
{
	T = (elemtype*)malloc(3*sizeof(elemtype));
	if(T == NULL)
	{
		printf("no enough memory");
		exit(OVERFLOW);
	}
	T[0] = v1;
	T[1] = v2;
	T[2] = v3;
	return OK;
}

int destory_triplet(triplet &T)
{
	free(T);
	T = NULL;
	printf("��Ԫ�����ٳɹ�"); 
	return OK;
}

int get(triplet T,int i,elemtype e)
{
	if(i<1 || i>3)
	{
		return ERROR;
	}
	e = T[i-1];
	return OK;
}

int put(triplet &T,int i,elemtype e)
{
	if(i<1 || i>3)
	{
		return ERROR;
	}
	T[i-1] = e;
	return OK;
}

int is_ascending(triplet T)
{
	return (T[0]<=T[1])&&(T[1]<=T[2]);//�߼���&&�����ã��ã�
}

int is_descending(triplet T)
{
	return (T[0]>=T[1])&&(T[1]>=T[2]);
}

int max(triplet T,elemtype &e)
{
	e = (T[0] > T[1] ? T[0] : T[1]) > (T[1] > T[2] ? T[1] : T[2]) ? (T[0] > T[1] ? T[0] : T[1]) : (T[1] > T[2] ? T[1] : T[2]);
	return OK;
}

int min(triplet T,elemtype &e)
{
	e = (T[0] < T[1] ? T[0] : T[1]) < (T[1] > T[2] ? T[1] : T[2]) ? (T[0] < T[1] ? T[0] : T[1]) : (T[1] < T[2] ? T[1] : T[2]);
	return OK;
}

int print_triplet(triplet T)
{
	int i = 0;
	printf("������������triplet��");
	for (i = 0; i < 3; i++)
		printf("%d ", T[i]);
	printf("\n");
	return OK;
}
