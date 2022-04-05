/*****************
�������������һ��һԪϡ�����ʽ�򵥼�����
����Ҫ�����벢��������ʽ��
		  ��˳���������ʽ��
		  ����ʽ��ӡ���������
���ݽṹ������ͨ�ṹ���ʾ���ϵ����ָ�����������ʾ����ʽ
******************/

#include<stdio.h>
#include<stdlib.h>
#include"polynomial.h"
#include"database.h"

int main()
{
	LinkList L1,L2;
	int n1,n2;
	
	printf("���������ʽL1��������");
	scanf("%d",&n1);
	CreatPolyn(L1,n1);
	printf("���������ʽL2��������");
	scanf("%d",&n2);
	CreatPolyn(L2,n2);
	
	printf("\n����ʽL1:  ");
	visitList(L1);
	printf("\n����ʽL2:  ");
	visitList(L2);
	
	LinkList add,sub,multiply;
	InitList(add);
	InitList(sub);
	InitList(multiply);
	
	addPolyn(add,L1,L2);
	SubtracatPolyn(sub,L1,L2);
	multiplyPolyn(multiply,L1,L2);
	
	printf("\nL1 + L2:   ");
	visitList(add);
	printf("\nL1 - L2:   ");
	visitList(sub);
	printf("\nL1 * L2:   ");
	visitList(multiply);
}


void InitList(LinkList &L)
{
	//��ʼ������
	L= (polynomial*)malloc(sizeof(polynomial));//ͷ���
	L->term.coef=0.0;
	L->term.expn=-1;
	L->next=NULL;
}

int cmp(Term a,Term b)
{
	//�ȽϽ���ϵ����С����
	if(a.expn>b.expn) return -1;
	else if(a.expn==b.expn) return 0;
	else return 1;
}

void insertNode(LinkList &L,Term e)//���ս���˳�������Ĳ���
{
	//�����������ʽ������ʵ�λ�ã�����ͬʱ�𵽴�������Ͷ���ʽ��ӵĹ���
	
	polynomial* q=L;//����ָ��q����������ȥ�����ж�λ
	
	while(q->next!=NULL)//��q����β���ʱ
	{
		if(cmp(q->next->term,e)<0)//�����ǰ���q����һ������ָ�� ���� Ҫ����Ľ���ָ��
			q=q->next;//qָ����һ�����
		else break;//��ʱ�� q.term.expn>e.expn >=q->next->term.expn
	}
	//�������д�������ȷ��q��λ��
	
	if(q->next!=NULL && cmp(q->next->term,e)==0)   //ָ����ͬ��ϵ�����
	{
		q->next->term.coef+=e.coef;
	}
	else
	{
		polynomial* node =(polynomial*) malloc(sizeof(polynomial));//����һ���½��
		node->term.coef=e.coef;
		node->term.expn=e.expn;
		//����5�д�����Ǿ����������������
		if(q->next==NULL)
			node->next=NULL; //���q���Ϊβ��㣬��node��ָ������ΪNULL
		else
			node->next=q->next; //����node��ָ����ָ��q����һ�����
		q->next=node;//��node������������
	}
}

void CreatPolyn(LinkList &L,int m)
{
	//����m���ϵ����ָ����������ʾһԪ����ʽ����������L
	Term e;
	InitList(L);
	for(int i=1; i<=m; i++)
	{
		printf("\n��%d���ϵ����ָ�����ո�������س�ȷ�ϣ���",i);
		scanf("%f%d",&e.coef,&e.expn);
		insertNode(L,e);
	}
}

void addPolyn(LinkList &L,LinkList L1,LinkList L2)
{
	//��L����L1+L2�Ľ��
	polynomial* q;
	for(q=L1->next; q!=NULL; q=q->next)
	{
		insertNode(L,q->term);//��L1��ÿһ����뵽L��
	}
	for(q=L2->next; q!=NULL; q=q->next)   //��L2��ÿһ����뵽L��
	{
		insertNode(L,q->term);
	}
}

void SubtracatPolyn(LinkList &L,LinkList L1,LinkList L2)
{
	//��L����L1-L2�Ľ��
	polynomial* q;
	for(q=L1->next; q!=NULL; q=q->next)
	{
		insertNode(L,q->term);//��L1��ÿһ����뵽L��
	}
	for(q=L2->next; q!=NULL; q=q->next)
	{
		q->term.coef = -(q->term.coef); //��ϵ������෴��,�ٽ�����Ӳ�������ΪL1-L2
		insertNode(L,q->term);//��L2��ÿһ����뵽L��
	}
}

void multiplyPolyn(LinkList &L,LinkList L1,LinkList L2)
{
	//��L����L1*L2�Ľ��
	polynomial *p,*q;
	Term term;//һ����temp���õ���
	term.coef=0.0;
	term.expn=0;
	for(q=L1->next; q!=NULL; q=q->next)
	{
		for(p=L2->next; p!=NULL; p=p->next)
		{
			term.coef=(q->term.coef)*(p->term.coef);//ϵ�����
			term.expn=(q->term.expn)+(p->term.expn);// ָ�����
			insertNode(L,term);
		}
	}
}

void visitList(LinkList L)
{
	//������ѧ���ʽ����ʽ��ӡ���һԪ����ʽL��
	//��ָ������ϵ��Ϊ1������� ʡ��1
	polynomial* q=L;
	int flag;//��flag��¼ָ��Ϊ0��ϵ��Ϊ1��������������������flagΪ1
	while(q->next!=NULL)
	{
		q=q->next;
		flag=1;
		if(q->term.coef==0) continue;//ϵ��Ϊ0 �����
		if(q->term.expn==0&&flag==1)   //ָ��Ϊ0
		{
			if(q->term.coef>0)
				printf("+%.2f",q->term.coef);
			else
				printf("%.2f",q->term.coef);
			flag=0;
		}
		if((q->term.coef==1||q->term.coef==-1)&&flag==1)   //ϵ��Ϊ1
		{
			if(q->term.expn==1)
			{
				if(q->term.coef==1)
					printf("+X");
				else
					printf("-X");
			}
			else
			{
				if(q->term.coef==1)
					printf("+X^%d",q->term.expn);
				else
					printf("-X^%d",q->term.expn);
			}
			flag=0;
		}
		if(flag==1)
		{
			if(q->term.coef>0)
				printf("+%.2fX^%d",q->term.coef,q->term.expn);
			else
				printf("%.2fX^%d",q->term.coef,q->term.expn);
		}

	}
	printf("\n");
}
