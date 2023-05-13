#include <iostream>
#include <string>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    while(n!=0) {
        int i;
        char a;
        
        string b;
        cin >> a >> b;
        
        int num=int(a)-'0';
        
        for(char temp:b) {
            for(i=0;i<num;i++) {
                cout << temp;
            }
        }
        cout << "\n";
        n--;
    }
}
