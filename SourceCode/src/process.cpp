#include "process.h"
#include "stdio.h"



process::process(int start, int length, string user)
{
    saddress = start;
    length = length;
    user = user;

    state = "sleep";
    level = 0;
    cnt = 0;
    printf("创建进程成功\n");
}

process::~process()
{
}

/*bool process::operator<(const process& rhs)
{
    // 重载小于号 比较到达时间
    if (this->arrivetime < rhs.arrivetime){
        return true;
    }
    else {
        return false;
    }
}*/
