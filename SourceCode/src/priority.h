#include <iostream>
#include"process.h"
#include"OS.h"
#include<vector>
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
    vector<process> Ready;          //优先队列，安优先数拍
    bool ComArrivetime(const process &p1, const process &p2);
    bool ComLevel(const process &p1, const process &p2);

};