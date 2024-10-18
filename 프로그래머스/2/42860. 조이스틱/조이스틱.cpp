#include <string>
#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> tempA;
vector<int> tempB;

int solution(string name) {
    int answer = 0;
    int temp_answer=0;
    for(char temp:name) {
        int al=min(('Z'-temp)+1,temp-'A');
        v.push_back(al);
        answer+=al;
    }
    
    
    for(int i=1;i<=v.size();i++) {
        if(v[i]) {
            tempA.push_back(i);
            tempB.push_back(v.size()-i);
        }
    }
    
    int min_Num=min(tempB[0],tempA[tempA.size()-1]);
    
    for(int i=0;i<tempA.size()-1;i++) {
        min_Num=min(min_Num,tempA[i]*2+tempB[i+1]);
    }
    for(int i=tempB.size()-1;i>=1;i--) {
        min_Num=min(min_Num,tempB[i]*2+tempA[i-1]);
    }
    
    return answer+min_Num;
}