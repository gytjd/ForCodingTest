#include <iostream>
using namespace std;

int arr[5][5];
int visited[5][5];
pair<int,int> bingo[26];

int is_bingo() {
    
    bool check_Flag=false;
    int temp=0;
    
    for(int i=0;i<5;i++) {
        check_Flag=false;
        for(int j=0;j<5;j++) {
            if(!visited[j][i]) {
                check_Flag=true;
                break;
            }
        }
        
        if(!check_Flag) {
            temp+=1;
        }
    }
    
    for(int i=0;i<5;i++) {
        check_Flag=false;
        for(int j=0;j<5;j++) {
            if(!visited[i][j]) {
                check_Flag=true;
                break;
            }
        }
        
        if(!check_Flag) {
            temp+=1;
        }
    }
    
    check_Flag=false;
    for(int i=0;i<5;i++) {
        if(!visited[i][i]) {
            check_Flag=true;
        }
    }
    
    if(!check_Flag) {
        temp+=1;
    }
    
    check_Flag=false;
    for(int i=0;i<5;i++) {
        if(!visited[i][4-i]) {
            check_Flag=true;
        }
    }
    
    if(!check_Flag) {
        temp+=1;
    }

    if(temp>=3) {
        return 1;
    }
    else {
        return 0;
    }
}

void go_() {
    
    int ret=0;
    while(1) {
        int data;
        cin >> data;
        visited[bingo[data].first][bingo[data].second]=1;
        
        if(is_bingo()) {
            cout << ret+1 << "\n";
            break;
        }
        ret+=1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            cin >> arr[i][j];
            bingo[arr[i][j]].first=i;
            bingo[arr[i][j]].second=j;
        }
    }
    
    go_();
    
    return 0;
}
