#include <iostream>
#include<string>
#include<unordered_map>
#include<climits>
using namespace std;

char maxOcc(string s)
{

pair<char,int>x;
x.second=INT_MIN;
unordered_map<char,int>m;
for(int i=0;s[i]; i++)
m[s[i]]++;

for(auto curr:m)
{
if(curr.second>x.second)
{
x.first=curr.first;
x.second=curr.second;
}

}

return x.first;
}
int main() {
string S;

getline(cin,S);

cout<<maxOcc(S);
return 0;
}