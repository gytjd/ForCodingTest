#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> temp;

bool cmp(string a,string b) {
    
    if(a.size()==b.size()) {
        int i;
        for(i=0;i<a.size();i++) {
            if(a[i]==b[i]) {
                continue;
            }
            return a[i]<b[i];
        }
    }
    return a.size()<b.size();
}

void find_num(string a) {
    
    string temp_St="";
    
    int zero_cnt=0;
    bool Flag=false;
    
    for(char q:a) {
        if(q>='0' and q<='9') {
            
            if(temp_St.size()==0 and q=='0') {
                zero_cnt+=1;
            }
            else {
                zero_cnt=0;
                temp_St+=q;
            }
            Flag=true;
        }
        else {
            
            if(Flag) {
                
                if(zero_cnt>0) {
                    temp.emplace_back("0");
                }
                else {
                    temp.emplace_back(temp_St);
                }
                
                temp_St.clear();
                Flag=false;
            }
        }
    }
    
    if(Flag) {
        if(zero_cnt>0) {
            temp.emplace_back("0");
        }
        else {
            temp.emplace_back(temp_St);
        }
    }
}
int main() {
    int i;
    int N;
    
    cin >> N;
    
    for(i=0;i<N;i++) {
        string a;
        cin >> a;
        
        find_num(a);
    }
    
    sort(temp.begin(), temp.end(), cmp);
    
    for(string q:temp) {
        cout << q << "\n";
    }
    
    return 0;
}
