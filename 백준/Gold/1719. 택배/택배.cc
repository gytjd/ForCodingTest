#include <iostream>
#include <algorithm>
#define INF 1e9

using namespace std;

int N,M;
int arr[204][204];
int ret[204][204];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(i==j) {
                arr[i][j]=0;
            }
            else {
                arr[i][j]=INF;
            }
            ret[i][j]=j;
        }
    }
    
    for(int i=0;i<M;i++) {
        int S,E,W;
        cin >> S >> E >> W;
        arr[S][E]=W;
        arr[E][S]=W;
    }
    
    for(int k=1;k<=N;k++) {
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                if(arr[i][j]>arr[i][k]+arr[k][j]) {
                    ret[i][j]=ret[i][k];
                    arr[i][j]=arr[i][k]+arr[k][j];
                }
            }
        }
    }
    
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            
            if(i==j) {
                cout << "-" << " ";
            }
            else {
                cout << ret[i][j] << " ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
    
    return 0;
}
