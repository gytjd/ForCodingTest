#include <iostream>
#include <vector>

using namespace std;

int N,M;
vector<int> v;

void display_() {
    
    int tempCnt=0;
    for(int i=0;i<N;i++) {
        cout << v[i] << " ";
        tempCnt+=1;
        
        if(tempCnt==20) {
            cout << "\n";
            tempCnt=0;
        }
    }
    cout << "\n";
}

void boy_(int idx) {
    
    for(int i=idx;i<N;i+=(idx+1)) {
        v[i]=!v[i];
    }
}

void girl_(int idx) {
    
    int low=idx-1;
    int high=idx+1;
    
    v[idx]=!v[idx];
    while(low>=0 and high<N) {
        
        if(v[low]==v[high]) {
            v[low]=!v[low];
            v[high]=!v[high];
        } else {
            break;
        }
        low-=1; high+=1;
    }
}

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
    
    cin >> M;
    for(int i=0;i<M;i++) {
        int com,idx;
        cin >> com >> idx;
        
        if(com==1) boy_(idx-1);
        else girl_(idx-1);
    }
    display_();
    
    return 0;
}
