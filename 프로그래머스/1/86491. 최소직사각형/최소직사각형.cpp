#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> first;
vector<int> second;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    for(vector<int> temp:sizes) {
        if(temp[0]<temp[1]) {
            first.push_back(temp[1]);
            second.push_back(temp[0]);
        }
        else {
            first.push_back(temp[0]);
            second.push_back(temp[1]);
        }
    }
    
    sort(first.begin(),first.end(),greater<>());
    sort(second.begin(),second.end(),greater<>());
    
    return first[0]*second[0];
}