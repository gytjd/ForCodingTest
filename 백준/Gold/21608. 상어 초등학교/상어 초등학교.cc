#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node {
    int x,y;
    int empty_Cnt;
    int love_Cnt;
};

int N;
int arr[24][24];
int person[404][4];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

bool cmp(Node a,Node b) {
    if(a.love_Cnt==b.love_Cnt) {
        
        if(a.empty_Cnt==b.empty_Cnt) {
            
            if(a.x==b.x) {
                return a.y<b.y;
            }
            return a.x<b.x;
        }
        return a.empty_Cnt>b.empty_Cnt;
    }
    return a.love_Cnt>b.love_Cnt;
}

void display_() {
    
    cout << "\n";
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
int is_love(int temp,int num) {
    
    for(int i=0;i<4;i++) {
        if(person[temp][i]==num) {
            return 1;
        }
    }
    
    return 0;
}

void go_(int temp) {
    
    vector<Node> tot;
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            
            if(arr[i][j]!=0) {
                continue;
            }
            
            
            Node stu;
            int dx,dy;
            
            stu.x=i;
            stu.y=j;
            stu.love_Cnt=0;
            stu.empty_Cnt=0;
            
            for(int k=0;k<4;k++) {
                dx=stu.x+dir[k][0];
                dy=stu.y+dir[k][1];
                
                if(dx<=0 or dx>N or dy<=0 or dy>N) {
                    continue;
                }
                
                if(is_love(temp, arr[dx][dy])) {
                    stu.love_Cnt+=1;
                }
                
                if(arr[dx][dy]==0) {
                    stu.empty_Cnt+=1;
                }
            }
            
            
            
            tot.push_back(stu);
        }
    }
    
    sort(tot.begin(), tot.end(), cmp);
    Node stu=tot[0];
    
    arr[stu.x][stu.y]=temp;
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;

    
    for(int i=1;i<=N*N;i++) {
        int num;
        cin >> num;
        
        for(int j=0;j<4;j++) {
            cin >>person[num][j];
        }
        
        go_(num);
    }
    
    int ret=0;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            
            int x,y;
            x=i;
            y=j;
            int dx,dy;
            int temp_Cnt=0;
            
            for(int k=0;k<4;k++) {
                dx=x+dir[k][0];
                dy=y+dir[k][1];
                
                if(dx<=0 or dx>N or dy<=0 or dy>N) {
                    continue;
                }
                
                if(is_love(arr[i][j], arr[dx][dy])) {
                    temp_Cnt+=1;
                }
            }
            
            if(temp_Cnt!=0) {
                ret+=pow(10, temp_Cnt-1);
            }
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}
