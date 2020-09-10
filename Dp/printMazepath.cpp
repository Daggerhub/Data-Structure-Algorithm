#include <iostream>
#include <cstring>
using namespace std;




void printmazePath(int i,int j,int n,int m,string path)
{
	if(i > n || j > m)
	{
		return;
	}

	if(i == n && j == m)
    {

		cout<<path<<endl;
		return;
	}
	printmazePath(i,j+1,n,m,path +"h1");
	printmazePath(i+1,j,n,m,path +"v1");

	return;
}

int main(){

 	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int n,m;
	cin>>n;
	cin>>m;
	printmazePath(1,1,n,m,"");
	return 0;
}
