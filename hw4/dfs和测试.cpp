#include<iostream>
using namespace std;
	
int k[3][3] = {1,2,3,4,5,6,7,8,9};
//�ؿ���� 
int square[3][3]={0};
//3*3�ķ��� 
int x[4] = {0,1,0,-1};
int y[4] = {1,0,-1,0};
//��¼��һ�������꣬xΪˮƽ��yΪ��ֱ��Ĭ������Ϊ����������˳��Ϊ�������� 
int total;
//int��Ĭ��ֵΪ0
 
void dfs(int xi,int yi,int step,string s)
{
	int tx,ty;
	//������һ�ؿ����� 
	if(step == 9)
	{
		total++;
		//9���ؿ��������Ϊһ������·�ߣ�·�߼���+1 
		cout<<"��"<<total<<"���Ѵ���·��Ϊ�� "<<s<<endl;
		//���ÿ��·�ߵľ��崳�ر��˳�� 
		return ;
		//��������ݹ麯��������һ�� 
	}
	for(int i=0;i<4;i++)//i<4��Ϊ�ĸ����������±�0��ʼ 
	{
		tx = xi + x[i];
		ty = yi + y[i];
		//������һ���ؿ������� 
		if(tx<0||tx>=3||ty<0||ty>=3)
			continue;
			//�����һ�ؿ��ڵ�ͼ����������һ������ 
		if(square[tx][ty]==1)
			continue;
			//�����һ�ؿ��Ѿ��ɹ�������һ������ 
		square[tx][ty]=1;
		//���ر��أ��Ҹ�Ը�����Ϊ�ֲݣ�Ҫ�ʾ���1��ݣ� 
		dfs(tx,ty,step+1,s+"->"+char('0'+k[tx][ty]));
		//�ݹ飬ע��ÿ�εݹ�step+1ָ�ֲ��� 
		square[tx][ty]=0;
		//�β� 
	}
}
int main()
{
	square[0][0]=1;
	//�ӵ�һ�ؿ�ʼ 
	dfs(0,0,1,"1");
	//string s��ֵ1�ӵ�һ�ؿ�ʼ��·�� 
	cout<<"һ��"<<total<<"������·��";
	return 0;            
}
