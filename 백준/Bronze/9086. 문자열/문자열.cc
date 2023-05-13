#include <iostream>

using namespace std;

string a;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        cin >> a;
        cout << a[0] << a[a.size()-1] << "\n";
    }


    
    return 0;
    
}
