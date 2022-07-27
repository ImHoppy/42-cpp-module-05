#include "ShrubberyCreationForm.hpp"

/* ------------------------------- CONSTRUCTOR ------------------------------ */

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : AForm(src)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const target ) : AForm("shrubbery creation", target, 145, 137)
{

	return ;
}

/* ------------------------------- DESTRUCTOR ------------------------------- */

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/* -------------------------------- OVERLOAD -------------------------------- */

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	(void) rhs;
	return *this;
}


/* -------------------------------- METHODS --------------------------------- */

void								ShrubberyCreationForm::execute( Bureaucrat const & executor) const
{
	if (this->isSigned() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getRequiredGradeExecute())
		throw AForm::GradeTooLowException();

	std::string nameFile = _target+"_shrubbery";
	std::ofstream treeFile(nameFile.c_str());

	treeFile << 
"          &&& &&  & &&\n"
"      && &\\/&\\|& ()|/ @, &&\n"
"      &\\/(/&/&||/& /_/)_&/_&\n"
"   &() &\\/&|()|/&\\/ '%\" & ()\n"
"  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
"&&   && & &| &| /& & % ()& /&&\n"
" ()&_---()&\\&\\|&&-&&--%---()~\n"
"     &&     \\|||\n"
"             |||\n"
"             |||\n"
"             |||\n"
"       , -=-~  .-^- _";
	treeFile.close();
}

AForm * ShrubberyCreationForm::make( std::string const & target )
{
	return new ShrubberyCreationForm(target);
}

/* -------------------------------- ACCESSOR -------------------------------- */


/* ************************************************************************** */