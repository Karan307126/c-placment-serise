#include <bits/stdc++.h>
using namespace std;

class Mobile
{
    int charge;
    int RAM;
    int storege;
    string company;

public:
    // Constructor
    Mobile()
    {
        cout << "Constructor call" << endl;
    }

    // Perameterized constructor and this keyword use --> (this keyword is addrese of object)
    Mobile(int charge, int RAM, int storege, string company)
    {
        this->charge = charge;
        this->RAM = RAM;
        this->storege = storege;
        this->company = company;
    }

    // getter and setter is a public function this is provide to us modification in private members.
    void getter()
    {
        cout << charge << endl;
        cout << RAM << endl;
        cout << storege << endl;
        cout << company << endl;
    }
};

int main()
{
    // static allocation of object.
    Mobile m1(50, 4, 16, "Samsung");
    m1.getter();

    // Dynamic allocation of object.
    Mobile *m2 = new Mobile(80, 8, 64, "MI");
    m2->getter(); // alternat way is "(*m2).getter()".
    return 0;
}