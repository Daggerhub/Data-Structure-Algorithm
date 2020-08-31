#include <iostream>
#include <cstring>
using namespace std;




void printPath(int input,string path)
{
	if(input < 0)
	{
		return;
	}

	if(input==0)
    {

		cout<<path<<endl;
		return;
	}
	printPath(input - 1, path + "1");
	printPath(input - 2, path + "2");
	printPath(input - 3, path + "3");


	return;
}

int main(){

 	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int input;
	cin>>input;
	printPath(input,"");
	return 0;
}
