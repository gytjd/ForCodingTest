#include <iostream>
using namespace std;

int temp[26];

void make_palin() {
    
    bool is_Flag=false;
    string front_s="";
    string mid_s="";
    string front_e="";
    
    string temp_s="";
    
    for(int i=0;i<26;i++) {
        
        if(temp[i]>0) {
            
            for(int j=0;j<temp[i]/2;j++) {
                front_s+=i+65;
                
                temp_s+=i+65;
            }
            
            
            temp_s+=front_e;
            
            front_e=temp_s;
            temp_s="";
            
            
            if(temp[i]%2==1) {
                mid_s+=i+65;
            }
        }
    }
    
    temp_s=front_s+mid_s+front_e;
    
    for(int i=0;i<temp_s.size()/2;i++) {
        
        if(temp_s[i]!=temp_s[temp_s.size()-1-i]) {
            is_Flag=true;
            break;
        }
    }
    
    
    if(is_Flag==true) {
        cout << "I'm Sorry Hansoo" << "\n";
    }
    else {
        cout << temp_s << "\n";
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string a;
    cin >> a;
    
    for(char q:a) {
        temp[q-65]+=1;
    }
    
    make_palin();
    
    return 0;
}
