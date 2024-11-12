/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:20:20 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/12 15:30:00 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#ifndef INTERN_HPP
#define INTERN_HPP

class	Intern {
	public:
		Intern(){}
		~Intern(){}
		Intern(const Intern & src) {*this = src;}
		Intern&	operator=(const Intern & src) {
			(void)src;
			return *this;}

		AForm*	makeForm(const std::string & nameForm, const std::string & targetForm);

		class	formCreationImpossibleException : public std::exception {
			private:
				std::string	_message;
			public:
				formCreationImpossibleException() {
					_message = "Intern cannot create this type of form.\
 Please chose among those ones : presidential pardon, shrubbery creation, robotomy request";
				}
				~formCreationImpossibleException () throw() {}
				virtual const char*	what() const throw() {
					return (_message.c_str());
				}
		};
};

#endif
