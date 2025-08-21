#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int ret;
int N,M,D;
int arr[20][20];
int visited[15];

vector<pair<int,int>> v;

bool cmp(pair<int,int> &a,pair<int,int> &b) {
    
    if(a.first==b.first) {
        return a.second<b.second;
    }
    return a.first>b.first;
}

int go_() {
    int tempRet = 0;

    vector<vector<int>> map(N, vector<int>(M));
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            map[i][j] = arr[i][j];
        }
    }


    for (int turn=0; turn<N; turn++) {
        vector<pair<int,int>> targets;

        
        for (int j=0;j<M;j++) {
            if (visited[j]) {
                pair<int,int> target = {-1,-1};
                int minDist = 1e9;

                
                for (int x=0;x<N;x++) {
                    for (int y=0;y<M;y++) {
                        if (map[x][y]==1) {
                            int dist = abs(N - x) + abs(j - y);
                            if (dist<=D) {
                                if (dist < minDist || (dist==minDist && y < target.second)) {
                                    minDist = dist;
                                    target = {x,y};
                                }
                            }
                        }
                    }
                }
                if (target.first!=-1) targets.push_back(target);
            }
        }
        
        for (auto &t: targets) {
            if (map[t.first][t.second]==1) {
                tempRet++;
                map[t.first][t.second]=0;
            }
        }

        for (int x=N-1;x>0;x--) {
            for (int y=0;y<M;y++) {
                map[x][y]=map[x-1][y];
            }
        }
        for (int y=0;y<M;y++) map[0][y]=0;
    }

    return tempRet;
}


void find_Archer(int curr,int idx) {
    
    if(curr==3) {
        ret=max(ret,go_());
        return;
    }
    
    for(int i=idx;i<M;i++) {
        if(visited[i]==0) {
            visited[i]=1;
            find_Archer(curr+1, i+1);
            visited[i]=0;
        }
    }
}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> D;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
            if(arr[i][j]) v.push_back({i,j});
        }
    }
    
    sort(v.begin(),v.end(),cmp);
    find_Archer(0, 0);
    cout << ret << "\n";
    
    return 0;
}
