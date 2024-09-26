#include <iostream>
#include <unordered_map>
using namespace std;

int N;
int arr[24];
int visited[24];
unordered_map<int, bool> m;

void DFS_recur(int fin,int idx,int cnt) {
    if(cnt==fin) {
        
        int temp=0;
        for(int i=0;i<fin;i++) {
            temp+=visited[i];
        }
        m[temp]=true;
        
        
        return;
    }
    
    for(int i=idx;i<N;i++) {
        visited[cnt]=arr[i];
        DFS_recur(fin, i+1, cnt+1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    for(int i=1;i<=N;i++) {
        DFS_recur(i, 0, 0);
    }
    
    for(int i=1;i<=987654321;i++) {
        if(m[i]==false) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}
