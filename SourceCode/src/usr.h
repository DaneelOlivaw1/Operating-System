#include <iostream>
#include "OS.h"
#pragma once
using namespace std;
class usr
{
public:
    string usr_name;
public:
    usr(string name);
    int Write(OS &os);  //生成代码块, os: 所属操作系统
    int GetRandomNum(int l, int r);
    ~usr();
};

