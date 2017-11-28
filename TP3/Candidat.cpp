/*
 * Candidat.cpp
 *
 *  Created on: 2017-11-25
 *      Author: etudiant
 */

#include "Candidat.h"
#include <string>

using namespace std;
using namespace util;



elections::Candidat::Candidat(const std::string& p_nas,
		const std::string& p_prenom, const std::string& p_nom,
		const util::Date& p_dateNaissance, const util::Adresse& p_adresse,
		int p_parti):Personne(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse),m_partipolitique(p_parti)
{
	PRECONDITION(p_parti == BLOC_QUEBECOIS or p_parti == CONSERVATEUR
			or p_parti == INDEPENDANT or p_parti == NOUVEAU_PARTI_DEMOCRATIQUE);

	POSTCONDITION(m_partipolitique == p_parti);
	INVARIANTS();
}

std::string elections::Candidat::reqPartiPolitiqueString() const {
	std::string partipol;

	switch(m_partipolitique){
		case BLOC_QUEBECOIS :
			partipol = "Blocs quebecois";
			break;
		case CONSERVATEUR:
			partipol = "Parti Conservateur";
			break;
		case INDEPENDANT:
			partipol = "Parti independant";
			break;
		case NOUVEAU_PARTI_DEMOCRATIQUE:
			partipol = "Nouveau parti democratique";
	}
	return partipol;
}

elections::Personne* elections::Candidat::clone() const {
	return new Candidat(*this);
}


std::string elections::Candidat::reqPersonneFormate() const {
	ostringstream sortie;
	sortie<<"Candidat"<<endl;
	sortie<<"----------------------------------------------"<<endl;
	sortie<<Personne::reqPersonneFormate();
	sortie<<"Partie politique    :"<<reqPartiPolitiqueString()<<endl;
	return sortie.str();
}

void elections::Candidat::verifieInvariant() const {
	INVARIANT(m_partipolitique == BLOC_QUEBECOIS or m_partipolitique == CONSERVATEUR
			or m_partipolitique == INDEPENDANT or m_partipolitique == NOUVEAU_PARTI_DEMOCRATIQUE);
}
