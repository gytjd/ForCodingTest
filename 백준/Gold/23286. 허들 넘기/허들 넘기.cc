#include <iostream>
#include <algorithm>

#define INF 1e9
using namespace std;

int N,M,T;
int arr[304][304];
int ret[304][304];

void init_() {
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(i==j) {
                arr[i][j]=0;
            }
            else {
                arr[i][j]=INF;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> T;
    
    init_();
    
    for(int i=0;i<M;i++) {
        int s,e,w;
        cin >> s >> e >> w;
        arr[s][e]=w;
    }
    
    for(int k=1;k<=N;k++) {
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                arr[i][j]=min(arr[i][j],max(arr[i][k],arr[k][j]));
            }
        }
    }
    
    for(int i=0;i<T;i++) {
        int s,e;
        cin >> s >> e;
        if(arr[s][e]==INF) {
            cout << -1 << "\n";
        }
        else {
            cout << arr[s][e] << "\n";
        }
    }
    
    return 0;
}
