#include <iostream>
#include <cstring>
using namespace std;

long long N,ret;
long long arr[104];
long long visited[104][104];

long long go_(long long idx,long long sum) {
    
    if(idx==N-2) {
        if(arr[idx+1]==sum) {
            return visited[idx][sum]=1;
        }
        else {
            return visited[idx][sum]=0;
        }
    }
    
    long long &ret=visited[idx][sum];
    
    if(ret!=-1) {
        return ret;
    }
    ret=0;
    
    if(sum+arr[idx+1]<=20) {
        ret+=go_(idx+1, sum+arr[idx+1]);
    }
    
    if(sum-arr[idx+1]>=0) {
        ret+=go_(idx+1, sum-arr[idx+1]);
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(long long i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    memset(visited, -1, sizeof(visited));
    
    cout << go_(0, arr[0]) << "\n";
    
    return 0;
}
