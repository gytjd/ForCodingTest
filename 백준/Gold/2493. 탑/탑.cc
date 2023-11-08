#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
stack<pair<int, int>> s;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=1;i<=N;i++) {
        int data;
        cin >> data;
        
        if(s.empty()) {
            s.push({data,i});
            cout << 0 << " ";
        }
        else {
            if(s.top().first>data) {
                cout << s.top().second << " ";
                s.push({data,i});
            }
            else {
                while(!s.empty() and s.top().first<=data) {
                    s.pop();
                }
                
                if(s.empty()) {
                    cout << 0 << " ";
                }
                else {
                    cout << s.top().second << " ";
                }
                s.push({data,i});
            }
        }
    }
    cout << "\n";
    
    return 0;
}
