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
    
    int ret=0;
    int low=v[0];
    int high=v[0];
    
    for(int i=1;i<N;i++) {
        if(low>v[i]) {
            low=v[i];
            high=v[i];
        }
        
        if(high<v[i]) {
            high=v[i];
        }
        ret=max(ret,high-low);
    }
    
    cout << ret << "\n";
    
    return 0;
}
