#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int ret;
double N,M;
queue<double> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    q.push(N);
    
    for(int i=0;i<=M;i++) {
        queue<double> temp;
        while(!q.empty()) {
            ret+=q.front();
//            cout << q.front() << " " << ceil(q.front()/2) << " " << floor(q.front()/2) << "\n";
            temp.push(ceil(q.front()/2));
            temp.push(floor(q.front()/2));
            q.pop();
        }
        q=temp;
    }
    
    cout << ret << "\n";
    
    return 0;
}
