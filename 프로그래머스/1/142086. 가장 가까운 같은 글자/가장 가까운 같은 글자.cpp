#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char,int> m;

vector<int> solution(string s) {
    vector<int> answer;
    for(char temp:s) {
        m[temp]=-1;
    }
    
    for(int i=0;i<s.size();i++) {
        if(m[s[i]]==-1) {
            answer.push_back(-1);
        }
        else {
            answer.push_back(i-m[s[i]]);
        }
        m[s[i]]=i;
    }
    return answer;
}