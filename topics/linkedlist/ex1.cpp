#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-08-25 11:45:34 */
using namespace std;

typedef struct Node {
    int data;
    Node *next;
}Node;

Node *head = NULL;
void insert(int new_data) {
    Node *new_node = new Node;
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}
void display() {
    Node *ptr;
    ptr = head;
    while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    insert(3);
    insert(1);
    insert(7);
    insert(2);
    insert(9);
    cout<<"The linked list is: ";
    display();
    return 0;
}