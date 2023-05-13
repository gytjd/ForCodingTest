#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    
    int max_N=v[0];
    for(int i=1;i<v.size();i++) {
        v[i]=max(v[i]+v[i-1],v[i]);
        
        if(v[i]>max_N) {
            max_N=v[i];
        }
    }
    
    cout << max_N << "\n";
    
    return 0;
}
