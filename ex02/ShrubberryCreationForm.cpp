/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberryCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:16:08 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/12 09:15:14 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ShrubberryCreationForm.hpp"
#include <fstream>

ShrubberryCreationForm::ShrubberryCreationForm(const ShrubberryCreationForm & src) {
	*this = src;
}

ShrubberryCreationForm&	ShrubberryCreationForm::operator=(const ShrubberryCreationForm & src) {
	if (this == &src)
		return *this;
	_target = src._target;
	return *this;
}

std::string	ShrubberryCreationForm::getTarget() const {
	return _target;
}

void	ShrubberryCreationForm::execute(Bureaucrat const & executor) const {
	if (getSigned() == false)
		throw ShrubberryCreationForm::

	std::ofstream	tree((_target + "_shruberry").c_str());


}
