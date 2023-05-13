#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ret;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int tot=0;
    
    for(int i=0;i<5;i++) {
        int data;
        cin >> data;
        tot+=data;
        ret.push_back(data);
    }
    
    sort(ret.begin(), ret.end());
    cout << tot/5 << "\n";
    cout << ret[2] << "\n";
    
    return 0;
}
