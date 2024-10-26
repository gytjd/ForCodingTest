#include <iostream>

using namespace std;

int N,M;
int arr[304][304];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            arr[i][j]+=max(arr[i-1][j],arr[i][j-1]);
        }
    }
    
    cout << arr[N][M] << "\n";
    
    return 0;
}
