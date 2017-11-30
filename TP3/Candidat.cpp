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
		int p_parti):Personne(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse),m_partipolitique(p_parti) {
}

std::string elections::Candidat::reqPartiPolitiqueString() const {
	std::string partipol;

 //TODO a faire, voir email du prof


	return partipol;
}

elections::Personne* elections::Candidat::clone() const {
	return new Candidat(*this);
}


std::string elections::Candidat::reqPersonneFormate() const {
	cout<<"Candidat"<<endl;
	cout<<"---------------------"<<endl;
	Personne::reqPersonneFormate();
}
