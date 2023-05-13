#include <iostream>
#include <deque>

using namespace std;

int arr[104][104];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int cnt_T;

pair<int, char> visited[10004];

int N,M,K;

void display_() {
    cout << "\n";
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
void start_(int x,int y) {
    
    int curr_dir=0;
    int dx,dy;
    
    deque<pair<int, int>> q;
    q.push_back({x,y});
    
    arr[x][y]=1;
    
    while(1) {
        
//        display_();
        
        if(cnt_T>10000) {
            cout << cnt_T << "\n";
            break;
        }
//        cout << x << " " << y << "\n";
        
        dx=x+dir[curr_dir][0];
        dy=y+dir[curr_dir][1];
        
        cnt_T+=1;
        
//        cout << dx << " " << dy << "\n";
        
        if(dx<=0 or dx>N or dy<=0 or dy>N or arr[dx][dy]==1) {
            break;
        }
        
        if(arr[dx][dy]==65) {
            q.push_back({dx,dy});
            arr[dx][dy]=1;
        }
        else {
            arr[dx][dy]=1;
            q.push_back({dx,dy});
            
            arr[q.front().first][q.front().second]=0;
            q.pop_front();
        }
        
        x=dx;
        y=dy;
        
//        cout << visited[cnt_T].first << "\n";

        
        if(visited[cnt_T].first!=0) {
            
            if(visited[cnt_T].second=='D') {
                curr_dir=(curr_dir+1)%4;
            }
            else {
                curr_dir=(curr_dir+3)%4;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    cin >> M;
    for(int i=0;i<M;i++) {
        int start,end;
        cin >> start >> end;
        arr[start][end]=65;
    }
    
    cin >> K;
    for(int i=0;i<K;i++) {
        int start;
        char end;
        cin >> start >> end;
        visited[start].first=start;
        visited[start].second=end;
    }
    
    start_(1, 1);
    
    cout << cnt_T << "\n";
    return 0;
}
