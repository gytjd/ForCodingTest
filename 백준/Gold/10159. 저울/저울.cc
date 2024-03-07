#include <iostream>

using namespace std;

int N,M;
int arr[104][104];
int visited[104];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    cin >> M;
    
    for(int i=0;i<M;i++) {
        int start,end;
        cin >> start >> end;
        arr[start][end]=1;
    }
    
    for(int k=1;k<=N;k++) {
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                if(arr[i][k] and arr[k][j]) {
                    arr[i][j]=1;
                }
            }
        }
    }
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(arr[i][j]==0 and arr[j][i]==0) {
                visited[i]+=1;
            }
        }
    }
    
    for(int i=1;i<=N;i++) {
        cout << visited[i]-1 << "\n";
    }
    
    return 0;
}
