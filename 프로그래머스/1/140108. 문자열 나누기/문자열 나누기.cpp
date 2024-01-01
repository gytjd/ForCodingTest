#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int curr_Count=1;
    int temp_Count=0;
    char temp_Chr=s[0];
    
    for(int i=1;i<s.size();i++) {        
        if(temp_Chr==s[i]) {
            curr_Count+=1;
        }
        else {
            temp_Count+=1;
        }
        
        if(curr_Count==temp_Count) {
            temp_Chr=s[i+1];
            curr_Count=0;
            temp_Count=0;
            answer+=1;
        }
    }
    
    if(curr_Count!=0 or temp_Count!=0) {
        answer+=1;
    }
    
    
    return answer;
}