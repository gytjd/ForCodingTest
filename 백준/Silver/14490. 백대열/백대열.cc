#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string a;
    cin >> a;
    
    istringstream ss(a);
    string stringbuffer;
    vector<string> v;
    
    while(getline(ss, stringbuffer, ':')) {
        v.push_back(stringbuffer);
    }
    
    int retA=stoi(v[0]);
    int retB=stoi(v[1]);
    int temp=gcd(retA, retB);
    
    cout << retA/temp << ':' << retB/temp << "\n";
 
    return 0;
}
