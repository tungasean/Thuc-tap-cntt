#include<stdio.h>
/* N?u n=1 th� S thu?c t?p {1}
N?u n=2 th� S thu?c t?p {-1,3}
N?u n=3 th� S thu?c t?p {-4,0,2,6}
N?u n=4 th� S thu?c t?p {-8,-4,-2,0,2,4,6,10}

V?i n b?t k? S thu?c t?p {L,��,R} ta th?y
1. Hai c?p s�t L,R c�ch nhau 4 c�n l?i c�ch nhau 2 v�
2. N?u S ch?n th� to�n s? ch?n, n?u d�y l? th� to�n s? l?
3. R= 1+2+�+n
4. L=2-R

Ta d? d�ng ki?m tra xem m?t s? S c� th? sinh ra du?c t? t?p A kh�ng v� d�ng d? quy d? g?i l�i v? 1 l� xong */
bool Check(long L,long R,long S)
{
    if(S>R || S<L || S==R-2 || S==L+2) return false;
    return true;
}
void Print(long L,long R,long n,long S)
{
    if(n==1) {printf("1");return;}
    if(Check(L+n,R-n,S-n)) {Print(L+n,R-n,n-1,S-n);printf("+%d",n);}
    else {Print(L+n,R-n,n-1,S+n);printf("-%d",n);}
}
int main()
{
    int n,S,L,R;
    scanf("%d%d",&n,&S);
    R=(n+1)*n/2;
    L=2-R;
    if((S+R)%2) printf("Impossible");
    else if(!Check(L,R,S)) printf("Impossible");
    else Print(L,R,n,S);
}
