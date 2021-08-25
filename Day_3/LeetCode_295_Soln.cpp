#include<bits/stdc++.h>
using namespace std;

priority_queue<int> s; 
priority_queue<int,vector<int>,greater<int> > g;

void addNum(int num) 
{
    if(s.size() == 0)
    {
        s.push(num);
    }
    else if(s.size() == g.size())
    {
        int min_g = g.top();
        if(num >= min_g)
        {
            g.pop();
            g.push(num);
            s.push(min_g);
        }
        else
        {
            s.push(num);
        }
    }
    else
    {
        int max_s = s.top();
        if(num <= max_s)
        {
            s.pop();
            s.push(num);
            g.push(max_s);
        }
        else
        {
            g.push(num);
        }
    }
}

double findMedian() 
{
    if(s.size()==0 && g.size()==0)
    {
        return 0;
    }
    else if(s.size()==g.size())
    {
        return (double)(s.top()+g.top()) / 2;
    }
    else
    {
        return (double)(s.top());
    }
    
}

int main()
{
    while(true)
    {
        cout << "\n1-Add a new element in the stream\n2-Find the median\n3-Exit\n";
        int n;
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Enter the new element\n";
            int n_e;
            cin >> n_e;
            addNum(n_e);
            break;
        case 2:
            cout << "\nThe current Median is - " << findMedian() << "\n";
            break;
        case 3:
            return 0;
            break;
        default:
            break;
        }
    }
}
