#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

string a;
string bomb;

deque<char> s;

int is_same_T(string a,string b) {
    
    for(int i=0;i<a.size();i++) {
        if(a[i]!=b[a.size()-i-1]) {
            return 0;
        }
    }
    
    return 1;
}
void str_Bomb() {
    
    for(int i=0;i<a.size();i++) {
        if(a[i]==bomb[bomb.size()-1] and s.size()>=bomb.size()-1) {
            
            string temp="";
            temp+=a[i];
            
            for(int j=1;j<bomb.size();j++) {
                temp+=s.back();
                s.pop_back();
            }

            if(is_same_T(bomb,temp)) {
                continue;
            }
            else {
                for(int k=temp.size()-1;k>=0;k--) {
                    s.push_back(temp[k]);
                }
            }
        }
        else {
            s.push_back(a[i]);
        }
    }
    
    if(s.empty()) {
        cout << "FRULA";
    }
    else {
        while(!s.empty()) {
            cout << s.front();
            s.pop_front();
        }
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> a;
    cin >> bomb;

    str_Bomb();
    
    return 0;
}
