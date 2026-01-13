/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:28:13 by amoiseik          #+#    #+#             */
/*   Updated: 2026/01/13 14:12:33 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main() {
	Intern		someRandomIntern;
	Bureaucrat	boss("Boss", 1);
	AForm*		form;

	std::cout << "\n--- Test 1: Robotomy Request ---\n" << std::endl;
	form = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	if (form) {
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	std::cout << "\n--- Test 2: Shrubbery Creation ---\n" << std::endl;
	form = someRandomIntern.makeForm("ShrubberyCreationForm", "Home");
	if (form) {
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	std::cout << "\n--- Test 3: Presidential Pardon ---\n" << std::endl;
	form = someRandomIntern.makeForm("PresidentialPardonForm", "Marvin");
	if (form) {
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	std::cout << "\n--- Test 4: Unknown Form Error ---\n" << std::endl;
	form = someRandomIntern.makeForm("coffee request", "Intern");
	if (!form) {
		std::cout << "Result: Successfully handled unknown form." << std::endl;
	}

	return (0);
}