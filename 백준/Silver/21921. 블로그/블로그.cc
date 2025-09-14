#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    
    vector<int> visitors(n);
    for(int i = 0; i < n; i++)
    {
        cin >> visitors[i];
    }
    
    long long max = 0;
    long long sum = 0;
    int count = 1;
    
    for(int i = 0; i < x; i++)
    {
        sum += visitors[i];
    }
    
    max = sum;
    
    for(int i = x; i < n; i++)
    {
        sum += visitors[i] - visitors[i-x];
        
        if(sum > max)
        {
            max = sum;
            count = 1;
        }
        else if(sum == max)
        {
            count++;
        }
    }
    
    if(max == 0)
        cout << "SAD";
    else
    {
        cout << max << endl << count;
    }
    
    return 0;
}