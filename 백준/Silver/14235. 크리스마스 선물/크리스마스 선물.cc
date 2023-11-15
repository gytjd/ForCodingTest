#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int A;
        cin >> A;
        if(!A) {
            if(pq.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            for(int i=0;i<A;i++) {
                int data;
                cin >> data;
                pq.push(data);
            }
        }
    }
    
    return 0;
}
