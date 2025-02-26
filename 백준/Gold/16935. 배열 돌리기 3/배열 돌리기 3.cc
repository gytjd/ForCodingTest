#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N,M,R;
int arr[104][104];
int temp[104][104];
vector<int> com;

void fill_Arr() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            arr[i][j]=temp[i][j];
        }
    }
}

void change_NM_() {
    int K=N;
    N=M;
    M=K;
}

void display_() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void upDown_() {
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            temp[N-i-1][j]=arr[i][j];
        }
    }
}

void leftRight_() {
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            temp[i][M-j-1]=arr[i][j];
        }
    }
}

void turn_Right_() {
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            temp[j][N-i-1]=arr[i][j];
        }
    }
}

void turn_Left_() {
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            temp[M-j-1][i]=arr[i][j];
        }
    }
}

void group_Change_Right() {
    
    for(int i=0;i<N/2;i++) {
        for(int j=0;j<M/2;j++) {
            temp[i][M/2+j]=arr[i][j];
        }
    }
    
    for(int i=0;i<N/2;i++) {
        for(int j=M/2;j<M;j++) {
            temp[N/2+i][j]=arr[i][j];
        }
    }
    
    for(int i=N/2;i<N;i++) {
        for(int j=M/2;j<M;j++) {
            temp[i][j-M/2]=arr[i][j];
        }
    }
    
    for(int i=N/2;i<N;i++) {
        for(int j=0;j<M/2;j++) {
            temp[i-N/2][j]=arr[i][j];
        }
    }
}

void group_Change_Left() {
    
    for(int i=0;i<N/2;i++) {
        for(int j=0;j<M/2;j++) {
            temp[i+N/2][j]=arr[i][j];
        }
    }
    
    for(int i=0;i<N/2;i++) {
        for(int j=M/2;j<M;j++) {
            temp[i][j-M/2]=arr[i][j];
        }
    }
    
    for(int i=N/2;i<N;i++) {
        for(int j=M/2;j<M;j++) {
            temp[i-N/2][j]=arr[i][j];
        }
    }
    
    for(int i=N/2;i<N;i++) {
        for(int j=0;j<M/2;j++) {
            temp[i][j+M/2]=arr[i][j];
        }
    }
}

void go_() {
    
    for(int i=0;i<R;i++) {
        
        memset(temp, 0, sizeof(temp));
        
        if(com[i]==1) {
            upDown_();
        } else if(com[i]==2) {
            leftRight_();
        } else if(com[i]==3) {
            turn_Right_();
            change_NM_();
        } else if(com[i]==4) {
            turn_Left_();
            change_NM_();
        } else if(com[i]==5) {
            group_Change_Right();
        } else {
            group_Change_Left();
        }
        
        memset(arr, 0, sizeof(arr));
        fill_Arr();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> R;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<R;i++) {
        int data;
        cin >> data;
        com.push_back(data);
    }
    
    go_();
    display_();
    
    return 0;
}
