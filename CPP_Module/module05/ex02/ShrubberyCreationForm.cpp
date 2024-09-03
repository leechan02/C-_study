#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& _target)
	: AForm("ShrubberyCreationForm", 145, 137), target(_target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	: AForm(copy), target(copy.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		target = copy.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	
	std::ofstream file(target + "_shrubbery");
	if (!file.is_open())
		throw FileOpenException();
	
	std::string shrubbery = "                                                        ,\n"
							"                                            .__ ._       \\_.\n"
							"                                     _, _.  '  \\/   \\.-  /\n"
							"                                      \\/     .-_`   // |/     \\,\n"
							"                     .-""""-.          \\.   '   \\`. ||  \\.-'  /\n"
							"                    F        Y        .-.`-(   _/\\ V/ \\//,-' >-'   ._,\n"
							"                   F          Y   .__/   `. \\.   ' J   ) ./  / __._/\n"
							"                  J         \\, I    '   _/ \\  \\  | |  / /  .'-'.-' `._,\n"
							"           (       L   \\_.--.| \\_.      ' .___ `\\: | / .--'.-'\"     \\\n"
							"         \\ '\\    .  L   /    \\/        ._/`-.`  \\ .'.' .'---./__   '\n"
							"    \\__  '\\ ) \\._/   `-.__. ` \\_. '   .---.  \\     /  /  ,   `  `\n"
							"  --'  \\  ): // \\,            `-.`__.'     `- \\  /   / _/-.---.__.- .\n"
							"     _.-`.'/ /'\\_, ._     >--.-\"\"'____.--\"`_     '   /.'..' \\   \\   _/`\n"
							" _ .---._\\ \'/ '__./__.-..  / .-|(    x_.-'___  |   :' /    _..---_' \\\n"
							" .:' /`\\ `. `..'.--'\\      /.' /`-`._  `-,'   ` '   I '_.--'__--..___.--._.-\n"
							"     `  `. `\\/'/  _.   _.-'      _.____./ .-.--\"\"-. .-\"    ' _..-.---'   \n"
							"  -._ .--.\\ / /-./     /   .---'-//.___. .-'       \\__ .--.  `    `.     '`-\n"
							" ,--'/.-. ^.   .-.--.  ` _/    _//     ./   _..   .'  `.    \\ \\    |_.\n"
							"    /' | >.   ' | \\._.-       '    _..'  `.' . `.       )    | |\\  `\n"
							"  ./ \\ \'  ) c| /  \\     \\_..  .--'    ,\\ \\_/`  :    )  (`-. `.|`\\\n"
							"   \'  / ,-.  | ` ./`  ._/ `\\'.--.,-((  `.`.__ |   _/   \\    |)  `--._/`\n"
							"______'\\   |  < __________  //'  //  _)   )/-._`.  (,-')  )  / \\_.    /\\. _____\n"
							"a:f        |  |        .__./    //  '\\  |//    `.\\ '\\ (  (  <`   ._  '\n"
							"           >  |      _.  /   ..-\\ _    _/ \\_.  \\ `\\    \\_ `---.-'__\n"
							"        . /  `-   _.'        /   `   _/|       J  /`     `-,,-----.`-.\n"
							"            '  .:'          '`      '          < `   f  I //        `\\_,\n"
							"              '                         \\.     J        I/\\_.        ./\n"
							"         __/                            `:     I  .:    K  `          `\n"
							"         \\/ )                            `,   J         L\n"
							"          )_(_                             .  F  .-'    J\n"
							"         /    `.                           .  I  (.   . I _.-.._\n"
							"   '    <'    \\ )                     _.---.J/      :'   L -'\n"
							" .:.     \\. _.->/                        _.-'_.)     ` `-.`---.,_.\n"
							":<        (    \\                    .--""   .F' J) `.`L.__`-.___\n"
							".:        |-'\\_.|                          Y ..Z     ))   `--'  `-\n"
							".         ) | > :                            . '    :'\n"
							"          / ) L_J                            .x,.\n"
							"          L_J .,                             .:<.,\n"
							"        .'`   `                               :J.,`\n"
							"                                           . ;.+K,:.\n"
							"                                               .,L+.,\n";
	file << shrubbery;
	file.close();
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return "FileOpenException: File open failed";
}