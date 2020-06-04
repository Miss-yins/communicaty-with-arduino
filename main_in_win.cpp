#include<iostream>
#include<stdlib.h>
#include<boost/asio.hpp>
#include<boost/bind.hpp>
#include<Windows.h>
#include<conio.h>
using namespace std;
using namespace boost;
int main()
{
	char servo_move_cmd[100];//创建足够大的空间

	std::size_t changdu = 0;
	boost::asio::io_service io_srv;
	boost::asio::serial_port serial(io_srv);
	serial.open("COM14");//根据不同端口进行调整
	serial.set_option(boost::asio::serial_port::baud_rate(9600));
	serial.set_option(boost::asio::serial_port::flow_control(boost::asio::serial_port::flow_control::none));
	serial.set_option(boost::asio::serial_port::parity(boost::asio::serial_port::parity::none));
	serial.set_option(boost::asio::serial_port::stop_bits(boost::asio::serial_port::stop_bits::one));
	serial.set_option(boost::asio::serial_port::character_size(8));
	
	while (true)
	{
		std::cout << "seriver:";
		std::cout << "\n";
		std::cin >> servo_move_cmd;//字符串输入
		//servo_move_cmd[0] = _getch();//单信号输入
		asio::write(serial, asio::buffer(servo_move_cmd, std::strlen(servo_move_cmd)));
		std::cout << "changdu:" << (int)std::strlen(servo_move_cmd) << endl;
		Sleep(50);
		// std::cout << servo_move_cmd << endl;//验证信号

		changdu = boost::asio::read(serial, boost::asio::buffer(servo_move_cmd, std::strlen(servo_move_cmd)));
		Sleep(1);
		std::cout << "temp:";
		std::cout << servo_move_cmd << std::endl;
		
	}
	return 0;
}
