/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:15:19 by amoiseik          #+#    #+#             */
/*   Updated: 2026/01/12 19:50:53 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() :
		_name("Undefined"),
		_isSigned(false),
		_GRADE_TO_SIGN(150),
		_GRADE_TO_EXECUTE(150) {
	std::cout << "Form. Default constructor called" << std::endl;
}

Form::Form(const std::string& name, bool isSigned, const int gradeToSign, const int gradeToExecute) : 
		_name(name),
		_isSigned(isSigned),
		_GRADE_TO_SIGN(gradeToSign),
		_GRADE_TO_EXECUTE(gradeToExecute) {
	std::cout << "Form. Default constructor with parametrs called" << std::endl;
	if (_GRADE_TO_SIGN < 1 || _GRADE_TO_EXECUTE < 1)
			throw Form::GradeTooHighException();
	if (_GRADE_TO_SIGN > 150 || _GRADE_TO_EXECUTE > 150)
			throw Form::GradeTooLowException();
}

Form::Form(const Form& other) : 
		_name(other._name),
		_isSigned(other._isSigned),
		_GRADE_TO_SIGN(other._GRADE_TO_SIGN),
		_GRADE_TO_EXECUTE(other._GRADE_TO_EXECUTE) {
	std::cout << "Form. Copy constructor called" << std::endl;
}

Form&	Form::operator=(const Form& other) {
	if(this != &other)
		this->_isSigned = other._isSigned;

	return *this;
}

Form::~Form() {
	std::cout << "Form. Default destructor called" << std::endl;
}

const std::string&	Form::getName() const {
	return _name;
}

bool	Form::getIsSigned() const {
	return _isSigned;
}

int	Form::getGradeToSign() const {
	return _GRADE_TO_SIGN;
}

int	Form::getGradeToExecute() const {
	return _GRADE_TO_EXECUTE;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade of the form is too high (1 is maximum)";
}

const char* Form::GradeTooLowException:: what() const throw() {
	return "Grade of the form is too low (150 is minimum)";
}

void Form::beSigned(const Bureaucrat& b) {
	int	bGrade = b.getGrade();
	
	if (bGrade <= _GRADE_TO_SIGN) {
		_isSigned = true;
	} else {
		throw Form::GradeTooLowException();
	}
}

std::ostream&	operator<<(std::ostream& os, const Form& f) {
	os << "Form name = " << f.getName() << std::endl;
	os << "Is form signed = " << f.getIsSigned() << std::endl;
	os << "Grade to sign = " << f.getGradeToSign() << std::endl;
	os << "Grade to Execute = " << f.getGradeToExecute();
	
	return os;
}