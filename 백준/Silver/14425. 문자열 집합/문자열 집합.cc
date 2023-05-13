#include <iostream>
#include <map>
using namespace std;

map<string,int> temp;
int N,M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        temp.insert({a,0});
    }
    
    int tot_Cnt=0;
    for(int j=0;j<M;j++) {
        string b;
        cin >> b;
        
        if(temp.find(b)!=temp.end()) {
            tot_Cnt+=1;
        }
    }
    
    cout << tot_Cnt << "\n";
    
    return 0;
}
