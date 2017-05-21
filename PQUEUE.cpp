#include <iostream>
#include <stdio.h>
using namespace std;
const int Max = 105;	
	
int Abs(int a)
{
	if(a >=0) return a;
	return -a;
}
main ()
{
	int T; // so ca kiem tra
	int N; // so luong cong viec trong hang doi
	int M; // vi tri cong viec cua ban
	// nhap so ca kiem tra
	cin>>T;
	int a[100];
	int d[100];
	
	for(int i=0;i<T;i++)
	{
		cin>>N; // nhap so luong cong viec trong hang doi
		cin>>M; // nhap cong viec cua ban
		for(int j =0; j<N;j++)
		{
			cin>>a[j]; // a[j] la do uu tien cua cong viec thu j,a[j] cang nho thi cong viec cang duoc uu tien
		}
		
		// danh sau vi tri cong viec hoan thanh bang cach chuyen gia tri ve am
		a[M] = - a[M];
		
		int front =0, rear = N, leng = N, numMinute = 0;
		while (leng > 0)
		{
			int p = a[front];
			front = (front +1) % Max;
			leng--;
			
			bool IsPrint = true;
			
			//duyet hang doi tu front den rear
			for(int l = front; l!=rear; l = (l+1) % Max)
			{
				// neu ton tai cong viec uu tien lon hon p thi cho p xuong cuoi hang doi
				if(Abs(p) < Abs(a[l]))
				{
					IsPrint = false;
					a[rear] = p;
					rear = (rear + 1) % Max;
					leng++;
					break;
				}
			}
			//neu khong tim thay thi p la cong viec cos do uu tien cao nhat
			if(IsPrint)
			{
				numMinute++;
				//neu k < 0 thi day chinh la cong viec cua ban
				if(p<0)
				{
					d[i] = numMinute;
					break;	
				}
			}
		}
	}
	for(int i=0;i<T;i++)
	{
		cout<<d[i]<<endl;
	}
	
	
}
