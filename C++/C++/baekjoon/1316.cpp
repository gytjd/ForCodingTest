#include <iostream>
#include <string>
#include <vector>

using namespace std;

int find_num(vector<char> *temp,char a) {
    
    for(char q:*temp) {
        if(q==a) {
            return 1;
        }
    }
    return 0;
}
int is_group(string temp) {
    
    char curr=' ';
    
    vector<char> vec;
    
    for(char a:temp) {
        if(a==curr) {
            continue;
        }
        else {
            if(find_num(&vec,a)==1) {
                return 1;
            }
            vec.push_back(a);
            curr=a;
        }
    }
    
    return 0;
}

int main() {
    
    int n;
    cin >> n;
    
    int count=0;
    
    while(n!=0) {
        
        string temp;
        cin >> temp;
        
        if(is_group(temp)==0) {
            count++;
        }
        
        n--;
    }
    
    cout << count << "\n";
    
    return 0;
}
