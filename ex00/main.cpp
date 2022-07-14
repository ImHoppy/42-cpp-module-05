#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	bob("Bob", 1);
		bob.increment();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}