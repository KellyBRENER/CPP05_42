/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:13:39 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/12 15:00:44 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AForm.hpp"

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

class RobotomyRequestForm : public AForm
{
private:
	std::string	_target;
public:
	/*canonique form*/
	RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target(NULL) {}
	~RobotomyRequestForm() {}
	RobotomyRequestForm(const std::string & target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}
	RobotomyRequestForm(const RobotomyRequestForm & src) : AForm(src) {*this = src;}
	RobotomyRequestForm &	operator=(const RobotomyRequestForm & src) {
		if (this != &src) {
			AForm::operator=(src);
			_target = src._target;
		}
		return *this;
	}

	/*MEMBER FUNCTION*/
	virtual void	execute(Bureaucrat const & executor) const;
	static AForm*	createForm(const std::string & target);
};

#endif

