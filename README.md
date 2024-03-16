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
3. 识别`openocd`的标准输出和标准错误,判断时候是否正确连接芯片调试功能//我感觉好像只有标准错误输出，？？？
4. 识别`RTT`是否找到成功//这个功能没有做，和下一个是重复的
5. ~~识别端口号，并自动连接~~
6. 给log文件添加颜色显示，`elog_assert`、`elog_error`、`elog_warn`、`elog_info`、`elog_debug`、`elog_verbose`都有不同的颜色表示
7. stm32核心异常的时候输出寄存器，pc指针，方便判断异常类型。