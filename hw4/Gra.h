#define MaxVertics 10

typedef struct
{
	int row;			//����±�
	int col;		    //�յ��±�
	int weight;			//Ȩֵ
}RowColWeight;	     	//����Ϣ���ɵ��ڽӾ��������Լ��ֶ�����ģ����㴫�ζ���

typedef struct
{					//ͼ���ڽӾ���ÿһ��Ϊ�ý�㵽��������Ȩ
	int size=0;
	int list[MaxVertics];	//ͼ����ָ��
}Node;						//��Ҳ������Ķ�������

class Graoh
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


