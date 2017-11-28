/**
 * \file Personne.cpp
 * \brief Fichier qui contient l'implementation de la classe Personne
 * \author Samuel Bouchard
 * \date 19 0ctobre 2017
 */
// derniere modification : 2017-10-19

#include "Personne.h"
#include "Date.h"
#include <string>
#include <sstream>
#include "validationFormat.h"
#include "Adresse.h"

using namespace std;
using namespace util;

namespace elections {
/**
 * \brief Contructeur avec parametres
 *		On construit un objet Personne avec les valeurs passees en parametres
 *\param[in] p_nas est un string qui represente le numero d'assurance sociale de la personne
 *\param[in] p_prenom est un string qui represente le prenom de la personne
 *\param[in] p_nom est un string qui represente le nom de la personne
 *\param[in] p_dateNaissance est un objet de type date qui represente la date de naissance de la personne
 *\param[in] p_adresse est un string qui represente l'adresse de residence de la personne
 */

Personne::Personne(
		const std::string& p_nas,
		const std::string& p_prenom,
		const std::string& p_nom,
		const util::Date& p_dateNaissance,
		const util::Adresse& p_adresse):m_nas(p_nas),m_prenom(p_prenom),m_nom(p_nom),
				m_dateNaissance(p_dateNaissance),m_adresse(p_adresse){

	PRECONDITION(util::validerNas(p_nas));
	PRECONDITION(!(p_prenom.empty()));
	PRECONDITION(!(p_nom.empty()));
	PRECONDITION(Date::validerDate(p_dateNaissance.reqJour(),p_dateNaissance.reqMois(),p_dateNaissance.reqAnnee()));


	POSTCONDITION(reqNas() == p_nas);
	POSTCONDITION(reqPrenom() == p_prenom);
	POSTCONDITION(reqNom() == p_nom);
	POSTCONDITION(reqDateNaissance() == p_dateNaissance);
	POSTCONDITION(m_adresse == p_adresse);
	INVARIANTS();




}
/**
 * \brief Assigne une adresse a l'objet personne courant
 * \param[in] p_adresse est un string qui represente la nouvelle adresse de la personne
 *
 */

void Personne::asgAdresse(const util::Adresse& p_adresse) {
	m_adresse=p_adresse;
	POSTCONDITION(m_adresse == p_adresse);
	INVARIANTS();

}

/**
 *\brief retourne le nom de la personne
 *\return un string qui represente le nom de la personne
 */
std::string Personne::reqNom() const {
	return m_nom;
}

/**
 *\brief retourne le nas de la personne
 *\return un string qui represente le nas de la personne
 */
std::string Personne::reqNas() const {
	return m_nas;
}
/**
 *\brief retourne le prenom de la personne
 *\return un string qui represente le prenom de la personne
 */
std::string Personne::reqPrenom() const {
	return m_prenom;
}

/**
 *\brief retourne l'adresse de la personne
 *\return un string qui represente l'adresse de la personne
 */
util::Adresse Personne::reqAdresse() const {
	return m_adresse;
}
/**
 *\brief retourne la date de naissance de la personne
 *\return un objet Date du namespace util representant la date de naissance de la personne
 */

util::Date Personne::reqDateNaissance() const {
	return m_dateNaissance;

}

/**
 *\brief retourne les informations de la personnes formatees dans une chaine de caracteres
 *\return les informations de la personnes formatees dans une chaine de caracteres
*/
std::string Personne::reqPersonneFormate() const  {
	ostringstream sortie;
	sortie<<"NAS               : "<<reqNas()<<endl;
	sortie<<"Prenom            : "<<reqPrenom()<<endl;
	sortie<<"Nom               : "<<reqNom()<<endl;
	sortie<<"Date de naissance : "<<m_dateNaissance.reqDateFormatee()<<endl;
	sortie<<"Adresse           : "<<m_adresse.reqAdresseFormate()<<endl;
	return sortie.str();


}
/**
 * \brief surcharge de l'operateur ==
 * \param[in] p_personne un objet de type personne valide
 * \return un booleen qui indique si les deux personnes compares sont egales(si c'est la meme personne)
 *
 */

bool Personne::operator ==(const Personne& p_personne) {
	return(p_personne.m_dateNaissance == m_dateNaissance
			and p_personne.m_nas == m_nas and p_personne.m_nom == m_nom and p_personne.m_prenom ==m_prenom);
}

/**
 * \brief Surchage de la fonction << d'ecriture dans un ostream
 * \param[in] p_os un ostream vide dans lequel on va ecrire
 * \param[in] p_personne une personne qui est une personne valide
 * \return un stream dans lequelle on y ecrit la personne
 *
 */
std::ostream& operator<<(std::ostream& p_os, const Personne& p_personne){
	ostringstream date;
	date<<p_personne.m_dateNaissance;
	string date_str = date.str();
	for(int i = 0; i<date_str.length();i++){
		if(date_str[i]=='/'){
			date_str[i]=' ';
		}
	}

	p_os<<p_personne.m_nas<<endl;
	p_os<<p_personne.m_prenom<<endl;
	p_os<<p_personne.m_nom<<endl;
	p_os<<date_str<<endl;
	p_os<<p_personne.m_adresse.reqAdresseFormate()<<endl;



	return p_os;
}

Personne::~Personne() {

}

void Personne::verifieInvariant() const {
	INVARIANT(util::validerNas(m_nas));
	INVARIANT(!(m_prenom.empty()));
	INVARIANT(!(m_nom.empty()));
	INVARIANT(Date::validerDate(m_dateNaissance.reqJour(),m_dateNaissance.reqMois(),m_dateNaissance.reqJourAnnee()));

}

} /* namespace elections */
