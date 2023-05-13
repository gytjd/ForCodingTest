#include <iostream>
using namespace std;

int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int price;
        cin >> price;
        
        cout << price/25 << " ";
        price%=25;
        
        cout << price/10 << " ";
        price%=10;
        
        cout << price/5 << " ";
        price%=5;
        
        cout << price/1 << "\n";
        price%=1;
    }
    
    
}
