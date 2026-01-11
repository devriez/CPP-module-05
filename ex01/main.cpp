/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:20:08 by amoiseik          #+#    #+#             */
/*   Updated: 2026/01/09 15:24:36 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void) {
	std::cout << "\n--- TEST 1: Basic Creation and Insertion Operator ---" << std::endl;
	try {
		Bureaucrat bob("Bob", 1);
		Bureaucrat jim("Jim", 150);
		std::cout << bob << std::endl;
		std::cout << jim << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 2: Grade Too High (Invalid Creation) ---" << std::endl;
	try {
		Bureaucrat boss("The Boss", 0);
	} catch (std::exception& e) {
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 3: Grade Too Low (Invalid Creation) ---" << std::endl;
	try {
		Bureaucrat intern("Intern", 151);
	} catch (std::exception& e) {
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 4: Increment/Decrement Success ---" << std::endl;
	try {
		Bureaucrat middle("Middle", 75);
		std::cout << "Before: " << middle << std::endl;
		middle.incrementGrade();
		std::cout << "After increment: " << middle << std::endl;
		middle.decrementGrade();
		std::cout << "After decrement: " << middle << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 5: Increment Failure ---" << std::endl;
	try {
		Bureaucrat elite("Elite", 1);
		elite.incrementGrade();
	} catch (std::exception& e) {
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 6: Form Signing ---" << std::endl;
	try {
		Bureaucrat high("High Rank", 5);
		Bureaucrat low("Low Rank", 140);
		// Assuming Form has: Name, signGrade, executeGrade
		Form f1("Important Document", false, 10, 20);
		
		std::cout << "Attempting to sign with low rank..." << std::endl;
		low.signForm(f1);
		
		std::cout << "Attempting to sign with high rank..." << std::endl;
		high.signForm(f1);
	} catch (std::exception& e) {
		std::cerr << "Exception in Form Test: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 7: Form Insertion Operator Visual ---" << std::endl;
	try {
		Form f2("Top Secret Project", false, 1, 1);
		Form f3("Simple Request", false, 150, 150);

		std::cout << "\nForm 2 initial state:\n" << f2 << std::endl;
		std::cout << "\nForm 3 initial state:\n" << f3 << std::endl;

		Bureaucrat god("God", 1);
		god.signForm(f2);

		std::cout << "\nForm 2 after signing:\n" << f2 << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception in Visual Test: " << e.what() << std::endl;
	}

	return 0;
}