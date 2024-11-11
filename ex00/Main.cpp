/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:04:40 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/11 11:47:45 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"

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
	try
	{
		std::cout<<"**********TEST WITHOUT ERROR**********"<<std::endl;
		Bureaucrat	manager("Dwight Schrute", 15);
		Bureaucrat	stagiaire("Ryan Howard", 140);
		Bureaucrat	BigBoss("Mickeal Scott", 2);
		theOffice(BigBoss, manager, stagiaire);
	}
	catch (std::exception& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	try
	{
		std::cout<<"**********GRADE TOO LOW**********"<<std::endl;
		Bureaucrat	manager("Dwight Schrute", 15);
		Bureaucrat	stagiaire("Ryan Howard", 151);
		Bureaucrat	BigBoss("Mickeal Scott", 2);
		theOffice(BigBoss, manager, stagiaire);
	}
	catch (std::exception& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	try
	{
		std::cout<<"**********GRADE TOO HIGH**********"<<std::endl;
		Bureaucrat	manager("Dwight Schrute", 15);
		Bureaucrat	stagiaire("Ryan Howard", 140);
		Bureaucrat	BigBoss("Mickeal Scott", 0);
		theOffice(BigBoss, manager, stagiaire);
	}
	catch (std::exception& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	try
	{
		std::cout<<"**********ERROR DECREMENTING**********"<<std::endl;
		Bureaucrat	manager("Dwight Schrute", 15);
		Bureaucrat	stagiaire("Ryan Howard", 150);
		Bureaucrat	BigBoss("Mickeal Scott", 2);
		theOffice(BigBoss, manager, stagiaire);
	}
	catch (std::exception& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	try
	{
		std::cout<<"**********ERROR INCREMENTING**********"<<std::endl;
		Bureaucrat	manager("Dwight Schrute", 15);
		Bureaucrat	stagiaire("Ryan Howard", 140);
		Bureaucrat	BigBoss("Mickeal Scott", 1);
		theOffice(BigBoss, manager, stagiaire);
	}
	catch (std::exception& e)
	{
		std::cerr<<e.what()<<std::endl;
	}

}
