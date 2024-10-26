#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N,M;
priority_queue<int,vector<int>,less<>> q;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        q.push(data);
    }
    
    for(int i=0;i<M;i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    
    bool check_Flag=false;
    for(int i=0;i<M;i++) {
            
        if(q.top()>=v[i]) {
            int temp=q.top();
            q.pop();
            q.push(temp-v[i]);
        } else {
            check_Flag=true;
            break;
        }
    }
    
    cout << (check_Flag ? 0 : 1) << "\n";
    
    return 0;
}
