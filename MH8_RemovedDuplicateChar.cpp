#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
class RemoveDuplicateCharFromString // class Definition
{
    char *str; //Private String

public:
    RemoveDuplicateCharFromString();
    RemoveDuplicateCharFromString(string);
    void getstring(string);
    void remove();
    void showString();
    ~RemoveDuplicateCharFromString() {}
};

RemoveDuplicateCharFromString::RemoveDuplicateCharFromString() // Default Constructor
{
    this->str = new char('\0');
}
RemoveDuplicateCharFromString::RemoveDuplicateCharFromString(string st) // Parameterized Constructor same as getString() function
{
    this->getstring(st);
}
void RemoveDuplicateCharFromString ::getstring(string st) // Get String From User
{
    try // Exception Handling
    {
        this->str = new char[st.length()]; // Copying string into private string
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
void RemoveDuplicateCharFromString ::remove() // Removing Duplicate Character from string 
{
    for (int i = 0; this->str[i] != '\0'; i++) //  take one character from string
    {
        for (int j = i + 1; this->str[j] != '\0'; j++) // check that character with all character in string
        {
            if (this->str[i] == this->str[j]) // if match
            {
                int k;
                for (k = j; this->str[k] != '\0'; k++) // k became j and itrates until null and sift up
                {
                    this->str[k] = this->str[k + 1]; // shift up
                }
                j--; // becuse if duplicate char arrives at middle it skip next iteration and duplicate char arrives at the end it didn't check next one because j value match to null 
                this->str[k] = '\0';
            }
        }
    }
}
void RemoveDuplicateCharFromString ::showString() // Displaying String
{ 
    // for (int i = 0; this->str[i]!= '\0'; i++)
    // {
    //     cout<<this->str[i];
    // }

    cout << "\nDisplaying String"
         << endl
         << this->str;
}
int main() // Main Function
{
    time_t start, end; // object of Time
    time(&start); // begin time

    ios_base::sync_with_stdio(false); // unsync with stdio

    RemoveDuplicateCharFromString RF1;
    RF1.getstring("thegreathansilchapadiya");
    RF1.remove();
    RF1.showString();

    time(&end); // end time

    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "\nTime taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
}