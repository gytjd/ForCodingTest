#include <iostream>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    bool check_Flag=false;
    for(int i=1;i<=N;i++) {
        int data;
        cin >> data;
        if(i%2 and data%2==0) {
            check_Flag=true;
        }
        
        if(i%2==0 and data%2) {
            check_Flag=true;
        }
    }
    
    cout << (!check_Flag ? "YES" : "NO") << "\n";
    
    return 0;
}
