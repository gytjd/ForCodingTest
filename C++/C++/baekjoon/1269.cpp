#include <iostream>
#include <unordered_map>
using namespace std;

int N,M;
int ret;
unordered_map<int, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
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
    
    for(pair<int, int> temp:m) {
        if(temp.second==1) {
            ret+=1;
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}

