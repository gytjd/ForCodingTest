#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int N,M,D;

int answer;
int arr[16][16];
int temp_Arr[16][16];
int arch_Visited[16];

struct Enemy {
    int dist;
    int x;
    int y;
};

bool cmp(Enemy &A,Enemy &B) {
    if(A.dist==B.dist) {
        return A.y<B.y;
    }
    return A.dist<B.dist;
}

void init_() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            temp_Arr[i][j]=arr[i][j];
        }
    }
}

void display_() {
    cout << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << temp_Arr[i][j] << " ";
        }
        cout << "\n";
    }
    
}

int end_Check() { // 적이 다 없으면 종료
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(temp_Arr[i][j]==1) {
                return 0;
            }
        }
    }
    return 1;
}

int attack_() {
    
    int temp_Answer=0;
    int temp_Visited[16][16];
    memset(temp_Visited, 0, sizeof(temp_Visited));
    
    for(int i=0;i<M;i++) {
        if(arch_Visited[i]) {
            
            vector<Enemy> tempV;
            for(int j=0;j<N;j++) {
                for(int k=0;k<M;k++) {
                    if(temp_Arr[j][k] and (abs(N-j)+abs(i-k))<=D) {
                        tempV.push_back({abs(N-j)+abs(i-k),j,k});
                    }
                }
            }

            if(tempV.empty()) continue;
            sort(tempV.begin(),tempV.end(),cmp);
            temp_Visited[tempV[0].x][tempV[0].y]=1;
        }
    }
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(temp_Visited[i][j]==1) {
                temp_Answer+=1;
                temp_Arr[i][j]=0;
            }
        }
    }
    return temp_Answer;
}

void down_() {
    for(int i=N-1;i>=1;i--) {
        for(int j=0;j<M;j++) {
            temp_Arr[i][j]=temp_Arr[i-1][j];
        }
    }
    for(int i=0;i<M;i++) {
        temp_Arr[0][i]=0;
    }
}

void go_() {
    
    int temp_Answer=0;
    init_();
    while(!end_Check()) {
        temp_Answer+=attack_();
        down_();
    }
    answer=max(answer,temp_Answer);
}

void combi_Recur(int cnt) { // 궁수들 자리배치
    
    if(cnt==3) {
        go_();
        return;
    }
    
    for(int i=0;i<M;i++) {
        if(!arch_Visited[i]) {
            arch_Visited[i]=1;
            combi_Recur(cnt+1);
            arch_Visited[i]=0;
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
        }
    }
    
    combi_Recur(0);
    
    cout << answer << "\n";
    
    return 0;
}
