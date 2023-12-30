#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool visited[30]; //97~(97+26) 이 소문자 ascii code;

void init_(string skip) {
    
    for(char temp:skip) {
        visited[temp-97]=true; // true 는 Pass 해야함
    }
}

char change_To(char c,int index) {
    
    int curr_Count=0;
    while(curr_Count!=index) {
        // cout << c-97 << " " << curr_Count << "\n";
        
        if(c=='z') {
            c='a';
        }
        else {
            c+=1;
        }
        
        if(!visited[c-97]) {
            curr_Count+=1;
        }
    }
    return c;
}

string solution(string s, string skip, int index) {
    string answer = "";
    
    init_(skip);
    
    for(char temp:s) {
        answer+=change_To(temp,index);
    }
    return answer;
}