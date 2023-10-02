#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    string s1 = "";
    
    for(int i=0;i<s.size();i++)
    {
        if(isalpha(s[i]))
        {
            s[i] = tolower(s[i]);
            s1 = s1+s[i];
        }
    }

    string s2 = s1;
    reverse(s1.begin(),s1.end());
    if(s1==s2)
        cout<<"true";
    else 
        cout<<"false";

    return 0;
}