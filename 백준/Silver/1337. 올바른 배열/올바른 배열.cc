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
    
    sort(v.begin(), v.end());
    
    int ret=0;
    int count=1;
    for(int i=0;i<N;i++) {
        count=1;
        for(int j=i+1;j<N;j++) {
            if(v[j]<v[i]+5) {
                count+=1;
            }
        }
        ret=max(ret,count);
    }
    
    cout << 5-ret << "\n";
    
    return 0;
}
