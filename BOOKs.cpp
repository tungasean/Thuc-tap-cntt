#include<iostream>
using namespace std;
 
const int MAX = 10000;
 
int M, K;                // luu so luong cuon sach va so phan can chia
int Left,Right, mid;        
int Page[MAX];           // luu so luong trang sach cua moi cuon sach
int Index[MAX];          // mang luu tru co cac phan tu dau tien cua moi phan
int ValidIndex[MAX];     // ket qua cuoi cung
 
// cap nhat lai tong so phan tu sao cho tong so phan tu khong lon hon mid
void Update(int id)
{
    int sum = 0, t = Index[id];
 
    for(int i = Index[id + 1] - 1; i >= t; i--)
    {
        sum += Page[i];
        
        if(sum == mid)
        {
            Index[id] = i;
            break;
        }else if(sum > mid)
        {
            Index[id] = i + 1;
            break;
        }
    }
}
 //kiem tra xem voi so luong lon nhat cua cac phan tu la mid
// co hop ly hay khong
bool IsValid()
{
    for(int i = 0; i < K; i++)
        Index[i] = i;
    Index[K] = M;
 
    // cap nhat lai phan tu
    for(int i = K - 1; i >= 0; i--)
        Update(i);
 
    // Neu khong
    if (Index[0] > 0) return false;
 
    return true;
}
 
int main()
{
    int T;
    cin >> T;
 
    for(int tc = 0; tc < T; tc++)
    {
        int max_page = 0;        // tim ra cuon sach co so trang nhieu nhat
        int sum_page = 0;        // Tim tong so trang
        
        cin >> M >> K;
 
        for(int i = 0; i < M; i++)
        {
            cin >> Page[i];
 
            if(Page[i] > max_page) max_page = Page[i];
            sum_page += Page[i];
        }
        // khi chia ra thanh cac phan thi tong lon nhat cua cac phan 
		// se nam trong khoang Left = max-page
		// right = sum_page 
        Left  = max_page;
        Right = sum_page;
 
        //trien khai thuat toan chia de tri
        while (Left < Right)
        {
            mid = (Left + Right) / 2;
            
            if (IsValid())
            {
                Right = mid;
                // ta dung mang de luu lai chi so cua cac phan tu
                // de phan chia cac phan
                for(int i = 0; i < K; i++)
                    ValidIndex[i] = Index[i];
            }
            else
            {
                Left = mid + 1;
            }
        }
 
        // In ra ket qua
        for(int i = 0; i < K - 1; i++)
        {
            for(int j = ValidIndex[i]; j < ValidIndex[i+1]; j++)
                cout << Page[j] << " ";
            cout << "/ ";
        }
        
        for(int i = ValidIndex[K-1]; i < M; i++)
        {
            cout << Page[i];
            if(i == M-1) break;
            cout << " ";
        }
 
        cout << endl;
    }
 
    return 0;
}
