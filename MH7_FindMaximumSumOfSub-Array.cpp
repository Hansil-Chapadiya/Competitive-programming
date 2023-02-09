// #include<iostream>
// #include<array>
// using namespace std;
// int main()
// {
//    int c;
//    int arr[]={1,2,3,4,5,6,7,8,9,0};
//    cout<<"The array is: ";
//    for(auto i: arr)
//    {
//    		cout<<i<<" ";
//    		c++;
//    }
//    cout<<"\nThe length of the given Array is: "<<c;
//    return 0;
// }

#include <iostream>
#include <array>
using namespace std;
template <class T>
class MaxSumOfSubArray
{
    T *arr;
    int size;
    int sPos;
    int ePos;
    T *sum1;
    T *sum2;

public:
    MaxSumOfSubArray();
    MaxSumOfSubArray(int);
    void assignValue(T[], int n = 0);
    void MaxFromSubArray();
    void display();
};

template <class T>
MaxSumOfSubArray<T>::MaxSumOfSubArray()
{
    this->arr = new T[10];
    size = 0;
}

template <class T>
MaxSumOfSubArray<T>::MaxSumOfSubArray(int size)
{
    this->size = size;
}

template <class T>
void MaxSumOfSubArray<T>::assignValue(T list[], int n)
{
    size = n;
    if (size != 0)
    {
        for (int i = 0; i < size; i++)
        {
            this->arr[i] = list[i];
        }
    }
    else
    {
        cout << "Enter Range of an Array to few arguments" << endl;
        exit(0);
    }
}

template <class T>
void MaxSumOfSubArray<T>::MaxFromSubArray()
{
    this->sum1 = new T(0);
    this->sum2 = new T(0);

    cout << "Enter Positions For Subarray1"
         << endl;
    cout << "Enter Start Position: ";
    cin >> sPos;
    cout << "Enter End Position: ";
    cin >> ePos;
    for (int i = sPos - 1; i < ePos; i++)
    {
        *this->sum1 += this->arr[i];
    }

    cout << "\nEnter Positions For Subarray2"
         << endl;
    cout << "Enter Start Position: ";
    cin >> sPos;
    cout << "Enter End Position: ";
    cin >> ePos;
    for (int i = sPos - 1; i < ePos; i++)
    {
        *this->sum2 += this->arr[i];
    }

    cout << "Sum of SubArray1: " << *this->sum1 << endl;
    cout << "Sum of SubArray2: " << *this->sum2 << endl;

    if (*this->sum1 > *this->sum2)
    {
        cout << "Sum of subArray1 > than Sum of SubArray2" << endl;
    }
    else if (*this->sum1 < *this->sum2)
    {
        cout << "Sum of subArray1 < than Sum of SubArray2" << endl;
    }
    else if (*this->sum1 == *this->sum2)
    {
        cout << "Both SubArray Sum is same" << endl;
    }
    else
    {
        cout << "Something went wrong" << endl;
    }
}

template <class T>
void MaxSumOfSubArray<T>::display()
{
    cout << "\nDisplaying Array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << this->arr[i] << " ";
    }
}

int main()
{
    double arr[] = {1.1, 2.6, 3.9, 4.10, 5.17, 6.17, 7.14, 8.10, 9.14, 0.0};
    MaxSumOfSubArray<double> M1;
    M1.assignValue(arr, 10);
    M1.MaxFromSubArray();
    M1.display();
}
