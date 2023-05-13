#include <iostream>
using namespace std;

#define MAX_SIZE 1000004
long long arr[MAX_SIZE];
bool visited[MAX_SIZE];
int N;

void init_() {
    for(int i=2;i<=MAX_SIZE;i++) {
        
        if(visited[i]==1) {
            continue;
        }
        
        for(int j=i*2;j<=MAX_SIZE;j+=i) {
            visited[j]=1;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    init_();
    visited[1]=1;
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        
        int cnt_T=0;
        
        for(int j=2;j<data/2+1;j++) {
            if(visited[j]==0 and visited[data-j]==0) {
                cnt_T+=1;
            }
        }
        
        cout << cnt_T << "\n";
    }
    
    return 0;
}
