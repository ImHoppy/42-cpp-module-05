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
	return "Grade too High";
}
char const * Bureaucrat::GradeTooLowException::what( void ) const throw () {
	return "Grade too Low";
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