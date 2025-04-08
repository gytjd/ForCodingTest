#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int A,B,N;
vector<int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> A >> B;
    v.push_back(abs(A-B));
    cin >> N;
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        v.push_back(abs(B-data)+1);
    }
    sort(v.begin(),v.end());
    
    cout << v[0] << "\n";
    
    return 0;
}
