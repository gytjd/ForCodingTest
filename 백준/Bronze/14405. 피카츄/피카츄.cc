#include <iostream>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string a;
    cin >> a;
    
    bool check_Flag=false;
    
    for(int i=0;i<a.size();i++) {
        
        if(a[i]=='p') {
            
            if(a[i+1]=='i') {
                i+=1;
                continue;
            }
            else {
                check_Flag=true;
                break;
            }
        }
        else if(a[i]=='k') {
            if(a[i+1]=='a') {
                i+=1;
                continue;
            }
            else {
                check_Flag=true;
                break;
            }
        }
        else if(a[i]=='c') {
            if(a[i+1]=='h' and a[i+2]=='u') {
                i+=2;
                continue;
            }
            else {
                check_Flag=true;
                break;
            }
        }
        else {
            check_Flag=true;
            break;
        }
    }
    
    if(check_Flag) {
        cout << "NO" << "\n";
    }
    else {
        cout << "YES" << "\n";
    }
    
    return 0;
}
