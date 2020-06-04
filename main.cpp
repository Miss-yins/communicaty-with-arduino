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
	char servo_move_cmd[100];

	std::size_t changdu = 0;
	//string duibi = 0;
	boost::asio::io_service io_srv;
	boost::asio::serial_port serial(io_srv);
	serial.open("COM14");
	serial.set_option(boost::asio::serial_port::baud_rate(9600));
	serial.set_option(boost::asio::serial_port::flow_control(boost::asio::serial_port::flow_control::none));
	serial.set_option(boost::asio::serial_port::parity(boost::asio::serial_port::parity::none));
	serial.set_option(boost::asio::serial_port::stop_bits(boost::asio::serial_port::stop_bits::one));
	serial.set_option(boost::asio::serial_port::character_size(8));
	
	std::cin >> servo_move_cmd;
	while (true)
	{
		std::cout << "seriver:";
		std::cout << "\n";
		//servo_move_cmd[0] = _getch();
		asio::write(serial, asio::buffer(servo_move_cmd, std::strlen(servo_move_cmd)));
		std::cout << "changdu:" << (int)std::strlen(servo_move_cmd) << endl;
		Sleep(50);
		// cout << servo_move_cmd << endl;

		changdu = boost::asio::read(serial, boost::asio::buffer(servo_move_cmd, std::strlen(servo_move_cmd)));
		Sleep(1);
		std::cout << "temp:";
		std::cout << servo_move_cmd << std::endl;
		
	}
	return 0;
}