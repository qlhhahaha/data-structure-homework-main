#include <stdio.h>
#define MAXE 100
#define MAXV 100

typedef struct
{
	int vex1;                     //�ߵ���ʼ����
	int vex2;                      //�ߵ���ֹ����
	int weight;                    //�ߵ�Ȩֵ
} Edge;

void kruskal(Edge E[],int n,int e); 
int fun(Edge arr[],int low,int high);
void quick_sort(Edge arr[],int start,int end);

int main()
{
	Edge E[MAXE];
	int nume,numn,i;
	//freopen("1.txt","r",stdin);//�ļ�����
	printf("���붥���ͱ���(�ո�������س�ȷ��):\n���Խ���������Ϊ����4��6�ߣ�\n");
	scanf("%d%d",&numn,&nume);
	for(i=0; i<nume; i++)
		scanf("%d%d%d",&E[i].vex1,&E[i].vex2,&E[i].weight);
	quick_sort(E,0,nume-1);//���ÿ���������ߵ�Ȩ������
	kruskal(E,numn,nume);
	return 0;
}

void kruskal(Edge E[],int n,int e)
{
	int i,j,m1,m2,sn1,sn2,k,sum=0;
	int vset[n+1];//����һ����������vset[i]�����ж�ĳ���Ƿ��������С����������
	for(i=1; i<=n; i++)      //��ʼ����������
		vset[i]=i;
	k=1;//��ʾ��ǰ������С�������ĵ�k���ߣ���ֵΪ1
	j=0;//E�бߵ��±꣬��ֵΪ0
	while(k<e)//���ɵı���С��eʱ����ѭ��
	{
		m1=E[j].vex1;
		m2=E[j].vex2;//ȡһ���ߵ������ڽӵ�
		sn1=vset[m1];
		sn2=vset[m2];
		//�ֱ�õ��������������ļ��ϱ��
		if(sn1!=sn2)//����������ڲ�ͬ�ļ��ϣ��ñ�����С��������һ����
		{
			//��ֹ���ֱպϻ�·
			printf("V%d-V%d=%d\n",m1,m2,E[j].weight);
			sum+=E[j].weight;
			k++;                //���ɱ�������
			if(k>=n)
				break;
			for(i=1; i<=n; i++)  //��������ͳһ���
				if (vset[i]==sn2)  //���ϱ��Ϊsn2�ĸ�Ϊsn1
					vset[i]=sn1;
		}
		j++;                  //ɨ����һ����
	}
	printf("��СȨֵ֮��=%d\n",sum);
}

void quick_sort(Edge arr[],int start,int end)
{
	int pos;
	if(start<end)
	{
		pos=fun(arr,start,end);
		quick_sort(arr,start,pos-1);
		quick_sort(arr,pos+1,end);
	}
}

int fun(Edge arr[],int low,int high)
{
	int key;
	Edge lowx;
	lowx=arr[low];
	key=arr[low].weight;
	while(low<high)
	{
		while(low<high && arr[high].weight>=key)
			high--;
		if(low<high)
			arr[low++]=arr[high];

		while(low<high && arr[low].weight<=key)
			low++;
		if(low<high)
			arr[high--]=arr[low];
	}
	arr[low]=lowx;
	return low;
}
