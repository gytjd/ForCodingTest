#include <iostream>
#include <vector>

using namespace std;

int N,M;
int arr[154];
int visited[154];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        arr[i]=data;
    }
    
    int start=0;
    while(!visited[arr[start]]) {
        visited[arr[start]]=visited[start]+1;
        start=arr[start];
    }
    
    if(visited[M]==0) {
        cout << -1 << "\n";
    } else {
        cout << visited[M] << "\n";
    }
    
    return 0;
}
