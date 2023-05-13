#include <iostream>
#include <string>
using namespace std;

int p[10000];

void find_selfNum(int a) {
    
    int i;
    string temp=to_string(a);
    
    int result=a;
    
    for(i=0;i<temp.size();i++) {
        result+=temp[i]-'0';
    }
    
    if(result<10000) {
        p[result]=1;
        find_selfNum(result);
    }
    
}
int main() {
    
    int i;
    for(i=1;i<10000;i++) {
        if(p[i]==1) {
            continue;
        }
        find_selfNum(i);
    }
    
    for(i=1;i<10000;i++) {
        if(p[i]==0) {
            cout << i << "\n";
        }
    }
    
    return 0;
    
    return 0;
}
