#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string,int> m;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    int curr=0;
    for(string temp:name) {
        m[temp]=yearning[curr++];
    }
    
    for(vector<string> tempA:photo) {
        int temp_Num=0;
        for(string tempB:tempA) {
            temp_Num+=m[tempB];
        }
        answer.push_back(temp_Num);
    }
    return answer;
}