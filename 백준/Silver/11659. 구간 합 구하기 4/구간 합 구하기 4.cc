#include <iostream>
#include <string>

using namespace std;

int N,M;

int visited[100004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=1;i<=N;i++) {
        
        int data;
        cin >> data;
        visited[i]=data;
    }
    
    for(int i=1;i<=N;i++) {
        visited[i]+=visited[i-1];
    }
    
    for(int i=0;i<M;i++) {
        int start,end;
        cin >> start >> end;
        cout << visited[end]-visited[start-1] << "\n";
    }
    
    return 0;
}
