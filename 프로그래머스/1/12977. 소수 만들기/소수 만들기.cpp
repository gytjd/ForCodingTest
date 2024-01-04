#include <vector>
#include <iostream>
using namespace std;

int N;
int answer;
int visited[3004];
int check[54];
vector<int> v;

void init_() {
    
    visited[0]=1;
    visited[1]=1;
    
    for(int i=2;i*i<=3000;i++) {
        if(visited[i]==0) {
            for(int j=i*i;j<=3000;j+=i) {
                visited[j]=1;
            }
        }
    }
}

void combi_recur(int curr,int count,int temp_Ret) {
    
    if(count==3) {
        if(visited[temp_Ret]==0) {
            answer+=1;
        }
        return;
    }
    for(int i=curr;i<N;i++) {
        if(check[i]==0) {
            check[i]=1;
            combi_recur(i+1,count+1,temp_Ret+v[i]);
            check[i]=0;
        }
    }
    
}

int solution(vector<int> nums) {

    N=nums.size();
    v=nums;
    init_();
    
    combi_recur(0,0,0);

    return answer;
}