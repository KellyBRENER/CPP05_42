/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:14:05 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/12 10:42:30 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AForm.hpp"

AForm::AForm(std::string name, int gradeToSignIt, int gradeToExecuteIt) :
_name(name),_isSigned(false), _gradeToSignIt(gradeToSignIt), _gradeToExecuteIt(gradeToExecuteIt) {
	if (_gradeToSignIt < 1)
		throw AForm::GradeTooHighException("this Form cannot be created, the gradeToSignIt is too high");
	else if (_gradeToExecuteIt < 1)
		throw AForm::GradeTooHighException("this Form cannot be created, the gradeToExecuteIt is too high");
	else if (_gradeToSignIt > 150)
		throw AForm::GradeTooLowException("this Form cannot be created, the gradeToSignIt is too low");
	else if (_gradeToExecuteIt > 150)
		throw AForm::GradeTooLowException("this Form cannot be created, the gradeToExecuteIt is too low");
	else
		std::cout<<"a Form named '"<<_name<<"' was created"<<std::endl;
}

AForm::AForm(const AForm & src) : _name(src._name), _isSigned(src._isSigned),
_gradeToSignIt(src._gradeToSignIt), _gradeToExecuteIt(src._gradeToExecuteIt) {
	*this = src;
}

AForm&	AForm::operator=(const AForm & src) {
	if (this ==&src)
		return *this;
	_isSigned = src._isSigned;
	return (*this);
}

/*GETTER*/

std::string	AForm::getName() const {
	return _name;
}

bool	AForm::getIsSigned() const {
	return _isSigned;
}

int	AForm::getGradeToSignIt() const {
	return _gradeToSignIt;
}

int	AForm::getGradeToExecuteIt() const {
	return _gradeToExecuteIt;
}

/*MEMBER FUNCTIONS*/
bool	AForm::beSigned(const Bureaucrat& employee) {
	if (employee.getGrade() <= _gradeToSignIt) {
		_isSigned = true;
	}
	else {
		std::string message = employee.getName() + " couldn't sign Form '" + _name + "' because his grade";
		throw AForm::GradeTooLowException(message);
	}
	return _isSigned;
}

std::ostream&	operator<<(std::ostream& o, const AForm & src) {
	o<<"Form named '"<<src.getName()<<"'";
	if (src.getIsSigned() == true)
		o<<" is signed";
	else
		o<<" is not signed";
	o<<", the grade minimum to sign it is : "<<src.getGradeToSignIt()
<<", the grade minimum to execute it is : "<<src.getGradeToExecuteIt();
	return o;
}

