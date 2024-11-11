/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:14:05 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/11 15:47:33 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Form.hpp"

Form::Form(std::string name, int gradeToSignIt, int gradeToExecuteIt) :
_name(name),_isSigned(false), _gradeToSignIt(gradeToSignIt), _gradeToExecuteIt(gradeToExecuteIt) {
	if (_gradeToSignIt < 1)
		throw Form::GradeTooHighException("this Form cannot be created, the gradeToSignIt is too high");
	else if (_gradeToExecuteIt < 1)
		throw Form::GradeTooHighException("this Form cannot be created, the gradeToExecuteIt is too high");
	else if (_gradeToSignIt > 150)
		throw Form::GradeTooLowException("this Form cannot be created, the gradeToSignIt is too low");
	else if (_gradeToExecuteIt > 150)
		throw Form::GradeTooLowException("this Form cannot be created, the gradeToExecuteIt is too low");
	else
		std::cout<<"a Form named '"<<_name<<"' was created"<<std::endl;
}

Form::Form(const Form & src) : _name(src._name), _isSigned(src._isSigned),
_gradeToSignIt(src._gradeToSignIt), _gradeToExecuteIt(src._gradeToExecuteIt) {
	*this = src;
}

Form&	Form::operator=(const Form & src) {
	if (this ==&src)
		return *this;
	_isSigned = src._isSigned;
	return (*this);
}

/*GETTER*/

std::string	Form::getName() const {
	return _name;
}

bool	Form::getIsSigned() const {
	return _isSigned;
}

int	Form::getGradeToSignIt() const {
	return _gradeToSignIt;
}

int	Form::getGradeToExecuteIt() const {
	return _gradeToExecuteIt;
}

/*MEMBER FUNCTIONS*/
bool	Form::beSigned(const Bureaucrat& employee) {
	if (employee.getGrade() <= _gradeToSignIt) {
		_isSigned = true;
	}
	else {
		std::string message = employee.getName() + " couldn't sign form '" + _name + "' because his grade is too low";
		throw Form::GradeTooLowException(message);
	}
	return _isSigned;
}

std::ostream&	operator<<(std::ostream& o, const Form & src) {
	o<<"Form named '"<<src.getName()<<"'";
	if (src.getIsSigned() == true)
		o<<" is signed";
	else
		o<<" is not signed";
	o<<", the grade minimum to sign it is : "<<src.getGradeToSignIt()
<<", the grade minimum to execute it is : "<<src.getGradeToExecuteIt();
	return o;
}
