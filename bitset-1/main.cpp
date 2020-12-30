#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 

    long long N, S, P, Q;
    cin >> N >> S >> P >> Q;

    set<int> s;
    
    long long cur = S;
    s.insert(cur);
    constexpr long long t_31 = 2147483648LL;
    for(int i = 1; i < N; ++i)
    {
        cur = cur * P + Q;
        cur = cur % t_31; 
        if(s.find(cur) == s.end())
        {
            s.insert(cur);
        }
        else
        {
            std::cout << s.size() << "\n";
            return 0;
        }
    }
    std::cout << s.size() << "\n";
    return 0;
}