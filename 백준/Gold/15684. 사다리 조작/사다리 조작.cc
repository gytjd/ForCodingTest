#include <iostream>
using namespace std;

int N,M,H;
int arr[31][11];
int count_T=987654321;

int is_right() {
    
    for(int i=1;i<=N;i++) {
        int temp=i;
        int j=1;
        
        while(j!=H+1) {
            if(arr[j][temp]!=0) {
                temp=arr[j][temp];
            }
            j+=1;
        }
        
        if(temp!=i) {
            return 0;
        }
    }
    
    return 1;
}

void DFS_recur(int x,int y,int depth,int count) {
    
    if(depth>count) {
        return;
    }
    
    if(is_right()) {
        if(count_T>depth) {
            count_T=depth;
        }
    }
    
    for(int i=x;i<=H;i++) {
        for(int j=y;j<=N;j++) {
            
            if(arr[i][j]==0) {
                
                if(arr[i][j+1]==0 and j+1<=N) {
                    arr[i][j]=j+1; arr[i][j+1]=j;
                    
                    DFS_recur(i,1,depth+1,count);
                    
                    arr[i][j]=0; arr[i][j+1]=0;
                }
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> H;
    
    for(int i=0;i<M;i++) {
        int start,end;
        cin >> start >> end;
        
        arr[start][end]=end+1;
        arr[start][end+1]=end;
    }
    
    for(int i=0;i<4;i++) {
        DFS_recur(1,1,0,i);
        
        if(count_T!=987654321) {
            break;
        }
    }
    
    if(count_T==987654321) {
        cout << -1 << "\n";
    }
    else {
        cout << count_T << "\n";
    }
    
    return 0;
}
