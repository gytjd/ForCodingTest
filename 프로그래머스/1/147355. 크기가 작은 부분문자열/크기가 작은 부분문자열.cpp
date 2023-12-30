#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int str_Size=p.size();
    
    for(int i=0;i<=t.size()-str_Size;i++) {
        string temp="";
        for(int j=i;j<i+str_Size;j++) {
            temp+=t[j];
        }
    
        // cout << stoi(temp) << " " << stoi(p) << " " << answer << "\n";
        
        if(stoll(temp)<=stoll(p)) {
            answer+=1;
        }
    }
    
    return answer;
}