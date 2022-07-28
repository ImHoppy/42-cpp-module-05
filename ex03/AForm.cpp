#include "AForm.hpp"

inline const char * BoolToStr(bool b)
{
  return (b ? "true" : "false");
}

/* ------------------------------- CONSTRUCTOR ------------------------------ */

AForm::AForm(): _name("undefined"), _grade_sign(150), _grade_exec(150), _signed(false), _target("undefinedTarget")
{
	return ;
}

AForm::AForm( const AForm & src ) : _name(src._name), _grade_sign(src._grade_sign), _grade_exec(src._grade_exec), _signed(src._signed), _target(src._target)
{
	return ;
}

AForm::AForm( const std::string & name, int grade_sign, int grade_exec ) : _name(name), _grade_sign(grade_sign), _grade_exec(grade_exec), _signed(false), _target("defaultTarget")
{
	if (grade_sign < 1 || grade_exec < 1)
		throw AForm::GradeTooHighException();
	if (grade_sign > 150 || grade_exec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm( const std::string & name, const std::string & target, int grade_sign, int grade_exec ) : _name(name), _grade_sign(grade_sign), _grade_exec(grade_exec), _signed(false), _target(target)
{
	if (grade_sign < 1 || grade_exec < 1)
		throw AForm::GradeTooHighException();
	if (grade_sign > 150 || grade_exec > 150)
		throw AForm::GradeTooLowException();
}




/* ------------------------------- DESTRUCTOR ------------------------------- */

AForm::~AForm()
{
}


/* -------------------------------- OVERLOAD -------------------------------- */

AForm &				AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
	{
		// this->_name = rhs.getName();
		this->_signed = rhs._signed;
	}
	return *this;
}

std::ostream &				operator<<( std::ostream & o , AForm const & src)
{
	o << "[ " << src.getName() << " ]" << std::endl
	<< "Is signed: " << BoolToStr(src.isSigned()) << std::endl
	<< "Required Sign grade: " << src.getRequiredGradeSign()  << std::endl
	<< "Required Execute grade: " << src.getRequiredGradeExecute()  << std::endl;
	return o;
}


/* -------------------------------- METHODS --------------------------------- */

void			AForm::beSigned( Bureaucrat const & src )
{
	if (src.getGrade() > this->_grade_sign)
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}


char const * AForm::GradeTooHighException::what( void ) const throw () {
	return "Grade too High";
}
char const * AForm::GradeTooLowException::what( void ) const throw () {
	return "Grade too Low";
}

char const * AForm::NotSignedException::what( void ) const throw () {
	return "Is not signed";
}

/* -------------------------------- ACCESSOR -------------------------------- */

int	const &					AForm::getRequiredGradeSign( void ) const
{
	return this->_grade_sign;
}

int	const &					AForm::getRequiredGradeExecute( void ) const
{
	return this->_grade_exec;
}

bool const &				AForm::isSigned( void ) const
{
	return (_signed);
}

std::string const &			AForm::getName( void ) const
{
	return this->_name;
}


/* ************************************************************************** */