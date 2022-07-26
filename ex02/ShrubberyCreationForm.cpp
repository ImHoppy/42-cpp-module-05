#include "ShrubberyCreationForm.hpp"

/* ------------------------------- CONSTRUCTOR ------------------------------ */

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : AForm(src)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const target ) : AForm("Shrubbery", target, 145, 137)
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
	if (this->isSigned() == false || executor.getGrade() > this->getRequiredGradeExecute())
		throw AForm::CantExecuteException();

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

/* -------------------------------- ACCESSOR -------------------------------- */


/* ************************************************************************** */