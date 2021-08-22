#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s) 
{
    vector<string> words;
    vector<string> spaces;
    int l = s.length();
    //cout << l << "\n";
    string temp="";
    string sc="";
    int fl=0;
    for(int i=0;i<l;i++)
    {
        if(s[i]==' ')
        {
            if(fl!=0)
            {
                if(temp.length()!=0)
                {
                    words.push_back(temp);
                    temp="";
                }
                if(sc.length()==0)
                {
                    sc.push_back(' ');
                }
            }
        }
        else
        {
            fl = 1;
            if(sc.length()>0)
            {
                spaces.push_back(sc);
                sc="";
            }
            temp.push_back(s[i]);
        }
    }
    if(temp.length()>0)
    {
        words.push_back(temp);
    }
    string res="";
    int j=spaces.size()-1;
        
    for(int k=words.size()-1;k>=0;k--)
    {
        if(j==k)
        {
            res+=spaces[j];
            j--;
        }   
        res+=words[k];
        if(j>=0)
        {
            res+=spaces[j];
            j--;
        }
    }
    return res;
}

int main()
{
    string s;
    getline(cin, s);
    cout << reverseWords(s)  << "\n";
    return 0;
}