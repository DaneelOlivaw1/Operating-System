#include <iostream>
#include "OS.h"
using namespace std;
class usr
{
public:
    string usr_name;
public:
    usr(string name);
    bool Write(OS &os);
    int GetRandomNum(int l, int r);
    ~usr();
};

