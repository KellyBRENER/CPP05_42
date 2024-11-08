/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:25:46 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/08 17:01:57 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
};

class	GradeTooHighException : public std::exception {
	private:
		std::string	_message;
	public :
		GradeTooHighException(const std::string & message) : _message(message) {}
		virtual ~GradeTooHighException() throw() {}
		virtual const char* what() const throw() {
			return _message.c_str();
		}
};

class GradeTooLowException : public std::exception {
	private:
		std::string	_message;
	public:
		GradeTooLowException(const std::string & message) : _message(message) {}
		virtual ~GradeTooLowException() throw() {}
		virtual const char* what() const throw() {
			return _message.c_str();
		}
};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& src);
#endif
