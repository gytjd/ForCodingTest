#include <iostream>

using namespace std;

int arr[20][20];
int dir[4][2]={{-1,1},{0,1},{1,1},{1,0}};

bool BFS_iter(int x,int y) {
    
    bool check_Flag=false;
    bool dir_Flag=false;
    
    int dx,dy;
    int temp_Num=arr[x][y];
    
    for(int i=0;i<4;i++) {
    
        check_Flag=false;
        dir_Flag=false;
        
        dx=x-dir[i][0];
        dy=y-dir[i][1];
        
        if(dx>=0 and dx<19 and dy>=0 and dy<19) {
        
            if(arr[dx][dy]==temp_Num) {
                check_Flag=true;
            }
        }
        
        dx=x;
        dy=y;
        for(int j=0;j<4;j++) {
            dx=dx+dir[i][0];
            dy=dy+dir[i][1];
            
//            cout << dx << " " << dy << "\n";
            
            if(dx<0 or dx>=19 or dy<0 or dy>=19 or !arr[dx][dy]) {
                dir_Flag=true;
                continue;
            }
            
            if(arr[dx][dy]!=temp_Num) { // 연속되지 않는다는거
                check_Flag=true;
            }
        }
        
//        cout << "# " << check_Flag << " " << dir_Flag << "\n";
        
        dx=dx+dir[i][0];
        dy=dy+dir[i][1];
        
        if(dx>=0 and dx<19 and dy>=0 and dy<19) {
            
            if(arr[dx][dy]==temp_Num) {
                check_Flag=true;
            }
        }
        
        if(!check_Flag and !dir_Flag) {
            return false;
        }
        
//        cout << "# " << check_Flag << " " << dir_Flag << "\n";
        
    }
    
    return true;
}
void go_() {
    
    bool check_Flag=false;
    for(int i=0;i<19;i++) {
        for(int j=0;j<19;j++) {
            if(arr[j][i] and !check_Flag) {
                bool ret_Flag=BFS_iter(j, i);
                if(!ret_Flag) {
                    cout << arr[j][i] << "\n";
                    cout << j+1 << " " << i+1 << "\n";
                    check_Flag=true;
                }
            }
        }
    }
    
    if(!check_Flag) {
        cout << 0 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    for(int i=0;i<19;i++) {
        for(int j=0;j<19;j++) {
            cin >> arr[i][j];
        }
    }
    
    go_();
    
    return 0;
}
