#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        
        if(a=="push") {
            int b;
            cin >> b;
            q.push(b);
        }
        else if(a=="pop") {
            if(q.size()==0) {
                cout << -1 << "\n";
            }
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(a=="size") {
            cout << q.size() << "\n";
        }
        else if(a=="empty") {
            if(q.empty()) {
                cout << 1 << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }
        else if(a=="front") {
            if(q.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << q.front() << "\n";
            }
        }
        else if(a=="back") {
            if(q.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << q.back() << "\n";
            }
        }
    }
    return 0;
}
