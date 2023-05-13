#include <iostream>
using namespace std;

int is_one(string a) {
    
    for(char temp:a) {
        if(temp=='a' or temp=='e' or temp=='i' or temp=='o' or temp=='u') {
            return 1;
        }
    }
    return 0;
}

int is_two(string a) {
    
    int count_a=0;
    int count_b=0;
    
    for(char temp:a) {
        
        if(temp=='a' or temp=='e' or temp=='i' or temp=='o' or temp=='u') {
            count_b=0;
            count_a+=1;
            
            if(count_a==3) {
                return 0;
            }
        }
        else {
            count_a=0;
            count_b+=1;
            
            if(count_b==3) {
                return 0;
            }
        }

    }
    
    return 1;
}

int is_three(string a) {
    
    int i;
    
    for(i=1;i<a.size();i++) {
        
        if(a[i]==a[i-1]) {
            
            if(a[i]=='e' or a[i]=='o') {
                continue;
            }
            return 0;
        }
    }
    
    return 1;
    
    
}
int main() {
    
    while(1) {
        
        string a;
        cin >> a;
        
        if(a=="end") {
            break;
        }
        
        if(is_one(a) and is_two(a) and is_three(a)) {
            cout << "<" << a << ">" << " is acceptable." << "\n";
        }
        else {
            cout << "<" << a << ">" << " is not acceptable." << "\n";
        }
    }
    
    return 0;
}
