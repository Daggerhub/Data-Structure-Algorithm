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

    vector<vector<bool>> dp(n + 1, vector<bool> (target + 1));

    for(int i  = 0; i < n+1; i++){
      for(int j = 0; j < target+1; j++){

        if(i == 0 && j == 0){
          dp[i][j] = true;
        }      
        else if(i == 0){
          dp[i][j] = false;
        }
        else if(j == 0){
          dp[i][j] = true;
        }
        else{
          if(dp[i-1][j] == true){
            dp[i][j] = true;
          }
          else{
            int val = arr[i -1];
            if(j >= val){
              if(dp[i-1][j-val] == true){
                dp[i][j] = true;
              }
            }
          }
        }

      }
    }

if(dp[dp.size()-1][dp[0].size()-1] == 1){
    cout<<"true";
}
else{
    cout<<"false";
}
return 0;

}

