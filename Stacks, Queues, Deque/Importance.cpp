#include <bits/stdc++.h> 
using namespace std; 

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

	int n,count=0;
	cin>>n;

	deque<int> b;
	deque<int> a;

	int x;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		cin>>x;
		b.push_back(x);
	}
	
while(!b.empty())
{
	if(b.front()==a.front())
	{
		count++;
		b.pop_front();
		a.pop_front();
	}
	else
	{
		a.push_back(a.front());
		a.pop_front();
		count++;
	}
}
cout<<count;
return 0;
}  
