/**
 * \file Adresse.h
 * \brief  interface de la classe adresse
 * à modifier pour avoir chaque partie de l'adresse dans des attributs distincts
 * \author the
 * \version 0.1
 * \date 2017-10-15
 */
#ifndef ADRESSE_H_
#define ADRESSE_H_
#include<string>
#include<sstream>
#include<iostream>
#include "ContratException.h"


namespace util
{
/**
 * \class Adresse
 * \brief Cette classe sert a la manipulation et au maintien des adresses civiques.
 * Cette classe peut aussi afficher l'adresse d'une personne sous une forme facilement lisble par l'utilisateur
 * 		<p>
 * 		Attributs: m_nom nom de la rue de l'adresse
 */
class Adresse
{

	friend std::ostream& operator<<(std::ostream& p_os, const Adresse& p_adresse);

public:
	Adresse(const std::string& p_nomrue,const std::string& p_ville,
			const std::string& p_codepostal,
			const std::string& p_province, int p_numerorue);

	std::string reqNomRue() const;
	std::string reqVille() const;
	std::string reqCodePostal() const;
	std::string reqProvince() const;
	int reqNumeroRue() const;
	std::string reqAdresseFormate() const;

	void asgAdresse(const std::string& p_nomrue,const std::string& p_ville,
			const std::string& p_codepostal,
			const std::string& p_province, int p_numerorue);

	friend std::ostream& operator <<(std::ostream& p_os, const Adresse& p_adresse);
	bool operator== (const Adresse& p_adresse) const;


private:
	void verifieInvariant() const;
	int m_numerorue;
	std::string m_nomrue;
	std::string m_ville;
	std::string m_codepostal;
	std::string m_province;

};

}

#endif /* ADDRESSE_H_ */
