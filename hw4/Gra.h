#define MaxVertics 10

typedef struct
{
	int row;			//起点下标
	int col;		    //终点下标
	int weight;			//权值
}RowColWeight;	     	//边信息构成的邻接矩阵，这是自己手动输入的，方便传参而已

typedef struct
{					//图的邻接矩阵，每一行为该结点到其他结点的权
	int size=0;
	int list[MaxVertics];	//图结点的指向
}Node;						//这也是输入的顶点序列

class Graoh
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


