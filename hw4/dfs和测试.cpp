#include<iostream>
using namespace std;
	
int k[3][3] = {1,2,3,4,5,6,7,8,9};
//关卡标号 
int square[3][3]={0};
//3*3的方格 
int x[4] = {0,1,0,-1};
int y[4] = {1,0,-1,0};
//记录下一步的坐标，x为水平，y为垂直，默认左上为正方向，搜索顺序为右下左上 
int total;
//int型默认值为0
 
void dfs(int xi,int yi,int step,string s)
{
	int tx,ty;
	//保存下一关卡坐标 
	if(step == 9)
	{
		total++;
		//9个关卡闯关完成为一条闯关路线，路线计数+1 
		cout<<"第"<<total<<"条搜闯关路线为： "<<s<<endl;
		//输出每条路线的具体闯关标号顺序 
		return ;
		//结束本层递归函数返回上一层 
	}
	for(int i=0;i<4;i++)//i<4因为四个方向，数组下标0开始 
	{
		tx = xi + x[i];
		ty = yi + y[i];
		//保存下一个关卡的坐标 
		if(tx<0||tx>=3||ty<0||ty>=3)
			continue;
			//如果下一关卡在地图外则跳过换一个方向 
		if(square[tx][ty]==1)
			continue;
			//如果下一关卡已经成功闯关则换一个方向 
		square[tx][ty]=1;
		//闯关本关，我更愿意理解为种草（要问就是1像草） 
		dfs(tx,ty,step+1,s+"->"+char('0'+k[tx][ty]));
		//递归，注意每次递归step+1指种草数 
		square[tx][ty]=0;
		//拔草 
	}
}
int main()
{
	square[0][0]=1;
	//从第一关开始 
	dfs(0,0,1,"1");
	//string s赋值1从第一关开始记路线 
	cout<<"一共"<<total<<"条闯关路线";
	return 0;            
}
