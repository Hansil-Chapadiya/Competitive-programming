#include <iostream>
#include <string>
using namespace std;
class Sorting
{
private:
    char *str;
    int size;

public:
    Sorting();
    Sorting(char[]);
    void sortString();
    ~Sorting();
};
Sorting::Sorting()
{
    *this->str = '\0';
    this->size = 0;
}
Sorting::Sorting(char st[])
{
    for (size = 0; st[size] != '\0'; size++)
        ;
    this->str = new char[size];
    for (int i = 0; i < size; i++)
    {
        this->str[i] = st[i];
    }
    this->str[size] = '\0';
}
void Sorting::sortString()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j <= size - 1; j++)
        {
            if (str[j] < str[i])
            {
                char temp;
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    cout << str;
}
Sorting::~Sorting()
{
}
int main()
{
    char arr[20] = "hansil";
    Sorting S1(arr);
    S1.sortString();
}
