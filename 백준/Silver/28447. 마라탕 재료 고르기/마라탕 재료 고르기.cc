#include <iostream>
#include <algorithm>

using namespace std;


int N,K;
int arr[14][14];
int visited[14];

int ret=-987654321;
int temp_Ret;
vector<int> temp;
int check[14];

void DFS_mara(int curr,int idx) {
    if(curr==2) {
        temp_Ret+=arr[check[0]][check[1]];
        return;
    }
    for(int i=idx;i<K;i++) {
        check[curr]=temp[i];
        DFS_mara(curr+1, i+1);
    }
}

void DFS_recur(int curr,int idx) {
    
    if(curr==K) {
        temp_Ret=0;
        temp.clear();
        
        for(int i=0;i<K;i++) {
            temp.push_back(visited[i]);
        }
        DFS_mara(0, 0);
        ret=max(ret,temp_Ret);
        
        return;
    }
    
    for(int i=idx;i<=N;i++) {
        visited[curr]=i;
        DFS_recur(curr+1, i+1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> K;
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin >> arr[i][j];
        }
    }
    
    DFS_recur(0, 1);
    
    cout << ret << "\n";
    
    return 0;
}
