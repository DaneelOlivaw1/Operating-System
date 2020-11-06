#!/bin/bash
echo "编译："
echo $(make)
echo "连接中...."
cd obj
if [ -f "a" ];then
    rm a
fi
f=$(ls)
echo $(g++ $f -o a)
echo $(rm *.o)
echo "运行结果："
echo $(./a)
