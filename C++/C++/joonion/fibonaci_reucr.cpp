#include <iostream>

using namespace std;

int arr[1004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    arr[1]=1;
    arr[2]=2;
    
    for(int i=3;i<=1000;i++) {
        arr[i]=(arr[i-1]+arr[i-2])%1000;
        cout << arr[i] << " ";
    }
    
    cout << arr[1000] << "\n";
    
    return 0;
}
