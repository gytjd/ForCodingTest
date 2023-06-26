#include <iostream>
#include <algorithm>
using namespace std;

int N;
char arr[100004][3];
int visited[100004][3];

void go_Max() {
    
    for(int i=0;i<3;i++) {
        visited[0][i]=arr[0][i]-'0';
    }
    
    for(int i=1;i<N;i++) {
        visited[i][0]=max(visited[i-1][0],visited[i-1][1])+arr[i][0]-'0';
        visited[i][1]=max(max(visited[i-1][0],visited[i-1][1]),visited[i-1][2])+arr[i][1]-'0';
        visited[i][2]=max(visited[i-1][1],visited[i-1][2])+arr[i][2]-'0';
    }
    
    cout << max(max(visited[N-1][0],visited[N-1][1]),visited[N-1][2]) << " ";
}

void go_Min() {
    for(int i=0;i<3;i++) {
        visited[0][i]=arr[0][i]-'0';
    }
    
    for(int i=1;i<N;i++) {
        visited[i][0]=min(visited[i-1][0],visited[i-1][1])+arr[i][0]-'0';
        visited[i][1]=min(min(visited[i-1][0],visited[i-1][1]),visited[i-1][2])+arr[i][1]-'0';
        visited[i][2]=min(visited[i-1][1],visited[i-1][2])+arr[i][2]-'0';
    }
    
    cout << min(min(visited[N-1][0],visited[N-1][1]),visited[N-1][2]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<3;j++) {
            cin >> arr[i][j];
        }
    }
    
    go_Max();
    go_Min();
    
    return 0;
}
