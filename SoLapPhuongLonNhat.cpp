#include <iostream>
#include <math.h>
using namespace std;
int SoNTMax(int max)
{
	if(max > 2)
	for(int i = 1; i < max;i++)
	{
		if(pow(i,3)> max) return i-1;
	}
	else return 1;
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
		d[i] = SoNTMax(N);
	}
	for(int i=0;i<T;i++)
	{
		cout<<d[i]<<endl;
	}
	
	
}
