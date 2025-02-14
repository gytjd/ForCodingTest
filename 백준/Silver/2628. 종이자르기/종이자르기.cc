#include <iostream>
#include <algorithm>

using namespace std;

int N,M,K;
vector<int> v,w;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> M >> N;
    cin >> K;
    for(int i=0;i<K;i++) {
        int com,data;
        cin >> com >> data;
        if(com) {
            w.push_back(data);
        } else {
            v.push_back(data);
        }
    }
    sort(v.begin(),v.end());
    sort(w.begin(),w.end());
    
    int v_Max;
    
    if(v.size()==0) {
        v_Max=N;
    } else {
        v_Max=max(v[0],N-v[v.size()-1]);
        for(int i=1;i<v.size();i++) {
            v_Max=max(v_Max,v[i]-v[i-1]);
        }
    }
    
    int w_Max;
    if(w.size()==0) {
        w_Max=M;
    } else {
        w_Max=max(w[0],M-w[w.size()-1]);
        for(int i=1;i<w.size();i++) {
            w_Max=max(w_Max,w[i]-w[i-1]);
        }
    }
    
    cout << v_Max*w_Max << "\n";
    
    return 0;
}
