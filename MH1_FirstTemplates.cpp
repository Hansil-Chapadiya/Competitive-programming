#include <iostream>
#include <string>
using namespace std;
template <class T>
class CompareValues
{
private:
    T v1;

public:
    CompareValues(T v1)
    {
        this->v1 = v1;
    }
    ~CompareValues()
    {
        cout << endl
             << "Destructor of object" << endl;
    }
    bool operator== (CompareValues &cv)
    {
        if (this->v1 == cv.v1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void show()
    {
        cout << this->v1 << endl;
    }
};
int main()
{
    CompareValues<int> c1(10);
    CompareValues<int> c2(10);
    c1.show();
    c2.show();
    if (c1 == c2)
    {
        cout << "Matched" << endl;
    }
    else
    {
        cout << "Miss Matched" << endl;
    }
}

// template <class T>
// class CompareValues
// {
// private:
//     T v1;

// public:
//     CompareValues(T v1)
//     {
//         this->v1 = v1;
//     }
//     bool operator==(CompareValues &cv)
//     {
//         if (this->v1 == cv.v1)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
//     void show()
//     {
//         cout << this->v1 << endl;
//     }
// };
// int main()
// {
//     CompareValues<string> C1("hello");
//     CompareValues<string> C2("hello");
//     C1.show();
//     C2.show();
//     bool result = C1 == C2;
//     cout << result;
// }