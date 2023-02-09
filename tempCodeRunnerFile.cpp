#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
class RemoveDuplicateCharFromString
{
    char *str;

public:
    RemoveDuplicateCharFromString();
    RemoveDuplicateCharFromString(string);
    void getstring(string);
    void remove();
    void showString();
    ~RemoveDuplicateCharFromString() {}
};

RemoveDuplicateCharFromString::RemoveDuplicateCharFromString()
{
    this->str = new char('\0');
}
RemoveDuplicateCharFromString::RemoveDuplicateCharFromString(string st)
{
    this->getstring(st);
}
void RemoveDuplicateCharFromString ::getstring(string st)
{
    try
    {
        this->str = new char[st.length()];
        int i;
        for (i = 0; i < st.length(); i++)
        {
            this->str[i] = st[i];
        }
        this->str[i] = '\0';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
void RemoveDuplicateCharFromString ::remove()
{
    for (int i = 0; this->str[i] != '\0'; i++)
    {
        for (int j = i + 1; this->str[j] != '\0'; j++)
        {
            if (this->str[i] == this->str[j])
            {
                int k;
                for (k = j; this->str[k] != '\0'; k++)
                {
                    this->str[k] = this->str[k + 1];
                }
                j--;
                this->str[k] = '\0';
            }
        }
    }
}
void RemoveDuplicateCharFromString ::showString()
{
    // for (int i = 0; this->str[i]!= '\0'; i++)
    // {
    //     cout<<this->str[i];
    // }

    cout << "\nDisplaying String"
         << endl
         << this->str;
}
int main()
{
    time_t start, end;
    time(&start);

    ios_base::sync_with_stdio(false);
    RemoveDuplicateCharFromString RF1;
    RF1.getstring("ghhhhgggnnnmmmmhhhhh");
    RF1.remove();
    RF1.showString();

    time(&end);

    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "\nTime taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
}