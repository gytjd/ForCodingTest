#include <iostream>
#include <queue>
using namespace std;

int N;
int arr[104][104];
int dir[4][2]={{0,1},{-1,0},{0,-1},{1,0}};


void make_curve(int x,int y,int d,int g) {
    
    int dx,dy;
    
    deque<int> q;
    deque<int> tmp;
    
    arr[x][y]=1;
    
    dx=x+dir[d][0];
    dy=y+dir[d][1];
    
    if(dx<0 or dx>100 or dy<0 or dy>100) {
        return;
    }
    
    arr[dx][dy]=1;
    q.push_back(d);
    
    for(int i=0;i<g;i++) {
        
        tmp=q;
        while(!tmp.empty()) {
            
            d=tmp.back();
            tmp.pop_back();
            d=(d+1)%4;
            
            dx=dx+dir[d][0];
            dy=dy+dir[d][1];
            
            if(dx<0 or dx>100 or dy<0 or dy>100) {
                continue;
            }
            
            arr[dx][dy]=1;
            q.push_back(d);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int x,y,d,g;
        cin >> x >> y >> d >> g;
        make_curve(y, x, d, g);
    }
    
    int count_T=0;
    for(int i=0;i<=100;i++) {
        for(int j=0;j<=100;j++) {
            
            if(arr[i][j]==1 and arr[i][j+1]==1 and arr[i+1][j]==1 and arr[i+1][j+1]==1) {
                count_T+=1;
            }
        }
    }
    
    cout << count_T << "\n";
    return 0;
}
