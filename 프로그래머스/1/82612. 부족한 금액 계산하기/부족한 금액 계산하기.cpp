using namespace std;

long long solution(int price, int money, int count)
{   
    long long temp_Count=0;
    for(int i=1;i<=count;i++) {
        temp_Count+=price*i;
    }
    
    if(temp_Count<money) {
        return 0;
    }
    else {
        return temp_Count-money;
    }
}