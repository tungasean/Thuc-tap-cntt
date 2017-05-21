#include <iostream>
using namespace std;
int b[50];
int a[50][50];
	
int SoNTMax(int max)
{
	max = max+4;
	
	for(int i=2;i< max;i++)
	{
		if(max%i == 0) return false;
	}
	return true;
}
main ()
{
	int T;
	string d[50];
	int N;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>N;
		if(SoNTMax(N) == true){
				d[i] = "YES";
		}
		else d[i] = "NO";
	}
	for(int i=0;i<T;i++)
	{
		cout<<d[i]<<endl;
	}
	
	
}
