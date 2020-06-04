/*
 Name:		main_in_ubuntu.cpp
 Created:	2020/5/20 10:49:10
 Author:	miss-yins
*/
#include <iostream>
#include <pthread.h>
#include <boost/asio.hpp>
#include <unistd.h>
#include<curses.h>

using namespace std;
using namespace boost;

int main(void)
{
    std::cout << "liyuhenghaosb" << std::endl;
    initscr();
    // 定义字符串长度
    char zifuchuan[1];
    char a;

    // 获取返回字符串长度
    std::size_t changdu = 0;

    // 定义串口服务
    boost::asio::io_service io_ser;
    boost::asio::serial_port serial(io_ser);

    //设置串口参数
    serial.open("/dev/ttyUSB0");
    serial.set_option(boost::asio::serial_port::baud_rate(38400));
    serial.set_option(boost::asio::serial_port::flow_control(boost::asio::serial_port::flow_control::none));
    serial.set_option(boost::asio::serial_port::parity(boost::asio::serial_port::parity::none));
    serial.set_option(boost::asio::serial_port::stop_bits(boost::asio::serial_port::stop_bits::one));
    serial.set_option(boost::asio::serial_port::character_size(8));

    //发送和接收
    while (true)
    {
        zifuchuan[0]=getch();//应用于游戏型单信号输入
        //std::cin>>zifuchuan>>std::endl;//应用于字符串输入

        std::cout << "发送：";
        asio::write(serial, asio::buffer(zifuchuan, std::strlen(zifuchuan)));
        // std::cout << "长度：" << (int)std::strlen(zifuchuan) << std::endl;
        usleep(1);

        changdu = boost::asio::read(serial, boost::asio::buffer(zifuchuan, std::strlen(zifuchuan)));
        std::cout << "接收：";
        std::cout.write(zifuchuan, changdu);
        std::cout << "\n长度：" << (int)changdu <<"\n"<< std::endl;
        usleep(1);
        
    }

    return 0;
}
