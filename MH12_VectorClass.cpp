#include <iostream>
#include <vector>
using namespace std;
template <class T>
class VectorClass
{
private:
    T *arr;
    int *n;

public:
    VectorClass(/* args */);
    VectorClass(vector<T> &);
    void getVector(vector<T> &);
    void showVector();
    ~VectorClass();
};

template <class T>
VectorClass<T>::VectorClass()
{
    this->arr = new T(T(0));
}

template <class T>
VectorClass<T>::VectorClass(vector<T> &vec1)
{
    this->arr = new T[vec1.size()];
    this->getVector(vec1);
}

template <class T>
void VectorClass<T>::getVector(vector<T> &vec1)
{
    this->arr = new T[vec1.size()];
    n = new int(vec1.size());
    for (int i = 0; i < vec1.size(); i++)
    {
        this->arr[i] = vec1.at(i);
    }
}

template <class T>
void VectorClass<T>::showVector()
{
    for (int i = 0; i < *this->n; i++)
    {
        cout << this->arr[i] << " ";
    }
}

template <class T>
VectorClass<T>::~VectorClass()
{
}

int main()
{
    vector<char> vec1(26);
    for (int i = 0; i < vec1.size(); i++)
    {
        vec1[i] = char(65 + i);
    }
    VectorClass<char> V1;
    V1.getVector(vec1);
    V1.showVector();
}
