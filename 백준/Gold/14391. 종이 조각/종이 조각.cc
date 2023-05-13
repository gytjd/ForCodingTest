#include <iostream>
#include <vector>
using namespace std;

int N,M;
int temp[20];
int arr[5][5];
int q[5][5];

int max_num=-987654321;


//void display_() {
//
//    cout << "\n";
//    for(int i=0;i<N;i++) {
//        for(int j=0;j<M;j++) {
//            cout << arr[i][j];
//        }
//        cout << "\n";
//    }
//}
int calculate_() {
    
    int ret=0;
    int visited[5][5]={0,};
    

    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            
            if(visited[i][j]==0) {
                
                int temp=0;
                
                if(arr[i][j]==0) {
                    int k=j;
                    while(arr[i][k]!=1 and k<M) {
                        temp=temp*10+q[i][k];
                        visited[i][k]=1;
                        k+=1;
                    }
                    
//                    cout << temp << "\n";
                }
                else {
                    int k=i;
                    while(arr[k][j]!=0 and k<N) {
                        temp=temp*10+q[k][j];
                        visited[k][j]=1;
                        k+=1;
                    }
//                    cout << temp << "\n";
                    
                }
                ret+=temp;
            
            }
        }
    }
    
    
    return ret;
}
void go_() {
    int count_T=0;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            arr[i][j]=temp[count_T++];
        }
    }
}

void start_() {
    
    for(int i=0;i<(1<<(N*M));i++) {
        
        for(int j=0;j<N*M;j++) {
            temp[j]=0;
        }
        
        for(int j=0;j<(N*M);j++) {
            
            if(((i&(1<<j))>>j)==1) {
                temp[j]=1;
            }
            else {
                temp[j]=0;
            }
        }
        
        go_();
//        display_();
        int tmp_ret=calculate_();
        
        if(max_num<tmp_ret) {
            max_num=tmp_ret;
        }
    }
    
    cout << max_num << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;

    for(int i=0;i<N;i++) {
        
        string a;
        cin >> a;
        
        for(int j=0;j<a.size();j++) {
            q[i][j]=a[j]-'0';
        }
    }
    
    start_();
    
    return 0;
}
