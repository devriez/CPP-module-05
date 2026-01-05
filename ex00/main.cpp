/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:20:08 by amoiseik          #+#    #+#             */
/*   Updated: 2026/01/05 18:58:24 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main() {

	std::cout << "--- Test 1: Standard creation and << operator ---" << std::endl;
	try {
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;

		const Bureaucrat chief("Chief", 1);
		std::cout << "Const Bureaucrat: " << chief << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2: Grade too high in constructor ---" << std::endl;
	try {
		Bureaucrat tooHigh("Icarus", 0);
		std::cout << tooHigh << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 3: Grade too low in constructor ---" << std::endl;
	try {
		Bureaucrat tooLow("Lazy", 151);
		std::cout << tooLow << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 4: Increment/Decrement boundaries ---" << std::endl;
	try {
		Bureaucrat top("TopManager", 2);
		std::cout << "Before: " << top << std::endl;
		top.incrementGrade();
		std::cout << "After increment: " << top << std::endl;
		
		std::cout << "Attempting to increment grade 1..." << std::endl;
		top.incrementGrade(); // Должно бросить GradeTooHighException
	} catch (const std::exception& e) {
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat bottom("Junior", 149);
		std::cout << "Before: " << bottom << std::endl;
		bottom.decrementGrade();
		std::cout << "After decrement: " << bottom << std::endl;
		
		std::cout << "Attempting to decrement grade 150..." << std::endl;
		bottom.decrementGrade(); // Должно бросить GradeTooLowException
	} catch (const std::exception& e) {
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}

	return 0;
}