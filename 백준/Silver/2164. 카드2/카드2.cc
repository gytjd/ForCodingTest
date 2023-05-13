#include <iostream>
#include <queue>

using namespace std;

int N;
deque<int> d;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=1;i<=N;i++) {
        d.push_back(i);
    }
    
    while(d.size()!=1) {
        d.pop_front();
        int temp=d.front();
        d.pop_front();
        d.push_back(temp);
    }
    
    cout << d[0] << "\n";
    
    return 0;
}
