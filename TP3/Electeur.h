/*
 * Electeur.h
 *
 *  Created on: 2017-11-27
 *      Author: etudiant
 */

#ifndef ELECTEUR_H_
#define ELECTEUR_H_
#include <string>
#include <iostream>
#include "Personne.h"

namespace elections {

class Electeur: public Personne{
public:
	Electeur(const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom,
	const util::Date& p_dateNaissance, const util::Adresse& p_adresse);

	virtual std::string reqPersonneFormate() const;
	virtual ~Electeur();

private:
};

} /* namespace elections */

#endif /* ELECTEUR_H_ */
