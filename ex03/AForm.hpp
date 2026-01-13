/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:15:22 by amoiseik          #+#    #+#             */
/*   Updated: 2026/01/09 15:32:14 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <exception>
# include <iostream>

class Bureaucrat;

class AForm {
	protected:
		const std::string	_name;
		bool				_isSigned;
		const int			_GRADE_TO_SIGN;
		const int			_GRADE_TO_EXECUTE;
		virtual void		_action() const = 0;
	public:
		AForm();
		AForm(const std::string& name, bool isSigned, const int gradeToSign, const int gradeToExecute);
		AForm(const AForm& other);
		AForm&	operator=(const AForm& other);
		virtual ~AForm();

		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign () const;
		int					getGradeToExecute() const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		void				beSigned(const Bureaucrat& b);

		void				execute(const Bureaucrat& executor) const;
};

std::ostream&	operator<<(std::ostream& os, const AForm& f);

#endif
