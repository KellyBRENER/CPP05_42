/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:04:40 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/08 17:15:47 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	Bureaucrat	Eddy("Eddy", 15);
	Bureaucrat	Francois("Francois", 160);
	Bureaucrat	Arthur("Arthur", 1);
	try
	{
		std::cout<<Eddy<<std::endl;
		Eddy.incrementGrade();
	}
	catch (GradeTooHighException& e)
	{
		std::cerr<<"echec de l'incrementation de "<<Eddy.getName()<<e.what()<<std::endl;
	}
	try
	{
		std::cout<<Francois<<std::endl;
		Francois.incrementGrade();
	}
	catch (GradeTooHighException& e)
	{
		std::cerr<<"echec de l'incrementation de "<<Francois.getName()<<e.what()<<std::endl;
	}
	try
	{
		std::cout<<Arthur<<std::endl;
		Arthur.incrementGrade();
	}
	catch (GradeTooHighException& e)
	{
		std::cerr<<"echec de l'incrementation de "<<Arthur.getName()<<e.what()<<std::endl;
	}
}
