#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(vector<int> temp:commands) {
        
        vector<int> ret;
        for(int i=temp[0]-1;i<=temp[1]-1;i++) {
            ret.push_back(array[i]);
        }
        sort(ret.begin(),ret.end());
        answer.push_back(ret[temp[2]-1]);
    }
    
    
    return answer;
}