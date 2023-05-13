#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
vector<int> computer[10001];
int visited[10001];
vector<int> result;

void init_() {
    int i;
    for(i=0;i<10001;i++) {
        visited[i]=0;
    }
}

void BFS_com(int start) {
    
    queue<int> q;
    visited[start]=1;
    q.push(start);
    
    while(!q.empty()) {
        int tempq=q.front();q.pop();
        for(int i=0;i<computer[tempq].size();i++) {
            
            if(visited[computer[tempq][i]]==0) {
                visited[computer[tempq][i]]=1;
                q.push(computer[tempq][i]);
            }
        }
    }
}

int count_visited() {
    int count=0;
    
    for(int i=1;i<=N;i++) {
        if(visited[i]==1) {
            count+=1;
        }
    }
    
    return count;
}

void go() {
    int max_num=0;
    for(int i=0;i<result.size();i++) {
        if(max_num<result[i]) {
            max_num=result[i];
        }
    }
    
    for(int i=0;i<result.size();i++) {
        if(result[i]==max_num) {
            cout << i+1 << " ";
        }
    }
    cout << "\n";
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    
    for (int i=0;i<M;i++) {
        int tempA,tempB;
        cin >> tempA >> tempB;
        computer[tempB].push_back(tempA);
    }
    
    for(int i=1;i<=N;i++) {
        init_();
        BFS_com(i);
        
        result.push_back(count_visited());
    }
    
    go();
    
    return 0;
}
