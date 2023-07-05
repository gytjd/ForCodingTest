#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char arr[504][504];
vector<pair<int, int>> v;

void display_() {
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
}
void go_() {
    
    int x,y;
    int dx,dy;
    
    for(int i=0;i<v.size();i++) {
        x=v[i].first;
        y=v[i].second;
        
        for(int j=0;j<4;j++) {
            dx=x+dir[j][0];
            dy=y+dir[j][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M) {
                continue;
            }
            
            if(arr[dx][dy]=='W') {
                cout << 0 << "\n";
                exit(0);
            }
            
            if(arr[dx][dy]=='.') {
                arr[dx][dy]='D';
            }
        }
    }
    
    cout << 1 << "\n";
    display_();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        for(int j=0;j<M;j++) {
            arr[i][j]=a[j];
            
            if(arr[i][j]=='S') {
                v.push_back({i,j});
            }
        }
    }
    
    go_();
    
    return 0;
}
