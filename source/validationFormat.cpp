/**
 * \file validationFormat.cpp
 * \brief Fichier qui contient l'implementation des fonctions de validations du nas et du format de fichier
 * \author Samuel Bouchard
 * \date 19 0ctobre 2017
 */
// derniere modification : 2017-10-19


#include <iostream>
#include <fstream>
#include <string>
#include "validationFormat.h"
using namespace std;

namespace util{

/**
 * \brief Fonction qui verfifie si le numero d'assurance sociale de la personne est un numero valide selon les normes
 * \param[in] p_nas soit une chaine de caracteres qui contient le nas a valider
 * \return un booleen qui indique true si le nas est valide et false s'il est invalide
 */

bool validerNas(const std::string& p_nas){
	bool validation = true;
	if (p_nas.length() != 11){
    	validation = false;
    }
    if (p_nas[3] != ' ' or p_nas[7] != ' '){
    	validation = false;
    }
   for(int i=0; p_nas[i] !='\0'; i++){
	   if(p_nas[i] != ' ' and isdigit(p_nas[i])==false){
		   validation = false;
	   }
   }
   int x = 0;
   int NASint[9];
   for(int i=0; p_nas[i] !='\0'; i++){
	   if (p_nas[i]==' '){
		   i++;
		   NASint[x] = p_nas[i]-'0';
		   x++;
	   }
	   else{
		   NASint[x]  = p_nas[i]-'0';
		   x++;
	   }
   }
   int Somme=0;
   int mul[9]={1,2,1,2,1,2,1,2,1};
   for(int i=0; i<=8;i++){
	   NASint[i]=NASint[i]*mul[i];
	   if (NASint[i] >=10){
		   switch (NASint[i]){
		       case 10: NASint[i]=1;
		       break;
		       case 11: NASint[i]=2;
		       break;
		       case 12: NASint[i]=3;
		       break;
		       case 13: NASint[i]=4;
		       break;
		       case 14: NASint[i]=5;
		       break;
		       case 15: NASint[i]=6;
		       break;
		       case 16: NASint[i]=7;
		       break;
		       case 17: NASint[i]=8;
		       break;
		       case 18: NASint[i]=9;
		       break;

		   }
	   }
	   Somme += NASint[i];
   }
   if (Somme%10 != 0){
	   validation = false;
   }
   return validation;






}

/**
 * \brief Fonction qui verifie la validite d'un fichier avec des deputes ou des candidats dedans
 * \param[in] p_is un objet istream avec le fichier a verifie en parametre
 * \return un booleen qui indique true si le fichier est de format valide et false s'il est invalide
 * ############CETTE FONCTION EST INCOMPLETE ELLE SERA COMPLETER POUR LES TP ULTERIEURES####################
 */
bool validerFormatFichier(std::istream& p_is){
	bool validation;
	validation = true;
	if(!p_is){    //On verifie si le fichier existe
		cout<<"Le fichier demande n'existe pas"<<endl;

	}
	int indiceLignes = 0;
	string listePartis[5]={"BLOC_QUEBECOIS","CONSERVATEUR","INDEPENDANT",
    "LIBERAL","NOUVEAU_PARTI_DEMOCRATIQUE"};
	string listemots[255];
	char buffer[255];
	while(p_is.getline(buffer,255)){
		listemots[indiceLignes]=buffer;
		indiceLignes++;
	}
	if (listemots[3].empty()==true or listemots[4].empty()==true){

	}


	bool validationParti = false;
	listemots[1].erase(listemots[1].size()-1);
	for (int i = 0; i<=4;i++){ //cOMPARE AVEC LES NOMS DE PARTIS
		if(listemots[1].compare(listePartis[i])==0){
			validationParti = true;
			cout<<"asdasdadas"<<endl;
		}
	}
	if( validationParti == false){
		cout<<"Le parti est invalide"<<endl;
	}
	listemots[2].erase(listemots[2].size()-1);
	validerNas(listemots[2]); //On regarde si c'est un Nas valide
	return validation;
}
} //namespace util


