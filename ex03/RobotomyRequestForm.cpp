/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:52:15 by amoiseik          #+#    #+#             */
/*   Updated: 2026/01/12 17:45:37 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : 
	AForm("RobotomyRequestForm", false, 75, 25), 
	_target("Undefined") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm("RobotomyRequestForm", false, 75, 25), 
	_target(target) {
	std::cout << "RobotomyRequestForm constructor with parameter called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other),
	_target(other._target) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void	RobotomyRequestForm::_action() const {
	std::cout << "* BZZZZZZZZ... DRILLING NOISES... *" << std::endl;
	
	if (std::rand() % 2) {
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "The robotomy on " << this->_target << " failed." << std::endl;
	}
}