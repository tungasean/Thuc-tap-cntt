#include <iostream>
#include <stdio.h>
using namespace std;
int b[50];
int a[50][50];
	
int quantyMax(int T,int N)
{
	for(int t =0; t < T;t++)
	{
		b[t] = 0;
		for(int i = 0; i < N; i ++)
		{
			for(int j = i; j< N ;j++)
			{
				int s =0;
				for(int k = i;k<=j;k++)
					s=s+a[t][k];
					b[t] = b[t] < s ? s: b[t];
			}
		}
		return b;
	}	
}
main ()
{
	int c;
	int T;
	int N;
	cin>>T;
	cin>>N;
	for(int i=0;i<T;i++)
	{
		for(int j =0; j<N;j++)
		{
			cin>>a[i][j];
		}
	}
	c= quantyMax(T,N);
	cout<<c<<endl;
	
}
