#include <iostream>
using namespace std;

int N,ret;
char arr[1004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    string a;
    cin >> a;
    for(int i=0;i<a.size();i++) {
        arr[i]=a[i];
    }
    
    ret=1;
    for(int i=1;i<N;i++) {
        if(arr[i]=='E' and arr[i-1]=='W') {
            ret+=1;
        }
    }
    cout << ret << "\n";
    
    return 0;
}
