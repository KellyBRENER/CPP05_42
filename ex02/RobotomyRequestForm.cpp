/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:32:50 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/12 12:02:17 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <unistd.h>

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (getIsSigned() == false)
		throw FormNotExecutableException("the form is not signed", getName());
	else if (executor.getGrade() > getGradeToExecuteIt())
		throw FormNotExecutableException("the executor grade is too low", getName());
	std::cout<<executor.getName()<<" is trying to robotomize "<<_target<<std::endl;
	sleep(1);
	std::cout<<"..."<<std::endl;
	sleep(1);
	std::cout<<"..."<<std::endl;
	sleep(1);
	std::cout<<"..."<<std::endl;
	srand(time(0));//initialise le générateur de rand avec l'heure actuelle
	int	random_number = rand() % 2;
	if (random_number == 0)
		std::cout<<_target<<" has been robotomized successfully"<<std::endl;
	else
		std::cout<<"the robotomy failed"<<std::endl;
}
