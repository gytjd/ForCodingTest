#include <iostream>
#include <queue>
#include <map>
using namespace std;

long long N,M;
long long temp_M;
long long ret;
queue<long long> q;
map<long long, bool> visited;
bool check_Flag;

void BFS_iter(long long num) {
    
    long long x;
    queue<long long> temp;
    while(!q.empty()) {
        x=q.front();
        q.pop();
        
        
        if(visited[x-1]==false) {
            temp_M+=1;
            visited[x-1]=true;
            ret+=num;
            if(temp_M==M) {
                check_Flag=true;
                break;
            }
            temp.push(x-1);
        }
        
        if(visited[x+1]==false) {
            temp_M+=1;
            visited[x+1]=true;
            ret+=num;
            if(temp_M==M) {
                check_Flag=true;
                break;
            }
            temp.push(x+1);
        }
    }
    
    q=temp;
}

void go_() {
    
    long long num=1;
    while(1) {
        BFS_iter(num);
        if(check_Flag) {
            cout << ret << "\n";
            break;
        }
        num+=1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(long long i=0;i<N;i++) {
        long long data;
        cin >> data;
        q.push(data);
        visited[data]=true;
    }
    
    go_();
    
    return 0;
}
