/*
 * Circonscription.h
 *
 *  Created on: 2017-11-29
 *      Author: etudiant
 */

#ifndef CIRCONSCRIPTION_H_
#define CIRCONSCRIPTION_H_
#include <string>

namespace elections {

class Circonscription {
public:
	Circonscription(const std::string& p_nom, const elections::Candidat& p_depute);
	virtual ~Circonscription();
private:
	std::string m_nom;
	elections::Candidat m_deputeElu;
};

} /* namespace elections */

#endif /* CIRCONSCRIPTION_H_ */
