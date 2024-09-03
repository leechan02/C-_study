#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* materia[4];
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& obj);
		MateriaSource& operator=(const MateriaSource& obj);
		~MateriaSource(void);

		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const &type);
};