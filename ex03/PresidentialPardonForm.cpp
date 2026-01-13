/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:04:10 by amoiseik          #+#    #+#             */
/*   Updated: 2026/01/12 17:45:23 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : 
	AForm("PresidentialPardonForm", false, 25, 5),
	_target("Undefined") {
	std::cout << "PresidentialPardonForm. Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm("PresidentialPardonForm", false, 25, 5), 
	_target(target) {
	std::cout << "PresidentialPardonForm, Costructor with parameter called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	AForm(other), 
	_target(other._target) {
	std::cout << "PresidentialPardonForm. Copy constructor called" << std::endl;
	
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}

	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm. Destructor called" << std::endl;
}

void	PresidentialPardonForm:: _action() const {
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}