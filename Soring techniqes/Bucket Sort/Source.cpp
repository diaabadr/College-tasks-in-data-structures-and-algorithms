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

void Insert(Node ** bin, int index)
{
    Node* t = new Node();
    t->value = index;
    t->next = NULL;
    if (bin[index] == NULL)
    {
        bin[index] = t;
    }
    else
    {
        Node* p = bin[index];
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


void BinSort(int a[], int s)
{
    int max = Max(a, s);
    Node** bin=new Node* [max+1];
    // Initialize bins array with nullptr
    for (int i = 0; i < max + 1; i++)
        bin[i] = NULL;
    // Update count array values based on array a values
    for (int j = 0; j < s; j++)
        Insert(bin, a[j]);
    // Update A with sorted elements
    int i = 0, j = 0;
    while (i <= max)
    {
        while (bin[i] != NULL)
        {
            a[j++] = Delete(bin,i);
        }
        i++;
    }
    delete []bin;
}


int main() {

    int A[] = { 2, 5, 8, 12, 3, 6, 7, 10 };
    int n = sizeof(A) / sizeof(A[0]);

    Print(A, n, "\t\tA");
    BinSort(A, n);
    Print(A, n, " Sorted A");
    cout << endl;
    return 0;
}