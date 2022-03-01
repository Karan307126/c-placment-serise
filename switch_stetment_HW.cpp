#include <bits/stdc++.h>
using namespace std;

int main()
{
    int amount;
    cout << "Enter amount : ";
    cin >> amount;

    int hundred = 0, fifty = 0, twenty = 0, one = 0;

    switch(1){
        case 1:
            hundred = amount / 100;
            cout << hundred << " -> 100 $" << endl;
            amount = amount % 100;

        case 2:
            fifty = amount / 50;
            cout << fifty << " -> 50 $" << endl;
            amount = amount % 50;
        
        case 3:
            twenty = amount / 20;
            cout << twenty << " -> 20 $" << endl;
            amount = amount % 20;
        
        case 4:
            one = amount / 1;
            cout << one << " -> 1 $" << endl;
    }
    return 0;
}