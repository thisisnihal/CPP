#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define sz size()
#define ed "\n"
/* author: nihal136nihal@gmail.com
 * created at 2023-09-14 17:33:42 */
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
    int total_nodes = 0;
    ListNode *dummy = head;
    while (dummy != nullptr)
    {
        total_nodes++;
        dummy = dummy->next;
    }

    if (k >= total_nodes and total_nodes != 0)
        k = k % total_nodes;
    if (total_nodes <= 1 or k == 0)
        return head;

    int counter = 1;
    dummy = head;
    while (total_nodes - counter != k)
    {
        counter++;
        dummy = dummy->next;
    }

    cout << "total_nodes = " << total_nodes << endl
         << "counter = " << counter << endl;

    ListNode *new_head = dummy->next;
    ListNode *temp = dummy->next;
    dummy->next = nullptr;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = head;

    return new_head;
}

int main()
{

    ListNode *n5 = new ListNode(5);
    ListNode *n4 = new ListNode(4, n5);
    ListNode *n3 = new ListNode(3, n4);
    ListNode *n2 = new ListNode(2, n3);
    ListNode *head = new ListNode(1, n2);

    int k;
    cout << "Enter k: ";
    cin >> k;
    ListNode *ans_node = rotateRight(head, k);
    while (ans_node != nullptr)
    {
        cout << ans_node->val << "->";
        ans_node = ans_node->next;
    }
    cout << "NULL";
    return 0;
}
// [4,5,1,2,3]