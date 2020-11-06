#include <iostream>
#include <ctime>
#include<queue>
#include "process.h"
#pragma once
class OS
{

private:
    static const int MAXN = 10000;
public:
    int memory[MAXN]; // 存储程序占用时间
    bool Source[MAXN]; // 是否使用竞争资源 0为不使用 1为使用
    int p;
    queue<process> Ready_q; //就绪队列

public:
    OS(/* args */);
    ~OS();
    void run(int T);          //OS运行: T表示当前时钟时间
};


