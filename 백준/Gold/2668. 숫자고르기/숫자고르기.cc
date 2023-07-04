#include <iostream>
using namespace std;

int N;
int arr[104];
int visited[104];
int ret[104];
int tot;

void go_(int start,int idx,int depth) {
//    cout << start << " " << idx << " " << depth << "\n";
    if(arr[idx]==start) {
        for(int i=1;i<=N;i++) {
            if(visited[i]==1) {
                ret[i]=1;
            }
        }
        return;
    }
    
    if(visited[arr[idx]]==0) {
        visited[arr[idx]]=1;
        go_(start, arr[idx], depth+1);
        visited[arr[idx]]=0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=1;i<=N;i++) {
        cin >> arr[i];
    }
    
    for(int i=1;i<=N;i++) {
        if(visited[i]==0) {
            visited[i]=1;
            go_(i, i, 1);
            visited[i]=0;
        }
    }
    
    
    for(int i=1;i<=N;i++) {
        if(ret[i]==1) {
            tot+=1;
        }
    }
    
    cout << tot << "\n";
    for(int i=1;i<=N;i++) {
        if(ret[i]==1) {
            cout << i << "\n";
        }
    }
    
    return 0;
}
