#include <iostream>
using namespace std;

int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        cout << a[0]-'0'+a[2]-'0' << "\n";
    }
    
    return 0;
}
