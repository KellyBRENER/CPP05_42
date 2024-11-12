/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:04:40 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/12 15:38:13 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "cstdlib"
#include "Intern.hpp"

int main() {
	Bureaucrat	manager("Dwight Schrute", 15);
	Bureaucrat	stagiaire("Ryan Howard", 150);
	Bureaucrat	BigBoss("Mickeal Scott", 2);
	/*SHRUBERRY TESTS*/
	try {
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		BigBoss.signForm(*rrf);
		BigBoss.executeForm(*rrf);
		AForm* file;
		file = someRandomIntern.makeForm("tghfdl", "turedlks");
		BigBoss.signForm(*file);
		delete(rrf);
		delete(file);
	}
	catch (std::exception& e) {
		std::cerr<<"ERROR : "<<e.what()<<std::endl;
	}
}
