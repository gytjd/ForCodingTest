#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int ret;
int cost[4];
vector<int> v;

void DFS_recur(int curr,int tempSum) {
    
    if(curr==12) {
        
        ret=min(ret,tempSum);
        return;
    }
    
    if(v[curr]) {
        
        DFS_recur(curr+1, tempSum+(v[curr]*cost[0]));
        DFS_recur(curr+1, tempSum+cost[1]);
        
        if(curr==10) {
            if(v[curr+1]) {
                DFS_recur(curr+2, tempSum+cost[2]);
            }
        } else if(curr==11) {
            DFS_recur(curr+1, tempSum+cost[2]);
        }
        else {
            if(v[curr+1] and v[curr+2]) {
                DFS_recur(curr+3, tempSum+cost[2]);
            }
        }
    } else {
        DFS_recur(curr+1, tempSum);
    }
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    for(int test=1;test<=T;test++) {
        
        ret=987654321;
        v.clear();
        
        for(int i=0;i<4;i++) {
            cin >> cost[i];
        }
        
        for(int i=0;i<12;i++) {
            int data;
            cin >> data;
            v.push_back(data);
        }
        
        DFS_recur(0, 0);
        ret=min(ret,cost[3]);
        cout << "#" << test << " " << ret << "\n";
    }
    
    return 0;
}