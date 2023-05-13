#include <iostream>
using namespace std;

long long arr[250000];
bool visited[250000];
int N;

void init_() {
    for(int i=2;i<=250000;i++) {
        
        if(visited[i]==1) {
            continue;
        }
        
        for(int j=i*2;j<=250000;j+=i) {
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
    
    while(1) {
        cin >> N;
        if(N==0) {
            break;
        }

        int ret=0;
        for(int i=N+1;i<=2*N;i++) {
            if(visited[i]==0) {
                ret+=1;
            }
        }

        cout << ret << "\n";
    }
    
    return 0;
}
