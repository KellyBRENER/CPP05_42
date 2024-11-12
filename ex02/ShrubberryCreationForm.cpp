/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberryCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:16:08 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/12 11:36:02 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ShrubberryCreationForm.hpp"
#include <fstream>

std::string	xtree =
"                       O\n"
"                      ***\n"
"                     **O**\n"
"                    *******\n"
"                   *********\n"
"                  ***********\n"
"                   ******o**\n"
"                  ***********\n"
"                 ****o********\n"
"                ***************\n"
"               ****o***o********\n"
"              *******************\n"
"            ***********************\n"
"               *****O***********\n"
"              **********o********\n"
"             ****************o****\n"
"            **O********************\n"
"           ***********o********O****\n"
"         *****************************\n"
"             *********************\n"
"            ***o*******************\n"
"           ***********o*******o*****\n"
"          ***************************\n"
"         ***********************O*****\n"
"        ***O***************************\n"
"      ***********************************\n"
"           *************************\n"
"          *******o********o**********\n"
"         *****************************\n"
"        **************o****************\n"
"       *************************O*******\n"
"      *****O*****************************\n"
"    **************o************************\n"
"          ***************************\n"
"         *************o***************\n"
"        ***********o*******************\n"
"       **************************O******\n"
"      ***o******************O************\n"
"    ***o***********o****************o******\n"
"                      ###\n"
"                      ###\n"
"                      ###\n"
"                  ###########\n"
"                  ###########\n";

ShrubberryCreationForm::ShrubberryCreationForm(const ShrubberryCreationForm & src) : AForm(src) {
	*this = src;
}

ShrubberryCreationForm&	ShrubberryCreationForm::operator=(const ShrubberryCreationForm & src) {
	if (this == &src)
		return *this;
	AForm::operator=(src);
	_target = src._target;
	return *this;
}

std::string	ShrubberryCreationForm::getTarget() const {
	return _target;
}

void	ShrubberryCreationForm::execute(Bureaucrat const & executor) const {
	if (getIsSigned() == false)
		throw FormNotExecutableException("the form is not signed", getName());
	else if (executor.getGrade() > getGradeToExecuteIt())
		throw FormNotExecutableException("the executor grade is too low", getName());
	std::ofstream	file((_target + "_shruberry").c_str());
	if (!file.is_open())
		throw FormNotExecutableException(("the file " + _target + "_shruberry creation failed"), getName());
	file<<xtree;
	file.close();
	std::cout<<executor.getName()<<" executed the "<<getName()<<std::endl;
}
