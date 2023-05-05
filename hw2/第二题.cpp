#include<iostream>
#include<stdio.h>
#include<stdlib.h>
int min(int temp[],int lo,int hi)
{
	int _min=0x7fffffff;
	for(lo;lo<hi;lo++)if(temp[lo]<_min)_min=temp[lo];
	return _min;
}
int main()
{
	freopen("输出结果.txt","w",stdout);
	int i,j;
	int a[1024];
	for(int flag=0;flag<10;flag++)
	{
		int len=rand()%104+1;
		int max=-1;
		for(i=0;i<len;i++)a[i]=rand()%104;
		printf("数组%d:\n",flag);
		for(int x=0;x<len;x++)printf("%d ",a[x]);
		for(i=1;i<=len;i++)
			for(j=0;j<=len-i;j++)
			{
				int c=min(a,j,j+i);
				if(max < c * i )max=c*i;
			}
		
		printf("\n%d\n",max);
	}
	return 0;
}
