/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:52:41 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/11 15:46:38 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"

#ifndef FORM_HPP
#define FORM_HPP

class	Form {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSignIt;
		const int			_gradeToExecuteIt;
	public:
	Form() : _name("unknown"), _isSigned(false), _gradeToSignIt(150), _gradeToExecuteIt(150) {}
	Form(std::string name, int gradeToSignIt, int gradeToExecuteIt);
	Form(const Form & src);
	Form&	operator=(const Form & src);
	~Form(){}
	/*GETTER*/
	std::string	getName() const;
	bool		getIsSigned() const;
	int			getGradeToSignIt() const;
	int			getGradeToExecuteIt() const;
	/*MEMBER FUNCTIONS*/
	bool	beSigned(const Bureaucrat& employee);
	class	GradeTooHighException : public std::exception {
		private:
		std::string	_message;
	public :
		GradeTooHighException(const std::string & message)
		: _message(message) {}
		virtual ~GradeTooHighException() throw() {}//en spécifiant throw() on précise qu'aucune exception ne sera lancée dans cette fonction
		virtual const char* what() const throw() {//ici, on redéfinit la fonction what() de std::exception
			return _message.c_str();
		}
	};
	class	GradeTooLowException : public std::exception {
		private:
		std::string	_message;
		public :
			GradeTooLowException(const std::string & message)
			: _message(message) {}
			virtual ~GradeTooLowException() throw() {}//en spécifiant throw() on précise qu'aucune exception ne sera lancée dans cette fonction
			virtual const char* what() const throw() {//ici, on redéfinit la fonction what() de std::exception
				return _message.c_str();
			}
	};
};

std::ostream&	operator<<(std::ostream& o, const Form& src);
#endif
