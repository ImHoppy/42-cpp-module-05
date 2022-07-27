#include "Intern.hpp"

/* ------------------------------- CONSTRUCTOR ------------------------------ */

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
	*this = src;
}

const std::string Intern::formsName[FORM_COUNT] = { "shrubbery creation", "robotomy request", "presidential pardon"};

AForm* (*Intern::formsPtr[FORM_COUNT])( std::string const & ) = {ShrubberyCreationForm::make, RobotomyRequestForm::make, PresidentialPardonForm::make};


/* ------------------------------- DESTRUCTOR ------------------------------- */

Intern::~Intern()
{
}


/* -------------------------------- OVERLOAD -------------------------------- */

Intern &				Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}


/* -------------------------------- METHODS --------------------------------- */


const char* Intern::UnknownFormException::what() const throw()
{
	return ("Intern: Form not found.");
}

AForm *			Intern::makeForm( std::string const & form, std::string const & target )
{
	
	for (size_t i = 0; i < FORM_COUNT; i++)
	{
		if (Intern::formsName[i] == form)
			return Intern::formsPtr[i](target);
	}
	// throw Intern::UnknownFormException();
	std::cout << "Intern: Form "<< form <<" not found" << std::endl;
	return NULL;
}


/* -------------------------------- ACCESSOR -------------------------------- */


/* ************************************************************************** */