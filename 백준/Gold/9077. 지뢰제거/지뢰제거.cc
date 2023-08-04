#include <iostream>
#include <cstring>

using namespace std;

int ret;
int T,N;
int visited[10004][10004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    for(int q=0;q<T;q++) {
        cin >> N;
        ret=0;
        memset(visited, 0, sizeof(visited));
        
        for(int i=0;i<N;i++) {
            
            int start,end;
            cin >> start >> end;
            
            for(int j=start;j<=start+10;j++) {
                
                if(j>10000) {
                    break;
                }
                
                for(int k=end;k<=end+10;k++) {
                    
                    if(k>10000) {
                        break;
                    }
                    
                    visited[j][k]+=1;
                    ret=max(ret,visited[j][k]);
                }
            }
        }
        
        cout << ret << "\n";
    }
}
