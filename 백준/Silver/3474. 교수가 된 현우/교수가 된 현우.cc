#include <iostream>
using namespace std;

int count_zero(int temp) {
    
    int count_total=0;
    int num=5;
    
    while(num<=
          temp) {
        count_total+=(temp/num);
        num*=5;
    }
    
    return count_total;
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int i;
    int tc;
    cin >> tc;
    
    for(i=0;i<tc;i++) {
        int num;
        cin >> num;
        
        cout << count_zero(num) << "\n";
    }
    return 0;
}
