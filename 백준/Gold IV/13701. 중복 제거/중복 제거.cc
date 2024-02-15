#include <iostream>
#include <vector>

using namespace std;

vector<bool> v(33554432,false);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int a;
    while(cin >> a) {
        if(v[a]==false) {
            cout << a << " ";
            v[a]=true;
        }
    }
    
    return 0;
}
