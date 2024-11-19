#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define sz size()
#define ed "\n"
/* author: nihal136nihal@gmail.com
 * created at 2023-08-27 23:25:16 */
using namespace std;



ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int carry = 0;
    struct ListNode ln;

    return ln;
}

public ListNode reverseList(ListNode head) {
        ListNode *dummy = new ListNode();
        while(head != nullptr) {
            ListNode *next = head.next;
            head.next = dummy;
            dummy = head;
            head = next;
        }
        return dummy;
    }



int main()
{
    struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
    return 0;
}