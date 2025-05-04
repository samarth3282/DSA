#include <iostream>

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n, m, l, r;
        std::cin >> n >> m >> l >> r;
        int diff = n - m;
        int l_prime = l - diff;
        int r_prime = r - diff;
        std::cout << l_prime << " " << r_prime << std::endl;
    }
    return 0;
}