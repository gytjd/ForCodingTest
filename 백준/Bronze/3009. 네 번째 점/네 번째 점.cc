#include <iostream>
#include <map>

using namespace std;



int temp[1004];

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    map<int, int> qa;
    map<int,int>qb;
    
    for(int i=0;i<3;i++) {
        int a,b;
        cin >> a >> b;
        
        qa[a]++;
        qb[b]++;
    }
    
    for(pair<int, int> tmp:qa) {
        if(tmp.second==1) {
            cout << tmp.first << " ";
        }
    }
    
    for(pair<int, int> tmp:qb) {
        if(tmp.second==1) {
            cout << tmp.first << "\n";
        }
    }
    return 0;
}

