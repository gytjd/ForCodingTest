#include <iostream>
#include <string>

using namespace std;

void display(int *pa) {
    int i;
    for(i=0;i<26;i++) {
        cout << pa[i] << " ";
    }
    cout << "\n";;
}

void init_array(int *pa) {
    int i;
    for(i=0;i<26;i++) {
        pa[i]=-1;
    }
}

int main() {
    
    int i;
    int count=0;
    
    string temp;
    cin >> temp;
    
    int result[26];
    init_array(result);
    
    for(i=0;i<temp.size();i++) {
        if(result[temp[i]-97]!=-1) {
            continue;
        }
        result[temp[i]-97]=i;
    }
    
    display(result);
    
    return 0;
}
