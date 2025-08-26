#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N,M;
int ret=987654321;
vector<pair<int,int>> v;
vector<pair<int,int>> w;
int visited[14];

int Cal_() {
    
    int tempHome=0;
    for(int i=0;i<v.size();i++) {
        
        int currX=v[i].first;
        int currY=v[i].second;
        
        int tempRet=987654321;
        for(int j=0;j<w.size();j++) {
            if(visited[j]) {
                int tempX=w[j].first;
                int tempY=w[j].second;
                tempRet=min(tempRet,abs(currX-tempX)+abs(currY-tempY));
            }
        }
        tempHome+=tempRet;
    }
    return tempHome;
}

void Combi_Recur(int curr,int idx) {
    
    if(curr==M) {
        ret=min(ret,Cal_());
        return;
    }
    
    for(int i=idx;i<w.size();i++) {
        
        if(visited[i]==0) {
            visited[i]=1;
            Combi_Recur(curr+1, i+1);
            visited[i]=0;
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            int data;
            cin >> data;
            if(data==2) {
                w.push_back({i,j});
            } else if(data==1) {
                v.push_back({i,j});
            }
        }
    }
    
    Combi_Recur(0, 0);
    cout << ret << "\n";
    
    return 0;
}
