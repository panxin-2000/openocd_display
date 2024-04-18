# 工作流程
常用的openocd命令格式
`openocd -f file.cfg`

在`file.cfg`中添加`SEGGER RTT`相关参数，主要是内存搜索起始地址和搜索长度，输出端口。
```
source [find interface/stlink.cfg] 
transport select hla_swd
source [find target/stm32h7x.cfg]

# download speed = 10MHz
adapter speed 10000
init
rtt setup 0x24005000 0x1000 "SEGGER RTT"
rtt start
rtt server start 9010 0
rtt server start 9011 1
```
`stlink.cfg`指明调试器是什么调试器,
`stm32h7x.cfg`指明嵌入式芯片的名称,
`0x24005000`是内存搜索起始地址,
`0x1000`是搜索长度。

成功搜索到后`openocd`会打印如下提示：

需要另开一个命令行执行`telnet localhost 9010`查看芯片`stm32h7x`输出的log。

# TODO
1. ~~将`openocd`的标准输出和标准错误都打印在控制台上~~
2. ~~记录芯片输出log~~
3. ~~识别`openocd`的标准输出和标准错误,判断时候是否正确连接芯片调试功能//我感觉好像只有标准错误输出，？？？~~
4. ~~识别`RTT`是否找到成功//这个功能没有做，和下一个是重复的~~
5. ~~识别端口号，并自动连接~~
6. ~~给log文件添加颜色显示，`elog_assert`、`elog_error`、`elog_warn`、`elog_info`、`elog_debug`、`elog_verbose`都有不同的颜色表示~~
7. stm32核心异常的时候输出寄存器，pc指针，方便判断异常类型。
8. ~~目前输出的log在控制台是有颜色的，界面中是没有颜色的，需要添加颜色现实，也就是第6项~~
9. 因为不断的添加显示的内容，所以光标一直在跳动，需要让光标不再跳动
10. 烧录程序的按钮也是需要去添加的
11. 记录上一次的配置文件位置和烧录的文件的位置，（想要记录，就一定要有一个固定位置的文件记录配置信息）



# 关于linxu
其实我仔细想了一下这个程序有什么用，对于熟悉命令行的人，其实这个程序是没有多大作用的，对于想要使用界面的
人，这个程序还是有点作用的，减少了了解更多需要的内容。

linux程序应该是什么样子的呢？每个都是小程序，小程序有清晰的输入和输出，可以通过管道或者进程间通信，完成输入和输出，可以同时被多个程序同时调用（多线程安全），小程序的组合能发挥很大的作用，比大程序要好的多。