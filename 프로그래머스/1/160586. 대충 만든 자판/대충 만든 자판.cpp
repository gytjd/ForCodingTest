#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char,int> m;

void init_(vector<string> &keymap) {
    
    for(string temp:keymap) {
        int curr_Count=1;
        for(char tempC:temp) {
            if(m[tempC]==0) {
                m[tempC]=curr_Count;
            }
            else {
                if(m[tempC]>curr_Count) {
                    m[tempC]=curr_Count;
                }
            }
            curr_Count+=1;
        }
    }
}

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    init_(keymap);
    
    for(string tempA:targets) {
        int temp_Num=0;
        bool check_Flag=false;

        for(char tempB:tempA) {            
            if(m[tempB]==0) {
                check_Flag=true;
                break;
            }
            temp_Num+=m[tempB];
        }
        
        if(check_Flag) {
            answer.push_back(-1);
        }
        else {
            answer.push_back(temp_Num);
        }
    }
    
    return answer;
}