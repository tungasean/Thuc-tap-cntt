#include <iostream>

using namespace std;

long algo1(int *a,int n)
{
	//int n = a.length;
	long max = a[0];
	for(int i = 0; i <n; i ++)
	{
		for(int j = i; j<n;j++)
		{
			int s =0;
			for(int k = i;k<=j;k++)
				s=s+a[k];
				max = max <s ? s: max;
		}
	}
	return max;
}

main()
{
	int a[] = {2,3,5,23,5,3,7};
	long max = algo1(a,7);
	cout<<max<<endl;
	//system("PAUSE");
}
