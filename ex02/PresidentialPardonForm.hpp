#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include <iostream>
# include <fstream>


class PresidentialPardonForm : public AForm 
{

	public:

		PresidentialPardonForm();
		PresidentialPardonForm( PresidentialPardonForm const & src );
		PresidentialPardonForm( std::string const target );

		virtual ~PresidentialPardonForm();

		virtual void			execute(Bureaucrat const & executor) const;


	private:
		PresidentialPardonForm &		operator=( PresidentialPardonForm const & rhs );

};

#endif /* PRESIDENTIALPARDONFORM_HPP */