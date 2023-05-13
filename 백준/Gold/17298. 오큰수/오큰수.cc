#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node {
    int data;
    int idx;
};

stack<Node> s;
vector<Node> temp;
int result[1000001];


int N;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        
        int a;
        cin >> a;
        Node temp_Node;
        temp_Node.data=a;
        temp_Node.idx=i;
        
        temp.push_back(temp_Node);
    }

    
    for(int i=0;i<N;i++) {
        
        if(s.size()==0 or s.top().data>=temp[i].data) {
            s.push(temp[i]);
        }
        else {
            while(s.size()!=0) {
                
                if(s.top().data>=temp[i].data) {
                    break;
                }
                result[s.top().idx]=temp[i].data;
                s.pop();
            }
            s.push(temp[i]);
        }
    }
    
    while(!s.empty()) {
        result[s.top().idx]=-1;
        s.pop();
    }
    
    for(int i=0;i<N;i++) {
        cout << result[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
