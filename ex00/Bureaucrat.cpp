#include "Bureaucrat.hpp"

/* ------------------------------- CONSTRUCTOR ------------------------------ */

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat( const Bureaucrat & src )
{
}


/* ------------------------------- DESTRUCTOR ------------------------------- */

Bureaucrat::~Bureaucrat()
{
}


/* -------------------------------- OVERLOAD -------------------------------- */

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &				operator<<( std::ostream & o , Bureaucrat const & src) const
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade();
	return o;
}

/* -------------------------------- METHODS --------------------------------- */

void						Bureaucrat::increment( void )
{
	if ( this->_value > 1 )
		this->_value--;
	else
		throw Bureaucrat::GradeTooHighException();
}
void						Bureaucrat::decrement( void )
{
	if ( this->_value < 150 )
		this->_value++;
	else
		throw Bureaucrat::GradeTooLowException();
}

/* -------------------------------- ACCESSOR -------------------------------- */

int						Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

std::string				Bureaucrat::getName( void ) const
{
	return this->_name;
}

/* ************************************************************************** */