#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;

int ret;
int visited[1004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    
    for(int i=0;i<N;i++) {
        visited[i]=v[i];
        for(int j=0;j<i;j++) {
            if(v[j]<v[i]) {
                visited[i]=max(visited[i],visited[j]+v[i]);
            }
        }
    }
    
    for(int i=0;i<N;i++) {
        ret=max(ret,visited[i]);
    }
    
    cout << ret << "\n";
    
    return 0;
}
