#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[2224][2224];
int visited[2224][2224];

void display_() {
    
    cout << "\n";
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}

void go_() {
    for(int i=2;i<=N;i++) {
        if(arr[i][1]>=arr[i-1][1]) {
            visited[i][1]=visited[i-1][1]+arr[i][1]-arr[i-1][1]+1;
        }
        else {
            visited[i][1]=visited[i-1][1];
        }
        
        if(arr[1][i]>=arr[1][i-1]) {
            visited[1][i]=visited[1][i-1]+arr[1][i]-arr[1][i-1]+1;
        }
        else {
            visited[1][i]=visited[1][i-1];
        }
    }
    
    for(int i=2;i<=N;i++) {
        for(int j=2;j<=N;j++) {
            
            int tempA=0;
            int tempB=0;
            if(arr[i][j]>=arr[i-1][j]) {
                tempA=visited[i-1][j]+arr[i][j]-arr[i-1][j]+1;
            }
            else {
                tempA=visited[i-1][j];
            }
            
            if(arr[i][j]>=arr[i][j-1]) {
                tempB=visited[i][j-1]+arr[i][j]-arr[i][j-1]+1;
            }
            else {
                tempB=visited[i][j-1];
            }
            
            visited[i][j]=min(tempA,tempB);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin >> arr[i][j];
        }
    }
    
    go_();
    cout << visited[N][N] << "\n";

    return 0;
}
