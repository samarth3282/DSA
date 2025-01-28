#include <iostream>
using namespace std;
void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void pattern4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void pattern5(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern6(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void pattern7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++)
        {
            cout << "*";
        }
        for (int l = 0; l < n - i - 1; l++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void pattern8(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * n - 2 * i - 1; k++)
        {
            cout << "*";
        }
        for (int l = 0; l < i; l++)
        {
            cout << " ";
        }

        cout << endl;
    }
}
void pattern10(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        for (int j = 1; j <= stars; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern11(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if ((i + j) % 2 == 0)
            {
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
void pattern12(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1;
        }
        for (int k = 0; k <= n - (2 * i) + 1; k++)
        {
            cout << " ";
        }
        for (int l = 0; l <= i; l++)
        {
            cout << l + 1;
        }
        cout << endl;
    }
}
void pattern13(int n)
{
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}
void pattern14(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char ch = 'A';
        for (int j = 1; j <= i; j++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
}
void pattern15(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A';
        for (int j = 0; j < n - i; j++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
}
void pattern16(int n)
{
    for (char i = 'A'; i <= 'E'; i++)
    {
        for (char j = 'A'; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void pattern17(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int k = 1; k <= 2 * i + 1; k++)
        {
            cout << ch;
            if (k <= breakpoint)
                ch++;
            else
                ch--;
        }
        for (int l = 0; l < n - i - 1; l++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void pattern18(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'E' - i; ch <= 'E' ; ch++)
        {
            /* code */
            cout << ch << " ";
        }
        
        cout << endl;
    }
}
void pattern19(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "*";
        }
        for (int k = 1; k <= 2 * i - 2; k++)
        {
            cout << " ";
        }
        for (int l = 1; l <= n - i + 1; l++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int m = 1; m <= n; m++)
    {
        
    }
    
}
void pattern22(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || j == 1 || i == n-1 || j == n-1)
            {
                // cout << number;
            }
            
        }
        
    }
    
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        cout << endl;
        pattern18(n);
    }
    return 0;
}