#include "PresidentialPardonForm.hpp"

/* ------------------------------- CONSTRUCTOR ------------------------------ */

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential pardon", 25, 5)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) : AForm(src)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string const target ) : AForm("Presidential pardon", target, 25, 5)
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
	if (this->isSigned() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getRequiredGradeExecute())
		throw AForm::GradeTooLowException();
	
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

AForm * PresidentialPardonForm::make( std::string const & target )
{
	return new PresidentialPardonForm(target);
}


/* -------------------------------- ACCESSOR -------------------------------- */


/* ************************************************************************** */