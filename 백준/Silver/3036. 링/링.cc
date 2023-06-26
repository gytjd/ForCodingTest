#include <iostream>
#include <numeric>
#include <vector>

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
    
    for(int i=1;i<N;i++) {
        int temp=gcd(v[0], v[i]);
        cout << v[0]/temp << "/" << v[i]/temp << "\n";
    }
}

