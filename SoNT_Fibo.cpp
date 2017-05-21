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
	int fib1 = 1, fib2 = 1, fib = 2;
	while (fib1+fib2 <= max) 
	{ 
		fib = fib1 + fib2; 
		fib2 = fib1; 
		fib1 = fib; 
	}
	if( fib==max) return true;
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
