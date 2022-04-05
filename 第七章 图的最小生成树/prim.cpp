#include<stdio.h>

#define MAX 100
#define MAXCOST 0x7fffffff  //����intֵ

int graph[MAX][MAX];

void prim(int graph[][MAX], int n);

int main()
{
	int i, j, k, m, n;
	int x, y, cost;
	//freopen("1.txt","r",stdin);//�ļ�����
	printf("������������ͱߵ��������ÿո����\n");
	scanf("%d%d",&m,&n);//m=����ĸ�����n=�ߵĸ���
	printf("�����ڽӱ�������ͱߵ���Ϣ���ÿո����\n");
	for (i = 1; i <= m; i++)//��ʼ��ͼ
	{
		for (j = 1; j <= m; j++)
		{
			graph[i][j] = MAXCOST;//Ĭ�ϳ�ʼȨ��Ϊ�����
		}
	}
	for (k = 1; k <= n; k++)
	{
		scanf("%d%d%d",&i,&j,&cost);
		graph[i][j] = cost;
		graph[j][i] = cost;
	}

	prim(graph, m);
	return 0;
}

void prim(int graph[][MAX], int n)
{
	int lowcost[MAX];//lowcost[i]:��ʾ��iΪ�յ�ıߵ���СȨֵ,��lowcost[i]=0��ʾi�������MST
	int mst[MAX];//mst[i]:��ʾ��Ӧlowcost[i]����㣬��mst[i]=0��ʾ���i����MST
	int i, j, min, minid, sum = 0;
	for (i = 2; i <= n; i++)
	{
		lowcost[i] = graph[1][i];//lowcost��Ŷ���1�ɴ���·������
		mst[i] = 1;//��ʼ����1λ��ʼ��
	}
	mst[1] = 0;
	for (i = 2; i <= n; i++)
	{
		min = MAXCOST;
		minid = 0;

		for (j = 2; j <= n; j++)//�ҳ�Ȩֵ��̵�·�������Լ���С��ID
		{
			if (lowcost[j] < min && lowcost[j] != 0)
			{
				min = lowcost[j];
				minid = j; 
			}
		}

		printf("V%d-V%d=%d\n",mst[minid],minid,min);
		sum += min;//���
		lowcost[minid] = 0;//�ô����·����Ϊ0

		for (j = 2; j <= n; j++)//��������Dijkstra��˼����о���ġ��ɳڡ�
		{
			if (graph[minid][j] < lowcost[j])//����һ��ֱ��Ķ������·������
			{
				lowcost[j] = graph[minid][j];
				mst[j] = minid;
			}
		}

	}
	printf("��СȨֵ֮��=%d\n",sum);
}
