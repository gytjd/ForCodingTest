#include <iostream>
#include <string>

using namespace std;

int main() {
    string temp;
    getline(cin, temp);
    
    int count=1;
    
    for(char a:temp) {
        if(a==' '){
            count+=1;
        }
    }
    
    if(temp[0]==' ') {
        count-=1;
    }
    
    if(temp[temp.size()-1]==' ') {
        count-=1;
    }
    
    cout << count << "\n";
    
    return 0;
}
