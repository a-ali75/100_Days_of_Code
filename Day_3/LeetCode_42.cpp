#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) 
{
    int l = height.size();
    
    if(l<3)
    {
        return 0;
    }
    
    vector<int> right_largest(l);
    vector<int> left_largest(l);
    left_largest[0]=0;
    for(int i=1;i<l;i++)
    {
        left_largest[i]=max(left_largest[i-1], height[i-1]);
    }
    
    right_largest[l-1]=0;
    for(int i=l-2;i>=0;i--)
    {
        right_largest[i]=max(right_largest[i+1], height[i+1]);
    }
    int res=0;
    for(int i=1;i<l-1;i++)
    {
        int sum = min(left_largest[i],right_largest[i])-height[i];
        if(sum>=0)
        {
            res+=sum;
        }
    }
    
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
    }
    cout << trap(v) << "\n";
}