#include <iostream>
#include <queue>

using namespace std;

int N,M;
deque<int> arr;

int is_idx_r(int findNum) {
    
    
    for(int i=0;i<arr.size();i++) {
        if(arr[i]==findNum) {
            return i;
        }
    }
    
    return 0;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=1;i<=N;i++) {
        arr.push_back(i);
    }
    
    
    int Cnt=0;
    for(int i=0;i<M;i++) {
        int data;
        cin >> data;
        
        if(arr.front()==data) {
            arr.pop_front();
        }
        else {
            
            int tmp_r=is_idx_r(data);
            int tmp_l=arr.size()-tmp_r;
            
            
            if(tmp_r<tmp_l) {
                
                int tmp;
                for(int j=0;j<tmp_r;j++) {
                    tmp=arr.front();
                    arr.pop_front();
                    arr.push_back(tmp);
                }
                Cnt+=tmp_r;
                arr.pop_front();
            }
            else {
                
                int tmp;
                for(int j=0;j<tmp_l;j++) {
                    tmp=arr.back();
                    arr.pop_back();
                    arr.push_front(tmp);
                }
                
                Cnt+=tmp_l;
                arr.pop_front();
            }
        }
    }
    
    cout << Cnt << "\n";
    
    return 0;
}
