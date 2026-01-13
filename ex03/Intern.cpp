/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:31:23 by amoiseik          #+#    #+#             */
/*   Updated: 2026/01/13 14:14:03 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
	std::cout << "Intern. Default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
	(void)other;
	std::cout << "Intern. Copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << "Intern assignment operator called" << std::endl;
	if (this != &other) {
		(void)other;
	}
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern. Destructor called" << std::endl;
}

static AForm* createPardon(const std::string& target) {
	return new PresidentialPardonForm(target);
}

static AForm* createRequest(const std::string& target) {
	return new RobotomyRequestForm(target);
}

static AForm* createCreation(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target) {
	std::string formNames[] = {
		"PresidentialPardonForm",
		"RobotomyRequestForm",
		"ShrubberyCreationForm"};
	formFactory creators[] = {
		&createPardon,
		&createRequest,
		&createCreation
	};
	for (int i = 0; i < 3; i++) {
		if (formNames[i] == name) {
			std::cout << "Intern creates " << name << std::endl;
			return creators[i](target);
		}
	}
	
	std::cout << "Error: Form '" << name << "' not found." << std::endl;
	return (NULL);
}
