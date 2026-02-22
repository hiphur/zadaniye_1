#include <iostream>
#include "CustomIntArr.h"

using std::cout;
using std::endl;


int main() {
    CustomIntArr a(8);
    cout << a.at(5);
    CustomIntArr b;
    b = a;
//    cout << b.at(5);

//    cout << b.at(7);
    return 0;
}
