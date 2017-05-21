#include <iostream>
#include <stdio.h>
#include <sstream>
#include <cstring>
#include <stdlib.h>
using namespace std;

int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

int mergeSort(int arr[], int array_size)
{
	int *temp = (int *)malloc(sizeof(int)*array_size);
	return _mergeSort(arr, temp, 0, array_size - 1);
}

int _mergeSort(int arr[], int temp[], int left, int right)
{
	int mid, inv_count = 0;
	if (right > left)
	{
		mid = (right + left)/2;
		inv_count = _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid+1, right);
		inv_count += merge(arr, temp, left, mid+1, right);
	}
	return inv_count;
}

int merge(int arr[], int temp[], int left, int mid, int right)
{
	int i, j, k;
	int inv_count = 0;
	
	i = left;
	j = mid;
	k = left;
	while ((i <= mid - 1) && (j <= right))
	{
		if (arr[i] <= arr[j])
		{
		temp[k++] = arr[i++];
		}
		else
		{
		temp[k++] = arr[j++];
		inv_count = inv_count + (mid - i);
		}
	}
	while (i <= mid - 1)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];
	for (i=left; i <= right; i++)
		arr[i] = temp[i];
	
	return inv_count;
}
main ()
{
	int sum;
	
	int* kq = new int[1000000];
	int N;
	cin>>sum;
	int count = 0;
	int i=0;
	while(count < 1000000)
	{
		cin>>N;
		int* d = new int[1000000];
		for(int j =0;j<N;j++)
		{
			cin>>d[count];
			count++;
		}
		kq[i] = mergeSort(d, count);
				count = 0;
				i++;
				if(i==sum)
				break;
				delete[] d;
	}
	for(int i=0;i<sum;i++)
	{
		cout<<kq[i]<<endl;
	}
	delete[] kq;
}
