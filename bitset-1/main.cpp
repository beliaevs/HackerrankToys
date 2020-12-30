#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

template<typename F>
int floyd(F f, int x_0, int N)
{
    int tortoise = f(x_0);
    int hare = f(tortoise);

    int i = 0;
    while(tortoise != hare && i < N)
    {
        tortoise = f(tortoise);
        hare = f(f(hare));
        ++i;
    }
    if( i == N)
        return N;

    int mu = 0;
    tortoise = x_0;
    while(tortoise != hare && mu < N)
    {
        tortoise = f(tortoise);
        hare = f(hare);
        mu += 1;
    }
    if(mu == N)
        return N;

    int lam = 1;
    hare = f(tortoise);
    while(tortoise != hare && lam < N)
    {
        hare = f(hare);
        lam += 1;
    }
    return min(mu + lam, N);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 

    long long N, S, P, Q;
    cin >> N >> S >> P >> Q;

    auto step = [S, P, Q](int n) -> int {
        constexpr long long t_31 = 2147483648LL;
        return ((long long)(n) * P + Q) % t_31;
    };

    
    std::cout << floyd(step, S, N) << "\n";
    return 0;
}