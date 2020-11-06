#include <iostream>
#pragma once
class OS
{

private:
    static const int MAXN = 10000;
public:
    int memory[MAXN]; // 存储程序占用时间
    bool Source[MAXN]; // 是否使用竞争资源 0为不使用 1为使用
    int p;
public:
    OS(/* args */);
    ~OS();
};


