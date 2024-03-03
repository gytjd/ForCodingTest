#include <iostream>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;

int T;
unordered_map<int, bool> m;
int visited[10004];

void init_() {
    
    m[0]=1;
    m[1]=1;
    for(int i=2;i*i<=10000;i++) {
        if(m[i]==0) {
            for(int j=i*i;j<=10000;j+=i) {
                m[j]=1;
            }
        }
    }
}

void BFS_iter(int start) {
    queue<int> q;
    q.push(start);
    visited[start]=1;
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        
//        cout << start << " "  << visited[start] << "\n";
        
        for(int i=1;i<=9;i++) {
            if(start/1000==i) continue; // 같은거
            int temp=i*1000+start%1000;
            if(visited[temp]==0 and !m[temp]) {
                visited[temp]=visited[start]+1;
                q.push(temp);
            }
        }
        
        for(int i=0;i<=9;i++) {
            if((start%1000)/100==i) continue; // 백의자리 같은거
            int temp=((start/1000)*1000)+(i*100)+(start%100);
            if(visited[temp]==0 and !m[temp]) {
                
                visited[temp]=(visited[start]+1);
                
//                cout << visited[start] << " " << visited[temp] << "\n";
                q.push(temp);
            }
        }
        
        for(int i=0;i<=9;i++) {
            if((start%100)/10==i) continue;
            int temp=(start/100)*100+(i*10)+(start%10);
            if(visited[temp]==0 and !m[temp]) {
                visited[temp]=visited[start]+1;
                q.push(temp);
            }
        }
        
        for(int i=0;i<=9;i++) {
            if((start%10)==i) continue;
            int temp=((start/10)*10)+i;
            if(visited[temp]==0 and !m[temp]) {
                visited[temp]=visited[start]+1;
                q.push(temp);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    
    init_();
    for(int test=0;test<T;test++) {
        memset(visited,0,sizeof(visited));
        int start,end;
        cin >> start >> end;
        
        BFS_iter(start);
        if(visited[end]==0) {
            cout << "Impossible" << "\n";
        }
        else {
            cout << visited[end]-1 << "\n";
        }
    }
    
    return 0;
}
