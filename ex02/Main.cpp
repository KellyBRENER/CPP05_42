/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:04:40 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/12 12:01:37 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	Bureaucrat	manager("Dwight Schrute", 15);
	Bureaucrat	stagiaire("Ryan Howard", 150);
	Bureaucrat	BigBoss("Mickeal Scott", 2);
	/*SHRUBERRY TESTS*/
	// try {
	// 	std::cout<<"********Shruberry work********"<<std::endl;
	// 	ShrubberryCreationForm	file("christmas");
	// 	BigBoss.signForm(file);
	// 	file.execute(BigBoss);
	// }
	// catch (std::exception& e) {
	// 	std::cerr<<"ERROR : "<<e.what()<<std::endl;
	// }
	// try {
	// 	std::cout<<"********Shruberry exception herited : cannot sign********"<<std::endl;
	// 	ShrubberryCreationForm	file("wrong_christmas");
	// 	stagiaire.signForm(file);
	// 	file.execute(stagiaire);
	// }
	// catch (std::exception& e) {
	// 	std::cerr<<"ERROR : "<<e.what()<<std::endl;
	// }
	// try {
	// 	std::cout<<"********Shruberry exception herited : cannot execute********"<<std::endl;
	// 	ShrubberryCreationForm	file("wrong_christmas");
	// 	manager.signForm(file);
	// 	file.execute(stagiaire);
	// }
	// catch (const std::exception& e) {
	// 	std::cerr<<"ERROR : "<<e.what()<<std::endl;
	// }
	// try {
	// 	std::cout<<"********Shruberry exception herited : cannot execute********"<<std::endl;
	// 	ShrubberryCreationForm	file("wrong_christmas");
	// 	file.execute(manager);
	// }
	// catch (const std::exception& e) {
	// 	std::cerr<<"ERROR : "<<e.what()<<std::endl;
	// }
	/*ROBOTOMY*/
	try {
		std::cout<<"********ROBOTOMY works********"<<std::endl;
		RobotomyRequestForm	zappette("stagiaire");
		BigBoss.signForm(zappette);
		zappette.execute(BigBoss);
	}
	catch (std::exception& e) {
		std::cerr<<"ERROR : "<<e.what()<<std::endl;
	}
	try {
		std::cout<<"********ROBOTOMY exception********"<<std::endl;
		RobotomyRequestForm	zappette("stagiaire");
		manager.signForm(zappette);
		zappette.execute(stagiaire);
	}
	catch (std::exception& e) {
		std::cerr<<"ERROR : "<<e.what()<<std::endl;
	}
}
