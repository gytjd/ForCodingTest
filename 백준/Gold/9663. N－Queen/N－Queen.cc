#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int visited[20];
int ret;

int is_check(int x,int y) {
    
    for(int i=1;i<x;i++) {
        if(abs(visited[i]-y)==abs(i-x) || visited[i]==y) {
            return 0;
        }
    }
    return 1;
}
void go_(int idx) {
    
    if(idx>N) {
        ret+=1;
        return;
    }
    else {
        for(int i=1;i<=N;i++) {
            if(is_check(idx, i)) {
                visited[idx]=i;
                go_(idx+1);
                visited[idx]=0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    go_(1);
    
    cout << ret << "\n";
    
    return 0;
}
