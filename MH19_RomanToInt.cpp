#include <iostream>
#include <map>
using namespace std;

class MH19_RomanToInt
{
private:
    map<char, int> mp;

public:
    MH19_RomanToInt()
    {
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
    }

    int romanToInt(string s)
    {
        int result = 0;
        int prevValue = 0;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            int currValue = mp[s[i]];

            if (currValue >= prevValue)
            {
                result += currValue;
            }
            else
            {
                result -= currValue;
            }

            prevValue = currValue;
        }

        return result;
    }
};

int main()
{
    MH19_RomanToInt converter;
    string romanNumeral = "VIIII";
    int result = converter.romanToInt(romanNumeral);
    cout << "Roman numeral: " << romanNumeral << endl;
    cout << "Integer value: " << result << endl;

    return 0;
}
