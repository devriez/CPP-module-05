/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:28:13 by amoiseik          #+#    #+#             */
/*   Updated: 2026/01/12 18:18:15 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {
	// Inicialisation of random generator
	std::srand(std::time(0));

	std::cout << "\n--- 1: Bureucrat with highest level ---\n" << std::endl;
	try {
		Bureaucrat				president("Boss", 1);
		std::cout << president << " was created \n" << std::endl;
		ShrubberyCreationForm	f1("SC_FORM");
		RobotomyRequestForm		f2("RR_FORM");
		PresidentialPardonForm	f3("PP_FORM");

		std::cout << "\n--- Testing Shrubbery ---\n" << std::endl;
		president.signForm(f1);
		president.executeForm(f1);

		std::cout << "\n--- Testing Robotomy (50/50) ---\n" << std::endl;
		president.signForm(f2);
		std::cout << "\nRepeating execution 3 times to show different results:" << std::endl;
		president.executeForm(f2);
		president.executeForm(f2); // Testing second time for statistic
		president.executeForm(f2); 

		std::cout << "\n--- Testing Pardon ---\n" << std::endl;
		president.signForm(f3);
		president.executeForm(f3);

		std::cout << "\n --- Deleting all instances --- \n";
	} catch (std::exception& e) {
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n\n--- 2: Bureaucrat with low level and complicate forms ---\n" << std::endl;
	try {
		Bureaucrat				intern("Intern", 140);
		std::cout << intern << " was created \n" << std::endl;
		PresidentialPardonForm	pardon("PP_FORM");

		intern.signForm(pardon); // Return error (we need 25 level)
		intern.executeForm(pardon);
		std::cout << "\n --- Deleting all instances --- \n";
	} catch (std::exception& e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	std::cout << "\n\n--- 3: Subscribed, but can not be executed ---\n" << std::endl;
	try {
		Bureaucrat				boss("Boss", 20);
		std::cout << boss << " was created \n" << std::endl;
		Bureaucrat				assistant("Assistant", 30);
		std::cout << assistant << " was created \n" << std::endl;
		PresidentialPardonForm	pardon("PP_Form");

		boss.signForm(pardon); // Boss has 20 level, he can signe it(need 25 level)
		assistant.executeForm(pardon); // Addistan can not execute (need 5 level)
		std::cout << "\n --- Deleting all instances --- \n";
	} catch (std::exception& e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	return 0;
}