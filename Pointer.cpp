#include <bits/stdc++.h>
using namespace std;

void Update(int **ptr)
{
    // ptr = ptr + 1; // this not make any change....
    // *ptr = *ptr + 1; // this make only change in p1....
    **ptr = **ptr+ 1;    // this make change only on i increment by 1....
}

int main()
{
    // int num = 5;
    // int *ptr = &num;
    // cout << "The value of Num is : " << num << endl;
    // cout << "The value of Num is : " << *ptr << endl;
    // cout << "The addrese of Num is : " << &num << endl;
    // cout << "The addrese of Num is : " << ptr << endl;
    // cout << endl;

    // char a = 'a';
    // char *cptr = &a;
    // cout << "The value of a is : " << a << endl;
    // cout << "The value of a is : " << *cptr << endl;
    // cout << "The addrese of a is : " << &a << endl;
    // cout << "The addrese of a is : " << cptr << endl;
    // printf("Addrese of a : %d\n", cptr);

    // int n = 10;
    // int *p = &n;
    // cout << p << endl;
    // cout << *p << endl;
    // p = p + 1;
    // cout << p << endl;
    // cout << *p << endl;

    // char b[] = "xyz";
    // char *c = b;
    // cout << c[0] << b[0] << endl;

    // char d[] = "xyz";
    // char *e = &d[0];
    // cout << e << endl;

    // int a = 10;
    // int *p = &a;
    // int **q = &p;
    // int b = 20;
    // *q = &b;
    // (*p)++;
    // cout << a << " " << b << endl;

    // int arr[5] = {23, 41, 76, 98, 12};
    // cout << "The value at index 3 is : " << 3 [arr] << endl; // This statement is same as arr[3] or *(arr + i) or *(i + arr).

    // char *a1 = "abcd";   // this is very riskky thing don't this ....

    int i = 5;
    int *p1 = &i;
    int **p2 = &p1;

    cout << "Before" << endl;
    cout << i << endl;
    cout << p1 << endl;
    cout << p2 << endl
         << endl;
    Update(p2);
    cout << "After" << endl;
    cout << i << endl;
    cout << p1 << endl;
    cout << p2 << endl;

    // cout << i << endl;
    // cout << *p1 << endl;
    // cout << **p2 << endl
    //      << endl;

    // cout << &i << endl;
    // cout << p1 << endl;
    // cout << *p2 << endl
    //      << endl;

    // cout << &(&i) << endl; // This thing is not work....
    // cout << &p1 << endl;
    // cout << p2 << endl
    //      << endl;
    return 0;
}