#include <iostream>

using namespace std;

int N;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        
        int ret=0;
        int cnt=0;
        string temp;
        cin >> temp;
        
        for(int j=0;j<temp.size();j++) {
            
            if(temp[j]=='O') {
                cnt+=1;
                ret+=cnt;
            } else {
                cnt=0;
            }
        }
        
        cout << ret << "\n";
    }
    
    return 0;
}
