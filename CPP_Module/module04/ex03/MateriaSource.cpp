#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	for (int i = 0; i < 4; i++)
	{
		if (obj.materia[i])
			materia[i] = obj.materia[i]->clone();
		else
			materia[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	if (this == &obj) return *this;

	for (int i = 0; i < 4; i++)
		if (materia[i])
			delete materia[i], materia[i] = NULL;
	for (int i = 0; i < 4; i++)
		if (obj.materia[i])
			materia[i] = obj.materia[i]->clone();
	return *this;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		if (materia[i])
			delete materia[i], materia[i] = NULL;
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!materia[i])
		{
			materia[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
		if (materia[i] && materia[i]->getType() == type)
			return materia[i]->clone();
	return NULL;
}