#include "Form.hpp"

inline const char * BoolToStr(bool b)
{
  return (b ? "true" : "false");
}

/* ------------------------------- CONSTRUCTOR ------------------------------ */

Form::Form(): _name("Bob"), _grade_sign(0), _grade_exec(0), _signed(false)
{
	return ;
}

Form::Form( const Form & src ) : _name(src._name), _grade_sign(src._grade_sign), _grade_exec(src._grade_exec), _signed(src._signed)
{
	return ;
}

Form::Form( const std::string & name, int grade_sign, int grade_exec ) : _name(name), _grade_sign(grade_sign), _grade_exec(grade_exec), _signed(false)
{
	if (grade_sign < 1 || grade_exec < 1)
		throw Form::GradeTooHighException();
	if (grade_sign > 150 || grade_exec > 150)
		throw Form::GradeTooLowException();
}


/* ------------------------------- DESTRUCTOR ------------------------------- */

Form::~Form()
{
}


/* -------------------------------- OVERLOAD -------------------------------- */

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		// this->_name = rhs.getName();
		this->_signed = rhs._signed;
	}
	return *this;
}

std::ostream &				operator<<( std::ostream & o , Form const & src)
{
	o << "[ " << src.getName() << " ]" << std::endl
	<< "Is signed: " << BoolToStr(src.isSigned()) << std::endl
	<< "Required Sign grade: " << src.getRequiredGradeSign()  << std::endl
	<< "Required Execute grade: " << src.getRequiredGradeExecute()  << std::endl;
	return o;
}


/* -------------------------------- METHODS --------------------------------- */

void			Form::beSigned( Bureaucrat const & src )
{
	if (src.getGrade() > this->_grade_exec || src.getGrade() > this->_grade_sign)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
} 

char const * Form::GradeTooHighException::what( void ) const throw () {
	return "Grade too High";
}
char const * Form::GradeTooLowException::what( void ) const throw () {
	return "Grade too Low";
}

/* -------------------------------- ACCESSOR -------------------------------- */

int	const &					Form::getRequiredGradeSign( void ) const
{
	return this->_grade_sign;
}

int	const &					Form::getRequiredGradeExecute( void ) const
{
	return this->_grade_exec;
}

bool const &				Form::isSigned( void ) const
{
	return (_signed);
}

std::string const &			Form::getName( void ) const
{
	return this->_name;
}


/* ************************************************************************** */