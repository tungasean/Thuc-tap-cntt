#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

int N = 0; // so luong test case
int m,k,left1,right1,mid; //m la so luong cuon sach, k so phan can chia
int page[10000]; // so luong trang cua moi cuon
int p[10000];
int index[10000];
int ValidIndex[10000];     // ket qua cuoi cung


void Update(int id)
{
	int sum = 0,t =index[id];
	for (int i =index[id + 1] - 1; i >= t;i--)
	{
		sum += page[i];
		if(sum 	== mid)
		{
			index[id] = i;
			break;
		}
		else if(sum > mid)
		{
			index[id] = i+1;
			break;
		}
	}
}

bool IsValid()
{
	for(int i =0; i< k;i++)
	{
		index[i] =i;
		index[k] = m;
		
		//cap nhat lai tung phan tu
		for(int i = k-1;i >= 0;i--)
		{
			Update(i);
		}
		
		//neu sau
		if(index[0] > 0) return false;
		
		return true;
	}
}

int main()
{
	cin >> N;
	for(int i =0;i<N;i++)
	{
		int max_Page = 0; //Tim cuon sach co nhieu trang nhat
		int sum_Page = 0; // tim tong so trang sach
		
		cin>>m>>k;
		for(int j = 0; j< m;j++)
		{
			cin>>p[j];
			
			if(p[j]>max_Page) max_Page = p[j];
			sum_Page += p[j];
		}
		left1 = max_Page;
		right1 = sum_Page;
		
		// Trien khai thuat toan chia de tri
		while(left1 < right1)
		{
			mid = (left1 + right1)/2;
			if (IsValid())
            {
                right1 = mid;
                
                // ta dung mang luu lai chi so giua cac phan tu
                // de phan chia cac phan
                for(int i = 0; i < k; i++)
                    ValidIndex[i] = index[i];
            }
            else
            {
                left1 = mid + 1;
            }
		}
		// In ra ket qua
        for(int i = 0; i < k - 1; i++)
        {
            for(int j = ValidIndex[i]; j < ValidIndex[i+1]; j++)
                cout << page[j] << " ";
            cout << "/ ";
        }
        
         for(int i = ValidIndex[k-1]; i < m; i++)
        {
            cout << page[i];
            if(i == m-1) break;
            cout << " ";
        }
	}
	
}
