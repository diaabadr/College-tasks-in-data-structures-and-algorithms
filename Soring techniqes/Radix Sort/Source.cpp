#include <iostream>
using namespace std;

template <class T>
void Print(T& vec, int n, string s) {
    cout << s << ": [" << flush;
    for (int i = 0; i < n; i++) {
        cout << vec[i] << flush;
        if (i < n - 1) {
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

int Max(int A[], int n) {
    int max = A[0];
    for (int i = 0; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

// Linked List node
class Node {
public:
    int value;
    Node* next;
};

void Insert(Node** rad, int index,int val)
{
    Node* t = new Node();
    t->value = val;
    t->next = NULL;
    if (rad[index] == NULL)
    {
        rad[index] = t;
    }
    else
    {
        Node* p = rad[index];
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = t;
    }
}


int Delete(Node** bin, int index)
{
    Node* p = bin[index];
    bin[index] = p->next;
    int x = p->value;
    delete p;
    return x;
}

void InitializingRads(Node **rad)
{
    for (int i = 0; i < 10; i++)
        rad[i] = NULL;
}

void RadixSort(int a[], int s)
{
    int Maximum = Max(a, s);
    int x = 1;
    Node** rad = new Node * [10];
    // Initialize rads array with nullptr

    // Update count array values based on array a values
    while (Maximum>x)
    {
        InitializingRads(rad);
        for (int j = 0; j < s; j++)
        {
            Insert(rad, (a[j] / x) % 10,a[j]);
        }
        // Update A with sorted elements
        int i = 0, j = 0;
        while (i < 10)
        {
            while (rad[i] != NULL)
            {
                a[j++] = Delete(rad, i);
            }
            i++;
        }
        x = x*10;
    }
    delete[]rad;
}


int main() {

    int A[] = { 237, 146, 259, 348, 152, 163, 235, 48, 36, 62 };

    Print(A, 10, "\t\tA");
    RadixSort(A, 10);
    Print(A, 10, " Sorted A");
    cout << endl;
    return 0;
}