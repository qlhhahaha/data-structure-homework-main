#ifndef _DATABASE_H
#define _DATABASE_H

#define MAXSIZE 50

typedef struct
{
	int i,j;
	int e;
} Triple;

typedef struct
{
	int mu,nu,tu;//��������������0Ԫ�ظ���
	Triple data[MAXSIZE];
} RLSMatrix;

#endif
