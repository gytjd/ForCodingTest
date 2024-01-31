#include <iostream>
#include <deque>

using namespace std;

int N;
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=1;i<=N;i++) {
        dq.push_back(i);
    }
    
    bool check_Flag=false;
    while(!dq.empty()) {
        if(!check_Flag) {
            cout << dq.front() << " ";
            dq.pop_front();
            check_Flag=true;
        }
        else {
            dq.push_back(dq.front());
            dq.pop_front();
            check_Flag=false;
        }
    }
    
    return 0;
}
