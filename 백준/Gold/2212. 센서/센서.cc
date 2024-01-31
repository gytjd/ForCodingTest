#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int N,K;
vector<int> v;
vector<int> temp;
unordered_map<int, bool> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    cin >> K;
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        if(!m[data]) {
            v.push_back(data);
            m[data]=true;
        }
    }
    sort(v.begin(),v.end());
    
    for(int i=1;i<v.size();i++) {
        temp.push_back(v[i]-v[i-1]);
    }
    sort(temp.begin(),temp.end());
    
    if(N<K) {
        cout << 0 << '\n';
    }
    else {
        int answer=0;
        for(int i=0;i<temp.size()-K+1;i++) {
            answer+=temp[i];
        }
        cout << answer << "\n";
    }
    
    return 0;
}
