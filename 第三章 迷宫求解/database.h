#ifndef _DATABASE_H
#define _DATABASE_H

typedef struct
{
    int i;//��ǰ�����к�
    int j;//��ǰ�����к�
    int di;//��һ�����ߵ����ڷ���ķ�λ��
}Box;//���巽������

typedef struct
{
    Box data[100];//10*10���Թ�����������100��box
    int top;//ջ��ָ��
}StType;//����˳��ջ����
#endif
