#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
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
				char const * what( void ) const throw ();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				char const * what( void ) const throw ();
		};
		
	private:
		std::string const		_name;
		int						_grade;
};

std::ostream &			operator<<( std::ostream & o , Bureaucrat const & src);

#endif /* BUREAUCRAT_HPP */