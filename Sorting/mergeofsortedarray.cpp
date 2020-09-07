#include<iostream>
using namespace std;

  void print(int *arr , int n) {
    for (int i = 0; i < n; i++) {
      cout<<arr[i]<<endl;
    }
  }


void mergeSortedArrays(int *arr1, int n1, int *arr2, int n2, int *result){
   int i, j, k;
   i = 0;
   j = 0;
   k = 0;
   while (i < n1 && j < n2) {
      if (arr1[i] < arr2[j]) {
         result[k] = arr1[i];
         ++k;
         ++i;
      } else {
         result[k] = arr2[j];
         ++k;
         ++j;
      }
   }
   while (i < n1) {
      result[k] = arr1[i];
      ++k;
      ++i;
   }
   while (j < n2) {
      result[k] = arr2[j];
      ++k;
      ++j;
   }
}

int main(){


  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
 
  int n;
  cin>>n;
  int arr[n];
  for(int i = 0 ; i < n ; i++){
    cin>>arr[i];
  }
  int m;
  cin>>m;
  int arr2[m];
    for(int i = 0 ; i < m ; i++){
    cin>>arr2[i];
  }
  int p= n+m;
  int res[p];

  mergeSortedArrays(arr,n,arr2,m,res);
  
  print(res,p);
}