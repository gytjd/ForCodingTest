#include <iostream>
#include <string>

using namespace std;

int T;
int is_Palindrome(string temp) {
    
    
    bool check_Flag_0=false;
    bool check_Flag_A=false;
    bool check_Flag_B=false;
    int temp_Idx=0;
    
    for(int i=0;i<temp.size()/2;i++) {
        if(temp[i]!=temp[temp.size()-i-1]) {
            check_Flag_0=true;
            temp_Idx=i;
            break;
        }
    }
    
    if(!check_Flag_0) {
        return 0;
    } else {
        int lowA=temp_Idx+1;
        int highA=temp.size()-temp_Idx-1;
        
//        cout << lowA << " " << highA << "\n";
        
        while(lowA<=highA) {
            if(temp[lowA]!=temp[highA]) {
                check_Flag_A=true; // 일단 안된다는거
                break;
            }
            lowA+=1;
            highA-=1;
        }
        
        int lowB=temp_Idx;
        int highB=temp.size()-temp_Idx-2;
        
        while(lowB<=highB) {
            if(temp[lowB]!=temp[highB]) {
                check_Flag_B=true;
                break;
            }
            lowB+=1;
            highB-=1;
        }
        
        if(!check_Flag_A or !check_Flag_B) {
            return 1;
        } else {
            return 2;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    for(int i=0;i<T;i++) {
        string data;
        cin >> data;
        cout << is_Palindrome(data) << "\n";
    }
    
    return 0;
}
