#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#define LOG(A) std::cout << "\e[35m" << A << "\e[0m\n";

int	main(void)
{
	Intern stagiaire;
	const std::string formsName[4] = { "presidential pardon", "robotomy request", "shrubbery creation", "undefined"};
	for (size_t i = 0; i < 4; i++)
	{
		std::string form = formsName[i];

		LOG("Le stagiaire crée le formulaire " << form)
		AForm *a = stagiaire.makeForm(form, "bob");
		if (a)
		{
			std::cout << a->getName() << std::endl;
			delete a;
		}
	}
	LOG("Check target name")
	Bureaucrat bob("bob", 1);
	AForm *a = stagiaire.makeForm("presidential pardon", "michel");
	a->beSigned(bob);
	a->execute(bob);
	delete a;
	return 0;
}