/**
 * \file  Principal.cpp
 * \brief Fichier qui demande les informations sur une personne et les valide afin de creer un objet personne et de la sauvegarder dans un fichier
 * \author Samuel Bouchard
 * \date 19 0ctobre 2017
 */
// derniere modification : 2017-10-19
#include "Date.h"
#include "Personne.h"
#include "validationFormat.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace util;
using namespace elections;


int main(){
	string p_nas;
	string p_nom;
	string p_prenom;
	string p_adresse;
	string p_nouvelleAdresse;
	long p_jour;
	long p_mois;
	long p_annee;
	cout<<"Bienvenue a l'outil d'ajout d'une personne"<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<endl;
	cout<<"Entrez son numéro d’assurance sociale"<<endl;
	char buffer[256];
	cin.getline(buffer,255);
	p_nas=buffer;
	if (!validerNas(p_nas)){
		do {
			cout<<"Nas invalide"<<endl;
			cout<<"Entrez son numéro d’assurance sociale"<<endl;
			char buffer[256];
			cin.getline(buffer,255);
			p_nas=buffer;
		}while(!validerNas(p_nas));
	}
	cout<<"Entrez le nom : ";
	char buffer2[256];
	cin.getline(buffer2,255);
	p_nom=buffer2;
	if(p_nom.empty()){
		do {
			cout<<"Le nom est vide,"<<endl;
			cout<<"Entrez le nom : ";
			char buffer2[256];
			cin.getline(buffer2,255);
			p_nom=buffer2;
		} while(p_nom.empty());
	}
	cout<<"Entrez le prenom : ";
	char buffer3[256];
	cin.getline(buffer3,255);
	p_prenom=buffer3;
	if(p_prenom.empty()){
		do{
			cout<<"Le prenom est vide,"<<endl;
			cout<<"Entrez le prenom : ";
			char buffer3[256];
			cin.getline(buffer3,255);
			p_prenom=buffer3;
		} while(p_prenom.empty());
	}
	cout<<"Veuillez entrer sa date de naissance"<<endl;
	cout<<"Le jour [1..31] :";
	cin>>p_jour;
	cout<<"Le mois [1..12]: ";
	cin>>p_mois;
	cout<<"L'annee [1970..2037]";
	cin>>p_annee;
	if(!Date::validerDate(p_jour,p_mois,p_annee)){
		do{
			cout<<"La date de naissance n'est pas valide"<<endl;
			cout<<endl;
			cout<<endl;
			cout<<"Veuillez entrer sa date de naissance"<<endl;
			cout<<"Le jour [1..31] :";
			cin>>p_jour;
			cout<<"Le mois [1..12]: ";
			cin>>p_mois;
			cout<<"L'annee [1970..2037]";
			cin>>p_annee;
			cout<<endl;
		} while(!Date::validerDate(p_jour,p_mois,p_annee));
	}
	Date p_dateNaissance(p_jour,p_mois,p_annee);
	char buffer4[256];
	cout<<"Entrer l'adresse "<<endl;
	cin.ignore();
	cin.getline(buffer4,255);
	p_adresse=buffer4;
	if(p_adresse.empty()){
		do {
			cout<<"L'adresse saisie est invalide"<<endl;
			cout<<"Entrer l'adresse"<<endl;
			char buffer4[256];
			cin.getline(buffer4,255);
			p_adresse=buffer4;
			cout<<endl;
		} while(p_adresse.empty());
	}
	Personne p_personne(p_nas,p_prenom,p_nom,p_dateNaissance,p_adresse);
		cout<<"Personne enregistree"<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<p_personne.reqPersonneFormate();
		cout<<endl;
		cout<<"Saisir la nouvelle adresse"<<endl;
		cout<<endl;
		cout<<"Entrez l'adresse"<<endl;
		char buffer5[256];
		cin.getline(buffer5,255);
		p_nouvelleAdresse=buffer5;
		if(p_nouvelleAdresse.empty()){
			do {
				cout<<"L'adresse saise est invalide"<<endl;
				cout<<"Entrer l'adresse"<<endl;
				char buffer5[256];
				cin.getline(buffer5,255);
				p_nouvelleAdresse=buffer5;
				cout<<endl;
			} while(p_nouvelleAdresse.empty());
		}
		p_personne.asgAdresse(p_nouvelleAdresse);
		cout<<endl;
		cout<<p_personne.reqPersonneFormate();
		string p_nomfichier;
		cout<<"Saisir le nom du fichier de sauvegarde : ";
		cin>>p_nomfichier;
		ofstream ofs(p_nomfichier.c_str(), ios::out);
		if (!ofs){
			cerr<<"Le fichier n'existe pas"<<endl;
			return 1;
			do{
				cout<<"Le fichier demande n'existe pas"<<endl;
				cout<<"Saisir le nom du fichier de sauvegarde : ";
				cin>>p_nomfichier;
			} while (!ofs);
		}
		ofs<<p_personne;
		ofs.close();

	return 0;
}


