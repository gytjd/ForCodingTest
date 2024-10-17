#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> first={1,2,3,4,5};
vector<int> second={2,1,2,3,2,4,2,5};
vector<int> third={3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int first_Cnt=0;
    int second_Cnt=0;
    int third_Cnt=0;
    
    int first_Num=0;
    int second_Num=0;
    int third_Num=0;
    
    for(int i=0;i<answers.size();i++) {
        
        if(answers[i]==first[first_Cnt]) {
            first_Num+=1;
        }
        
        if(answers[i]==second[second_Cnt]) {
            second_Num+=1;
        }
        
        if(answers[i]==third[third_Cnt]) {
            third_Num+=1;
        }
        
        first_Cnt=(first_Cnt+1)%5;
        second_Cnt=(second_Cnt+1)%8;
        third_Cnt=(third_Cnt+1)%10;
    }
    
    vector<int> temp;
    temp.push_back(first_Num);
    temp.push_back(second_Num);
    temp.push_back(third_Num);
    
    int temp_Max=temp[0];
    for(int i=1;i<3;i++) {
        temp_Max=max(temp[i],temp_Max);
    }
    
    for(int i=0;i<3;i++) {
        if(temp[i]==temp_Max) {
            answer.push_back(i+1);
        }
    }
    
    
    
    return answer;
}