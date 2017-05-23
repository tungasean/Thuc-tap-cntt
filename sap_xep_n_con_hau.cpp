#include <stdio.h>
#define  maxN 100
int n;
bool check[maxN];
int a[maxN];
bool Accect(int x1,int y1,int x2,int y2)
{
	if((x1+y1) == (x2+y2) || (x1-y1)==(x2-y2))
	return true;
	return false;
}

void Try(int id)
{
	if(id==n) // Du n phan tu
	{
	for(int i = 0; i <n;i++) //duyet vi tri cac con tro
		for(int j = i+1;j<n;j++)
		{
			//con hau thu i co toa do (a[i],i)
			//con hau thu i co toa do (a[j],j)
			if(a[i] - a[j] == i - j || a[i] +a[j] == i+j)
			return ;	
		}
		for(int i = 0;i<n;i++)
		{
			printf("(%d,%d);",i,a[i]);
		}
			printf("\n");
			return;
	}
		for( int i =0;i<n;i++)
		{
			if(!check[i])// neu chua dat i
			{
				bool ok = true;
				for(int j =0;j<id-1;j++)
				if(Accect(id,i,j,a[j]))
				{
					ok = false;
					break;
				}
				if(!ok) continue;
				a[id] = i;
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
