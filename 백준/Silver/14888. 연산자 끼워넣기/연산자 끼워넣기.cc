#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
int op[4];
long long max_Ret=-10999999999;
long long min_Ret=10999999999;

void DFS_recur(int cnt,long long num) {
    if(cnt==N-1) {
        max_Ret=max(max_Ret,num);
        min_Ret=min(min_Ret,num);
        return;
    }
    
    for(int i=0;i<4;i++) {
        if(op[i]) {
            op[i]-=1;
            if(i==0) {
                DFS_recur(cnt+1, num+v[cnt+1]);
            }
            else if(i==1) {
                DFS_recur(cnt+1, num-v[cnt+1]);
            }
            else if(i==2) {
                DFS_recur(cnt+1, num*v[cnt+1]);
            }
            else {
                DFS_recur(cnt+1, num/v[cnt+1]);
            }
            op[i]+=1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    for(int i=0;i<4;i++) {
        cin >> op[i];
    }
    DFS_recur(0, v[0]);
    cout << max_Ret << "\n";
    cout << min_Ret << "\n";
    
    return 0;
}
