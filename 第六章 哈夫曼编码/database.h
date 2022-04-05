#ifndef _DATABASE_H
#define _DATABASE_H

#define MAXBIT      100
#define MAXVALUE  10000
#define MAXLEAF     30
#define MAXNODE    MAXLEAF*2 -1

typedef struct
{
	int bit[MAXBIT];
	int start;
} HCodeType;        /* ����ṹ�� */

typedef struct
{
	int weight;
	int parent;
	int lchild;
	int rchild;
	int value;
} HNodeType;        /* ���ṹ�� */

#endif
