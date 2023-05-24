#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N,K;
vector<long double> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    long double ret=987654321;
    cin >> N >> K;
    for(int i=0;i<N;i++) {
        long double data;
        cin >> data;
        v.push_back(data);
    }
    
    for(int q=K;q<=N;q++) {
        
        for(int i=0;i<=N-q;i++) {
            
            long double avg=0;
            for(int j=i;j<i+q;j++) {
                avg+=(long double)v[j];
            }
            avg/=q;
            
            long double temp=0;
            for(int j=i;j<i+q;j++) {
                temp+=pow((long double)v[j]-avg,2);
            }
            temp/=q;
            ret=min(ret,sqrt(temp));
        }
    }
    printf("%.11Lf\n",ret);
    
    return 0;
}
