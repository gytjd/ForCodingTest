#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[100004];
int visited[100004];

int N,K;
vector<int> v;

void BFS_iter() {
    
    int temp;
    bool check_Flag=false;
    
    queue<int> q;
    for(int a:v) {
        visited[a]=1;
        q.push(a);
    }
    
    while(!q.empty()) {
        temp=q.front();
        q.pop();
        
        if(temp==K) {
            check_Flag=true;
            break;
        }
        
        for(int a:v) {
            if(visited[temp+a]==0 and temp+a<=100000) {
                visited[temp+a]=visited[temp]+1;
                q.push(temp+a);
            }
        }
    }
    
    if(check_Flag) {
        cout << visited[K] << "\n";
    }
    else {
        cout << -1 << "\n";
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> K;
    
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    
    BFS_iter();
    
    return 0;
}
