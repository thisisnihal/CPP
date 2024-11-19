#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define sz size()
#define ed "\n"

using namespace std;




 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


vector<string> nums;
void func(TreeNode *root, int idx)
{
    if (root == nullptr)
        return;

    if (root != nullptr)
        nums[idx].push_back(char(root->val) + 0);
    func(root->left, idx);
    func(root->right, idx + 1);
}

int sumNumbers(TreeNode *root)
{
    int sum = 0;
    nums.resize(1100, "");
    func(root, 0);
    for (string s : nums)
    {
        cout << s << endl;
        // if (s !=  "")sum += stoi(s);
    }
    return sum;
}

int main()
{
    int n = 2;
    char c = n;
    string s = "ab";
    s[0] = c+'0';
    cout << s << ed;
}