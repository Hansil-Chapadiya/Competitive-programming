#include <iostream>
#include <string.h>
using namespace std;
class SortStringOccurance
{
private:
    char *str;
    int cnt = 0;
    int arr[26][2];
    int sam[26][2];
    int temp[1][1];

public:
    SortStringOccurance();
    SortStringOccurance(string);
    void getString(string);
    void showString();
    void sorting();
    ~SortStringOccurance();
};

// Method/Functions
SortStringOccurance::SortStringOccurance() // Default Constructor
{
    this->str = new char('\0');
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 1)
            {
                arr[-1 * (65 - i)][j] = 0;
            }
            else
            {
                arr[-1 * (65 - i)][j] = i;
            }
        }
    }
}
SortStringOccurance::SortStringOccurance(string str) // Parameterized Constructor
{
    this->getString(str);
}
void SortStringOccurance::getString(string str) // getString From User
{
    this->str = new char[str.length()];
    int i;
    for (i = 0; i < str.length(); i++)
    {
        this->str[i] = str[i];
    }
    this->str[i] = '\0';
    cout << "Original String" << endl;
    cout << this->str << endl;
}
void SortStringOccurance::showString() // Displaying String on console
{
    cout << "\nDisplaying String" << endl
         << this->str
         << endl;
}
void SortStringOccurance::sorting() // sorting string according that occurance
{
    int s;
    int r = 0;
    // increament of column 1 value according to that character
    for (int i = 0; this->str[i] != '\0'; i++)
    {
        s = -1 * (65 - int(this->str[i]));
        arr[s][1]++;
    }

    // assigning only that value to new sample array which are greater than 0
    // such as:
    //  A - 2 Times
    //  B - 4 Times
    s = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 1)
            {
                if (arr[i][j] > 0)
                {
                    cnt++; // counting character which occurance > than 0
                    r = 0;
                    sam[s][r] = arr[i][j - 1];
                    sam[s][r + 1] = arr[i][j];
                    s++;
                }
            }
        }
    }

    // sort the value according frequency of character in sample array
    for (int i = 0; i < this->cnt; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 1)
            {
                for (int k = i + 1; k < this->cnt; k++)
                {
                    if (sam[i][j] > sam[k][j])
                    {
                        temp[0][0] = sam[i][j];
                        sam[i][j] = sam[k][j];
                        sam[k][j] = temp[0][0];

                        temp[0][0] = sam[i][j - 1];
                        sam[i][j - 1] = sam[k][j - 1];
                        sam[k][j - 1] = temp[0][0];
                    }
                    else if (sam[i][j] == sam[k][j])
                    {
                        if ((char)sam[i][j - 1] > (char)sam[k][j - 1])
                        {
                            temp[0][0] = sam[i][j - 1];
                            sam[i][j - 1] = sam[k][j - 1];
                            sam[k][j - 1] = temp[0][0];
                        }
                    }
                }
            }
        }
    }

    // assigning samplearray value to this->string char by char.
    r = 0;
    for (int i = 0; i < this->cnt; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                for (int k = 0; k < sam[i][j + 1]; k++)
                {
                    this->str[r] = (char)this->sam[i][j];
                    r++;
                }
            }
        }
    }
    this->str[r] = '\0';
}
SortStringOccurance::~SortStringOccurance() // Destructor
{
    free(this->str);
    free(this->arr);
    free(this->sam);
    free(this->temp);
}
int main() // Main Function
{
    SortStringOccurance S1;
    S1.getString("HELOPWORLDASLOP");
    S1.sorting();
    S1.showString();
}

/*occurance of character
// cout<<endl<<"Occurance of character" <<endl;
// for (int i = 0; i < 26; i++)
// {
//     for (int j = 0; j < 2; j++)
//     {
//         if (j == 0)
//         {
//             cout << char(arr[i][j]) << " ";
//         }
//         else
//         {
//             cout << arr[i][j] << " ";
//         }
//     }
//     cout << endl;
// }
// cout << endl
        << endl;*/

/* sorted sample array with only arguments
// cout<<endl<<"SampleArray"<<endl;
// for (int i = 0; i < this->cnt; i++)
// {
//     for (int j = 0; j < 2; j++)
//     {
//         if (j == 1)
//         {
//             cout << sam[i][j] << " ";
//         }
//         else
//         {
//             cout << (char)sam[i][j] << " ";
//         }
//     }
//     cout << endl;
}*/

// for (int k = i + 1; k < 4; i++)
// {
//     if (sam[i][j] > sam[k][j])
//     {
//         temp[0][0] = sam[i][j];
//         sam[i][j] = sam[k][j];
//         sam[k][j] = temp[0][0];

//         temp[0][0] = sam[i][j-1];
//         sam[i][j-1] = sam[k][j-1];
//         sam[k][j-1] = temp[0][0];
//     }
// }