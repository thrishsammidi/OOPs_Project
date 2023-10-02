#include<bits/stdc++.h>
using namespace std;

class Main
{
    public:
    bool Rotation(string s1,string s2)
    {
        int a = s1.size() - 1;
        int b = s2.size() - 1;

        if(a!=b)
            return 0;
        
        string s;

        for(int i=0;i<a;i++)
        {
            if(s1[i]==s2[0])
            {
                string sub = s1.substr(0,i);
                s = s1.substr(i,a-i+1) + sub;
                if(s2 == s)
                    return true;
            }
        }
        return false;
    } 
    
}; 
int main() 
{ 
    int t; 
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Main obj;
        cout<<obj.Rotation(s1,s2)<<endl;
    }
    return 0;
}