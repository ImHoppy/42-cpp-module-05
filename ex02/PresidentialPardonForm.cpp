#include "PresidentialPardonForm.hpp"

/* ------------------------------- CONSTRUCTOR ------------------------------ */

PresidentialPardonForm::PresidentialPardonForm() : AForm("Shrubbery", 25, 5)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) : AForm(src)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string const target ) : AForm("Shrubbery", target, 25, 5)
{

	return ;
}

/* ------------------------------- DESTRUCTOR ------------------------------- */

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/* -------------------------------- OVERLOAD -------------------------------- */

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	(void) rhs;
	return *this;
}


/* -------------------------------- METHODS --------------------------------- */

void								PresidentialPardonForm::execute( Bureaucrat const & executor) const
{
	if (this->isSigned() == false || executor.getGrade() > this->getRequiredGradeExecute())
		throw AForm::CantExecuteException();
	
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
/* -------------------------------- ACCESSOR -------------------------------- */


/* ************************************************************************** */