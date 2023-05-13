#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int K,x,y;
int size_K;
int count_T=1;

vector<vector<int>> arr;

void init_() {
        
    for(int i=0;i<=size_K;i++) {
        vector<int> tmp;
        for(int j=0;j<=size_K;j++) {
            tmp.push_back(0);
        }
        arr.push_back(tmp);
    }
}

void display_() {
    for(int i=size_K;i>=1;i--) {
        for(int j=1;j<=size_K;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
int is_check(int x,int y,int n) {
    
    for(int i=x;i<x+n;i++) {
        for(int j=y;j<y+n;j++) {
            if(arr[i][j]!=0) {
                
                if(i<x+n/2 and j<y+n/2) {
                    return 1;
                }
                else if(i<x+n/2 and j>=y+n/2) {
                    return 2;
                }
                else if(i>=x+n/2 and j<y+n/2) {
                    return 3;
                }
                else if(i>=x+n/2 and j>=y+n/2){
                    return 4;
                }
            }
        }
    }
    
    return 0;
}

void fill_A(int start,int x,int y,int n) {
    
    if(start==1) {
        arr[x+n/2-1][y+n/2]=count_T;
        arr[x+n/2][y+n/2-1]=count_T;
        arr[x+n/2][y+n/2]=count_T;
    }
    else if(start==2) {
        arr[x+n/2-1][y+n/2-1]=count_T;
        arr[x+n/2][y+n/2-1]=count_T;
        arr[x+n/2][y+n/2]=count_T;
    }
    else if(start==3) {
        arr[x+n/2-1][y+n/2-1]=count_T;
        arr[x+n/2-1][y+n/2]=count_T;
        arr[x+n/2][y+n/2]=count_T;
    }
    else if(start==4) {
        arr[x+n/2-1][y+n/2-1]=count_T;
        arr[x+n/2-1][y+n/2]=count_T;
        arr[x+n/2][y+n/2-1]=count_T;
    }
    count_T+=1;
}


void start_(int x,int y,int n) {

    if(n==1) {
        return;
    }
    
    int temp=is_check(x,y,n);
    
    if(temp!=0) {
        
        fill_A(temp, x, y, n);
        start_(x, y, n/2);
        start_(x, y+n/2, n/2);
        start_(x+n/2, y, n/2);
        start_(x+n/2, y+n/2, n/2);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> K;
    cin >> x >> y;
    size_K=pow(2, K);
    
    init_();
    
    arr[y][x]=-1;
    
    start_(1, 1, size_K);
    
    display_();
    
    return 0;
}

