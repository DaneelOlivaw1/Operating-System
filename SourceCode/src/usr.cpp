#include "usr.h"
#include <cstdlib>
#include <ctime>

usr::usr(string name)
{
    usr_name = name;
}

bool usr::Write(OS &os){
    return true;
}

int usr::GetRandomNum(int l, int r){
    //unsigned seed = time();
    //srand(seed);
    int res = (rand() % (r-l))+ l;
    return res;
}

usr::~usr()
{
}
