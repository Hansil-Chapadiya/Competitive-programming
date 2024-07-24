#include <iostream>
#include <iomanip> // For setprecision
#include <ctime>   // For time

using namespace std;

class MH21_BubbleSort
{
private:
    int arr[10];

public:
    int *bubbleSort(int[]);
    MH21_BubbleSort();
    ~MH21_BubbleSort();
};

int *MH21_BubbleSort::bubbleSort(int arr[])
{
    for (int i = 0; i < 10; i++)
    {
        bool swapped = false; // Use a boolean flag instead of cnt
        for (int j = 0; j < 10 - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true; // Set flag to true
            }
        }
        // If no elements were swapped, the array is sorted
        if (!swapped)
        {
            cout << "Array is Sorted" << endl;
            return arr;
        }
    }
    return arr;
}

MH21_BubbleSort::MH21_BubbleSort()
{
}

MH21_BubbleSort::~MH21_BubbleSort()
{
}

int main(int argc, char const *argv[])
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    MH21_BubbleSort bubbleSort1;

    time_t start, end; // Object of Time
    time(&start);      // Begin time

    ios_base::sync_with_stdio(false); // Unsync with stdio

    int *sortedArr = bubbleSort1.bubbleSort(arr); // Capture the returned array

    cout << "Sorted array: ";
    for (int i = 0; i < 10; i++)
    {
        cout << sortedArr[i] << " ";
    }
    cout << endl;

    time(&end); // End time

    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "\nTime taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;

    return 0;
}

/*

#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>

using namespace std;

class MH21_BubbleSort
{
public:
    vector<int> bubbleSort(vector<int>& arr);
    MH21_BubbleSort() = default;
    ~MH21_BubbleSort() = default;
};

vector<int> MH21_BubbleSort::bubbleSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            cout << "Array is already sorted" << endl;
            break;
        }
    }
    return arr;
}

int main()
{
    vector<int> arr(10);
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    MH21_BubbleSort bubbleSort1;

    time_t start, end;
    time(&start);

    ios_base::sync_with_stdio(false);

    vector<int> sortedArr = bubbleSort1.bubbleSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < 10; i++)
    {
        cout << sortedArr[i] << " ";
    }
    cout << endl;

    time(&end);

    double time_taken = double(end - start);
    cout << "\nTime taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;

    return 0;
}

*/