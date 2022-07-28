#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# define FORM_COUNT 3

class Intern
{

	public:

		Intern();
		~Intern();

		AForm *			makeForm( std::string const & form, std::string const & target );
		class UnknownFormException : public std::exception {
			public:
				const char *what(void) const throw();
		};
	private:
		Intern( Intern const & src );
		Intern &		operator=( Intern const & rhs );

		static const std::string formsName[FORM_COUNT];
		static AForm* (*formsPtr[FORM_COUNT])( std::string const & );


};

#endif /* INTERN_HPP */