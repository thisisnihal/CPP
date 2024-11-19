#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-08-25 19:29:02 */
using namespace std;
/**
 * Linked List Tutorial
 * 
 *  
 */
class Node 
{
    public:
    int data;
    Node* next;

    Node(int val) 
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int val) {
    Node* n = new Node(val);
    n->next = head;
    head = n;
}
void insertAtTail(Node* &head, int val) {
    Node* n = new Node(val);
    if (head == NULL) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}
void deletion(Node* &head, int val) {
    
    if (head == NULL) return;
    if (head->next == NULL) {
        deleteAtHead(head);
        return;
    }
    Node* temp = head;
    while (temp->next->data != val) {
        temp = temp->next;
    }
    Node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}
void deleteAtHead(Node* &head) {
    Node* todelete = head;
    head = head->next;
    delete todelete;
}

void display(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

bool search(Node* head, int key) {
    Node* temp = head;
    while(temp != NULL) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}


int main()
{
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtHead(head, 4);
    display(head);
    deletion(head, 2);
    display(head);
    return 0;
}