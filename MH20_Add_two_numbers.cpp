#include <iostream>
using namespace std;

class singly_linked_list
{
private:
    int data;
    singly_linked_list *next;
    singly_linked_list *head = NULL;

public:
    singly_linked_list(/* args */);
    void insertAtBegin(int);
    void insertAtEnd(int);
    void displayList();
    singly_linked_list addTwoNumbers(singly_linked_list);
    ~singly_linked_list();
};

singly_linked_list::singly_linked_list(/* args */)
{
}
void singly_linked_list::insertAtBegin(int data)
{
    singly_linked_list *ptr = (singly_linked_list *)malloc(sizeof(singly_linked_list *));
    if (ptr == NULL)
    {
        cout << "List is Overflow" << endl;
    }
    else
    {
        ptr->data = data;
        ptr->next = head;
        head = ptr;
    }
}
void singly_linked_list::insertAtEnd(int data)
{
    singly_linked_list *ptr = (singly_linked_list *)malloc(sizeof(singly_linked_list *));
    singly_linked_list *newNode = new singly_linked_list();
    newNode->data = data;
    newNode->next = NULL;

    if (ptr == NULL)
    {
        cout << "List is Overflow" << endl;
    }
    else
    {
        if (this->head == NULL)
        {
            this->head = newNode;
        }
        else
        {
            ptr = this->head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }
}
singly_linked_list singly_linked_list::addTwoNumbers(singly_linked_list l2)
{
    singly_linked_list S3;
    if (this->head == NULL)
    {
        cout << endl
             << "List is underflow" << endl;
        exit(0);
    }

    singly_linked_list *ptrL1, *ptrL2;
    ptrL1 = this->head;
    ptrL2 = &l2;
    ptrL2 = ptrL2->head;

    while (ptrL1 != NULL)
    {
        S3.insertAtEnd(ptrL1->data+ptrL2->data);
        ptrL1 = ptrL1->next;
        ptrL2 = ptrL2->next;
    }
    return S3;
}
void singly_linked_list::displayList()
{
    if (this->head == NULL)
    {
        cout << endl
             << "List is UnderFlow" << endl;
        return;
    }
    singly_linked_list *ptr;
    ptr = this->head;
    while (ptr != NULL)
    {
        cout << endl
             << (ptr->data) << endl;
        ptr = ptr->next;
    }
}
singly_linked_list::~singly_linked_list()
{
}
int main()
{
    singly_linked_list S1, S2, S3;
    cout << "Displaying first list" << endl;
    S1.insertAtEnd(12);
    S1.insertAtEnd(15);
    S1.insertAtEnd(13);
    S2.insertAtEnd(12);
    S2.insertAtEnd(15);
    S2.insertAtEnd(13);
    // S1.insertAtBegin(10);
    // S1.insertAtBegin(40);
    // S1.insertAtBegin(30);
    // S1.insertAtBegin(20);
    // S1.insertAtBegin(10);
    // S1.displayList();
    // cout << endl
    //      << "Displaying second list" << endl;
    // S2.insertAtBegin(40);
    // S2.insertAtBegin(50);
    // S2.insertAtBegin(60);
    // S2.displayList();
    S3 = S1.addTwoNumbers(S2);
    S3.displayList();
}

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node(int value) : data(value), next(nullptr) {}
// };

// class singly_linked_list
// {
// private:
//     Node *head;

// public:
//     singly_linked_list();
//     ~singly_linked_list();

//     void insertAtBegin(int data);
//     void insertAtEnd(int data);
//     void displayList();
//     singly_linked_list addTwoNumbers(const singly_linked_list &l2);
// };

// singly_linked_list::singly_linked_list() : head(nullptr) {}

// singly_linked_list::~singly_linked_list()
// {
//     Node *current = head;
//     Node *nextNode;

//     while (current != nullptr)
//     {
//         nextNode = current->next;
//         delete current;
//         current = nextNode;
//     }
// }

// void singly_linked_list::insertAtBegin(int data)
// {
//     Node *newNode = new Node(data);
//     if (newNode == nullptr)
//     {
//         cout << "Memory allocation failed" << endl;
//         return;
//     }

//     newNode->next = head;
//     head = newNode;
// }

// void singly_linked_list::insertAtEnd(int data)
// {
//     Node *newNode = new Node(data);
//     if (newNode == nullptr)
//     {
//         cout << "Memory allocation failed" << endl;
//         return;
//     }

//     if (head == nullptr)
//     {
//         head = newNode;
//     }
//     else
//     {
//         Node *current = head;
//         while (current->next != nullptr)
//         {
//             current = current->next;
//         }
//         current->next = newNode;
//     }
// }

// void singly_linked_list::displayList()
// {
//     if (head == nullptr)
//     {
//         cout << "List is underflow" << endl;
//         return;
//     }

//     Node *current = head;
//     while (current != nullptr)
//     {
//         cout << current->data << endl;
//         current = current->next;
//     }
// }
// singly_linked_list singly_linked_list::addTwoNumbers(const singly_linked_list &l2)
// {
//     singly_linked_list result;
//     Node *ptrL1 = head;
//     Node *ptrL2 = l2.head;

//     int carry = 0;

//     while (ptrL1 != nullptr || ptrL2 != nullptr || carry != 0)
//     {
//         int valueL1 = (ptrL1 != nullptr) ? ptrL1->data : 0;
//         int valueL2 = (ptrL2 != nullptr) ? ptrL2->data : 0;

//         int sum = valueL1 + valueL2 + carry;
//         carry = sum / 10;
//         int digit = sum % 10;

//         result.insertAtEnd(digit);

//         if (ptrL1 != nullptr)
//             ptrL1 = ptrL1->next;

//         if (ptrL2 != nullptr)
//             ptrL2 = ptrL2->next;
//     }

//     return result;
// }

// int main()
// {
//     singly_linked_list S1, S2, S3;

//     cout << "Displaying first list" << endl;
//     S1.insertAtEnd(12);
//     S1.insertAtEnd(15);
//     S1.insertAtEnd(13);

//     S1.displayList();

//     cout << "Displaying second list" << endl;
//     S2.insertAtEnd(12);
//     S2.insertAtEnd(15);
//     S2.insertAtEnd(13);

//     S2.displayList();

//     S3 = S1.addTwoNumbers(S2);
//     S3.displayList();

//     return 0;
// }
