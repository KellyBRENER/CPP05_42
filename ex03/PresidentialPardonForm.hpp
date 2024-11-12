/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:05:01 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/12 15:00:36 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AForm.hpp"

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

class PresidentialPardonForm : public AForm
{
private:
	std::string	_target;
public:
	PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target(NULL) {}
	~PresidentialPardonForm() {}
	PresidentialPardonForm(const std::string & target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}
	PresidentialPardonForm(const PresidentialPardonForm & src) : AForm(src) {*this = src;}
	PresidentialPardonForm&	operator=(const PresidentialPardonForm & src) {
		if (this != &src) {
			AForm::operator=(src);
			_target = src._target;
		}
		return *this;
	}

	virtual void	execute(Bureaucrat const & executor) const;
	static AForm*	createForm(const std::string & target);
};

#endif
