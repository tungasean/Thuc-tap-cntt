#include <iostream>
#include <stdio.h>
#include <sstream>

using namespace std;

string XuLyKyTu(int count,char s[2000])
{
	//
	int i=0,left=0,ans=0;
  	while(s[i])
  	{
	   if(s[i]=='{')
	   	left++;
	   else
	   {
	   	if(s[i]=='}' && left==0)
	   		{
		    	left++;
		       	ans+=1;
	        }
	        else
	        	left--;
		}
	        
	        i++;
  	}
  	
  	ans+=left/2;
  	if(left%2 > 0) ans++;
	//
	ostringstream temp;
	temp << count;
	ostringstream temp1; 
	temp1 << ans;
	string e = temp.str() + ". " + temp1.str();
	return e;
}
main ()
{
	try
	{
		char d[2000];
		string a[2000];
		int count = 1;
		bool i = true;
		while(count <= 2000){
			gets(d);
			if(d[0]=='-')
			{
				if(count == 1)
				a[count] = "0. 0";
				break;
			}
	  		
			string b = XuLyKyTu(count,d);
			a[count] = b;
			count++;
		}
		for(int j=1;j<=count;j++)
		{
			cout<<a[j]<<endl;
		}
	}
	catch(const char* msg)
	{
		cerr << msg << endl;
	}
}
