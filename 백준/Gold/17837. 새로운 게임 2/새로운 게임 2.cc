#include <iostream>
#include <queue>
using namespace std;

int N,K;
int arr[14][14];
int dir[5][2]={{0,0},{0,1},{0,-1},{-1,0},{1,0}};

struct Node {
    int x,y,dir,num;
};

deque<int> q[14][14];
vector<Node> v;

void display_() {
    
    cout << "\n";
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
//            if(q[i][j].size()==0) {
//                cout << 0 << " ";
//            }
//            else {
//                cout << q[i][j].front() << " ";
//            }
            
            cout << q[i][j].size() << " ";
        }
        cout << "\n";
    }
}

int white_(int x,int y,int d,int num) {
    
    int dx,dy;
    dx=x+dir[d][0];
    dy=y+dir[d][1];
    
    int check_temp;
    vector<int> temp;
    
    while(!q[x][y].empty()) {
        check_temp=q[x][y].front();
//        cout << check_temp << "\n";
        v[check_temp].x=dx;
        v[check_temp].y=dy;
        
        temp.push_back(check_temp);
        q[x][y].pop_front();
        
        if(check_temp==num) {
            v[check_temp].dir=d;
            break;
        }
    }
    
    for(long long i=temp.size()-1;i>=0;i--) {
        q[dx][dy].push_front(temp[i]);
    }
    
    if(q[dx][dy].size()>=4) {
        return 1;
    }
    else {
        return 0;
    }
    
}

int red_(int x,int y,int d,int num) {
    
    int dx,dy;
    int check_temp;
    dx=x+dir[d][0];
    dy=y+dir[d][1];
    
    while(!q[x][y].empty()) {
        check_temp=q[x][y].front();
        v[check_temp].x=dx;
        v[check_temp].y=dy;
        
        q[dx][dy].push_front(check_temp);
        q[x][y].pop_front();
        
        if(check_temp==num) {
            v[check_temp].dir=d;
            break;
        }
    }
    
    if(q[dx][dy].size()>=4) {
        return 1;
    }
    else {
        return 0;
    }
}

int change_dir(int d) {
    if(d==1) {
        return 2;
    }
    else if(d==2) {
        return 1;
    }
    else if(d==3) {
        return 4;
    }
    else {
        return 3;
    }
}
int blue_(int x,int y,int d,int num) {
    
    int temp=0;
    d=change_dir(d);
    
    int dx,dy;
    dx=x+dir[d][0];
    dy=y+dir[d][1];
    
    if(dx<=0 or dx>N or dy<=0 or dy>N or arr[dx][dy]==2) {
        dx=x;
        dy=y;
        v[num].dir=d;
        
        if(q[dx][dy].size()>=4) {
            return 1;
        }
        else {
            return 0;
        }
        
    }
    else {
        if(arr[dx][dy]==0) {
            temp=white_(x, y, d, num);
        }
        else if(arr[dx][dy]==1) {
            temp=red_(x, y, d, num);
        }
    }
    
    if(temp) {
        return 1;
    }
    else {
        return 0;
    }
    
}

int move_(int x,int y,int d,int num) {
    
    int temp=0;
    int dx,dy;
    dx=x+dir[d][0];
    dy=y+dir[d][1];
//    cout << dx << " " << dy << "\n";
    
    if(dx<=0 or dx>N or dy<=0 or dy>N) {
        temp=blue_(x,y,d,num);
    }
    else {
        if(arr[dx][dy]==0) {
            temp=white_(x, y, d,num);
        }
        else if(arr[dx][dy]==1) {
            temp=red_(x, y, d, num);
        }
        else if(arr[dx][dy]==2) {
            temp=blue_(x, y, d,num);
        }
    }
    
    if(temp) {
        return 1;
    }
    else {
        return 0;
    }
}

int is_check() {
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(q[i][j].size()>=4) {
                return 1;
            }
        }
    }
    return 0;
}
void start_() {
    
    int cnt_T=1;
    bool check_Flag=false;
    
    while(1) {
        
        if(cnt_T>1000) {
            cout << -1 << "\n";
            break;
        }
        
        for(int i=1;i<=K;i++) {
            int temp=0;
            
//            if(is_check()) {
//                cout << cnt_T << "\n";
//                check_Flag=true;
//                break;
//            }
//             display_();
//            cout << v[i].x << " " << v[i].y << " " <<v[i].dir << " " << v[i].num << "\n";
            temp=move_(v[i].x,v[i].y,v[i].dir,v[i].num);
//            cout << v[i].x << " " << v[i].y << " " <<v[i].dir << " " << v[i].num << "\n";
//            cout << "\n";
            if(temp) {
                cout << cnt_T << "\n";
                check_Flag=true;
                break;
            }
        }
        
        if(check_Flag) {
            break;
        }
        cnt_T+=1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> K;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin >> arr[i][j];
        }
    }
    
    v.push_back({0,0,0,0});
    for(int i=0;i<K;i++) {
        int start,end,dir;
        cin >> start >> end >> dir;
        
        v.push_back({start,end,dir,i+1});
        q[start][end].push_back(i+1);
    }
    
    start_();
    
    return 0;
}
