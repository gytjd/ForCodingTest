#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;
int visited[1004];
int ret;

void go_() {
    
    ret=v[0];
    for(int i=1;i<N;i++) {
        for(int j=0;j<i;j++) {
            if(v[j]<v[i]) {
                visited[i]=max(visited[i],v[i]+visited[j]);
            }
            ret=max(ret,visited[i]);
        }
    }
    cout << ret << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        v.push_back(data);
        visited[i]=data;
    }
    
    go_();
    
    return 0;
}
