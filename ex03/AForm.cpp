/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:15:19 by amoiseik          #+#    #+#             */
/*   Updated: 2026/01/09 15:23:52 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() :
		_name("Undefined"),
		_isSigned(false),
		_GRADE_TO_SIGN(150),
		_GRADE_TO_EXECUTE(150) {
	std::cout << "AForm. Default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, bool isSigned, const int gradeToSign, const int gradeToExecute) : 
		_name(name),
		_isSigned(isSigned),
		_GRADE_TO_SIGN(gradeToSign),
		_GRADE_TO_EXECUTE(gradeToExecute) {
	std::cout << "AForm. Default constructor with parametrs called" << std::endl;
	if (_GRADE_TO_SIGN < 1 || _GRADE_TO_EXECUTE < 1)
			throw AForm::GradeTooHighException();
	if (_GRADE_TO_SIGN > 150 || _GRADE_TO_EXECUTE > 150)
			throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) : 
		_name(other._name),
		_isSigned(other._isSigned),
		_GRADE_TO_SIGN(other._GRADE_TO_SIGN),
		_GRADE_TO_EXECUTE(other._GRADE_TO_EXECUTE) {
	std::cout << "AForm. Copy constructor called" << std::endl;
}

AForm&	AForm::operator=(const AForm& other) {
	if(this != &other)
		this->_isSigned = other._isSigned;

	return *this;
}

AForm::~AForm() {
	std::cout << "AForm. Default destructor called" << std::endl;
}

const std::string&	AForm::getName() const {
	return _name;
}

bool	AForm::getIsSigned() const {
	return _isSigned;
}

int	AForm::getGradeToSign() const {
	return _GRADE_TO_SIGN;
}

int	AForm::getGradeToExecute() const {
	return _GRADE_TO_EXECUTE;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade of the AFormform is too high";
}

const char* AForm::GradeTooLowException:: what() const throw() {
	return "Grade of the AFormform is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}

void AForm::beSigned(const Bureaucrat& b) {
	int	bGrade = b.getGrade();
	
	if (bGrade <= _GRADE_TO_SIGN) {
		_isSigned = true;
	} else {
		throw AForm::GradeTooLowException();
	}
}

void	AForm::execute(const Bureaucrat& executor) const {
	if (_isSigned) {
		if (executor.getGrade() <= _GRADE_TO_EXECUTE) {
			_action();
		} else {
			throw AForm::GradeTooLowException();
		}
	} else {
		throw AForm::FormNotSignedException();
	}
}

std::ostream&	operator<<(std::ostream& os, const AForm& f) {
	os << "AForm name = " << f.getName() << std::endl;
	os << "Is AFormform signed = " << f.getIsSigned() << std::endl;
	os << "Grade to sign = " << f.getGradeToSign() << std::endl;
	os << "Grade to Execute = " << f.getGradeToExecute();
	
	return os;
}