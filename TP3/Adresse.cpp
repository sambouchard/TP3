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
 * \param[in] p_adresse une chaine de caractères contenant l'adresse
 * \pre ne doit pas être vide
 */
Adresse::Adresse(const std::string& p_nomrue,const std::string& p_ville,
			const std::string& p_codepostal,
			const std::string& p_province, int p_numerorue):m_codepostal(p_codepostal),
			m_nomrue(p_nomrue),m_numerorue(p_numerorue),m_province(p_province)
{
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

void Adresse::asgNomRue(const std::string& p_nomrue) {
	m_nomrue=p_nomrue;
}

void Adresse::asgVille(const std::string& p_ville) {
	m_ville=p_ville;
}

void Adresse::asgCodePostal(const std::string& p_codepostal) {
	m_codepostal=p_codepostal;
}

void Adresse::asgProvince(const std::string& p_province) {
	m_province=p_province;
}

void Adresse::asgNumeroRue(int p_numerorue) {
	m_numerorue=p_numerorue;
}

std::string Adresse::reqAdresseFormate() const {
	ostringstream p_os;
	p_os<<m_numerorue<<" "<<endl;
	p_os<<m_nomrue<<" "<<endl;
	p_os<<m_ville<<" "<<endl;
	p_os<<m_codepostal<<" "<<endl;
	p_os<<m_province<<" "<<endl;


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

} //namespace util

