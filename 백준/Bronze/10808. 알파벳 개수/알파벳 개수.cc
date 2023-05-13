#include <iostream>
#include <string>

using namespace std;
int result[26];

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    
    string a;
    cin >> a;
    
    for(char temp:a) {
        result[temp-97]+=1;
    }
    
    for(int i=0;i<26;i++) {
        cout << result[i] << " ";
    }
    return 0;
}
