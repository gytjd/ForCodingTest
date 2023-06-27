#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N;
set<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        s.insert(data);
    }
    
    for(int temp:s) {
        cout << temp << " ";
    }
    cout << "\n";
    
    return 0;
}
