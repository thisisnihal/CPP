#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define sz size()
#define ed "\n"
/* author: nihal136nihal@gmail.com
 * created at 2023-05-10 10:37:00 */
using namespace std;
void printBinary(int num)
{
    for (int i = 10; i >= 0; i--)
        cout << ((num >> i) & 1);
    cout << "\n";
}

void even_odd_check()
{
    // 0th bit of even number is always 0
    // 0th bit of odd number is always 1
    // so taking (1 & odd_number) gives 1 always and (1 & even_number) gives 0 always.
    for (int i = 0; i < 9; i++) {
        cout << i << " = ";
        printBinary(i);
        if (1&i) cout << "odd\n";
        else cout << "even\n";
    }

    int num = 30;
    cout << "30 >> 1 = " <<  (num >> 1) << ed; // = 15; num = num/2; left shift means divide by 2
    cout << "30 >> 1 = " <<(num << 1) << ed; // = 60; num = nums * 2; right shift means divide by 2

    // (hi+lo >> 1) is equivalent to (hi+lo)/2

    //In general

    
}
void upper_lower_case()
{
    for (char c = 'A'; c <= 'E'; c++) {
        cout << c << " = ";
        (printBinary(int(c)));
    }
    for (char c = 'a'; c <= 'e'; c++) {
        cout << c << " = ";
       (printBinary(int(c)));
    }
    // To covert upper case char to lower case : set the 5th bit 
    char A = 'A';
    char a = A | (1 << 5) ;
    cout << "'A' | (1 << 5) = " << a << ed;

    // To convert lower case char to upper case : unset the 5th bit.
    char upper_a = ('a' & (~(1 << 5))); 
    cout << "'a' & (~(1 << 5)) = " << upper_a << ed << ed;; 
    cout << "'A' = "; printBinary(int('A'));
    cout << "' ' = "; printBinary(int(' '));
    cout << "'a' = "; printBinary(int('a'));
    // Taking ('A' | ' ') gives 'a'
    cout << "'A' | ' ' = " <<  char( ('A' | ' ') ) << ed;
    
    cout << ed; 
    
    cout << "'a' = "; printBinary(int('a'));
    cout << "'_' = ";printBinary(int('_'));
    cout << "'A' = "; printBinary(int('A')); 
    // Taking ('a' & '_') gives 'A
    cout << "'a' & '_' = " <<  char( ('a' & '_') ) << ed;
}
void clear_lsb_msb() {
    
    int num = 59;
    int i = 4;
    int b = (num & ( ~((1 << (i+1)) - 1) )); //it unset all the bit after ith bit
    printBinary(num);
    printBinary(b);
    i = 3;
    int c = (num & ((1<<(i+1))-1)); // it unset all the bit before ith bit
    printBinary(c);
}
int main()
{
    // even_odd_check();
     upper_lower_case();

    //clear_lsb_msb();

    return 0;
}



