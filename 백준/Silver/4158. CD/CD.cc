#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> m;
int answer=0;
int N,M;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    while(1) {
        cin >> N >> M;
        
        if(!N and !M) {
            break;
        }
        answer=0;
        m.clear();
        
        for(int i=0;i<N;i++) {
            int data;
            cin >> data;
            m[data]+=1;
        }
        
        for(int i=0;i<M;i++) {
            int data;
            cin >> data;
            m[data]+=1;
        }
        
        for(pair<int,int> temp:m) {
            if(temp.second==2) {
                answer+=1;
            }
        }
        cout << answer << "\n";
    }
    
    
    return 0;
}
