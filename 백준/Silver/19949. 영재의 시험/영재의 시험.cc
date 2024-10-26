#include <iostream>
#include <vector>

using namespace std;

int ret;
vector<int> v;
int visited[14];

void DFS_recur(int curr) {
    if(curr==10) {
        
        int temp_ret=0;
        bool check_Flag=false;
        for(int i=0;i<10;i++) {
            if(i<8) {
                if(visited[i]==visited[i+1] and visited[i+1]==visited[i+2]) {
                    check_Flag=true;
                    break;
                }
            }
            
            if(v[i]==visited[i]) {
                temp_ret+=1;
            }
        }
        
        if(!check_Flag and temp_ret>=5) {
            ret+=1;
        }
        return;
    }
    
    for(int i=1;i<6;i++) {
        visited[curr]=i;
        DFS_recur(curr+1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    for(int i=0;i<10;i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    
    DFS_recur(0);
    cout << ret << "\n";
    
    return 0;
}
