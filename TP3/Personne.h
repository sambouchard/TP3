/**
 *\ file : Personne.h
 *\ brief: Fichier qui contient l'interface de la classe personne qui sert au maintien et a la manipulation
 *\ des objets de type personne
 *\ author Samuel Bouchard
 */

#ifndef PERSONNE_H_
#define PERSONNE_H_
#include <string>
#include <iostream>
#include "Date.h"
#include "Personne.h"





namespace elections {

/**
 *\class Personne
 *\brief Cette classe sert au maintien et a la manipulations des personnes
 *				Cette classe peut aussi afficher la personne sous une forme
 *				facilement lisible a l'utilisateur et peut aussi mettre les informations sur la personne
 *				dans un fichier .txt
 *				<p>
 *				Attributs: m_nom   Nom de la personne\n
 *				m_prenom prenom de la personne\n
 *				m_nas   numero d'assurance social de la personne, peut etre valide
 *				a l'aide de la fonction validerNAS du namespace util\n
 *				m_dateNaissance objet Date du namespace util representant la date de naissance de la personne\n
 *				m_adresse adresse de la residence de la personne, seul attribut que l'on peut modifier avec les
 *				methodes de la classe\n
 *				<p>
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

class Personne {
public:
	Personne(const std::string& p_nas,
	const std::string& p_prenom,
	const std::string& p_nom,
	const util::Date& p_dateNaissance,
	const util::Adresse p_adresse);

	void asgAdresse(const std::string& p_adresse);

	std::string reqNom() const;
	std::string reqNas() const;
	std::string reqPrenom() const;
	util::Adresse reqAdresse() const;
	util::Date reqDateNaissance() const;

	std::string reqPersonneFormate() const ;

	bool operator==(const Personne& p_personne);
	friend std::ostream& operator<<(std::ostream& p_os, const Personne& p_personne);

private:

	 std::string m_nom;
	 std::string m_nas;
	 std::string m_prenom;
     std::string m_adresse;
	 util::Date m_dateNaissance;


};

} /* namespace elections */

#endif /* PERSONNE_H_ */
