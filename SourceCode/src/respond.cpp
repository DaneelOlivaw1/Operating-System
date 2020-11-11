#include"respond.h"
#include<vector>
#include"process.h"
using namespace std;
respond::respond(){

}
respond::~respond(){

}
void respond::FeedIn(OS os){
    sort(PCB.begin(), PCB.end(), CmpByComeTime);		//按到达时间排序
 
	//同时到达的按优先级降序排序，决定首先运行的作业
	int i = 1;
	vector<process>::iterator it = PCB.begin() + 1;
	while ((*it).arrivetime == (*(it - 1)).arrivetime)
	{
		++i;
		++it;
	}
	CalPriority(PCB.begin(), PCB.begin() + i, 0);		//计算优先级
	sort(PCB.begin(), PCB.begin() + i, CmpByLevel);
 
	int FinishTime = -1;
	for (it = PCB.begin(); it < PCB.end(); ++it)
	{
		if ((*it).arrivetime >= FinishTime)		//没有作业正在运行，取队首作业运行
			(*it).FinishTime = (*it).arrivetime + (*it).ServerTime;
		else									//有作业正在运行，等待作业完毕，此作业再运行
			(*it).FinishTime = FinishTime + (*it).ServerTime;


		(*it).TurnTime = (*it).FinishTime - (*it).arrivetime;
		(*it).DaiquanTime = (double)(*it).TurnTime / (*it).ServerTime;
		FinishTime = (*it).FinishTime;
 
		//在一个作业运行期间，如果有其他作业到达，将他们按照优先级降序排列
		i = 1;
		while ((it + i) < PCB.end() && (*(it + i)).arrivetime <= FinishTime)
			++i;
		CalPriority(it + 1, it + i, FinishTime);
		sort(it + 1, it + i, CmpByLevel);
	}
 
	//sort(PCB.begin(), PCB.end(), CmpByComeTime);		//重新排列，用于显示结果
}
void respond::CalPriority(vector<process>::iterator b, vector<process>::iterator e, int CurTime){
    while (b < e)
	{
		(*b).level = 1+(double)(CurTime - (*b).arrivetime) / (*b).ServerTime ;
		++b;
	}

}
bool respond::CmpByLevel(const process &p1, const process &p2){
        return p1.level > p2.level;
}
bool respond::CmpByComeTime(const process &p1, const process &p2)
{
	return p1.arrivetime < p2.arrivetime;
}
