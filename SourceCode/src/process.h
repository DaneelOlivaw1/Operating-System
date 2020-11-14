#include <iostream>
using namespace std;
#pragma once


class process
{
public:
    string state; // 进程状态
    int saddress; // 在内存的首地址
    int length; // 在内存的长度 
    string user; // 用户名
    int level; // 优先级
    int cnt; //当前运行了多少行
    int arrivetime; // 到达时间。
public:
    int FinishTime;     //结束时间
    int TurnTime;       //周转时间
    int DaiquanTime;  //带权周转时间
    int ServerTime;  //服务时间
    bool operator<(const struct process &a)const {              //优先权排
		return level > a.level || level == a.level;
	}

public:
    process(int start, int length, string user); //start: 开始地址, length: 代码块长度, user: 用户名
    ~process();
    
};