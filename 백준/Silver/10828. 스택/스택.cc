#include <iostream>
#include <stack>

using namespace std;

int N;
stack<int> s;

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
            s.push(b);
        }
        else if(a=="pop") {
            if(s.size()==0) {
                cout << -1 << "\n";
            }
            else {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if(a=="size") {
            cout << s.size() << "\n";
        }
        else if(a=="empty") {
            if(s.empty()) {
                cout << 1 << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }
        else if(a=="top") {
            if(s.size()==0) {
                cout << -1 << "\n";
            }
            else {
                cout << s.top() << "\n";
            }
        }
    }
    
    return 0;
    
}
