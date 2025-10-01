#include <iostream>
#include <vector>
#include <queue>
#include <functional>

// Function to solve a single test case
void solve()
{
    long long n;
    std::cin >> n;

    if (n < 2)
    {
        std::cout << "0 0\n";
        return;
    }

    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;

    for (int i = 0; i < n; ++i)
    {
        pq.push(0);
    }

    long long min_entertainment = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        long long skill1 = pq.top();
        pq.pop();
        long long skill2 = pq.top();
        pq.pop();

        long long current_entertainment = skill1 + skill2;
        min_entertainment += current_entertainment;

        pq.push(skill1 + 1);
    }

    long long max_entertainment = (n - 1) * (n - 2) / 2;

    std::cout << min_entertainment << " " << max_entertainment << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}