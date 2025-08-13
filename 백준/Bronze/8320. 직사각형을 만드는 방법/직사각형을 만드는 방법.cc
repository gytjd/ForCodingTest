#include <iostream>

using namespace std;

int ret;
int N;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=1;i<=N;i++) {
        for(int j=i;j<=N;j++) {
            if(i*j<=N) {
                ret+=1;
            }
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}
