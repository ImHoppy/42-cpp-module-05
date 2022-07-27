#include "RobotomyRequestForm.hpp"

/* ------------------------------- CONSTRUCTOR ------------------------------ */

RobotomyRequestForm::RobotomyRequestForm() : AForm("Shrubbery", 72, 45)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) : AForm(src)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( std::string const target ) : AForm("Shrubbery", target, 72, 45)
{
	return ;
}

/* ------------------------------- DESTRUCTOR ------------------------------- */

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/* -------------------------------- OVERLOAD -------------------------------- */

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	(void) rhs;
	return *this;
}


/* -------------------------------- METHODS --------------------------------- */

void								RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	if (this->isSigned() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getRequiredGradeExecute())
		throw AForm::GradeTooLowException();

	std::cout << "* Drilling noises *" << std::endl << _target;
	if (std::rand() % 2 == 0)
	{
		std::cout << " fail" << std::endl;
	}
	else
	{
		std::cout << " sucess" << std::endl;
	}
}

/* -------------------------------- ACCESSOR -------------------------------- */


/* ************************************************************************** */