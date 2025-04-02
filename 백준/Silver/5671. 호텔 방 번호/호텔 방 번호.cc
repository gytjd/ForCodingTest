#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<int,int>> v;
int visited[10004];
int check[10];
int a,b;

void DFS_recur(int curr,int end,string temp) {
    
    if(!temp.empty()) visited[stoi(temp)]=1;
    
    if(curr==end) {
        return;
    }
    
    for(int i=0;i<10;i++) {
        if(check[i]==0) {
            check[i]=1;
            DFS_recur(curr+1, end, temp+(char)(i + '0'));
            check[i]=0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    
    while(cin >> a && cin >> b) {
        v.push_back({a,b});
    }
    
    
    DFS_recur(0, 4, "");
    
    for(pair<int,int> temp: v) {
        int temp_Cnt=0;
        for(int i=temp.first;i<=temp.second;i++) {
            if(visited[i]==1) {
                temp_Cnt+=1;
            }
        }
        cout << temp_Cnt << "\n";
    }
    return 0;
}
