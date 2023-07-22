#include <iostream>
using namespace std;

int N;
int arr[1004];

void go_() {
    arr[1]=1;
    arr[2]=2;
    arr[3]=1;
    arr[4]=2;
    
    for(int i=5;i<=N;i++) {
        arr[i]=2;
        if(arr[i-1]==2 and arr[i-3]==2 and arr[i-4]==2) {
            arr[i]=1;
        }
    }
    
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    go_();
    
    if(arr[N]==2) {
        cout << "SK" << "\n";
    }
    else {
        cout << "CY" << "\n";
    }
}
