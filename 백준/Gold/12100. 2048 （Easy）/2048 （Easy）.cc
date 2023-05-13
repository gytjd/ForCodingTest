#include <iostream>
using namespace std;

int N;
int arr[24][24];
int visited[24][24];
int max_tot;
//
//
//void display_(int arr_Tmp[24][24]) {
//    for(int i=0;i<N;i++) {
//        for(int j=0;j<N;j++) {
//            cout << arr_Tmp[i][j] << " ";
//        }
//        cout << "\n";
//    }
//}

void init_visited() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            visited[i][j]=0;
        }
    }
}

void gravity_(int arr_Tmp[24][24]) {
    
    
    init_visited();
    
    for(int i=0;i<N;i++) {
        
        for(int j=N-2;j>=0;j--) {
            if(arr_Tmp[j][i]==0) {
                continue;
            }
            
            int temp=j;
            
            while(temp<N-1) {
                
                if(arr_Tmp[temp+1][i]==0) {
                    temp+=1;
                }
                else {
                    break;
                }
            }
            
            if(temp==N-1) {
                arr_Tmp[temp][i]=arr_Tmp[j][i];
                arr_Tmp[j][i]=0;
            }
            else {
                
                if(arr_Tmp[temp+1][i]==arr_Tmp[j][i] and visited[temp+1][i]==0) {
                    visited[temp+1][i]=1;
                    arr_Tmp[temp+1][i]+=arr_Tmp[j][i];
                    arr_Tmp[j][i]=0;
                }
                else {
                    
                    if(temp==j) {
                        continue;
                    }
                    
                    arr_Tmp[temp][i]=arr_Tmp[j][i];
                    arr_Tmp[j][i]=0;
                }
                
            }
        }
    }
}

void go_left_(int ret[24][24]) {
    
    int temp[24][24];
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            temp[i][j]=ret[j][N-i-1];
        }
    }
    
    gravity_(temp);
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            ret[i][j]=temp[N-j-1][i];
        }
    }
}

void go_right_(int ret[24][24]) {
    
    int temp[24][24];
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            temp[i][j]=ret[N-j-1][i];
        }
    }
    
    gravity_(temp);
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            ret[i][j]=temp[j][N-i-1];
        }
    }
}

void go_up_(int ret[24][24]) {
    
    int temp[24][24];
    
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            temp[i][j]=ret[N-i-1][N-j-1];
        }
    }
    
    gravity_(temp);
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            ret[i][j]=temp[N-i-1][N-j-1];
        }
    }
}

void start_(int temp[24][24],int depth) {
    
    if(depth==5) {
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(temp[i][j]>max_tot) {
                    max_tot=temp[i][j];
                }
            }
        }
        return;
    }
    
    int ret[24][24];
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            ret[i][j]=temp[i][j];
        }
    }

    go_left_(ret);
    start_(ret, depth+1);
    

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            ret[i][j]=temp[i][j];
        }
    }
    gravity_(ret);
    start_(ret,depth+1);
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            ret[i][j]=temp[i][j];
        }
    }

    go_right_(ret);
    start_(ret, depth+1);
    
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            ret[i][j]=temp[i][j];
        }
    }

    go_up_(ret);
    start_(ret, depth+1);
//
    

    
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
    
    start_(arr,0);
    
    cout << max_tot << "\n";
    
    return 0;
}
