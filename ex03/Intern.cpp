/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:21:38 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/12 15:34:30 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Intern.hpp"

AForm*	Intern::makeForm(const std::string & nameForm, const std::string & targetForm) {
	std::string	listOfFormName[3] = {"shruberry creation", "robotomy request", "presidential pardon"};
	AForm*	(*listOfCreateFormFunctions[3])(const std::string & target) =
	{ShrubberryCreationForm::createForm, RobotomyRequestForm::createForm, PresidentialPardonForm::createForm};
	for (int i = 0; i < 3; ++i) {
		if (listOfFormName[i] == nameForm) {
			std::cout<<"Intern creates "<<nameForm<<std::endl;
			return (listOfCreateFormFunctions[i](targetForm));
		}
	}
	throw formCreationImpossibleException();
}
