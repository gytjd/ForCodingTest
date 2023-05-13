#include <iostream>
#include <algorithm>
# define MAX 10000
using namespace std;

int N, M;
int ride[MAX];

long long binarySearch(void)
{
    long long low = 0, high = 2000000000LL * 30LL;
    long long result = -1;
    
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long children = M;
        
        for (int i = 0; i < M; i++) {
            children += mid / ride[i];
        }
    
        if(children>= N)
        {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    
    return result;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        cin >> ride[i];
    }
    if (N <= M)
    {
        cout << N << "\n";
        return 0;
    }
    
    long long time = binarySearch();
    long long children = M;
    
    for (int i = 0; i < M; i++) {
        children += (time - 1) / ride[i];
    }
    
    for (int i = 0; i < M; i++)
    {
        if (!(time % ride[i]))
            children++;
        
        if(children == N)
        {
            cout << i + 1 << "\n";
            break;
        }
    }
    return 0;
}
