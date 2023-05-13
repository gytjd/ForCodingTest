#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
int arr[53][53];
int dir[4][2]={{0,-1},{1,0},{0,1},{-1,0}};

int temp_dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

vector<pair<int, int>> bllizard;

deque<int> dq;
deque<int> tmp;

void display_() {
    
    cout << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            printf("%3d ",arr[i][j]);
        }
        cout << "\n";
    }
}

int result[4];

void init_(int x,int y) {
    
    int init_dir=0;
    int temp_size=1;
    
    int check_=0;
    bool check_Flag=false;
    
    while(1) {
        
        for(int i=0;i<temp_size;i++) {
            x=x+dir[init_dir][0];
            y=y+dir[init_dir][1];
            
            
            
            if(arr[x][y]!=0) {
//                cout << arr[x][y] << "\n";
                dq.push_back(arr[x][y]);
            }
            
            if(x==0 and y==0) {
                check_Flag=true;
                break;
            }
        }
        
        if(check_Flag){
            break;
        }
        
        check_+=1;
        init_dir=(init_dir+1)%4;
        
        if(check_==2) {
            temp_size+=1;
            check_=0;
        }
    }
}

void move_(int x,int y) {
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            arr[i][j]=0;
        }
    }
    
    int init_dir=0;
    int temp_size=1;
    
    int check_=0;
    bool check_Flag=false;
    
    while(!dq.empty()) {
        
        for(int i=0;i<temp_size;i++) {
            x=x+dir[init_dir][0];
            y=y+dir[init_dir][1];
            
            arr[x][y]=dq.front();
//            cout << arr[x][y] << "\n";
            dq.pop_front();
            
            if(dq.empty()) {
                check_Flag=true;
                break;
            }
        }
        
        if(check_Flag){
            break;
        }
        
        check_+=1;
        init_dir=(init_dir+1)%4;
        
        if(check_==2) {
            temp_size+=1;
            check_=0;
        }
    }
    
}

int bloom_(int x,int y) {
    
    int dx,dy;
    int init_dir=0;
    int temp_size=1;
    
    int check_=0;
    bool check_Flag=false;
    int check_Cnt=0;
    
    int bloom_Cnt=0;
    
    int prev;
    int curr;
    
    vector<pair<int, int >> v;
    
    while(1) {
        
        for(int i=0;i<temp_size;i++) {
            
            dx=x;dy=y;
            prev=arr[dx][dy];
            
            x=x+dir[init_dir][0];
            y=y+dir[init_dir][1];
            curr=arr[x][y];
            
//            cout << prev << " " << curr << "\n";
            
            if(prev==curr) {
                check_Cnt+=1;
                v.push_back({dx,dy});
            }
            else {
                v.push_back({dx,dy});
                check_Cnt+=1;
                
//                cout << check_Cnt << "\n";
                
                if(check_Cnt>=4) {
                    
                    bloom_Cnt+=1;
                    unsigned long v_Size=v.size();
                    for(int i=0;i<v_Size;i++) {
                        arr[v[i].first][v[i].second]=0;
//                        cout << v[i].first << " " << v[i].second << "\n";
                    }
//                    cout << prev << "\n";
                    result[prev]+=check_Cnt;
                    v.clear();
                    check_Cnt=0;
                }
                else {
                    v.clear();
                    check_Cnt=0;
                }
            }
            
            
            if(x==0 and y==0) {
                check_Flag=true;
                break;
            }
        }
        
        if(check_Flag){
            break;
        }
        
        check_+=1;
        init_dir=(init_dir+1)%4;
        
        if(check_==2) {
            temp_size+=1;
            check_=0;
        }
    }
    
    return bloom_Cnt;
}

void make_(int x,int y) {
    
    int dx,dy;
    int init_dir=0;
    int temp_size=1;
    
    int check_=0;
    bool check_Flag=false;
    int check_Cnt=0;
    
    int prev;
    int curr;
    
    while(1) {
        
        for(int i=0;i<temp_size;i++) {
            dx=x; dy=y;
            prev=arr[dx][dy];
            
            x=x+dir[init_dir][0];
            y=y+dir[init_dir][1];
            curr=arr[x][y];
            
            
            if(prev==curr) {
                check_Cnt+=1;
            }
            else {
                check_Cnt+=1;
                
//                cout << check_Cnt << " " << arr[dx][dy] << "\n";
                
                tmp.push_back(check_Cnt);
                tmp.push_back(arr[dx][dy]);
                check_Cnt=0;
                
            }
            
            
            if(x==0 and y==0) {
                check_Flag=true;
                break;
            }
        }
        
        if(check_Flag){
            break;
        }
        
        check_+=1;
        init_dir=(init_dir+1)%4;
        
        if(check_==2) {
            temp_size+=1;
            check_=0;
        }
    }
    
    
}

void last_(int x,int y) {
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            arr[i][j]=0;
        }
    }
    
    int init_dir=0;
    int temp_size=1;
    
    int check_=0;
    bool check_Flag=false;
    
    while(!tmp.empty()) {
        
        for(int i=0;i<temp_size;i++) {
            x=x+dir[init_dir][0];
            y=y+dir[init_dir][1];
            
            arr[x][y]=tmp.front();
            tmp.pop_front();
            
            if(tmp.empty()) {
                check_Flag=true;
                break;
            }
            
            if(x==0 and y==0) {
                check_Flag=true;
                break;
            }
        }
        
        if(check_Flag){
            break;
        }
        
        check_+=1;
        init_dir=(init_dir+1)%4;
        
        if(check_==2) {
            temp_size+=1;
            check_=0;
        }
    }
    
}

int is_check() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(arr[i][j]!=0) {
                return 0;
            }
        }
    }
    return 1;
}
void go_() {
    
    for(int i=0;i<M;i++) {
        
        if(is_check()) {
            continue;
        }
        
        int dx=N/2,dy=N/2;
        int D=bllizard[i].first;
        int S=bllizard[i].second;
        
        for(int j=0;j<S;j++) {
            dx=dx+temp_dir[D-1][0];
            dy=dy+temp_dir[D-1][1];
            
            arr[dx][dy]=0;
        }
        
//        cout << "#####" << '\n';
        init_(N/2, N/2);
//        display_();
        move_(N/2,N/2);
//        display_();
        
        while(1) {
            int temp=bloom_(N/2, N/2);
//            display_();
            
            if(temp==0) {
                break;
            }
            
            init_(N/2, N/2);
            move_(N/2, N/2);
        }
        
        tmp.clear();
        
        make_(N/2, N/2);
        
        tmp.pop_front();
        tmp.pop_front();
        
        last_(N/2, N/2);
//        display_();
    }
    
    cout << result[1]*1+result[2]*2+result[3]*3 << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int i=0;i<M;i++) {
        int d,s;
        cin >> d >> s;
        bllizard.push_back({d,s});
    }
    
    go_();
    
    return 0;
}
