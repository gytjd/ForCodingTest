#include <iostream>
using namespace std;

int N,A,B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> A >> B;
    
    if(N>B) {
        cout << "Bus" << "\n";
    }
    else {
        if(A<B) {
            cout << "Bus" << "\n";
        }
        else if(A>B) {
            cout << "Subway" << "\n";
        }
        else {
            cout << "Anything" << "\n";
        }
    }
    
    return 0;
}
