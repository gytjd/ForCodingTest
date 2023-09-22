#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<int> temp;
    temp.push_back(0);
    
    for(int a:sequence) {
        temp.push_back(a);
    }
    
    for(int i=1;i<=temp.size();i++) {
        temp[i]+=temp[i-1];
    }
    
    int low=0;
    int high=0;
    int ret=987654321;
    int retLow=0;
    int retHigh=0;
    
    while(low<=high and high<=temp.size()) {
        
        if(temp[high]-temp[low]<k) {
            high+=1;
        }
        else {
            if(temp[high]-temp[low]==k) {
                if(high-low<ret) {
                    ret=high-low;
                    retLow=low;
                    retHigh=high-1;
                }
            }
            low+=1;
        }
    }
    
    answer.push_back(retLow);
    answer.push_back(retHigh);

    return answer;
}