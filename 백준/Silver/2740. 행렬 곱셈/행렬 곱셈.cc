#include <iostream>

using namespace std;

int N,M;
int Q,W;
int A[104][104];
int B[104][104];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> A[i][j];
        }
    }
    cin >> Q >> W ;
    for(int i=0;i<Q;i++) {
        for(int j=0;j<W;j++) {
            cin >> B[i][j];
        }
    }
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<W;j++) {
            //(0,0),(0,1)
            int temp=0;
            for(int k=0;k<M;k++) {
//                cout << i << " " << j << " " << j << " " << k << "\n";
                temp+=A[i][k]*B[k][j];
            }
            cout << temp << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
