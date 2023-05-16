#include <iostream>

#define Endless 9999

using namespace std;

#define MaxVertics 10

typedef struct
{
	int row;			//起点下标
	int col;		    //终点下标
	int weight;			//权值
}   RowColWeight;	     	//边信息构成的邻接矩阵，这是自己手动输入的，方便传参而已

typedef struct
{					//图的邻接矩阵，每一行为该结点到其他结点的权
    int data; 
	int size=0;
	int list[MaxVertics];	//图结点的指向
}Node;						//这也是输入的顶点序列

class Graph
{
public:
	Node Vertic;// = NULL;
	int edge[MaxVertics][MaxVertics];	//最大10*10的邻接矩阵,二维矩阵声明在这个图内部
	int nums_edge;						//边个数
	//int Versize;						//顶点个数

public:
	void InitGra();								//初始化图
	int IsVertex(int vertex);					//图中是否存在顶点vertex
	void InsertVertex(int vertex);				//插入顶点vertex
	int ListVerAdd(Node Ver, int size, int v);  //把顶点V插入图的顶点数组最后

	int IsEdge(int i, int j);								//图的顶点序列中第i个点与第j个点之间是否有边
	void InsertEdge(int i, int j, int weight);			//在两点间插入边
	void GraphCreat(int *v, int n, RowColWeight *W, int e); //新建图
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
			this->edge[i][j] = Endless;		//初始化让邻接矩阵中有无穷大
			if(i==j)
			{
				this->edge[i][j] = 0; 
			}
		}
	}
}

int Graph::IsVertex( int vertex)
/*判断顶点vertex是否是有向图G的顶点，是则返回顶点在顶点顺序表中的序号，否则返回-1。*/
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
/*在带权有向图G中插入顶点vertex。如果图中已经有顶点vertex，则图不变。*/
{
	if (this->IsVertex(vertex) < 0)//O(n)
	{						  //在顶点顺序表的表尾插入顶点vertex
		//this->Vertic = new Node();
		
		
		this->Vertic.list[this->Vertic.size] = vertex;
		this->Vertic.size += 1;
	}
}

int Graph::IsEdge(int i, int j)
/*判断图的顶点序列第i个顶点到第j个顶点是否有边，是则返回1，否则返回0。 */
{
	if (this->edge[i][j] == Endless || i == j)
	{
		//cout<<"该边不存在！\n";
		return 0;
	}
	return 1;
}

void Graph::InsertEdge( int i, int j, int weight)
/* 在带权有向图G中插入一条第v1个顶点指向第v2个顶点，权值为weight的有向边。如果v1和v2有一个不是图中的顶点，则图不变；如果v1和v2相等，则图不变。如果图已经包含该边，则边的权值更改为新的权值。*/
{
	
	if (this->IsEdge(i, j) == 1)
	{
		cout<<"插入边时出错,已经有边了！";
			exit(1);
	}
	this->edge[i][j] = weight;
	this->nums_edge++;
}

void Graph::GraphCreat(int *v, int n, RowColWeight *W, int e)
/*创建有n个顶点和e条边的带权有向图G。v[]、W[]是提前写好的顶点数组和边信息对象*/
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
	int v[3] = {15,20,30};   //提前定义三个顶点
	cout << "输入图的边数\t";
	int n;
	cin >> n;
	RowColWeight *W=new RowColWeight[n];
	
	
	for (int a = 0; a < n;a++)
	{
		cout << "输入权重的边两端点(以该点在顶点序列中的顺序为名)\t";
		cin >> W[a].row >> W[a].col;
		cout << "输入权重\t";
		cin >> W[a].weight;
	}
	G.InitGra();
	G.GraphCreat( v, 3, W, n);		//这里第二个参数是数组点的个数，上面声明了点数组
	return 0;
}

