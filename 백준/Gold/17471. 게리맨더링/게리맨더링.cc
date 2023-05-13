#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<int> arr[14];
int visited[14];
int weight[14];
bool check[14];
int N;

int tot;

int min_tot=987654321;

void BFS_iter(int start,bool tmp) {
    visited[start]=1;
    
    queue<int> q;
    q.push(start);
    
    while(!q.empty()) {
        start=q.front();q.pop();
        
        for(int i=0;i<arr[start].size();i++) {
            
            if(visited[arr[start][i]]==0 and check[arr[start][i]]==tmp) {
                visited[arr[start][i]]=1;
                q.push(arr[start][i]);
            }
        }
    }
}

int go_(int n) {
    
    int start=0;
    
    for(int i=0;i<14;i++) {
        check[i]=false;
        visited[i]=0;
    }
    
    for(int i=0;i<N;i++) {
        if(n&(1<<i)) {
            check[i]=true;
            start=i;
        }
    }
    
    bool check_Flag_A=false;
    int ret=0;
    BFS_iter(start,true);
    
    for(int i=0;i<N;i++) {
        if(check[i]==true and visited[i]==0) {
            check_Flag_A=true;
            break;
        }
        else if(check[i]==true and visited[i]==1) {
            ret+=weight[i];
        }
    }
    
    int tmp_start=0;
    for(int i=0;i<N;i++) {
        if(check[i]==false) {
            tmp_start=i;
            break;
        }
    }
    
    bool check_Flag_B=false;
    BFS_iter(tmp_start, false);
    
    for(int i=0;i<N;i++) {
        if(visited[i]==0) {
            check_Flag_B=true;
            break;
        }
    }
    
    if(check_Flag_A==true or check_Flag_B==true) {
        return -1;
    }
    else {
        return abs(ret-(tot-ret));
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        cin >> weight[i];
        tot+=weight[i];
    }
    
    for(int i=0;i<N;i++) {
        int num;
        cin >> num;
        
        for(int j=0;j<num;j++) {
            int data;
            cin >> data;
            arr[i].push_back(data-1);
        }
    }
    
    
    for(int i=0;i<=(1<<N);i++) {
        int g=go_(i);
        
        if(g==-1) {
            continue;
        }
        else {
            if(min_tot>g) {
                min_tot=g;
            }
        }
    }
    
    if(min_tot==987654321) {
        cout << -1 << "\n";
    }
    else {
        cout << min_tot << "\n";
    }
    
    return 0;
}
