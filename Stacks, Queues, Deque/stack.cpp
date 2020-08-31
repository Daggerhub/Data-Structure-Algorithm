#include <iostream>
#include <cstring>
using namespace std;

int count = 0;


void subseq(string input,string ans)
{
	if(input.length()==0)
    {

		cout<<ans<<" ";
		return;
	}
    char ch=input[0];
    string ros=input.substr(1);
    subseq(ros,ans+ch);	
    subseq(ros,ans);

	return;
}

int main(){

 	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    string input;
	cin>>input;
	subseq(input," ");
	return 0;
}
