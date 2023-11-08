#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int N,M;
unordered_set<string> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        string data;
        cin >> data;
        m.insert(data);
    }
    
    for(int i=0;i<M;i++) {
        string data;
        cin >> data;

        string temp="";
        
        for(int j=0;j<data.size();j++) {
            if(data[j]==',') {
                m.erase(temp);
                temp="";
                continue;
            }
            temp+=data[j];
        }
        m.erase(temp);
        
        
        cout << m.size() << "\n";
    }
    
    return 0;
}
