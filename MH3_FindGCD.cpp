#include <iostream>
using namespace std;
class FindGCD
{
private:
    int *num1;
    int *num2;

public:
    FindGCD();
    ~FindGCD();
    int getGCD(int, int);
};
FindGCD::FindGCD()
{
    this->num1 = new int(0);
    this->num2 = new int(0);
}
FindGCD::~FindGCD()
{
}
int FindGCD::getGCD(int n1, int n2)
{
    this->num1 = new int(n1);
    this->num2 = new int(n2);
    // cout << *this->num1 << " " << *this->num2 << endl;
    // while ((*this->num2) > 0)
    // {
    //     int q = *this->num1 / *this->num2;
    //     int r = *this->num1 - (q * (*this->num2));
    //     *this->num1 = *this->num2;
    //     *this->num2 = r;
    // }
    // return *this->num1;
    if (*this->num1 == 0)
    {
        return *this->num2;
    }
    else
    {
        int r = (*this->num2) % (*this->num1);
        return getGCD(r, *this->num1);
    }
}
int main()
{
    FindGCD F1;
    int num1, num2;
    cout << "Enter Number 1: ";
    cin >> num1;
    cout << "Enter Number 2: ";
    cin >> num2;
    int GCD = F1.getGCD(num1, num2);
    cout << "GCD(" << num1 << "," << num2 << ") = " << GCD << endl;
}