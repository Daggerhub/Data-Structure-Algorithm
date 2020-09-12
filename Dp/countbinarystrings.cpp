#include<iostream>
#include<vector>
using namespace std;

int main(){

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
  freopen("output.txt", "w" , stdout);
  #endif
  
  int n;
  cin>>n;

  int zeros = 1;
  int ones  = 1;

  for(int i = 1; i < n ; i++){
    int newzeros = ones;
    int newones  = ones + zeros;

    zeros = newzeros;
    ones  = newones;

  }
  cout<<(zeros+ones);

return 0;

}
