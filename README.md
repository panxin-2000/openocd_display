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
1. 将`openocd`的标准输出和标准错误都打印在控制台上
2. 识别`openocd`的标准输出和标准错误，成功读取到`RTT`自动创建log文件,记录芯片输出log
3. 给log文件添加颜色显示，`elog_assert`、`elog_error`、`elog_warn`、`elog_info`、`elog_debug`、`elog_verbose`都有不同的颜色表示
4. stm32核心异常的时候输出寄存器，pc指针，方便判断异常类型。