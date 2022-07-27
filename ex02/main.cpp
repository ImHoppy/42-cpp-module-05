#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define LOG(A) std::cout << "\e[35m" << A << "\e[0m\n";

int	main(void)
{

	Bureaucrat bob("bob", 1);
	Bureaucrat michel("michel", 150);
	LOG("ShrubberyCreationForm")
	{
		ShrubberyCreationForm a("home");
		ShrubberyCreationForm c(a);
		try
		{
			a.execute(bob);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		c.beSigned(bob);
		LOG("# file home_shrubbery created")
		c.execute(bob);
		bob.executeForm(a);
	}
	LOG("RobotomyRequestForm")
	{
		std::srand(std::time(NULL));
		RobotomyRequestForm a("bob robot");
		RobotomyRequestForm c(a);

		try
		{
			c.execute(bob);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		c.beSigned(bob);
		c.execute(bob);
		bob.executeForm(c);
		
	}
	LOG("PresidentialPardonForm")
	{
		std::srand(std::time(NULL));
		PresidentialPardonForm a("bob robot");
		PresidentialPardonForm c(a);

		try
		{
			c.execute(bob);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		c.beSigned(bob);
		c.execute(bob);
		michel.executeForm(c);
		
	}
	return 0;
}