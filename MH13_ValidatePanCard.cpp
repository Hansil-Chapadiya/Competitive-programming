#include <iostream>
#include <string.h>
using namespace std;
class ValidatePanCard
{
private:
    char pStatus[11] = {'A', 'B', 'C', 'F', 'G', 'H', 'J', 'L', 'P', 'T', '\0'}; //Place Holder status Character
    char *panstr; // Pancard Number
    int *len; // Len of Number

public:
    ValidatePanCard(/* args */);
    ValidatePanCard(string);
    void getPannum(string);
    void showPannum();
    int checkPannum();
    ~ValidatePanCard();
};

ValidatePanCard::ValidatePanCard(/* args */) // Defualt Constructor
{
    this->panstr = new char('\0');
}
ValidatePanCard::ValidatePanCard(string s) // Parameterized Constructor
{
    this->getPannum(s);
}
void ValidatePanCard::getPannum(string s) // Get Pan number from User
{
    this->panstr = new char[s.length()];
    for (int i = 0; i < s.length(); i++)
    {
        this->panstr[i] = s[i];  // Copying user string into private member
    }
}
int ValidatePanCard::checkPannum() // Check whether number correct or not
{
    len = new int(strlen(this->panstr)); 
    if ((*this->len) == 10) // it return false if lenth of PanNum is not 10
    {
        for (int i = 0; i < 4; i++) // Check first 4 charcter  
        {
            if (this->panstr[i] >= 'A' && this->panstr[i] <= 'Z')  
            {
                if (i == 3) // when 4th character arrives
                {
                    for (int j = 0; j < strlen(this->pStatus); j++)
                    {
                        if (this->panstr[i] == this->pStatus[j]) // check 4th charcter whether its belongs to place holder status character or not
                        {
                            if (this->panstr[++i] >= 'A' && this->panstr[i] <= 'Z') // check 5th character if it is alphabate (actually first character of Surname)
                            {
                                for (int k = 5; k < 9; i++, k++) // check 5th to 9th character series 
                                {
                                    if ((int(this->panstr[i] - '0') >= 0) && (int(this->panstr[k] - '0') <= 9)) // it must be number between 0 to 9
                                    {
                                        if ((k + 1) == 9 && (this->panstr[k + 1] >= 'A' && this->panstr[k + 1] <= 'Z')) // check 10th character if it is character or not
                                        {
                                            return 1; // if all condition are true
                                        }
                                    }
                                    else
                                    {
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        return 0;
    }
    return 0; // if any condition will be false 
}
void ValidatePanCard::showPannum() // Displaying Pancard Number
{
    cout << endl
         << "Displaying Pancard Number: ";
    cout << this->panstr << endl;
}
ValidatePanCard::~ValidatePanCard() // Destructor 
{
    free(this->len);
    free(this->panstr);
    free(this->pStatus);
}
int main()
{
    ValidatePanCard v1("HMACS5699L");
    v1.showPannum();
    if (v1.checkPannum())
    {
        cout << "\nSuccessfully Verified" << endl;
    }
    else
    {
        cout << "\nOops! wrong Pancard number" << endl;
    }
}
