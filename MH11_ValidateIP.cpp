#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class ValidateIP
{
private:
    char *ip;
    int count;
    string *sPart;

public:
    ValidateIP();
    ValidateIP(string);
    void getIP(string);
    int checkIP();
    void putIP();
    ~ValidateIP();
};

ValidateIP::ValidateIP() // Defualt Constructor
{
    this->ip = new char('\0');
    this->count = 0;
    this->sPart = new string[4];
}
ValidateIP::ValidateIP(string ip) // Parameterized Constructor
{
    this->ip = new char('\0');
    this->count = 0;
    this->sPart = new string[4];
    getIP(ip);
}
void ValidateIP::getIP(string ip) // Get IP address from user
{
    int i;
    this->ip = new char[ip.length()];
    for (i = 0; ip[i] != '\0'; i++) // Copying string into private data member
    {
        this->ip[i] = ip[i];
    }
    this->ip[i] = '\0';
}
int ValidateIP::checkIP()
{
    stringstream split(this->ip); // string strem object used to read value from string >> extraction,<< insertion
    string sPart;
    while (!split.eof()) // until string value raach to the NULL('\0')
    {
        if (getline(split, sPart, '.')) // taking sub string from string
        {
            try
            {
                if (count < 4)
                {
                    this->sPart[count] = sPart; // Assign substring in private sPart(string part) variable(string array)
                }
                count++; // check for IP address has 4 sub part
            }
            catch (const std::exception &e)
            {
                cout << e.what() << endl;
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    if (this->count == 4) // check for IP address has 4 sub part
    {
        for (int i = 0; i < count; i++)
        {
            if (stoi(this->sPart[i]) > 255) // return false if any sub part of IP is > than 255
            {
                return 0;
                break;
            }
        }
        return 1; // return true if IP is valid
    }
    else
    {
        return 0; // return false if IP hasn't 4 sub parts
    }
}
void ValidateIP::putIP() // Display IP Address
{
    cout << "IP ADDRESS = " << this->ip << endl;
}
ValidateIP::~ValidateIP() // Destructorફ
{
    free(this->ip);
    free(this->sPart);
}
int main() // Main Method(Funtion)
{
    ValidateIP VP("20.255.254.255"); // Object Declaring/Initializing
    if (VP.checkIP())                // Check IP methods calling
    {
        cout << "SuccessFully Verified" << endl;
        VP.putIP(); // display method calls
    }
    else
    {
        cout << "Oops! Invalid IP Address.." << endl; // show Invalid IP massage
    }
}