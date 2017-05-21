#include <iostream>
using namespace std;
int SoNTMax(int max)
{
	 int count = 1;
	int nt1 = 1;
	int nt2 = 1;
	int h = 0;
	for(int i=2;i< max;i++)
	{
		if(max%i == 0) return false;
	}
	int a = 1;
	int b = 1;
	while (a <= max)
	{ 
		b = b*a;
		a++;
		if(b == (max -1) || b == (max + 1))
		{
			return true;
		}
	}
	   return false;
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
