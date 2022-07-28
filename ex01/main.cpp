#include "Bureaucrat.hpp"

#define LOG(A) std::cout << "\e[35m" << A << "\e[0m\n";

int	main(void)
{
	LOG("Copy contructor test")
	{
		Form	michel("Michel", 1, 2);
		Form	copy(michel);
		std::cout << michel << std::endl;
		std::cout << copy << std::endl;
	}

	LOG(std::endl << "Constructor throw test")
	try
	{
		Form bob("bob", 0, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form bob("bob", 1, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	LOG(std::endl << "Form grade test")
	{
		Bureaucrat	michel("Michel", 3);
		Form	inscription("Inscription", 1, 2);
		std::cout << michel << std::endl;
		std::cout << inscription << std::endl;
		LOG(std::endl << "#1")
		try
		{
			inscription.beSigned(michel);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		michel.signForm(inscription);
		std::cout << std::endl;
		std::cout << michel << std::endl;
		std::cout << inscription << std::endl;

		LOG(std::endl << "#2")
		michel.increment();
		try
		{
			inscription.beSigned(michel);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		michel.signForm(inscription);
		std::cout << std::endl;
		std::cout << michel << std::endl;
		std::cout << inscription << std::endl;

		LOG(std::endl << "#3")
		michel.increment();
		michel.signForm(inscription);
		std::cout << std::endl;
		std::cout << michel << std::endl;
		std::cout << inscription << std::endl;
	}
	
	return 0;
}