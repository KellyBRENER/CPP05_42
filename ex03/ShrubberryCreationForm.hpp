/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberryCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:08:15 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/12 15:00:51 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AForm.hpp"

#ifndef SHRUBBERRYCREATIONFORM_HPP
#define SHRUBBERRYCREATIONFORM_HPP

class	ShrubberryCreationForm : public AForm {
	private:
		std::string	_target;
	public :
		ShrubberryCreationForm() : AForm("ShrubberryCreationForm", 145, 137), _target(NULL) {}
		ShrubberryCreationForm(const ShrubberryCreationForm & src);
		ShrubberryCreationForm(const std::string & target) : AForm("ShrubberryCreationForm", 145, 137), _target(target) {}
		~ShrubberryCreationForm() {}
		ShrubberryCreationForm&	operator=(const ShrubberryCreationForm & src);

		std::string		getTarget() const;
		virtual void	execute(Bureaucrat const & executor) const;
		static AForm*	createForm(const std::string & target);
};

#endif
