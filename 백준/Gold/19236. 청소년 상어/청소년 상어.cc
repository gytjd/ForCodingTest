#include <iostream>
using namespace std;

struct Node {
    int x,y,num,dir;
    bool check_Flag;
};

int dir[9][2]={{0,0},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
int arr[4][4];
Node check[20];
int max_ret=-987654321;

void display_(int arr[4][4]) {
    
    cout << "\n";
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void go_(int arr[4][4],Node check[20],int currX,int currY,int sum) {
    
    
    
    int temp[4][4];
    Node temp_check[20];
    
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            temp[i][j]=arr[i][j];
        }
    }
    for(int i=0;i<20;i++) {
        temp_check[i]=check[i];
    }


    Node shark=temp_check[temp[currX][currY]];
    temp_check[temp[currX][currY]].check_Flag=true;
    sum+=shark.num;
    
    if(max_ret<sum) {
        max_ret=sum;
    }
    
    
    
    for(int i=1;i<=16;i++) {
        
        if(temp_check[i].check_Flag) {
            continue;
        }
        
        int x,y,temp_dir;
        int dx,dy;
        
        x=temp_check[i].x;
        y=temp_check[i].y;
        temp_dir=temp_check[i].dir;
        
        while(1) {
            dx=x+dir[temp_dir][0];
            dy=y+dir[temp_dir][1];
            
            if(dx>=0 and dx<4 and dy>=0 and dy<4 and(dx!=shark.x or dy!=shark.y)) {
                
                int temp_N=temp[dx][dy];
                int temp_x=temp_check[temp_N].x;
                int temp_y=temp_check[temp_N].y;
                 
                temp_check[i].x=temp_x;
                temp_check[i].y=temp_y;
                temp_check[i].dir=temp_dir;
                
                temp_check[temp_N].x=x;
                temp_check[temp_N].y=y;
                
                temp[dx][dy]=i;
                temp[x][y]=temp_N;
                
                break;
            }
            
            temp_dir=(temp_dir+1)%9;
            if(temp_dir==0) {
                temp_dir=1;
            }
        }
    }
    
    int x,y;
    x=shark.x;
    y=shark.y;

    
    for(int i=0;i<3;i++) {
        
        x=x+dir[shark.dir][0];
        y=y+dir[shark.dir][1];
        
        if(x>=0 and x<4 and y>=0 and y<4 and !temp_check[temp[x][y]].check_Flag) {
            go_(temp, temp_check, x, y,sum);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            int num,dir;
            cin >> num >> dir;
            
            arr[i][j]=num;
            check[num]={i,j,num,dir,false};
        }
    }
    
    go_(arr, check, 0, 0, 0);
    cout << max_ret << "\n";
    
    return 0;
}
