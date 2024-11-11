/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:25:46 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/11 11:49:22 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string>
#include <iostream>
#include <stdexcept>

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class	Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string & name, int grade);
		Bureaucrat(const Bureaucrat & src);
		~Bureaucrat();
		Bureaucrat &	operator=(const Bureaucrat & src);

		std::string	getName() const;
		int			getGrade() const;
		void			incrementGrade();
		void			decrementGrade();

		class	GradeTooHighException : public std::exception {
	private:
		std::string	_message;
		std::string	_nameOfTheBureaucrat;
		std::string	_fullMessage;
	public :
		GradeTooHighException(const std::string & message, const std::string & nameOfTheBureaucrat)
		: _message(message), _nameOfTheBureaucrat(nameOfTheBureaucrat) {
			_fullMessage = _nameOfTheBureaucrat + " " + _message + ", the grade is too high";
		}
		virtual ~GradeTooHighException() throw() {}//en spécifiant throw() on précise qu'aucune exception ne sera lancée dans cette fonction
		virtual const char* what() const throw() {//ici, on redéfinit la fonction what() de std::exception
			return _fullMessage.c_str();
		}
};

class GradeTooLowException : public std::exception {
	private:
		std::string	_message;
		std::string	_nameOfTheBureaucrat;
		std::string	_fullMessage;
	public :
		GradeTooLowException(const std::string & message, const std::string & nameOfTheBureaucrat)
		: _message(message), _nameOfTheBureaucrat(nameOfTheBureaucrat) {
			_fullMessage = _nameOfTheBureaucrat + " " + _message + ", the grade is too low";
		}
		virtual ~GradeTooLowException() throw() {}//en spécifiant throw() on précise qu'aucune exception ne sera lancée dans cette fonction
		virtual const char* what() const throw() {//ici, on redéfinit la fonction what() de std::exception
			return _fullMessage.c_str();
		}
};

};


std::ostream&	operator<<(std::ostream& o, const Bureaucrat& src);
#endif
