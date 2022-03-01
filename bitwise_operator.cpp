#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 21;
    int b = 57;
    cout << "a & b = " << (a & b) << endl;
    cout << "a | b = " << (a | b) << endl;
    cout << "a ^ b = " << (a ^ b) << endl;
    cout << "~b = " << ~b << endl;
    cout << "~a = " << ~a << endl;

    // left sift means multiply by 2 in small numbers.
    // right sift means devide by 2 in small numbers.
    cout << "a left sift with 2 = " << (a << 2) << endl;
    cout << "a right sift with 3 = " << (a >> 3) << endl;
    cout << "b left sift with 3 = " << (b << 3) << endl;
    cout << "b right sift with 4 = " << (b >> 4) << endl;
    return 0;
}