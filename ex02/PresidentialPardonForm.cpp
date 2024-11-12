/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:22:18 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/12 12:23:26 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PresidentialPardonForm.hpp"

void	 PresidentialPardonForm::execute(Bureaucrat const & executor) const {
		if (getIsSigned() == false)
			throw FormNotExecutableException("the form is not signed", getName());
		else if (executor.getGrade() > getGradeToExecuteIt())
			throw FormNotExecutableException("the executor grade is too low", getName());
		std::cout<<executor.getName()<<" execute the "<<getName()<<" : "<<std::endl;
		std::cout<<_target<<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
	}
