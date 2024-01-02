#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int visited[204];

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    for(int i=0;i<numbers.size();i++) {
        for(int j=i+1;j<numbers.size();j++) {
            if(visited[numbers[i]+numbers[j]]==0) {
                visited[numbers[i]+numbers[j]]=1;
                answer.push_back(numbers[i]+numbers[j]);
            }
        }
    }
    
    sort(answer.begin(),answer.end());
    
    return answer;
}