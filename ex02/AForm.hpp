/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:52:41 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/11 15:46:38 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"

#ifndef AFORM_HPP
#define AFORM_HPP

class	AForm {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSignIt;
		const int			_gradeToExecuteIt;
	public:
	AForm() : _name("unknown"), _isSigned(false), _gradeToSignIt(150), _gradeToExecuteIt(150) {}
	AForm(std::string name, int gradeToSignIt, int gradeToExecuteIt);
	AForm(const AForm & src);
	AForm&	operator=(const AForm & src);
	~AForm(){}

	/*GETTER*/

	std::string	getName() const;
	bool		getIsSigned() const;
	int			getGradeToSignIt() const;
	int			getGradeToExecuteIt() const;

	/*MEMBER FUNCTIONS*/

	bool	beSigned(const Bureaucrat& employee);
	virtual void	execute(Bureaucrat const & executor) const = 0;

	/*EXCEPTION*/
	class	GradeTooHighException : public std::exception {
		private:
			std::string	_gradeName;
		public :
			GradeTooHighException(const std::string & gradeName)
			: _gradeName(gradeName) {}
			virtual ~GradeTooHighException() throw() {}//en spécifiant throw() on précise qu'aucune exception ne sera lancée dans cette fonction
			virtual const char* what() const throw() {//ici, on redéfinit la fonction what() de std::exception
				return ("the grade " + _gradeName + " is too low").c_str();
			}
	};
	class	GradeTooLowException : public std::exception {
		private:
			std::string	_gradeName;
		public :
			GradeTooLowException(const std::string & gradeName)
			: _gradeName(gradeName) {}
			virtual ~GradeTooLowException() throw() {}//en spécifiant throw() on précise qu'aucune exception ne sera lancée dans cette fonction
			virtual const char* what() const throw() {//ici, on redéfinit la fonction what() de std::exception
				return ("the grade " + _gradeName + " is too low").c_str();
			}
	};
	class	FormNotExecutableException : public std::exception {
		private:
			std::string	_reason;
		public :
			GradeTooLowException(const std::string & reason)
			: _reason(reason) {}
			virtual ~GradeTooLowException() throw() {}//en spécifiant throw() on précise qu'aucune exception ne sera lancée dans cette fonction
			virtual const char* what() const throw() {//ici, on redéfinit la fonction what() de std::exception
				return ("the form "+ getName()+ " is not executable because " + _reason).c_str();
			}
	};
};

std::ostream&	operator<<(std::ostream& o, const AForm& src);
#endif
