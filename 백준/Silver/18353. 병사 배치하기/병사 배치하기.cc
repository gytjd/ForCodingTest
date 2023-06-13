#include <iostream>
using namespace std;

int N;
int arr[2004];
int visited[2004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        cin >> arr[i];
        visited[i]=1;
    }
    
    
    if(N==1) {
        cout << 0 << "\n";
    }
    else {
        int ret=0;
        for(int i=1;i<N;i++) {
            for(int j=0;j<i;j++) {
                if(arr[j]>arr[i]) {
                    visited[i]=max(visited[i],visited[j]+1);
                }
            }
            ret=max(ret,visited[i]);
        }
        
        
        cout << N-ret << "\n";
    }
    
//    for(int i=0;i<N;i++) {
//        cout << visited[i] << " ";
//    }
//    cout << "\n";
    
    return 0;
}
