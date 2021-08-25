#include <bits/stdc++.h>
using namespace std;
int real_part(string num1)
{
    int l1 = num1.size();
    int pos=1;
    if(num1[0]=='-')
    {
        pos = -1;
    }
    int r_o=0;
    int mul=10;
    for(int i=0;i<l1;i++)
    {
        if(i==0 && (num1[0]=='+' || num1[0]=='-'))
        {
            continue;
        }
        if(i!=0 && num1[i]=='+')
        {
            break;
        }
        r_o = r_o*mul + (num1[i]-48);
    }
    r_o = r_o * pos;
    
    return r_o;
}

int imag_part(string num1)
{
    int l1 = num1.size();
    int in = -1;
    for(int i=0;i<l1;i++)
    {
        if(i!=0 && num1[i]=='+')
        {
            in = i;
            break;
        }
    }
    int pos=1;
    if(num1[in+1]=='-')
    {
        pos = -1;
    }
    int r_o=0;
    int mul=10;
    for(int i=in;i<l1;i++)
    {
        if(num1[i]=='+' || num1[i]=='-')
        {
            continue;
        }
        if(num1[i]=='i')
        {
            break;
        }
        r_o = r_o*mul + (num1[i]-48);
    }
    r_o = r_o * pos;
    return r_o;
}
string convert_complex(int real, int imag)
{
    //cout << real << "\n";
    string res="";
    int pos = 1;
    if(real<0)
    {
        pos = -1;
        real = real*pos;
    }
    if(real == 0)
    {
        res.push_back('0');
    }
    else
    {
        while(real>0)
        {
            int r = real%10;
            res.push_back(r+'0');
            real = real/10;
        }
    }
    
    string temp="";
    if(pos == -1)
    {
        temp.push_back('-');
    }
    for(int i=res.length()-1;i>=0;i--)
    {
        temp.push_back(res[i]);
    }

    temp.push_back('+');

    //cout << imag << "\n";
    res="";
    pos = 1;
    if(imag<0)
    {
        pos = -1;
        imag = imag*pos;
    }
    if(imag == 0)
    {
        res.push_back('0');
    }
    else
    {
         while(imag>0)
        {
            int r = imag%10;
            res.push_back(r+'0');
            imag = imag/10;
        }
    }
   
    if(pos == -1)
    {
        temp.push_back('-');
    }
    for(int i=res.length()-1;i>=0;i--)
    {
        temp.push_back(res[i]);
    }
    
    temp.push_back('i');
    
    return temp;
}
string complexNumberMultiply(string num1, string num2) {
    int r1 = real_part(num1);
    int r2 = real_part(num2);
    
    int im1 = imag_part(num1);
    int im2 = imag_part(num2);

    int real_res = r1*r2 - im1*im2;
    int imag_res = r1*im2 + im1*r2;

    return convert_complex(real_res, imag_res);
}
int main() {
	string s1,s2;
	cin >> s1 >> s2;
	cout << complexNumberMultiply(s1,s2);
	return 0;
}
