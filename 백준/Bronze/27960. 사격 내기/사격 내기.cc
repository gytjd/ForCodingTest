#include <iostream>
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  int c = a ^ b;
  cout << c;
  return 0;
}