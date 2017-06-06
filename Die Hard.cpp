#include<stdio.h>
#define maxN 1000
int main()
{
    int t,def,hp;
    int time=0;
    int a[maxN];
    int dem;
    scanf("%d",&t);
    dem =t;
    while(t--)
    {
      time=0;
      scanf("%d%d",&hp,&def);
    while(hp>0 && def>0)
       {
       hp= hp +3;
       def= def+2;
       time++;
       if(hp<=20 && def<=20)
                        {
                                hp=hp-5;
                                def=def-10;
                                if(hp>0 && def>0)
                                {
                                        time++;
                                }
                        }
        else
       if(def>=hp)
    	{
        hp= hp-5;
        def=def-10;
        time++;
    	}
    	else
       	{
           hp=hp-20;
           def=def+5;
           time++;
        }
	}
		a[t] = time;
    }
    for( int i =dem-1; i>=0; i--)
    {
    	printf("%d\n",a[i]);
    }
}
