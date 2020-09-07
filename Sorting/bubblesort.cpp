#include<iostream>
using namespace std;


  void swap(int arr[], int i, int j) {
    cout<<"Swapping "<< arr[i]<<" and "<<arr[j]<<endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
  bool isSmaller(int arr[], int i, int j) {
  cout<<"Comparing " <<arr[i]<< " and " <<arr[j]<<endl;
    if (arr[i] < arr[j]) {
      return true;
    } else {
      return false;
    }
  }

  void print(int arr[] , int n) {
    for (int i = 0; i < n; i++) {
      cout<<arr[i]<<endl;
    }
  }


  void bubblesort(int arr[] , int n) {
    for(int i = 1 ; i <= n - 1; i++){
      for(int j = 0 ; j < n - i ; j++){
        if(isSmaller(arr,j+1,j)){
          swap(arr,j+1,j);
        }
      }
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
  bubblesort(arr,n);
  print(arr,n);
}