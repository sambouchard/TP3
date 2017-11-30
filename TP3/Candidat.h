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

namespace elections {


class Candidat : public Personne{
public:
	Candidat(const std::string& p_nas,
			const std::string& p_prenom,
			const std::string& p_nom,
			const util::Date& p_dateNaissance,
			const util::Adresse& p_adresse,
			int p_parti);
	std::string reqPartiPolitiqueString() const;
	virtual Personne* clone() const;
	virtual std::string reqPersonneFormate() const ;
private:
	int m_partipolitique;


};

} /* namespace elections */

#endif /* CANDIDAT_H_ */
