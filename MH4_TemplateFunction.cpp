#include <iostream>
using namespace std;
template <class T>
class Square
{
    T num;
    T r;

public:
    Square();
    Square(T);
    void Sqr();
    void display();
};

template <class T>
Square<T>::Square()
{
    this->num = 0;
    this->r = 0;
}

template <class T>
Square<T>::Square(T num)
{
    this->num = num;
}

template <class T>
void Square<T>::Sqr()
{
    this->r = ((this->num) * (this->num));
}

template <class T>
void Square<T>::display()
{
    cout << "Square of " << this->num << " = " << this->r << endl;
}
int main()
{
    Square<int> s1(14);
    s1.Sqr();
    s1.display();
}