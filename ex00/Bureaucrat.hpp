#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat : public std::exception
{
	public:
		Bureaucrat( void );
		Bureaucrat( const Bureaucrat & src );
		Bureaucrat( const std::string & name, int grade );

				
		~Bureaucrat( void );

		Bureaucrat &			operator=( Bureaucrat const & rhs );
		
		void					increment( void );
		void					decrement( void );
		int const &				getGrade( void ) const;
		std::string	const &		getName( void ) const;
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *		what( void ) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *		what( void ) const throw();
		};
		
	private:
		int						_grade;
		std::string const		_name;
};

std::ostream &			operator<<( std::ostream & o , Bureaucrat const & src);

#endif /* BUREAUCRAT_HPP */