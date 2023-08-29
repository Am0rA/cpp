#include <iostream>

int	main(void)
{
	std::string text = "HI THIS IS BRAIN";
	std::string	*textPTR = &text;
	std::string &textREF = text;

	std::cout << "address of text: " << &text << std::endl;
	std::cout << "address of textPTR: " << textPTR << std::endl;
	std::cout << "address of textREF: " << &textREF << std::endl;

	std::cout << "value of text: " << text << std::endl;
	std::cout << "value of textPTR: " << *textPTR << std::endl;
	std::cout << "value of textREF: " << textREF << std::endl;

	std::cout << "address of text: " << &text << std::endl;
	std::cout << "address of textPTR: " << textPTR << std::endl;
	std::cout << "address of textREF: " << &textREF << std::endl;

	std::cout << "value of text: " << text << std::endl;
	std::cout << "value of textPTR: " << *textPTR << std::endl;
	std::cout << "value of textREF: " << textREF << std::endl;
}