#include <iostream>
#include <cstring>
using namespace std;


int N,M,C;
int arr[54][54];
int visited[54][54][54][54];

int go_(int x,int y,int cnt,int prev) {
    if(x>N or y>M) {
        return 0;
    }
    
    if(x==N and y==M) {
        if(cnt==0 and arr[x][y]==0) {
            return 1;
        }
        
        if(cnt==1 and arr[x][y]>prev) {
            return 1;
        }
        return 0;
    }
    
    int &ret=visited[x][y][cnt][prev];
    
    if(ret!=-1) {
        return ret;
    }
    
    ret=0;
    
    if(arr[x][y]==0) {
        ret=(go_(x, y+1, cnt, prev)+go_(x+1, y, cnt, prev))%1000007;
    }
    else if(arr[x][y]>prev) {
        ret=(go_(x, y+1, cnt-1, arr[x][y])+go_(x+1, y, cnt-1, arr[x][y]))%1000007;
    }
    
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    memset(visited, -1, sizeof(visited));
    
    cin >> N >> M >> C;
    
    for(int i=0;i<C;i++) {
        int start,end;
        cin >> start >> end;
        arr[start][end]=i+1;
    }
    
    for(int i=0;i<=C;i++) {
        cout << go_(1, 1, i, 0) << " ";
    }
    cout << "\n";
    
    return 0;
}
