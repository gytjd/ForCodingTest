#include <iostream>
#include <algorithm>

using namespace std;

int N;
int visited[10];
vector<long long> v;

void combi_Recur(int curr,int cnt,long long temp) {
    
    v.push_back(temp);
    
    if(cnt==10) {
        return;
    }
    
    for(int i=0;i<10;i++) {
        if(cnt==0) {
            if(visited[i]==0) {
                visited[i]=1;
                combi_Recur(i+1, cnt+1, i);
                visited[i]=0;
            }
        }
        else {
            if(temp%10>i and visited[i]==0) {
                visited[i]=1;
                combi_Recur(i+1, cnt+1, temp*10+i);
                visited[i]=0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    combi_Recur(0,0, 0);
    sort(v.begin(),v.end());
//
//    for(int i=0;i<v.size();i++) {
//        cout << i << " " << v[i] << "\n";
//    }
    
    if(N>1022) {
        cout << -1 << "\n";
    }
    else {
        cout << v[N+1] << "\n";
    }
    
    return 0;
}
