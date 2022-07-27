#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include <iostream>
# include <fstream>


class ShrubberyCreationForm : public AForm 
{

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		ShrubberyCreationForm( std::string const target );

		virtual ~ShrubberyCreationForm();

		virtual void			execute(Bureaucrat const & executor) const;


		static AForm * make( std::string const & target );


	private:
		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );

};

#endif /* SHRUBBERYCREATIONFORM_HPP */