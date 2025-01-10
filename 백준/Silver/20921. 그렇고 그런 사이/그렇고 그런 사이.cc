#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,K;
vector<int> v;
vector<int> temp;
vector<int> ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> K;
    for(int i=N;i>0;i--) {
        v.push_back(i);
    }
    
    for(int i=0;i<N;i++) {
        if(K>=N-i-1) {
            K-=(N-i-1);
            ret.push_back(N-i);
        } else {
            temp.push_back(N-i);
        }
    }
    reverse(temp.begin(), temp.end());
    
    for(int i=0;i<ret.size();i++) {
        cout << ret[i] << " ";
    }
    for(int i=0;i<temp.size();i++) {
        cout << temp[i] << " ";
    }
 
    return 0;
}
