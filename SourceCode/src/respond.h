#include <iostream>
#include "OS.h"
#include<vector>
#include"process.h"
 #include<algorithm>
#pragma once

class respond{
    public:
        respond();
        ~respond();
        void FeedIn(OS);
        bool CmpByLevel(const process &p1, const process &p2);
        bool CmpByComeTime(const process &p1, const process &p2);
        void CalPriority(std::vector<process>::iterator b, std::vector<process>::iterator e, int CurTime);
    public:
    vector<process> PCB;

};