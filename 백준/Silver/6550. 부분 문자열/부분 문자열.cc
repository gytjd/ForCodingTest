#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string a,b;
    while(cin >> a >> b) {
        int Idx=0;
        bool check_Flag=false;
        
        for(int i=0;i<b.size();i++) {
            if(a[Idx]==b[i]) {
                Idx+=1;
            }
            
            if(Idx==a.size()) {
                check_Flag=true;
                break;
            }
        }
        
        cout << (check_Flag ? "Yes" : "No") << "\n";
    }
    
    return 0;
}
