#ifndef _TRIPLET_H
#define _TRIPLET_H

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int elemtype;//����Ԫ�����಻һ��Ҫ��int�����ڴ˴�ֱ���޸�
typedef elemtype* triplet;//triplet����Ϊһ��ָ�뼴�ɣ����弸Ԫ��malloc����

int init_triplet(triplet &T,elemtype v1,elemtype v2,elemtype v3);
//������Ԫ��

int destory_triplet(triplet &T);
//�ݻ���Ԫ��

int get(triplet T,int i,elemtype e);
//��e����T�ĵ�i��Ԫ�ص�ֵ

int put(triplet &T,int i,elemtype e);
//��T�ĵ�i��Ԫ�ص�ֵ�ı�Ϊe

int is_ascending(triplet T);
//����ǰ������������򷵻�1����֮����0

int is_descending(triplet T);
//��������return 1������0
 
int max(triplet T,elemtype &e);
//��e����max

int min(triplet T,elemtype &e);
//��e����min

int print_triplet(triplet T);

#endif
