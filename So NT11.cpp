#include <iostream>
using namespace std;
int b[50];
int a[50][50];
	
int SoNTMax(int max)
{
	int maxNt = 1;
	
	for(int i=1;i<= max;i++)
	{
		bool is = true;
		for(int j=2;j<i;j++)
		{
			if(i%j == 0) is = false;
		}
		if(is == true) maxNt = i;
	}
	return maxNt;
}
main ()
{
	int T;
	int d[50];
	int N;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>N;
		d[i]= SoNTMax(N);
	}
	for(int i=0;i<T;i++)
	{
		cout<<d[i]<<endl;
	}
	
	
}
