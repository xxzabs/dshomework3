#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int Map[5][5];  //�����ͼ��С
int dir[4][2]= {1,0,-1,0,0,-1,0,1};  //���巽��
int n,m,ans;
struct node
{
    int x,y,step;

} now,nextt;  //�����߲�
int BFS(int x,int y)
{
    queue<node>q;
    int xx,yy,zz;
    Map[x][y]=2;  //�߹���ʼ��
    now.x=x;
    now.y=y;
    now.step=0;
    q.push(now);  //�ӵ�ǰ�㿪ʼ
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        for(int i=0; i<4; i++)  //�����ĸ�����
        {
            xx=now.x+dir[i][0];
            yy=now.y+dir[i][1];  //��һ��
            if(xx>=0&&xx<5&&yy>=0&&yy<5&&Map[xx][yy]!=1&&Map[xx][yy]!=2)  //������
            {
                nextt.x=xx;
                nextt.y=yy;
                nextt.step=now.step+1;  //������һ
                Map[now.x][now.y]=2;   //�߹�һ����
                if(Map[xx][yy]==3)  //�����յ�
                    return nextt.step;
                q.push(nextt);

            }
            for(int i=0; i<5; i++){      //��ӡ��ͼ
                for(int j=0; j<5; j++)
                    cout << Map[i][j];
                cout << endl;
            }
            cout << endl;
        }
    }
    return -1;   //�߲���ȥ
}

int main()
{

    for(int i=0; i<5; i++)     //�����ͼ
        for(int j=0; j<5; j++)
            cin >> Map[i][j];
    Map[4][4]=3;  //�����յ�
    ans=BFS(0,0);
    cout << ans<< endl;
    return 0;

}


