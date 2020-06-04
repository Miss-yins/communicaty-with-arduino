# communicaty-with-arduino
Communicate with MCU through ASIO

这个项目一开始是用于搭建控制底盘。
后来不断完善，发现该通讯系统适用范围较广，故分享。

系统的核心是基于asio的上位机与下位机串口通讯，在此基础上进行拓展。

目前本人将此应用于网络通讯，即：pc-pc（asio-MCU），低盘选择arduino，也可以选用其他的单片机或者pc设备。


PC与PC之间是通过网络广播通讯，可以是ssh，云端，ros等；pc（asio-MCU）端则通过串口连接，接收远端PC的信息，并将指令信息转译并作为控制信号发送给MCU。

当然，在pc（asio-MCU）端需要安装boost::asio库，并确保能用。
注：asio库有单独的安装方法，但是介于boost还是有很多用处，我就一并安装了boost库。
windows下安装方法很多，可以自行百度或者bing，
Ubuntu下可以参考：
https://blog.csdn.net/weixin_42723906/article/details/100163590?ops_request_misc=&request_id=&biz_id=102&utm_term=ubuntu%E4%B8%8B%E4%BD%BF%E7%94%A8boost::asio%EF%BC%8C%E5%B9%B6%E4%BD%BF%E7%94%A8cmake%E7%BC%96&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-0-100163590
