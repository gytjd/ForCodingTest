#include <string>
#include <vector>

using namespace std;
int visited[10];

int solution(vector<int> numbers) {
    
    for(int temp:numbers) {
        visited[temp]=1;
    }
    
    int temp_Ret=0;
    for(int i=0;i<10;i++) {
        if(visited[i]==0) {
            temp_Ret+=i;
        }
    }
    return temp_Ret;
}