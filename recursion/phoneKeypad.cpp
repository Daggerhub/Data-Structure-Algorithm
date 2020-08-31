#include <iostream>
#include <cstring>
using namespace std;


void printKpc(string input,string ans,string code[])
{
	if(input.length()==0)
    {

		cout<<ans<<endl;
		return;
	}
    char ch=input[0];
    string ros=input.substr(1);
    string codeforch = code[ch - 48];

    for(int i = 0 ; i < codeforch[i] != '\0'; i++){
    	char cho = codeforch[0];
    	printKpc(ros,ans + cho,code);

    }

	return;
}

int main(){

 	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    string input;
	cin>>input;
	string code[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
	printKpc(input," ",code);
	return 0;
}
