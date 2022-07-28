#include "Bureaucrat.hpp"

#define LOG(A) std::cout << "\e[35m" << A << "\e[0m\n";

int	main(void)
{
	LOG("Copy contructor test")
	{
		Bureaucrat	michel("Michel", 2);
		Bureaucrat	copy(michel);
		std::cout << michel << std::endl;
		LOG("Decrement Original")
		michel.decrement();
		LOG("Original Michel")
		std::cout << michel << std::endl;
		LOG("Copy Michel")
		std::cout << copy << std::endl;
	}

	LOG(std::endl << "Constructor throw test")
	try
	{
		Bureaucrat bob("bob", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat bob("bob", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	LOG(std::endl << "Increment and High grade test")
	{
		Bureaucrat	michel("Michel", 1);
		michel.decrement();
		std::cout << michel << std::endl;
		michel.increment();
		std::cout << michel << std::endl;
		try
		{
			michel.increment();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << michel << std::endl;
	}

	LOG(std::endl << "Decrement and Low grade test")
	{
		Bureaucrat	bob;
		bob.increment();
		std::cout << bob << std::endl;
		bob.decrement();
		std::cout << bob << std::endl;
		try
		{
			bob.decrement();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << bob << std::endl;
	}
	return 0;
}