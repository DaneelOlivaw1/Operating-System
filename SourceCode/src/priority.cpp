#include"priority.h"
#include "stdio.h"
#include <algorithm>
using namespace std;
priority::priority(){

};
priority::~priority(){
    
}
void priority::FeedIn(OS os){            //指向当前优先级最高进程的指针，level越小优先级越大
    for(int i = 1; i < os.Ready_q.size(); i++){
        auto A = os.Ready_q.front();
        os.Ready_q.pop();
        Ready.push_back(A);
    }
    sort(Ready.begin(),Ready.end(),ComArrivetime);
    int j = 0;
   vector<process>::iterator it = Ready.begin();
	while ((*it).arrivetime == (*(it + 1)).arrivetime)
	{
		++j;
		++it;
	}
    sort(Ready.begin(),Ready.begin()+j,ComLevel);
    int CpuTime = -1;
    for(it = Ready.begin();it != Ready.end();it++){     
        if((*it).arrivetime > CpuTime)          //进程到达时，没有其他进程在运行
            (*it).FinishTime = (*it).arrivetime + (*it).ServerTime;
        else
            (*it).FinishTime = CpuTime + (*it).ServerTime;

        (*it).TurnTime = (*it).FinishTime - (*it).arrivetime;
		(*it).DaiquanTime = (double)(*it).TurnTime / (*it).ServerTime;
		CpuTime = (*it).FinishTime;

        // 程序运行过程有其他进程到达的情况
        j = 1;
        while((it + 1) != Ready.end() && (*(it+1)).arrivetime <= CpuTime)
            j++;
        sort((it+1),(it+j),ComLevel);
        
    }

}
bool priority::ComLevel(const process &p1, const process &p2){
    return p1.level > p2.level;
}
bool priority::ComArrivetime(const process &p1, const process &p2){
    return p1.arrivetime < p2.arrivetime;
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