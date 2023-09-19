#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        long temp = x, sum = 0;

        while (x > 0)
        {
            long rem = x % 10;
            sum = (sum * 10) + rem;
            x /= 10;
        }

        return (sum == temp) ? true : false;
    }
};

int main()
{
    Solution s1;
    bool b = s1.isPalindrome(1234567899);
    cout << b;
}