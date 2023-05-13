#include <iostream>
using namespace std;

int arr[503][503];
int N;
int startX,startY;

int dir[4][2]={{0,-1},{1,0},{0,1},{-1,0}};

struct Node {
    int x,y,per;
};

int sand_dir[4][10][3]={{{-1,1,1},{-1,0,7},{-2,0,2},{-1,-1,10},{0,-2,5},{1,-1,10},{1,0,7},{2,0,2},{1,1,1},{0,-1,0}},
    {{0,1,7},{0,2,2},{-1,1,1},{-1,-1,1},{0,-1,7},{0,-2,2},{1,-1,10},{2,0,5},{1,1,10},{1,0,0}},
    {{0,2,5},{-1,1,10},{-1,0,7},{-2,0,2},{-1,-1,1},{1,-1,1},{1,0,7},{2,0,2},{1,1,10},{0,1,0}},
    {{0,1,7},{0,2,2},{-1,1,10},{-2,0,5},{-1,-1,10},{0,-1,7},{0,-2,2},{1,-1,1},{1,1,1},{-1,0,0}}
};
//int sand_dir_A[10][3]={{-1,1,1},{-1,0,7},{-2,0,2},{-1,-1,10},{0,-1,0},{0,-2,5},{1,-1,10},{1,0,7},{2,0,2},{1,1,1}};
//int sand_dir_B[10][3]={{0,1,7},{0,2,2},{-1,1,1},{-1,-1,1},{0,-1,7},{0,-2,2},{1,-1,10},{1,0,0},{2,0,5},{1,1,10}};
//int sand_dir_C[10][3]={{0,1,0},{0,2,5},{-1,1,10},{-1,0,7},{-2,0,2},{-1,-1,1},{1,-1,1},{1,0,7},{2,0,2},{1,1,10}};
//int sand_dir_D[10][3]={{0,1,7},{0,2,2},{-1,1,10},{-1,0,0},{-2,0,5},{-1,-1,10},{0,-1,7},{0,-2,2},{1,-1,1},{1,1,1}};

int visited[503][503];

void display_() {
    cout << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
void go_() {
    
    
    int tot=0;
    
    int dx,dy;
    int temp_sand;
    int init_dir=0;
    int init_size=1;
    
    int check_=0;
    
    int br_Flag=false;
    
    
    while(1) {

        
        for(int i=0;i<init_size;i++) {
//            cout << startX << " " << startY << "\n";
            startX=startX+dir[init_dir][0];
            startY=startY+dir[init_dir][1];
            
            int temp=arr[startX][startY];
            
            for(int j=0;j<10;j++) {
                dx=startX+sand_dir[init_dir][j][0];
                dy=startY+sand_dir[init_dir][j][1];
                temp_sand=(double)arr[startX][startY]/100*sand_dir[init_dir][j][2];
                
//                cout << temp_sand << "\n";
                
                if(j==9) {
//                    cout << temp << "\n";
                    temp_sand=temp;
                }

                temp-=temp_sand;
                
                if(dx<0 or dx>=N or dy<0 or dy>=N) {
                    tot+=temp_sand;
                    continue;
                }
                
                
                arr[dx][dy]+=temp_sand;
            }
            
            arr[startX][startY]=0;
//            display_();
            
            if(startX==0 and startY==0) {
                br_Flag=true;
                break;
            }
            
        }
        
        if(br_Flag){
            cout << tot << "\n";
            break;
        }
        
        check_+=1;
        init_dir=(init_dir+1)%4;
        
        if(check_==2) {
            check_=0;
            init_size+=1;
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
        }
    }
    startX=N/2; startY=N/2;
    
    go_();
    
    return 0;
}
