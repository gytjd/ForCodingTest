#include <iostream>
#include <map>
using namespace std;

int N;
map<string, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    m["ChongChong"]=1;
    
    for(int i=0;i<N;i++) {
        string a,b;
        cin >> a >> b;
        
        if(m[a]!=0 or m[b]!=0) {
            m[a]+=1;
            m[b]+=1;
        }
    }
    
    int ret=0;
    for(pair<string, int> temp:m) {
        if(temp.second==0) {
            continue;
        }
        ret+=1;
    }
    
    cout << ret << '\n';
    
    return 0;
}
