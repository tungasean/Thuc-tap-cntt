#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

int a[1000],n, dem = 0;
string str[1000];
int main() {
  while (1) {
  	cin>>n;
  	if(n == 0) break;
    for (int i = 0; i < n; i++)
    cin>>a[i];
    int k = 0, i = 0;
    stack<int> st;
    while (i < n) {
      while (st.size() && st.top() == k + 1) k++, st.pop();
      if (a[i] != k + 1) st.push(a[i]);
      else k++;
      i++;
    }
    while (st.size() && st.top() == k + 1) k++, st.pop();
    str[dem] = k == n ? "yes" : "no";
    dem++;
  }
  for(int j = 0; j<= dem;j++)
  {
  	cout<<str[j]<<endl;
  }
}
