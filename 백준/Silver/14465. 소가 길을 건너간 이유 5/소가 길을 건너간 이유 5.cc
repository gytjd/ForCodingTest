#include <iostream>
#include <algorithm>
using namespace std;

int N,K,B;
int visited[100004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> K >> B;
    for(int i=0;i<B;i++) {
        int data;
        cin >> data;
        visited[data]=1; // 고장난거
    }
    
    int curr=0;
    for(int i=1;i<=K;i++) {
        if(visited[i]) {
            curr+=1;
        }
    }
    
    int ret=curr;
    int j=1;
    
    for(int i=K+1;i<=N;i++) {
        curr+=visited[i];
        curr-=visited[j++];
        ret=min(ret,curr);
    }
    
    cout << ret << "\n";
    
    return 0;
}
