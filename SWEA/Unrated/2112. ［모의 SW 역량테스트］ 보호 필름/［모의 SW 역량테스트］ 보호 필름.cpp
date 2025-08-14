#include <iostream>
#include <algorithm>

using namespace std;

int T;
int ret;
int N,M,K;
int arr[24][24];
int visited[24];
int drug[24]; // 각 행에 어떤 약품(A=0/B=1) 적용할지

bool is_(int temp[24][24]) {
    for(int i=0;i<M;i++) {
        int curr=temp[0][i];
        int cnt=1;
        int maxCnt=cnt;
        for(int j=1;j<N;j++) {
            if(temp[j][i]==curr) cnt++;
            else { curr=temp[j][i]; cnt=1; }
            maxCnt=max(maxCnt,cnt);
            if(maxCnt>=K && j==N-1) break; // early exit
        }
        if(maxCnt<K) return false;
    }
    return true;
}

bool check_() {
    int temp[24][24];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(visited[i]) temp[i][j] = drug[i];
            else temp[i][j] = arr[i][j];
        }
    }
    return is_(temp);
}

// DFS: curr = 현재 투입 약품 수, idx = 현재 행
void DFS_recur(int curr,int idx) {
    // 가지치기: 이미 최소보다 크면 더 이상 탐색 불필요
    if(curr >= ret) return;

    if(check_()){
        ret=min(ret,curr);
        return;
    }
    
    if(idx==N) return;
    
    for(int i=idx;i<N;i++){
        if(visited[i]==0){
            // A 약품
            visited[i]=1;
            drug[i]=0;
            DFS_recur(curr+1, i+1);
            
            // B 약품
            drug[i]=1;
            DFS_recur(curr+1, i+1);
            
            visited[i]=0; // 복원
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    
    for(int test_case=1;test_case<=T;test_case++){
        cin >> N >> M >> K;
        ret=987654321;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin >> arr[i][j];
            }
        }
        
        DFS_recur(0,0);
        cout << "#" << test_case << " " << ret << "\n";
    }
    
    return 0;
}