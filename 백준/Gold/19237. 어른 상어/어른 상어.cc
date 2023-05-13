#include <iostream>
#include <vector>

using namespace std;

struct Shark {
    int x,y,dir,num;
    bool check_Flag;
    int pri[4][4];
};

pair<int, int> arr[24][24];
int visited[24][24];
Shark v[404];

int N,M,K;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

void display_() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << arr[i][j].first << " " <<arr[i][j].second << " ";
        }
        cout << "\n";
    }
}

void init_() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            visited[i][j]=0;
        }
    }
}

int tmp_to_(Shark temp) {
    
    int x,y;
    int dx,dy;
    x=temp.x;
    y=temp.y;
    
    for(int i=0;i<4;i++) {
        int temp_dir=temp.pri[temp.dir][i];
        
        dx=x+dir[temp_dir][0];
        dy=y+dir[temp_dir][1];
        
        if(dx<0 or dx>=N or dy<0 or dy>=N) {
            continue;
        }
        
        if(arr[dx][dy].first==arr[x][y].first) {
            return temp_dir;
        }
    }
    
    return -1;
}
int to_(Shark temp) {
    
    int x,y;
    int dx,dy;
    x=temp.x;
    y=temp.y;
    
    for(int i=0;i<4;i++) {
        int temp_dir=temp.pri[temp.dir][i];
        
        dx=x+dir[temp_dir][0];
        dy=y+dir[temp_dir][1];
        
        if(dx<0 or dx>=N or dy<0 or dy>=N) {
            continue;
        }
        
        if(arr[dx][dy].first==0) {
            return temp_dir;
        }
    }
    
    return -1;

}

void clear_() {
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            
            if(visited[i][j]==1) {
                continue;
            }
            
            if(arr[i][j].first!=0) {
                arr[i][j].second-=1;
                
                if(arr[i][j].second==0) {
                    arr[i][j].first=0;
                }
            }
        }
    }
}

int is_fin() {
    
    for(int i=2;i<=M;i++) {
        if(!v[i].check_Flag) {
            return 0;
        }
    }
    
    return 1;
}
void go_() {
    
    bool tot_Flag=false;
    int count_T=0;
    while(count_T<=1000) {

        if(is_fin()) {
            tot_Flag=true;
            break;
        }
        
        pair<int, int> vec_temp[404];
        
        for(int i=1;i<=M;i++) {
            
            if(v[i].check_Flag) {
                continue;
            }
            
            int x,y,temp_dir;
            int dx,dy;
            
            x=v[i].x;
            y=v[i].y;
            temp_dir=to_(v[i]);

            
            if(temp_dir==-1) {
                temp_dir=tmp_to_(v[i]);
                dx=x+dir[temp_dir][0];
                dy=y+dir[temp_dir][1];
                
                

                vec_temp[i]=make_pair(dx, dy);
                
                v[i].x=dx;
                v[i].y=dy;
                v[i].dir=temp_dir;
            }
            else {
                dx=x+dir[temp_dir][0];
                dy=y+dir[temp_dir][1];
                
                vec_temp[i]=make_pair(dx, dy);
                
                v[i].x=dx;
                v[i].y=dy;
                v[i].dir=temp_dir;
            }
        }
        
        init_();
        
        
        for(int i=1;i<=M;i++) {
            
            if(v[i].check_Flag)
                continue;
            
            
            if(arr[vec_temp[i].first][vec_temp[i].second].first==0 or arr[vec_temp[i].first][vec_temp[i].second].first==i) {
                arr[vec_temp[i].first][vec_temp[i].second].first=i;
                arr[vec_temp[i].first][vec_temp[i].second].second=K;
                visited[vec_temp[i].first][vec_temp[i].second]=1;
            }
            else {
                if(arr[vec_temp[i].first][vec_temp[i].second].first<i) {
                    v[i].check_Flag=true;
                }
            }
        }
        
        clear_();
        

        count_T+=1;
    }
    
    if(tot_Flag) {
        cout << count_T << "\n";
    }
    else {
        cout << -1 << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> K;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            
            int data;
            cin >> data;
            arr[i][j]=make_pair(data, 0);
            
            if(arr[i][j].first!=0) {
                arr[i][j].second=K;
                v[arr[i][j].first]={i,j,0,K,false};
            }
        }
    }
    
    for(int i=1;i<=M;i++) {
        cin >> v[i].dir;
        v[i].dir-=1;
    }
    
    for(int i=1;i<=M;i++) {
        for(int j=0;j<4;j++) {
            for(int k=0;k<4;k++) {
                cin >> v[i].pri[j][k];
                v[i].pri[j][k]-=1;
            }
        }
    }
    
    go_();
    return 0;
}
