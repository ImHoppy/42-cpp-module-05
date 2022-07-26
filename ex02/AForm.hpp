#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm( void );
		AForm( const AForm & src );
		AForm( const std::string & name, int grade_sign, int grade_exec );
		AForm( const std::string & name, const std::string & target, int grade_sign, int grade_exec );

				
		virtual ~AForm( void );

		
		void					beSigned( Bureaucrat const & src );

		int const &				getRequiredGradeSign( void ) const;
		int const &				getRequiredGradeExecute( void ) const;
		bool const &			isSigned( void ) const;
		std::string	const &		getName( void ) const;

		virtual void			execute(Bureaucrat const & executor) const = 0;

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
		class CantExecuteException : public std::exception
		{
			public:
				char const * what( void ) const throw ();
		};
		

	private:
		AForm &			operator=( AForm const & rhs );

		std::string const		_name;
		int const				_grade_sign;
		int const				_grade_exec;
		bool					_signed;
	protected:
		std::string const		_target;
};

std::ostream &			operator<<( std::ostream & o , AForm const & src);

#endif /* AFORM_HPP */