#include <iostream>
using namespace std;
template <class temp1, class temp2, class temp3>
class ComplexNumbers
{
private:
    temp1 *v1;
    temp2 *v2;
    temp3 *v3;

public:
    ComplexNumbers()
    {
        v1 = new temp1(0);
        v2 = new temp2(0);
        v3 = new temp3(0);
    }
    ComplexNumbers(temp1 v1, temp2 v2, temp3 v3)
    {
        this->v1 = new temp1(v1);
        this->v2 = new temp2(v2);
        this->v3 = new temp3(v3);
    }
    ComplexNumbers AddComplexNumbers(ComplexNumbers &cn)
    {
        ComplexNumbers tempCN;
        *tempCN.v1 = *v1 + *cn.v1;
        *tempCN.v2 = *v2 + *cn.v2;
        *tempCN.v3 = *v3 + *cn.v3;
        return tempCN;
    }
    void Display()
    {
        cout << "Value of Real Numbers" << endl;
        cout << *this->v1 << "i + " << *this->v2 << "j + " << *this->v3 << "k ";
    }
    ~ComplexNumbers() {}
};
int main()
{
    // ComplexNumbers <int,int,int> C1(10,14,14);
    // ComplexNumbers <int,int,int> C2(10,10,14);
    // ComplexNumbers <int,int,int> addComplexNumbers;
    // addComplexNumbers = C1.AddComplexNumbers(C2);
    // addComplexNumbers.Display();

    ComplexNumbers<float, float, double> C3(10.14f, 14.10f, 14.14);
    ComplexNumbers<float, float, double> C4(10.14f, 14.10f, 10.10);
    ComplexNumbers<float, float, double> addComplexnumbers;
    addComplexnumbers = C3.AddComplexNumbers(C4);
    addComplexnumbers.Display();
}