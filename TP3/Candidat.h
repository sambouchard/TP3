/*
 * Candidat.h
 *
 *  Created on: 2017-11-25
 *      Author: etudiant
 */

#ifndef CANDIDAT_H_
#define CANDIDAT_H_
#include <string>
#include "Date.h"
#include "Adresse.h"
#include "Personne.h"
enum PartisPolitiques {BLOC_QUEBECOIS, CONSERVATEUR, INDEPENDANT, LIBERAL,
NOUVEAU_PARTI_DEMOCRATIQUE};

class Candidat {
public:
	Candidat(const std::string& p_nas,
			const std::string& p_prenom,
			const std::string& p_nom,
			const util::Date& p_dateNaissance,
			const util::Adresse& p_adresse,
			int p_parti);
private:
	const std::string& p_nas;
	const std::string& p_prenom;
	const std::string& p_nom;
	const util::Date& p_dateNaissance;
	const util::Adresse& p_adresse;
	int m_partipolitique;


};

#endif /* CANDIDAT_H_ */
