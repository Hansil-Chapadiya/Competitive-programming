#include <iostream>
using namespace std;
template <class T>
class FindDesiredSum
{
private:
    T *arr;
    int size;
    T sum;

public:
    FindDesiredSum();
    void getArray(T[], int n);
    void putArray();
    void DesiredSum(T);
    ~FindDesiredSum();
};
template <class T>
FindDesiredSum<T>::FindDesiredSum(/* args */)
{
    this->arr = new T(0);
}

template <class T>
void FindDesiredSum<T>::getArray(T arr[], int n)
{
    size = n;
    this->arr = new T[size];
    for (int i = 0; i < size; i++)
    {
        this->arr[i] = arr[i];
    }
}

template <class T>
void FindDesiredSum<T>::DesiredSum(T sum)
{
    int left = 0, right = size - 1;
    while (left < right)
    {
        this->sum = this->arr[left] + this->arr[right];
        if (this->sum == sum)
        {
            cout << "Matched Pair" << endl;
            cout << "(" << this->arr[left] << "," << this->arr[right] << ")";
            exit(0);
        }
        else if (this->sum < sum)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
}

template <class T>
void FindDesiredSum<T>::putArray()
{
    cout << "\nDisplaying Array\n";
    for (int i = 0; i < size; i++)
    {
        cout << this->arr[i] << " ";
    }
    cout << endl
         << endl;
}

template <class T>
FindDesiredSum<T>::~FindDesiredSum()
{
}

int main()
{
    FindDesiredSum<double> F1;
    double arr[] = {1.6, 2.6, 3.2, 4.1, 5.5, 6.3};
    F1.getArray(arr, 6);
    F1.putArray();
    F1.DesiredSum(7.3);
}