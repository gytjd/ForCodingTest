#include <iostream>
using namespace std;


int main() {
    
    int max_num=-987653321;
    int x,y,num;
    
    for(int i=1;i<=9;i++) {
        for(int j=1;j<=9;j++) {
            cin >> num;
            if(max_num<num) {
                x=i;
                y=j;
                max_num=num;
            }
        }
    }
    
    cout << max_num << "\n";
    cout << x << " " << y << "\n";
    
    return 0;
}
