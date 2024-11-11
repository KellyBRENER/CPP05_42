/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:29:48 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/11 11:30:46 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string & name, int grade) : _name(name) {
	if (grade < 1)
		throw GradeTooHighException("cannot be constructed with this grade", _name);
	else if (grade > 150)
		throw GradeTooLowException("cannot be constructed with this grade", _name);
	else
		_grade = grade;
	std::cout<<"a Bureaucrat named '"<<_name<<"' with the grade '"<<_grade
<<"' has just been employed"<<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat & src) : _name(src._name) {
	*this = src;
}

Bureaucrat &	Bureaucrat::operator=(const Bureaucrat & src) {
	if (this == &src)
		return *this;
	_grade = src._grade;
	return *this;
}

std::string	Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}


void	Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException("Grade cannot be increment", _name);
	else
		_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException("Grade cannot be decrement", _name);
	else
		_grade++;
}

Bureaucrat::~Bureaucrat() {}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& src) {
	o<<src.getName()<<", bureaucrat grade "<<src.getGrade();
	return o;
}
