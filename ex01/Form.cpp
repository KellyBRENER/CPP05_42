/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:14:05 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/11 12:18:26 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Form.hpp"

Form::Form(std::string name, bool isSigned, int gradeToSignIt, int gradeToExecuteIt) :
_name(name), _isSigned(isSigned), _gradeToSignIt(gradeToSignIt), _gradeToExecuteIt(gradeToExecuteIt) {
	if (_gradeToSignIt < 0 || _gradeToExecuteIt < 0)
		throw Form::GradeTooLowException("this form cannot be created", _name)
}
