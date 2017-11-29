/**
 * \file Adresse.cpp
 * \brief classe adresse
 * à modifier
 * \author the
 * \version 0.1
 * \date 2017-10-15
 */
#include <sstream>
#include <iostream>
#include "Adresse.h"
using namespace std;

namespace util
{
/*
 * \brief constructeur
 * \param[in]
 * \param[in]
 * \param[in]
 * \param[in]
 * \param[in]
 * \pre ne doit pas être vide
 */
Adresse::Adresse(const std::string& p_nomrue,const std::string& p_ville,
			const std::string& p_codepostal,
			const std::string& p_province, int p_numerorue):m_codepostal(p_codepostal),
			m_nomrue(p_nomrue),m_numerorue(p_numerorue),m_province(p_province)
{
	PRECONDITION(p_numerorue > 0);
	PRECONDITION(p_nomrue);
	PRECONDITION(p_ville);
	PRECONDITION(p_codepostal);
	PRECONDITION(p_province);


	POSTCONDITION(m_codepostal == p_codepostal);
	POSTCONDITION(m_nomrue == p_nomrue);
	POSTCONDITION(m_ville == p_ville);
	POSTCONDITION(m_numerorue == p_numerorue);
	POSTCONDITION(m_province == p_province);
	INVARIANTS();
}

std::string Adresse::reqNomRue() const {
	return m_nomrue;
}

std::string Adresse::reqVille() const {
	return m_ville;
}

std::string Adresse::reqCodePostal() const {
	return m_codepostal;
}

std::string Adresse::reqProvince() const {
	return m_province;
}

int Adresse::reqNumeroRue() const {
	return m_numerorue;
}

void Adresse::asgAdresse(const std::string& p_nomrue,
		const std::string& p_ville, const std::string& p_codepostal,
		const std::string& p_province, int p_numerorue) {

	PRECONDITION(p_numerorue > 0);
	PRECONDITION(p_nomrue);
	PRECONDITION(p_ville);
	PRECONDITION(p_codepostal);
	PRECONDITION(p_province);

	m_nomrue = p_nomrue;
	m_numerorue = p_numerorue;
	m_ville = p_ville;
	m_province = p_province;
	m_codepostal = p_codepostal;





	POSTCONDITION(m_codepostal == p_codepostal);
	POSTCONDITION(m_nomrue == p_nomrue);
	POSTCONDITION(m_ville == p_ville);
	POSTCONDITION(m_numerorue == p_numerorue);
	POSTCONDITION(m_province == p_province);
	INVARIANTS();




}




std::string Adresse::reqAdresseFormate() const {
	ostringstream p_os;
	p_os<<m_numerorue<<", ";
	p_os<<m_nomrue<<", ";
	p_os<<m_ville<<", ";
	p_os<<m_codepostal<<", ";
	p_os<<m_province<<endl;
	return p_os.str();


}

bool Adresse::operator ==(const Adresse& p_adresse) const {
	return(p_adresse.m_codepostal==m_codepostal and p_adresse.m_nomrue==m_nomrue and p_adresse.m_numerorue ==m_numerorue
			and p_adresse.m_province==m_province and p_adresse.m_ville==m_ville);
}
std::ostream& operator <<(std::ostream& p_os, const Adresse& p_adresse)
{
	p_os<<p_adresse.m_numerorue<<endl;
	p_os<<p_adresse.m_nomrue<<endl;
	p_os<<p_adresse.m_codepostal<<endl;
	p_os<<p_adresse.m_ville<<endl;
	p_os<<p_adresse.m_province<<endl;
	return p_os;

}



void Adresse::verifieInvariant() const {
	INVARIANT(m_numerorue>0);
	INVARIANT(m_codepostal);
	INVARIANT(m_nomrue);
	INVARIANT(m_ville);
	INVARIANT(m_province);

}

} //namespace util

