#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file)
		throw std::ios_base::failure("Could not create shrubbery file");
	file << "       _-_\n"
		 << "    /~~   ~~\\\n"
		 << " /~~         ~~\\\n"
		 << "{               }\n"
		 << " \\  _-     -_  /\n"
		 << "   ~  \\ //  ~\n"
		 << "_- -   | | _- _\n"
		 << "  _ -  | |   -_\n"
		 << "      // \\\n";
}