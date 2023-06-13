#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N;
vector<long long> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        long long data;
        string temp;
        cin >> data;
        temp=to_string(data);
        reverse(temp.begin(), temp.end());
        v.push_back(stoll(temp));
    }
    
    sort(v.begin(), v.end());
    for(long long temp:v) {
        cout << temp << "\n";
    }
    
    return 0;
}
