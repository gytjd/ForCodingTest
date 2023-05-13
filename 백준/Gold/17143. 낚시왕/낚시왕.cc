#include <iostream>

using namespace std;

int R,C,M;
int dir[5][2]={{0,0},{-1,0},{1,0},{0,1},{0,-1}};

struct Shark {
    int r,c,s,d,z;
    int num;
};


Shark shark[10004];
int visited[10004];
pair<int, int> arr[104][104];
pair<int, int> temp[104][104];

void display_() {
    cout << "\n";
    for(int i=1;i<=R;i++) {
        for(int j=1;j<=C;j++) {
            cout << arr[i][j].first << " " ;
        }
        cout << "\n";
    }
}

void init_() {
    for(int i=0;i<104;i++) {
        for(int j=0;j<104;j++) {
            temp[i][j].first=0;
            temp[i][j].second=0;
        }
    }
}

int find_minPos(int c) {
    
    int temp=0;
    for(int i=1;i<=R;i++) {
        if(arr[i][c].first!=0) {
            temp=arr[i][c].first;
            arr[i][c].first=0;
            visited[arr[i][c].second]=1;
            return temp;
        }
    }
    
    return 0;
}

void fish_move(int x,int y,int s,int d,int z,int num) {
    
    int dx,dy;
    
    for(int i=0;i<s;i++) {
        dx=x+dir[d][0];
        dy=y+dir[d][1];
        
        if(dx<=0 or dx>R or dy<=0 or dy>C) {
            if(d==1 or d==3) {
                d+=1;
            }
            else {
                d-=1;
            }
            
            dx=x+dir[d][0];
            dy=y+dir[d][1];
        }
        x=dx;
        y=dy;
    }
    
    if(temp[x][y].first<z) {
        visited[temp[x][y].second]=1;
        
        temp[x][y].first=z;
        temp[x][y].second=num;
        
        shark[num].r=x;
        shark[num].c=y;
        shark[num].d=d;
    }
    else {
        visited[num]=1;
    }
    
}

void move_() {
    
    init_();
    for(int i=1;i<=M;i++) {
        if(visited[i]==0) {
            fish_move(shark[i].r, shark[i].c,shark[i].s,shark[i].d,shark[i].z,i);
        }
    }
    
    for(int i=0;i<104;i++) {
        for(int j=0;j<104;j++) {
            arr[i][j].first=temp[i][j].first;
            arr[i][j].second=temp[i][j].second;
        }
    }
}
void start_() {
    
    int count_T=0;
    for(int i=1;i<=C;i++) {
        count_T+=find_minPos(i);
        move_();
//        display_();
    }
    
    cout << count_T << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> R >> C >> M;
    
    for(int i=1;i<=M;i++) {
        cin >> shark[i].r >> shark[i].c >> shark[i].s >> shark[i].d >> shark[i].z;
        
        if(shark[i].d==1 or shark[i].d==2) {
            shark[i].s%=((R-1)*2);
        }
        else {
            shark[i].s%=((C-1)*2);
        }
        arr[shark[i].r][shark[i].c].first=shark[i].z;
        arr[shark[i].r][shark[i].c].second=i;
    }
    
    start_();
    
    return 0;
}
