#include <iostream>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=N-1;i>=0;i--) {
        for(int j=0;j<i;j++) {
            cout << " ";
        }
        for(int j=0;j<N-i;j++) {
            cout << "*";
        }
        for(int j=0;j<N-i-1;j++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<i+1;j++) {
            cout << " ";
        }
        
        for(int j=i+1;j<N;j++) {
            cout << "*";
        }
        for(int j=i+2;j<N;j++) {
            cout << "*";
        }
        cout << "\n";
    }
}
