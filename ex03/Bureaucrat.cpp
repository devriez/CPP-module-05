/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:20:03 by amoiseik          #+#    #+#             */
/*   Updated: 2026/01/12 17:43:05 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	std::cout << "Bureaucrat constructor with variable called" << std::endl;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat copyconstructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	if (this != &other) {
		_grade = other._grade;
		// _name is const and cannot be assigned
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string&	Bureaucrat::getName(void) const {
	return _name;
}

int	Bureaucrat::getGrade(void) const {
	return _grade;
}

void	Bureaucrat::incrementGrade(void) {
	if (_grade <= 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	_grade--;
}

void	Bureaucrat::decrementGrade(void) {
	if (_grade >= 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
		return "Grade is too high (1 is maximum)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
		return "Grade is too low (150 is minimum)";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}

void	Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because of " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form) const {
	try {
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Form " << form.getName() << " can not be executed because of " << e.what() << std::endl; 
	}
}

// Lastly, add the executeForm(AForm const & form) const member function to the
// Bureaucrat class. It must attempt to execute the form. If successful, print something like:
// <bureaucrat> executed <form>
// If not, print an explicit error message.
// Implement and submit some tests to ensure everything works as expected.