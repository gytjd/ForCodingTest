#include <iostream>
#include <vector>

using namespace std;

int N,M;
vector<int> v;
int visited[1004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    
    for(int i=0;i<M;i++) {
        int data;
        cin >> data;
        visited[data]=1;
    }
    
    int ret=0;
    for(int i=0;i<M;i++) {
        if(!visited[v[i]]) {
            ret+=1;
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}
