#include <iostream>
#include <vector>

using namespace std;

int N,M;
vector<int> v;
vector<int> temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    
    int temp_N=0;
    temp.push_back(0);
    for(int i=1;i<N;i++) {
        if(v[i-1]>v[i]) {
            temp.push_back(++temp_N);
        }
        else {
            temp.push_back(temp_N);
        }
    }
    
    cin >> M;
    for(int i=0;i<M;i++) {
        int start,end;
        cin >> start >> end;
        cout << temp[end-1]-temp[start-1] << "\n";
    }
    
    return 0;
}
