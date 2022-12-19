#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include "Form.hpp"
#include <cstdlib>


class RobotomyRequestForm: public Form
{

	/*******************/
	/*      CANON      */
	/*******************/

	public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	~RobotomyRequestForm();
	RobotomyRequestForm	&operator=(RobotomyRequestForm const &src);
	virtual void	action(std::string target) const;
	bool			randomBool() const;

	private:
	RobotomyRequestForm();

};

#endif
