#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int r,c,m,s,d;
};

int N,M,K;
int dir[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

deque<Node> arr[54][54];
int visited[54][54];

void display_() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            
            if(arr[i][j].size()==0) {
                cout << 0 << " ";
            }
            else {
                cout << arr[i][j][0].m << " ";
            }
        }
        cout << "\n";
    }
}

void go_() {
    
    while(K!=0) {
        
        
        deque<Node> temp[54][54];
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                
                if(arr[i][j].size()!=0) {
                    unsigned long arr_Size=arr[i][j].size();
                    for(int k=0;k<arr_Size;k++) {
                        
                        Node shark=arr[i][j].front();
                        int x,y,temp_dir;
                        x=shark.r;
                        y=shark.c;
                        temp_dir=shark.d;
                        
    //                    cout << x << " " << y << "\n";
                        
                        shark.r=(x+(dir[temp_dir][0]*shark.s))%N;
                        shark.c=(y+(dir[temp_dir][1]*shark.s))%N;
                        
                        if(shark.r<0) {
                            shark.r=abs(shark.r)%N;
                            shark.r=-shark.r+N;
                        }
                        
                        if(shark.c<0) {
                            shark.c=abs(shark.c)%N;
                            shark.c=-shark.c+N;
                        }
                        
    //                    cout << shark.r << " " << shark.c << "\n";
                        
                        temp[shark.r][shark.c].push_back(shark);
                        arr[i][j].pop_front();
                    }
                }
            }
        }
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                
                int temp_cnt=0;
                int temp_M=0;
                int temp_S=0;
                bool even_Flag=false;
                bool odd_Flag=false;
                bool check_Flag=false;
                
                if(temp[i][j].size()>=2) {
                    
                    unsigned long temp_Size=temp[i][j].size();
                    
                    for(int k=0;k<temp_Size;k++) {
                        Node temp_shark=temp[i][j].front();
                        temp_M+=temp_shark.m;
                        temp_S+=temp_shark.s;
                        
                        if(temp_shark.d%2==0) {
                            even_Flag=true;
                            
                            if(odd_Flag) {
                                check_Flag=true;
                            }
                        }
                        else {
                            
                            odd_Flag=true;
                            
                            if(even_Flag) {
                                check_Flag=true;
                            }
                        }
                        
                        temp[i][j].pop_front();
                        temp_cnt+=1;
                    }
                    
                    temp_M/=5;
                    temp_S/=temp_cnt;
                    
                    if(temp_M==0) {
                        continue;
                    }
                    
                    
                    for(int k=0;k<4;k++) {
                        
                        if(check_Flag) {
                            arr[i][j].push_back({i,j,temp_M,temp_S,k*2+1});
                        }
                        else {
                            arr[i][j].push_back({i,j,temp_M,temp_S,k*2});
                        }
                    }
                }
                else if(temp[i][j].size()==1) {
                    arr[i][j].push_back(temp[i][j].front());
                    temp[i][j].pop_front();
                    
                }
            }
        }
        
        
        K-=1;
    }
    
//    display_();
    
    
    int ret=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            
            if(arr[i][j].size()!=0) {
                for(int k=0;k<arr[i][j].size();k++) {
                    ret+=arr[i][j][k].m;
                }
            }
        }
    }
    
    
    cout << ret << "\n";
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> K;
    
    for(int i=0;i<M;i++) {
        int r,c,m,s,d;
        cin >> r >> c >> m >> s >> d;
        
        visited[r-1][c-1]=1;
        arr[r-1][c-1].push_back({r-1,c-1,m,s,d});
    }
    
    go_();
    
    return 0;
}
