#ifndef _DATABASE_H
#define _DATABASE_H

//ÿ�����һ���ṹ���ʾ
typedef struct
{
	float coef;//ϵ����ע��Ҫ��float
	int expn;//ָ��
} Term;

//����������ʾ����ʽ
typedef struct polynomial
{
	Term term;
	polynomial* next;
} polynomial,*LinkList;

#endif