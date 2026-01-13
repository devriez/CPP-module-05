/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:39:21 by amoiseik          #+#    #+#             */
/*   Updated: 2026/01/12 17:12:26 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : 
		AForm::AForm("ShrubberyCreationForm", false, 145, 137),
		_target("Undefined") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : 
		AForm::AForm("ShrubberyCreationForm", false, 145, 137),
		_target(target) {
	std::cout << "ShrubberyCreationForm constructor with parametr called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : 
		AForm::AForm(other),
		_target(other._target) {
	std::cout << "ShrubberyCreationForm cope constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm distracter called" << std::endl;
}

void	ShrubberyCreationForm::_action() const {
	std::string filename = _target + "_shrubbery";
	std::ofstream outfile(filename.c_str());

	if (!outfile)
		std::cerr << "Error: Could not create file " << filename << std::endl;
	else {
		std::cout << "File " << filename << " created" << std::endl;
		outfile << "        ^        " << std::endl;
		outfile << "       / \\       " << std::endl;
		outfile << "      /   \\      " << std::endl;
		outfile << "     /_____\\     " << std::endl;
		outfile << "      |   |      " << std::endl;
		outfile << std::endl;
	}
	outfile.close();
	std::cout << "Shrubbery has been created in " << filename << std::endl;
}
