#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int curr_A,curr_B,curr_C;
vector<int> A={1,2,3,4,5}; //5
vector<int> B={2,1,2,3,2,4,2,5}; // 8
vector<int> C={3,3,1,1,2,2,4,4,5,5}; // 10
int retA,retB,retC;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    for(int temp:answers) {
        
        cout << A[curr_A] << " " << B[curr_B] << " " << C[curr_C] << "\n";
        
        if(A[curr_A]==temp) {
            retA+=1;
        }
        curr_A=(curr_A+1)%5;
        
        if(B[curr_B]==temp) {
            retB+=1;
        }
        curr_B=(curr_B+1)%8;
        
        if(C[curr_C]==temp) {
            retC+=1;
        }
        curr_C=(curr_C+1)%10;
    }
    
    vector<int> temp;
    temp.push_back(retA);
    temp.push_back(retB);
    temp.push_back(retC);
    
    int max_Ret=max(max(retA,retB),retC);
    
    int curr_Temp=1;
    for(int a:temp) {
        if(a==max_Ret) {
            answer.push_back(curr_Temp);
        }
        curr_Temp+=1;
    }
    
    return answer;
}