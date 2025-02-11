#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string s;
    getline(cin, s);
    
    string target = "UCPC";
    int idx = 0;
    
    for (char c : s) {
        if (c == target[idx]) {
            idx++;
        }
        if (idx == 4) break;
    }
    
    if (idx == 4) {
        cout << "I love UCPC\n";
    } else {
        cout << "I hate UCPC\n";
    }
    
    return 0;
}

