#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    int p_Count=0;
    int y_Count=0;
    
    for(int i=0;i<s.size();i++) {
        if(s[i]=='p' or s[i]=='P') {
            p_Count+=1;
        }
        
        if(s[i]=='y' or s[i]=='Y') {
            y_Count+=1;
        }
    }
    
    if(p_Count!=y_Count) {
        answer=false;
    }

    return answer;
}