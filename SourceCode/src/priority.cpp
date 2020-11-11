#include"priority.h"
#include "stdio.h"
priority::priority(){

};
priority::~priority(){
    
}
void priority::FeedIn(OS os){            //指向当前优先级最高进程的指针，level越小优先级越大
    int size = os.Ready_q.size();
    for(int i = 0; i < size;i++)
    {
        auto A = os.Ready_q.front();
        os.Ready_q.pop();
        Ready.push(A);
    }

}

// void priority::print(){
//     while(Ready.size() != NULL)
//     {
//         auto p = Ready.top();
//         Ready.pop();
//         cout << "正在运行的进程" << endl;
// 		cout << "进程名\t优先数 服务时间 已运行时间 还剩运行时间" << endl;//输出当前进程

//     }
// }