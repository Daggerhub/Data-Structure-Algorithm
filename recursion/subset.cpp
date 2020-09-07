#include<iostream>
#include<string>
using namespace std;
void sum_subset(int arr[],int idx, string set, int sos,int t, int n)
{
    if(idx == n)
    {
        if(sos == t)
        {
            cout<<set<<'.'<<endl;
        }
        return;
    }
  
    sum_subset(arr,idx+1,set + to_string(arr[idx]) +", ",sos + arr[idx], t,n);
    sum_subset(arr,idx+1,set,sos,t,n);
}
int main()
{
	 	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

     int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin>>arr[i];
    }
    int t;
    cin>>t;
    sum_subset(arr,0,"",0,t,n);
}