#include <iostream>
#include <algorithm>

using namespace std;

struct  so {
	int a;
	int b;
};

so day[5000];
int kq[1000][5000];
int sl[1000];

int cmp(so x,so y)
{
	return x.a<y.a;
}

int main()
{
	try
	{
		int  e;
		cin>>e;
		for(int l=e;l>0;l--)
		{
			
			cin>>sl[l];
			for(int i=0;i<sl[l];i++)
				cin>>day[i].a;
			for(int j=0;j<sl[l];j++)
				cin>>day[j].b;
			//sap xem lai mang k[j].a
			sort(day,day+sl[l],cmp);
			
			for(int i=0;i<sl[l];i++)
			{
				int dem = day[i].b;
				for(int j =0; j<sl[l];j++)
				{
					if(kq[l][j] == 0 && dem == 0)
					{
						kq[l][j]=day[i].a;
						break; 
					}
					if(kq[l][j] == 0)
						dem--;
				}
			}
		}
			for(int l=e;l>0;l--)
			{
				for(int i =0;i<sl[l];i++)
				{
					cout<<kq[l][i]<<" ";
				}
				cout<<"\n";
			}
	}
	catch(const char* msg)
	{
		cerr << msg << endl;
	}
	
}
