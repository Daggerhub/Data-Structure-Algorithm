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
  int arr[n];
  int wt[n];

      for(int i = 0 ; i < n; i++){
       cin>>arr[i];
    }   

          for(int i = 0 ; i < n; i++){
       cin>>wt[i];
    }   

int target;
cin>>target;
int bagc;

     vector<int> dp(target + 1);

     for( bagc = 1; bagc <= target; bagc++){
    int ma =0;
      for(int i = 1; i < n ; i++){

     
        if(wt[i] <= bagc){
          int rbagc = bagc - wt[i];
          int rbagv = dp[rbagc];
          int tbagv = rbagv + arr[i];

          if(tbagv > ma){
            ma = tbagv;
          }
        }

      }
        dp[bagc] = ma;
    }

  cout<<dp[target];

return 0;

}
