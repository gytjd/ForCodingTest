#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[9][9];
vector<pair<int, int>> v;

void display_() {
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
}

int to_idx(int idx) {
    if(idx==0 or idx==1 or idx==2) {
        return 0;
    }
    else if(idx==3 or idx==4 or idx==5) {
        return 3;
    }
    else if(idx==6 or idx==7 or idx==8) {
        return 6;
    }
    
    return -1;
}

int is_promising(int x,int y,int data) {
    
//    cout << x << " " << y << " " << data << "\n";
    
    for(int i=0;i<9;i++) {
        if(arr[x][i]==data) {
            return 0;
        }
    }
    
    for(int i=0;i<9;i++) {
        if(arr[i][y]==data) {
            return 0;
        }
    }
    
    int tempX=to_idx(x);
    int tempY=to_idx(y);
    
//    cout << tempX << " " << tempY << "\n";
    
    for(int i=tempX;i<tempX+3;i++) {
        for(int j=tempY;j<tempY+3;j++) {
            if(arr[i][j]==data) {
                return 0;
            }
        }
    }
    
    return 1;
}

void go_(int idx) {
    
    if(idx==N) {
        display_();
        exit(0);
    }
    
    for(int i=1;i<=9;i++) {
        if(is_promising(v[idx].first,v[idx].second,i)) {
            arr[v[idx].first][v[idx].second]=i;
            go_(idx+1);
            arr[v[idx].first][v[idx].second]=0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    for(int i=0;i<9;i++) {
        string temp;
        cin >> temp;
        for(int j=0;j<9;j++) {
            arr[i][j]=temp[j]-'0';
            
            if(arr[i][j]==0) {
                v.push_back({i,j});
                N+=1;
            }
        }
    }
    
//    display_();
    go_(0);
    
    return 0;
}
