#include <iostream>

using namespace std;

int N,M,X,Y;
int arr[604][604];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> X >> Y;
    for(int i=0;i<N+X;i++) {
        for(int j=0;j<M+Y;j++) {
            cin >> arr[i][j];
        }
    }
    
//    X,Y // 밀려난 곳의 시작점
    for(int i=X;i<N;i++) {
        for(int j=Y;j<M;j++) {
            
            if(i<N and j<M) {
                arr[i][j]-=arr[i-X][j-Y];
            } else {
                arr[i][j]=arr[i+X][j+Y];
            }
        }
    }
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
