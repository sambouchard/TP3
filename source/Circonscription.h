/*
 * Circonscription.h
 *
 *  Created on: 2017-11-29
 *      Author: etudiant
 */

#ifndef CIRCONSCRIPTION_H_
#define CIRCONSCRIPTION_H_
#include <string>
#include <vector>
#include "Candidat.h"


namespace elections {

class Circonscription {
public:
	Circonscription(const std::string& p_nom, const Candidat& p_depute);
	~Circonscription();
	std::string reqNom() const;
	Candidat reqDeputeElu() const;
	std::string reqCirconscriptionFormate() const;
	void inscrire(const Personne& p_nouvelInscrit) ;
private:
	void verifieInvariant() const;
	std::string m_nom;
	std::vector<Personne*> m_vInscrits;
	Candidat m_deputeElu;
};

} /* namespace elections */

#endif /* CIRCONSCRIPTION_H_ */
