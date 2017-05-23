#include <stdio.h>
#define  maxN 100
int n;
bool check[maxN];
int a[maxN];

void Try(int id)
{
	if(id==n) // Du n phan tu
	{
		for(int i =0;i<n;i++)
		{
			printf("%d",a[i]);
			printf("\n");
			return;
		}
	}	
		for( int i =0;i<n;i++)
		{
			if(!check[i])// neu chua dat i
			{
				a[id] = i+1;
				check[i] = true;
				Try(id+1);
				check[i] = false;
			}
		}
	
}
int main()
{
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	{
		check[i] = false;
	}
	Try(0);
}
