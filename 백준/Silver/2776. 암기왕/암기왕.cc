#include <iostream>
#include <unordered_map>
using namespace std;

int T;
int N,M;
unordered_map<int, int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    
    for(int i=0;i<T;i++) {
        q.clear();
        cin >> N;
        
        for(int j=0;j<N;j++) {
            int data;
            cin >> data;
            q[data]+=1;
        }
        
        cin >> M;
        
        for(int j=0;j<M;j++) {
            int data;
            cin >> data;
            if(q[data]>=1) {
                cout << 1 << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }
    }
    return 0;
}
