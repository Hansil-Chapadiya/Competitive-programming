#include<iostream>
using namespace std;
template <class T>
T sqr(T num)
{
    T a = num;
    return a*a;
}
int main()
{
    int n = sqr<int>(10);
    cout<<n;
}