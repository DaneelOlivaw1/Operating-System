#include "usr.h"
#include <cstdlib>
#include <ctime>

usr::usr(string name)
{
    usr_name = name;
}

int usr::Write(OS &os){
    // 在操作系统内存中写入程序
    // 程序长度为length为20～50
    // 占用时间为10～30
    // 占用竞争资源的概率为30% 抢占CPU的概率为70%
    int length = GetRandomNum(20, 51);
    for (int i = 1; i <= length; i++){
        os.memory[os.p] = GetRandomNum(10, 30);
        GetRandomNum(1,11) <= 3 ? os.Source[os.p] = 1 : os.Source[os.p] = 0;
        os.p++;
    }
    return length;
}

int usr::GetRandomNum(int l, int r){
    // 生成随机数
    // 随机数范围 [l,r)
    int res = (rand() % (r-l))+ l;
    return res;
}

usr::~usr()
{
}
