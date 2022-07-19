#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form( void );
		Form( const Form & src );
		Form( const std::string & name, int grade_sign, int grade_exec );

				
		~Form( void );

		Form &			operator=( Form const & rhs );
		
		void					beSigned( Bureaucrat const & src );

		int const &				getRequiredGradeSign( void ) const;
		int const &				getRequiredGradeExecute( void ) const;
		bool const &			isSigned( void ) const;
		std::string	const &		getName( void ) const;

		class GradeTooHighException : public std::exception
		{
			public:
				char const * what( void ) const throw ();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				char const * what( void ) const throw ();
		};

	private:
		std::string const		_name;
		int const				_grade_sign;
		int const				_grade_exec;
		bool					_signed;
};

std::ostream &			operator<<( std::ostream & o , Form const & src);

#endif /* FORM_HPP */