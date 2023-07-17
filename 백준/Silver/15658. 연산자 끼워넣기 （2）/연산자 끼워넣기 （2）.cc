#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ret_Max=-987654321;
int ret_Min=987654321;
int N;
vector<int> v;
int visited[4];

void go_(int idx,int sum) {
    
    if(idx==N-1) {
        ret_Max=max(ret_Max,sum);
        ret_Min=min(ret_Min,sum);
        return;
    }
    
    if(visited[0]) {
        visited[0]-=1;
        go_(idx+1,sum+v[idx+1]);
        visited[0]+=1;
    }
    
    if(visited[1]) {
        visited[1]-=1;
        go_(idx+1,sum-v[idx+1]);
        visited[1]+=1;
    }
    
    if(visited[2]) {
        visited[2]-=1;
        go_(idx+1,sum*v[idx+1]);
        visited[2]+=1;
    }
    
    if(visited[3]) {
        visited[3]-=1;
        go_(idx+1,sum/v[idx+1]);
        visited[3]+=1;
    }
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
    }
    
    for(int i=0;i<4;i++) {
        cin >> visited[i];
    }
    
    go_(0, v[0]);
    cout << ret_Max << "\n";
    cout << ret_Min << "\n";
    
    return 0;
}
