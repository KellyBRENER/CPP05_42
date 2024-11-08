/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:29:48 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/08 17:04:09 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150) {
	std::cout<<"Bureaucrat default constructor called"<<std::endl;
}

Bureaucrat::Bureaucrat(const std::string & name, int grade) : _name(name) {
	std::cout<<"Bureaucrat constructor called"<<std::endl;
	if (grade < 1)
		throw GradeTooHighException("Grade is too high, 1 is the highest");
	else if (grade > 150)
		throw GradeTooLowException("Grade is too low, 150 is th lowest");
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & src) : _name(src._name) {
	*this = src;
	std::cout<<"Bureaucrat cpy constructor called"<<std::endl;
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

int			Bureaucrat::getGrade() const {
	return _grade;
}


void	Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw GradeTooHighException("Grade cannot be higher");
	else
		_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw GradeTooLowException("Grade cannot be lower");
	else
		_grade++;
}

Bureaucrat::~Bureaucrat() {
	std::cout<<"Bureaucrat destructor called"<<std::endl;
}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& src) {
	o<<src.getName()<<", bureaucrat grade "<<src.getGrade();
	return o;
}
