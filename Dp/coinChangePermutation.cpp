#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
  freopen("output.txt", "w" , stdout);
  #endif
  
  int n;
  cin>>n;
  int arr[n];

      for(int i = 0 ; i < n; i++){
       cin>>arr[i];
    }   
int target;
cin>>target;

    vector<int> dp(target+1);
    dp[0] = 1;

    for(int amt = 1 ; amt <= target ; amt++){
      for(int coin : arr){
        if( coin <= amt){
          int ramt = amt - coin;
          dp[amt] += dp[ramt];
        }
      }
    }

    cout<<dp[target];

return 0;

}

