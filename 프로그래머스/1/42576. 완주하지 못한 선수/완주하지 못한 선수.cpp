#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string,int> m;
unordered_map<string,int> temp_m;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(string temp:completion) {
        m[temp]+=1;
    }
    
    for(string temp:participant) {
        temp_m[temp]+=1;
    }
    
    for(string temp:participant) {
        if(m[temp]!=temp_m[temp]) {
            answer=temp;
            break;
        }
    }
    return answer;
}