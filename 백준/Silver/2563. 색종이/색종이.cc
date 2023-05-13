#include <iostream>
using namespace std;

int N;
int arr[104][104];

void init_(int x,int y) {
    
    int i,j;
    
    for(int i=y;i<y+10;i++) {
        for(int j=x;j<x+10;j++) {
            arr[i][j]=1;
        }
    }
}

int cal_paper() {
    int result=0;
    for(int i=0;i<104;i++) {
        for(int j=0;j<104;j++) {
            if(arr[i][j]==1) {
                result+=1;
            }
        }
    }
    
    return result;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int start,end;
        cin >> start >> end;
        
        init_(start, end);
    }
    
    cout << cal_paper() << "\n";
    
    return 0;
}
