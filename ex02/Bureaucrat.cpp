#include "Bureaucrat.hpp"

/* ------------------------------- CONSTRUCTOR ------------------------------ */

Bureaucrat::Bureaucrat(): _name("Bob"), _grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : _name(src._name), _grade(src._grade)
{
	return ;
}

Bureaucrat::Bureaucrat( const std::string & name, int grade ) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}


/* ------------------------------- DESTRUCTOR ------------------------------- */

Bureaucrat::~Bureaucrat()
{
}


/* -------------------------------- OVERLOAD -------------------------------- */

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		// this->_name = rhs.getName();
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::ostream &				operator<<( std::ostream & o , Bureaucrat const & src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return o;
}

/* -------------------------------- METHODS --------------------------------- */

char const * Bureaucrat::GradeTooHighException::what( void ) const throw () {
	return "Grade too High, 1 is the highest grade.";
}
char const * Bureaucrat::GradeTooLowException::what( void ) const throw () {
	return "Grade too Low, 150 is the lowest grade.";
}

void						Bureaucrat::signForm( AForm const & form)
{
	if (form.isSigned())
		std::cout << _name << " signed " << form.getName() << std::endl;
	else
	{
		std::cout << _name << " couldn’t sign " << form.getName() << " because ";
		
		if (_grade > form.getRequiredGradeExecute())
			std::cout << "required grade to execute is too high ";
		// if ((_grade < form.getRequiredGradeExecute()) && (_grade < form.getRequiredGradeSign()))
			// std::cout << " & ";
		if (_grade > form.getRequiredGradeSign())
			std::cout << "required grade to sign is too high";
		std::cout << std::endl;
	}
}


void						Bureaucrat::increment( void )
{
	if ( this->_grade > 1 )
		this->_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}
void						Bureaucrat::decrement( void )
{
	if ( this->_grade < 150 )
		this->_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

void					Bureaucrat::executeForm( AForm const & form ) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}


/* -------------------------------- ACCESSOR -------------------------------- */

int	const &					Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

std::string const &			Bureaucrat::getName( void ) const
{
	return this->_name;
}

/* ************************************************************************** */