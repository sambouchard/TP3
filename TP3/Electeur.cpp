/*
 * Electeur.cpp
 *
 *  Created on: 2017-11-27
 *      Author: etudiant
 */

#include "Electeur.h"
#include <sstream>

using namespace std;
using namespace util;

namespace elections {

Electeur::Electeur(const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom,
		const util::Date& p_dateNaissance, const util::Adresse& p_adresse):Personne(p_nas,p_prenom,p_nom,p_dateNaissance,p_adresse) {


}

std::string Electeur::reqPersonneFormate() const {
	ostringstream sortie;
	sortie<<"Electeur"<<endl;
	sortie<<"----------------------------------------------"<<endl;
	Personne::reqPersonneFormate();


}

Electeur::~Electeur() {
}

Personne* Electeur::clone() const {
	return new Electeur(*this);
}

void Electeur::verifieInvariant() const {
}

} /* namespace elections */
