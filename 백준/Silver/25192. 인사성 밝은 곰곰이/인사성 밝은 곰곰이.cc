#include <iostream>
#include <map>

using namespace std;

int N,ret;
map<string, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        string temp;
        cin >> temp;
        if(temp=="ENTER") {
            for(int i=0;i<m.size();i++) {
                ret+=1;
            }
            ret-=1;
            m.clear();
        }
        m[temp]=1;
    }
    
    for(int i=0;i<m.size();i++) {
        ret+=1;
    }
    
    cout << ret << "\n";
    
    return 0;
}
