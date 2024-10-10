#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> temp;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    for(int i=0;i<progresses.size();i++) {
        if((100-progresses[i])%speeds[i]) {
            temp.push_back((100-progresses[i])/speeds[i]+1);
        } else {
            temp.push_back((100-progresses[i])/speeds[i]);
        }
    }
    
    int count=1;
    int temp_Num=temp[0];
    for(int i=1;i<temp.size();i++) {
        if(temp_Num<temp[i]) {
            answer.push_back(count);
            temp_Num=temp[i];
            count=1;
        }
        else {
            count+=1;
        }
    }
    answer.push_back(count);
    
    return answer;
}