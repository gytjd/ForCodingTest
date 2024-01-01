#include <string>
#include <vector>

using namespace std;

int N;
int answer;
int visited[15];
vector<int> v;

void combi_Recur(int curr,int count) {
    if(count==3) {
        int temp_Num=0;
        for(int i=0;i<N;i++) {
            if(visited[i]) {
                temp_Num+=v[i];
            }
        }
        
        if(temp_Num==0) {
            answer+=1;
        }
        return;
    }
    
    for(int i=curr;i<N;i++) {
        if(visited[i]==0) {
            visited[i]=1;
            combi_Recur(i+1,count+1);
            visited[i]=0;
        }
    }
}

int solution(vector<int> number) {
    v=number;
    N=number.size();
    
    combi_Recur(0,0);
    
    return answer;
}