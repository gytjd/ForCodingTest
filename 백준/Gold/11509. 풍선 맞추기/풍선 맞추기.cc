#include <iostream>
using namespace std;

int N;
int visited[1000004];
int ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        
        
        if(visited[data+1]) {
            visited[data+1]-=1;
            visited[data]+=1;
        }
        else {
            ret+=1;
            visited[data]+=1;
        }
    }
    
    cout << ret << "\n";
    
    return 0;
    
}
