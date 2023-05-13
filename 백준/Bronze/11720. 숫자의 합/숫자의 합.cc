#include <iostream>
#include <string>

using namespace std;

int main() {
    int n,i;
    int result=0;
    
    cin >> n;
    
    string temp;
    cin >> temp;
    
    for(i=0;i<n;i++) {
        result += temp[i]-'0';
    }
    
    cout << result << "\n";
    
    return 0;
    
}
