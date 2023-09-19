#include <iostream>
#include <cctype>

using namespace std;

class Solution {
private:
    int i;
    string str;

public:
    string toLowerCase(string s) {
        for (int i = 0; i < s.length(); i++) {
            s[i] = tolower(s[i]);
        }
        return s;
    }
};

int main() {
    Solution s1;
    string s;
    cout<<"Enter string: ";
    cin>>s;
    string lowercaseString = s1.toLowerCase(s);
    cout << lowercaseString << endl;
    return 0;
}
