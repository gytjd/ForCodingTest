#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    int temp=arr[0];
    answer.push_back(arr[0]);
    for(int i=1;i<arr.size();i++) {
        if(temp!=arr[i]) {
            answer.push_back(arr[i]);
            temp=arr[i];
        }
    }

    return answer;
}