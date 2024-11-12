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
	virtual ~AForm(){}

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
			std::string _fullMessage;
		public :
			GradeTooHighException(const std::string & gradeName)
			: _gradeName(gradeName), _fullMessage("the grade " + _gradeName + " is too high") {}
			virtual ~GradeTooHighException() throw() {}
			virtual const char* what() const throw() {
				return _fullMessage.c_str();
			}
	};
	class	GradeTooLowException : public std::exception {
		private:
			std::string	_gradeName;
			std::string	_fullMessage;
		public :
			GradeTooLowException(const std::string & gradeName)
			: _gradeName(gradeName), _fullMessage("the grade " + _gradeName + " is too low") {}
			virtual ~GradeTooLowException() throw() {}
			virtual const char* what() const throw() {
				return _fullMessage.c_str();
			}
	};
	class	FormNotExecutableException : public std::exception {
		private:
			std::string	_reason;
			std::string	_formName;
			std::string _fullMessage;
		public :
			FormNotExecutableException(const std::string & reason, const std::string & formName)
			: _reason(reason), _formName(formName) , _fullMessage("the form '" + _formName + "' is not executable because " + _reason){}
			virtual ~FormNotExecutableException() throw() {}
			virtual const char* what() const throw() {
				return _fullMessage.c_str();
			}
	};
};

std::ostream&	operator<<(std::ostream& o, const AForm& src);
#endif
