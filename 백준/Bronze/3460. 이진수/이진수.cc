#include <iostream>
using namespace std;

int N;

void to_binary(int data) {
    
    int ret=0;
    while(data>0) {
        if(data%2==1) {
            cout << ret << " ";
        }
        data/=2;
        ret+=1;
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        to_binary(data);
    }
    
    return 0;
}
