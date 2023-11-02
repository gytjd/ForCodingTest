#include <iostream>
#include <vector>
using namespace std;

bool ret;
int N,M;
char arr[10][10];
int check[30];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

vector<pair<int, int>> t;
vector<pair<int, int>> o;

void display_() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int is_stu(int x,int y) {
    
    for(int i=0;i<4;i++) {
        int dx=x,dy=y;
        while(dx>=0 and dx<N and dy>=0 and dy<N) {
            dx=dx+dir[i][0];
            dy=dy+dir[i][1];
            
            if(arr[dx][dy]=='O' or arr[dx][dy]=='T') {
                break;
            }
            
            if(arr[dx][dy]=='S') {
                return 1;
            }
        }
    }
    return 0;
}

int find_Student() {
    
    for(pair<int, int> temp:t) {
        if(is_stu(temp.first, temp.second)) {
            return 1; // 찾음
        }
    }
    return 0; // 못찾음
}

void recur_Object(int cnt) {
    
    if(cnt==3) {
        if(find_Student()==0) {
            ret=true;
        }
        return;
    }
    
    for(int i=0;i<M;i++) {
        if(check[i]==0) {
            check[i]=1;
            arr[o[i].first][o[i].second]='O';
            recur_Object(cnt+1);
            check[i]=0;
            arr[o[i].first][o[i].second]='X';
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
            
            if(arr[i][j]=='X') {
                o.push_back({i,j});
                M+=1;
            }
            
            if(arr[i][j]=='T') {
                t.push_back({i,j});
            }
        }
    }
    
    recur_Object(0);
    
    if(ret) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
    
    return 0;
}
