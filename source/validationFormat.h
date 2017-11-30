/**
 * \file validationFormat.h
 * \brief Fichier qui contient l'interface des fonctions de validations du nas et du format de fichier
 * \author Samuel Bouchard
 * \date 19 0ctobre 2017
 */
// derniere modification : 2017-10-19
#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_
/**
 *\brief Declaration des fonctions servant a valider le nas et le format du fichier
 *
 */

namespace util{

bool validerNas(const std::string& p_nas);
bool validerFormatFichier(std::istream& p_is);

}
// namespace util


#endif /* VALIDATIONFORMAT_H_ */
