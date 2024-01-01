#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int visited[10];
int check[10];

string solution(string X, string Y) {
    string answer = "";
    
    for(char temp:X) {
        visited[temp-'0']+=1;
    }
    
    for(char temp:Y) {
        check[temp-'0']+=1;
    }
    
    for(int i=0;i<10;i++) {
        check[i]=min(check[i],visited[i]);
    }
    
    string temp_Str="";
    for(int i=9;i>=0;i--) {
        for(int j=0;j<check[i];j++) {
            temp_Str+=char(i+48);
        }
    }
    
    if(temp_Str=="") {
        answer="-1";
    }
    else {
        bool check_Flag=false;
        for(char a:temp_Str) {
            if(a!='0') {
                check_Flag=true;
            }
        }
        
        if(check_Flag) {
            answer=temp_Str;
        }
        else {
            answer="0";
        }
    }
    

    
    return answer;
}