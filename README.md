# QGSortProject
 QGSortProject

## 程序组成

### 	randomTable.exe

​		测试数据随机生成器，为排序程序生成测试数据，存储文件为“randomTable.dat”，每次打开都将生成一系列随机数据。

### 	largeScaleArray.exe

​		大规模数组排序测试程序，对本程序实现的功能进行一次大规模测试

​			**(Windows):** 为Windows用户准备的测试程序，调用了Windows.h库，时间记录精确到小数后四位

​			**(Not Windows):** 为非Windows用户准备的测试程序，调用了ctime库，时间记录精确到整数

### 	main.exe

​		从“randomTable.dat”中随机抽取长度为10的数组，对本程序的功能进行一次快速的演示与测试

​			**(Windows):** 为Windows用户准备的测试程序，调用了Windows.h库，时间记录精确到小数后四位

​			**(Not Windows):** 为非Windows用户准备的测试程序，调用了ctime库，时间记录精确到整数