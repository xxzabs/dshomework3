#include <iostream>

#define Endless 9999

using namespace std;

#define MaxVertics 10

typedef struct
{
	int row;			//����±�
	int col;		    //�յ��±�
	int weight;			//Ȩֵ
}   RowColWeight;	     	//����Ϣ���ɵ��ڽӾ��������Լ��ֶ�����ģ����㴫�ζ���

typedef struct
{					//ͼ���ڽӾ���ÿһ��Ϊ�ý�㵽��������Ȩ
    int data; 
	int size=0;
	int list[MaxVertics];	//ͼ����ָ��
}Node;						//��Ҳ������Ķ�������

class Graph
{
public:
	Node Vertic;// = NULL;
	int edge[MaxVertics][MaxVertics];	//���10*10���ڽӾ���,��ά�������������ͼ�ڲ�
	int nums_edge;						//�߸���
	//int Versize;						//�������

public:
	void InitGra();								//��ʼ��ͼ
	int IsVertex(int vertex);					//ͼ���Ƿ���ڶ���vertex
	void InsertVertex(int vertex);				//���붥��vertex
	int ListVerAdd(Node Ver, int size, int v);  //�Ѷ���V����ͼ�Ķ����������

	int IsEdge(int i, int j);								//ͼ�Ķ��������е�i�������j����֮���Ƿ��б�
	void InsertEdge(int i, int j, int weight);			//�����������
	void GraphCreat(int *v, int n, RowColWeight *W, int e); //�½�ͼ
};


void Graph::InitGra()
{
	this->Vertic.size = 0;
	this->nums_edge = 0;
	//this->Vertic = new Node[10];
	for (int i = 0; i < MaxVertics; i++)
	{
		for (int j = 0; j < MaxVertics; j++)
		{
			this->edge[i][j] = Endless;		//��ʼ�����ڽӾ������������
			if(i==j)
			{
				this->edge[i][j] = 0; 
			}
		}
	}
}

int Graph::IsVertex( int vertex)
/*�ж϶���vertex�Ƿ�������ͼG�Ķ��㣬���򷵻ض����ڶ���˳����е���ţ����򷵻�-1��*/
{
	int i;
	for (i = 0; i<this->Vertic.size; i++)
	{
		if (this->Vertic.data == vertex)
			break;
	}
	if (i == this->Vertic.size)
		return -1;
	else
		return i;
}

void Graph::InsertVertex(int vertex)
/*�ڴ�Ȩ����ͼG�в��붥��vertex�����ͼ���Ѿ��ж���vertex����ͼ���䡣*/
{
	if (this->IsVertex(vertex) < 0)//O(n)
	{						  //�ڶ���˳���ı�β���붥��vertex
		//this->Vertic = new Node();
		
		
		this->Vertic.list[this->Vertic.size] = vertex;
		this->Vertic.size += 1;
	}
}

int Graph::IsEdge(int i, int j)
/*�ж�ͼ�Ķ������е�i�����㵽��j�������Ƿ��бߣ����򷵻�1�����򷵻�0�� */
{
	if (this->edge[i][j] == Endless || i == j)
	{
		//cout<<"�ñ߲����ڣ�\n";
		return 0;
	}
	return 1;
}

void Graph::InsertEdge( int i, int j, int weight)
/* �ڴ�Ȩ����ͼG�в���һ����v1������ָ���v2�����㣬ȨֵΪweight������ߡ����v1��v2��һ������ͼ�еĶ��㣬��ͼ���䣻���v1��v2��ȣ���ͼ���䡣���ͼ�Ѿ������ñߣ���ߵ�Ȩֵ����Ϊ�µ�Ȩֵ��*/
{
	
	if (this->IsEdge(i, j) == 1)
	{
		cout<<"�����ʱ����,�Ѿ��б��ˣ�";
			exit(1);
	}
	this->edge[i][j] = weight;
	this->nums_edge++;
}

void Graph::GraphCreat(int *v, int n, RowColWeight *W, int e)
/*������n�������e���ߵĴ�Ȩ����ͼG��v[]��W[]����ǰд�õĶ�������ͱ���Ϣ����*/
{
	int i, k;
	this->InitGra();
	for (i = 0; i<n; i++)
		this->InsertVertex(v[i]);
	for (k = 0; k<e; k++)
		this->InsertEdge(W[k].row, W[k].col, W[k].weight);
}
			
int main()
{
	Graph G;
	int v[3] = {15,20,30};   //��ǰ������������
	cout << "����ͼ�ı���\t";
	int n;
	cin >> n;
	RowColWeight *W=new RowColWeight[n];
	
	
	for (int a = 0; a < n;a++)
	{
		cout << "����Ȩ�صı����˵�(�Ըõ��ڶ��������е�˳��Ϊ��)\t";
		cin >> W[a].row >> W[a].col;
		cout << "����Ȩ��\t";
		cin >> W[a].weight;
	}
	G.InitGra();
	G.GraphCreat( v, 3, W, n);		//����ڶ��������������ĸ��������������˵�����
	return 0;
}

