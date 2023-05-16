#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int Map[5][5];  //定义地图大小
int dir[4][2]= {1,0,-1,0,0,-1,0,1};  //定义方向
int n,m,ans;
struct node
{
    int x,y,step;

} now,nextt;  //保存走步
int BFS(int x,int y)
{
    queue<node>q;
    int xx,yy,zz;
    Map[x][y]=2;  //走过初始点
    now.x=x;
    now.y=y;
    now.step=0;
    q.push(now);  //从当前点开始
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        for(int i=0; i<4; i++)  //遍历四个方向
        {
            xx=now.x+dir[i][0];
            yy=now.y+dir[i][1];  //走一步
            if(xx>=0&&xx<5&&yy>=0&&yy<5&&Map[xx][yy]!=1&&Map[xx][yy]!=2)  //可以走
            {
                nextt.x=xx;
                nextt.y=yy;
                nextt.step=now.step+1;  //步数加一
                Map[now.x][now.y]=2;   //走过一个点
                if(Map[xx][yy]==3)  //到达终点
                    return nextt.step;
                q.push(nextt);

            }
            for(int i=0; i<5; i++){      //打印地图
                for(int j=0; j<5; j++)
                    cout << Map[i][j];
                cout << endl;
            }
            cout << endl;
        }
    }
    return -1;   //走不过去
}

int main()
{

    for(int i=0; i<5; i++)     //输入地图
        for(int j=0; j<5; j++)
            cin >> Map[i][j];
    Map[4][4]=3;  //定义终点
    ans=BFS(0,0);
    cout << ans<< endl;
    return 0;

}


