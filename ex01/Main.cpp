/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:04:40 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/11 15:38:57 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	theOffice(Bureaucrat& BigBoss, Bureaucrat& manager, Bureaucrat& stagiaire)
{
	std::cout<<BigBoss<<", "<<manager<<" and "<<stagiaire<<
" try to have a promotion..."<<std::endl;
		BigBoss.incrementGrade();
		std::cout<<BigBoss.getName()<<" succeeds! **APPLAUSE**"<<
"his grade is now :"<<BigBoss.getGrade()<<std::endl;
		manager.incrementGrade();
		std::cout<<manager.getName()<<" succeeds! **APPLAUSE**"<<
"his grade is now :"<<manager.getGrade()<<std::endl;
		stagiaire.incrementGrade();
		std::cout<<stagiaire.getName()<<" succeeds! **APPLAUSE**"<<
"his grade is now :"<<stagiaire.getGrade()<<std::endl;
		std::cout<<"But "<<manager.getName()<<" and "<<stagiaire.getName()<<
" were surprise to play at MarioKart without "<<
BigBoss.getName()<<"!!! So, like he is the Big Boss, he decided to decrement twice their grade"<<std::endl;
		manager.decrementGrade();
		manager.decrementGrade();
		stagiaire.decrementGrade();
		stagiaire.decrementGrade();
		std::cout<<"Our three protagonists finish the day with respectively : \n"<<
BigBoss<<"\n"<<manager<<"\n"<<stagiaire<<"\n"<<"***Tomorrow is another day..."<<std::endl;
}

int main() {
		Bureaucrat	manager("Dwight Schrute", 15);
		Bureaucrat	stagiaire("Ryan Howard", 140);
		Bureaucrat	BigBoss("Mickeal Scott", 2);
		Form	formToSign("bon de livraison", 15, 150);
		std::cout<<formToSign<<std::endl;
		Form	contrat("contract", 1, 1);
		std::cout<<contrat<<std::endl;
	try
	{
		std::cout<<"**********TEST WITHOUT ERROR**********"<<std::endl;
		BigBoss.signForm(formToSign);
		manager.signForm(formToSign);
	}
	catch (std::exception& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	try
	{
		std::cout<<"**********BUREAUCRAT GRADE TOO LOW**********"<<std::endl;
		BigBoss.signForm(contrat);
	}
	catch (std::exception& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	try
	{
		std::cout<<"**********BUREAUCRAT GRADE ENOUGH**********"<<std::endl;
		theOffice(BigBoss, manager, stagiaire);
		BigBoss.signForm(contrat);
	}
	catch (std::exception& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	try
	{
		std::cout<<"**********GRADE TOO HIGH DURING CONSTRUCTION**********"<<std::endl;
		Form	papier("paperasse", 0, 150);
	}
	catch (std::exception& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	try
	{
		std::cout<<"**********GRADE TOO HIGH DURING CONSTRUCTION**********"<<std::endl;
		Form papier("paperasse", 1, 160);
	}
	catch (std::exception& e)
	{
		std::cerr<<e.what()<<std::endl;
	}

}
