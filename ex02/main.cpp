#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#define LOG(A) std::cout << "\e[35m" << A << "\e[0m\n";

int	main(void)
{

	Bureaucrat bob("bob", 1);

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
		c.execute(bob);
	}
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
		
	}
	return 0;
}