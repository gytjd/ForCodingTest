#include <iostream>
using namespace std;

int N,L,D;
int arr[4004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> L >> D;
    
    int temp=0;
    
    for(int i=0;i<N;i++) {
        for(int j=temp;j<temp+L;j++){
            arr[j]=1;
        }
        temp+=L+5;
    }
    
    temp=0;
    while(temp<=4004) {
        if(arr[temp]==0) {
            cout << temp << "\n";
            break;
        }
        temp+=D;
    }
    
    return 0;
}
