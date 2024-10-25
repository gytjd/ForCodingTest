#include <iostream>
#include <algorithm>

using namespace std;

string temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> temp;
    
    temp+='?';
    int zero_Cnt=0;
    int temp_Cnt=0;
    for(int i=0;i<temp.size();i++) {
        if(temp[i]=='0') {
            temp_Cnt+=1;
        } else {
            if(temp_Cnt) zero_Cnt+=1;
            temp_Cnt=0;
        }
    }
    
    int one_Cnt=0;
    temp_Cnt=0;
    for(int i=0;i<temp.size();i++) {
        if(temp[i]=='1') {
            temp_Cnt+=1;
        } else {
            if(temp_Cnt) one_Cnt+=1;
            temp_Cnt=0;
        }
    }
    
    cout << min(zero_Cnt,one_Cnt) << "\n";
    
    return 0;
}
