/*
 * Circonscription.cpp
 *
 *  Created on: 2017-11-29
 *      Author: etudiant
 */

#include "Circonscription.h"
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

namespace elections {



Circonscription::~Circonscription() {
	// TODO Auto-generated destructor stub
}

Circonscription::Circonscription(const std::string& p_nom,
		const Candidat& p_depute):m_nom(p_nom), m_deputeElu(p_depute){
	PRECONDITION(!(p_nom.empty()));
	POSTCONDITION(m_nom == p_nom);
	INVARIANTS();
}

std::string Circonscription::reqNom() const {
	return m_nom;
}

Candidat Circonscription::reqDeputeElu() const {
	return m_deputeElu;
}

std::string Circonscription::reqCirconscriptionFormate() const {
	ostringstream sortie;
	sortie<<"circonscription : "<<reqNom()<<endl;
	sortie<<"Depute sortant :"<<endl;
	sortie<<m_deputeElu.reqPersonneFormate();
	sortie<<"Liste des inscrits : "<<endl;

	for(int i = 0; i < m_vInscrits.size();i++){
		sortie<<m_vInscrits.at(i)->reqPersonneFormate();
	}
	return sortie.str();
}

void Circonscription::inscrire(const Personne& p_nouvelInscrit) {
	m_vInscrits.push_back(p_nouvelInscrit.clone());
}

void Circonscription::verifieInvariant() const {
	INVARIANT(!(m_nom.empty()));
}

} /* namespace elections */
