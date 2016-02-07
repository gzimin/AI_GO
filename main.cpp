#include <fstream>
#include <string>
#include <iostream>
#include "input.h"
using namespace std;

int main()
{
    Desk *testdeck;
    testdeck = info("inp.txt");
    testdeck->show();
    delete testdeck;
}
