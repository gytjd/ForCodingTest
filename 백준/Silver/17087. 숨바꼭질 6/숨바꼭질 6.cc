#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

int N,S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> temp;
    cin >> N >> S;
    
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        
        temp.push_back(abs(S-data));
    }
    
    int min_num=temp[0];
    for(int i=1;i<temp.size();i++) {
        min_num=gcd(min_num, temp[i]);
    }
    
    cout << min_num << "\n";
    return 0;
}
