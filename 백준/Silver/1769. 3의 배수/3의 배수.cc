#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string a;
    cin >> a;
    
    int curr_Count=0;
    while(a.size()!=1) {
        int temp=0;
        for(int i=0;i<a.size();i++) {
            temp+=a[i]-'0';
        }
        a=to_string(temp);
        curr_Count+=1;
    }
    
    cout << curr_Count << "\n";
    
    if((a[0]-'0')%3==0) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
    
    return 0;
}
