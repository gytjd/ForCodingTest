#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ret;
int N;
vector<int> v;

void DFS_recur(int curr,int target,int num) {
    
    if(curr==N-1) {
        if(num==target) {
            ret+=1;
        }
        return;
    }
    
    DFS_recur(curr+1,target,num+v[curr+1]);
    DFS_recur(curr+1,target,num-v[curr+1]);
}

int solution(vector<int> numbers, int target) {
    
    v=numbers;
    N=numbers.size();
    
    DFS_recur(0,target,v[0]);
    DFS_recur(0,target,-v[0]);
    return ret;
}