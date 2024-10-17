#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string &a,string &b) {
    
    string tempA=a+b;
    string tempB=b+a;
    return tempA>tempB;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    for(int i=0;i<numbers.size();i++) {
        temp.push_back(to_string(numbers[i]));
    }
    
    sort(temp.begin(),temp.end(),cmp);
    for(string a:temp) {
        answer+=a;
    }
    if(answer[0]=='0') {
        return "0";
    }
    return answer;
}