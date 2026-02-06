#include <iostream>
using namespace std;

int main() {

    int a = 10;
    int &ref = a;

    ref = 20;

    cout << "a = " << a << endl;
    return 0;
}

