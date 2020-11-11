#include <iostream>
#include"process.h"
#include"OS.h"
using namespace std;
#pragma once


class priority
{
    public:
    priority();
    ~priority();
    void FeedIn(OS);
    //void print();  //输出结果




    public:
    priority_queue<process> Ready;          //优先队列，安优先数拍


};