/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:04:40 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/11 10:29:21 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"

int main() {
			/*to test without error*/
	try
	{
		Bureaucrat	manager("Eddy", 15);
		Bureaucrat	stagiaire("Francois", 140);
		Bureaucrat	BigBoss("Arthur", 2);
		std::cout<<"***"<<BigBoss<<", "<<manager<<" and "<<stagiaire<<
" try to have a promotion...***"<<std::endl;
		BigBoss.incrementGrade();
		std::cout<<BigBoss.getName()<<" succeeds! **APPLAUSE**"<<
"his grade is now :"<<BigBoss.getGrade()<<std::endl;
		manager.incrementGrade();
		std::cout<<manager.getName()<<" succeeds! **APPLAUSE**"<<
"his grade is now :"<<manager.getGrade()<<std::endl;
		stagiaire.incrementGrade();
		std::cout<<stagiaire.getName()<<" succeeds! **APPLAUSE**"<<
"his grade is now :"<<stagiaire.getGrade()<<std::endl;
		std::cout<<"***But "<<manager.getName()<<" and "<<stagiaire.getName()<<
" were surprise to play at MarioKart..., the Big Boss "<<
BigBoss.getName()<<" decide to decrement twice their grade***"<<std::endl;
		manager.decrementGrade();
		manager.decrementGrade();
		stagiaire.decrementGrade();
		stagiaire.decrementGrade();
		std::cout<<"***Our three protagonists finish the day with respectively : \n"<<
BigBoss<<"\n"<<manager<<"\n"<<stagiaire<<"\n"<<"***Tomorrow is another day...***"<<std::endl;
	}
	catch (GradeTooHighException& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	catch (GradeTooLowException& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
		/*to test with error gradetoolow*/
	try
	{
		Bureaucrat	manager("Eddy", 15);
		Bureaucrat	stagiaire("Francois", 151);
		Bureaucrat	BigBoss("Arthur", 2);
		std::cout<<"***"<<BigBoss<<", "<<manager<<" and "<<stagiaire<<
" try to have a promotion...***"<<std::endl;
		BigBoss.incrementGrade();
		std::cout<<BigBoss.getName()<<" succeeds! **APPLAUSE**"<<
"his grade is now :"<<BigBoss.getGrade()<<std::endl;
		manager.incrementGrade();
		std::cout<<manager.getName()<<" succeeds! **APPLAUSE**"<<
"his grade is now :"<<manager.getGrade()<<std::endl;
		stagiaire.incrementGrade();
		std::cout<<stagiaire.getName()<<" succeeds! **APPLAUSE**"<<
"his grade is now :"<<stagiaire.getGrade()<<std::endl;
		std::cout<<"***But "<<manager.getName()<<" and "<<stagiaire.getName()<<
" were surprise to play at MarioKart..., the Big Boss "<<
BigBoss.getName()<<" decide to decrement twice their grade***"<<std::endl;
		manager.decrementGrade();
		manager.decrementGrade();
		stagiaire.decrementGrade();
		stagiaire.decrementGrade();
		std::cout<<"***Our three protagonists finish the day with respectively : \n"<<
BigBoss<<"\n"<<manager<<"\n"<<stagiaire<<"\n"<<"***Tomorrow is another day...***"<<std::endl;
	}
	catch (GradeTooHighException& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	catch (GradeTooLowException& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
		/*to test with error grade too high*/
	try
	{
		Bureaucrat	manager("Eddy", 15);
		Bureaucrat	stagiaire("Francois", 140);
		Bureaucrat	BigBoss("Arthur", 0);
		std::cout<<"***"<<BigBoss<<", "<<manager<<" and "<<stagiaire<<
" try to have a promotion...***"<<std::endl;
		BigBoss.incrementGrade();
		std::cout<<BigBoss.getName()<<" succeeds! **APPLAUSE**"<<
"his grade is now :"<<BigBoss.getGrade()<<std::endl;
		manager.incrementGrade();
		std::cout<<manager.getName()<<" succeeds! **APPLAUSE**"<<
"his grade is now :"<<manager.getGrade()<<std::endl;
		stagiaire.incrementGrade();
		std::cout<<stagiaire.getName()<<" succeeds! **APPLAUSE**"<<
"his grade is now :"<<stagiaire.getGrade()<<std::endl;
		std::cout<<"***But "<<manager.getName()<<" and "<<stagiaire.getName()<<
" were surprise to play at MarioKart..., the Big Boss "<<
BigBoss.getName()<<" decide to decrement twice their grade***"<<std::endl;
		manager.decrementGrade();
		manager.decrementGrade();
		stagiaire.decrementGrade();
		stagiaire.decrementGrade();
		std::cout<<"***Our three protagonists finish the day with respectively : \n"<<
BigBoss<<"\n"<<manager<<"\n"<<stagiaire<<"\n"<<"***Tomorrow is another day...***"<<std::endl;
	}
	catch (GradeTooHighException& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	catch (GradeTooLowException& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
		/*to test with error decrement*/
	try
	{
		Bureaucrat	manager("Eddy", 15);
		Bureaucrat	stagiaire("Francois", 150);
		Bureaucrat	BigBoss("Arthur", 2);
		std::cout<<"***"<<BigBoss<<", "<<manager<<" and "<<stagiaire<<
" try to have a promotion...***"<<std::endl;
		BigBoss.incrementGrade();
		std::cout<<BigBoss.getName()<<" succeeds! **APPLAUSE**"<<
"his grade is now :"<<BigBoss.getGrade()<<std::endl;
		manager.incrementGrade();
		std::cout<<manager.getName()<<" succeeds! **APPLAUSE**"<<
"his grade is now :"<<manager.getGrade()<<std::endl;
		stagiaire.incrementGrade();
		std::cout<<stagiaire.getName()<<" succeeds! **APPLAUSE**"<<
"his grade is now :"<<stagiaire.getGrade()<<std::endl;
		std::cout<<"***But "<<manager.getName()<<" and "<<stagiaire.getName()<<
" were surprise to play at MarioKart..., the Big Boss "<<
BigBoss.getName()<<" decide to decrement twice their grade***"<<std::endl;
		manager.decrementGrade();
		manager.decrementGrade();
		stagiaire.decrementGrade();
		stagiaire.decrementGrade();
		std::cout<<"***Our three protagonists finish the day with respectively : \n"<<
BigBoss<<"\n"<<manager<<"\n"<<stagiaire<<"\n"<<"***Tomorrow is another day...***"<<std::endl;
	}
	catch (GradeTooHighException& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	catch (GradeTooLowException& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
		/*to test with error increment*/
	try
	{
		Bureaucrat	manager("Eddy", 15);
		Bureaucrat	stagiaire("Francois", 140);
		Bureaucrat	BigBoss("Arthur", 1);
		std::cout<<"***"<<BigBoss<<", "<<manager<<" and "<<stagiaire<<
" try to have a promotion...***"<<std::endl;
		BigBoss.incrementGrade();
		std::cout<<BigBoss.getName()<<" succeeds! **APPLAUSE**"<<
"his grade is now :"<<BigBoss.getGrade()<<std::endl;
		manager.incrementGrade();
		std::cout<<manager.getName()<<" succeeds! **APPLAUSE**"<<
"his grade is now :"<<manager.getGrade()<<std::endl;
		stagiaire.incrementGrade();
		std::cout<<stagiaire.getName()<<" succeeds! **APPLAUSE**"<<
"his grade is now :"<<stagiaire.getGrade()<<std::endl;
		std::cout<<"***But "<<manager.getName()<<" and "<<stagiaire.getName()<<
" were surprise to play at MarioKart..., the Big Boss "<<
BigBoss.getName()<<" decide to decrement twice their grade***"<<std::endl;
		manager.decrementGrade();
		manager.decrementGrade();
		stagiaire.decrementGrade();
		stagiaire.decrementGrade();
		std::cout<<"***Our three protagonists finish the day with respectively : \n"<<
BigBoss<<"\n"<<manager<<"\n"<<stagiaire<<"\n"<<"***Tomorrow is another day...***"<<std::endl;
	}
	catch (GradeTooHighException& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	catch (GradeTooLowException& e)
	{
		std::cerr<<e.what()<<std::endl;
	}

}
