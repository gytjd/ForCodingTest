#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[14][14];
int num[6];
int min_N=987654321;
vector<pair<int, int>> v;

void display_() {
    
    cout << "\n";
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void set_(int temp[14][14],int arr[14][14]) {
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            temp[i][j]=arr[i][j];
        }
    }
}

int is_check(int x,int y,int n) {
    for(int i=x;i<x+n;i++) {
        for(int j=y;j<y+n;j++) {
            
            if(i>10 or j>10) {
                return 0;
            }
            
            if(arr[i][j]==0) {
                return 0;
            }
        }
    }
    return 1;
}

void check_(int x,int y,int n) {
    for(int i=x;i<x+n;i++) {
        for(int j=y;j<y+n;j++) {
            arr[i][j]=0;
        }
    }
}

int ret_check() {
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            if(arr[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}
void go_(int idx,int ret) {
    
//    display_();
    if(ret>min_N) {
        return;
    }
    if(ret_check()) {
        if(ret<min_N) {
            min_N=ret;
        }
//        cout << min_N << "\n";
        return ;
    }
    
    int temp[14][14];
    set_(temp,arr);
    
    for(int i=idx;i<N;i++) {
        
        if(arr[v[i].first][v[i].second]==0) {
            continue;
        }
        
        for(int j=1;j<=5;j++) {
            if(is_check(v[i].first, v[i].second, j) and num[j]<5) {
                check_(v[i].first, v[i].second, j);
                num[j]+=1;
                
                go_(i+1, ret+1);
                
                num[j]-=1;
                set_(arr,temp);
            }
        }
        
        return;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            cin >> arr[i][j];
            if(arr[i][j]==1) {
                v.push_back({i,j});
                N+=1;
            }
        }
    }
    
    go_(0,0);
    
    if(min_N==987654321) {
        cout << -1 << "\n";
    }
    else {
        cout << min_N << "\n";
    }
    return 0;
}

