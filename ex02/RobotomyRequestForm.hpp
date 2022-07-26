#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include <iostream>
# include <fstream>
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm 
{

	public:

		RobotomyRequestForm();
		RobotomyRequestForm( RobotomyRequestForm const & src );
		RobotomyRequestForm( std::string const target );

		virtual ~RobotomyRequestForm();

		virtual void			execute(Bureaucrat const & executor) const;


	private:
		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

};

#endif /* ROBOTOMYREQUESTFORM_HPP */