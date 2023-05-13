#include <iostream>
using namespace std;

int arr[104][104];

int N,M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int q=0;q<2;q++) {
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                int data;
                cin >> data;
                
                arr[i][j]+=data;
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
