#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int T,N,L;

int arr[104][104];
int visited[104][104];

void change_() {
    
    memset(visited,0,sizeof(visited));
    
    int tmp[104][104];
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            tmp[i][j]=arr[i][j];
        }
    }
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            arr[j][N-i-1]=tmp[i][j];
        }
    }
}
int is_(int start) {
    
    int curr=arr[start][0];
    
    for(int i=1;i<N;i++) {
        if(arr[start][i]>curr) {
            if(arr[start][i]-curr!=1) {
                return 0;
            }
            
            int cnt_N=0;
            curr=arr[start][i-1];
            
            for(int j=i-1;j>=0;j--) {
                if(arr[start][j]==curr and !visited[start][j]) {
                    visited[start][j]=1;
                    cnt_N+=1;
                }
                else {
                    break;
                }
                
                if(cnt_N==L) {
                    break;
                }
            }
            
            if(cnt_N!=L) {
                return 0;
            }
        }
        else if(arr[start][i]<curr) {
            if(curr-arr[start][i]!=1) {
                return 0;
            }
            
            int cnt_N=0;
            curr=arr[start][i];
            
            for(int j=i;j<N;j++) {
                if(arr[start][j]==curr and visited[start][j]==0) {
                    visited[start][j]=1;
                    cnt_N+=1;
                }
                else {
                    break;
                }
                
                if(cnt_N==L) {
                    break;
                }
            }
            
            if(cnt_N!=L) {
                return 0;
            }
        }
        
        curr=arr[start][i];
    }
    
    return 1;
}

int check_() {
    
    int ret=0;
    
    for(int i=0;i<N;i++) {
        ret+=is_(i);
    }
    
    change_();
    
    for(int i=0;i<N;i++) {
        ret+=is_(i);
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    for(int test_case=1;test_case<=T;test_case++) {
        
        cin >> N >> L;
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                cin >> arr[i][j];
            }
        }
        
        memset(visited,0,sizeof(visited));
        cout << "#" << test_case << " " <<  check_() << "\n";
    }
    
    return 0;
}

