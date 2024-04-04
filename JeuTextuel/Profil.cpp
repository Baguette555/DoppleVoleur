#include "Profil.h"
#include <string>

Profil::Profil()
{
	setDescription("Profil de (prenom) - Ancien copain de (prenom)");
	setAge(26);
	setTaille(180);
	setHasWork(true);
	if (getHasWork()) {		// am about to destroy this guy right here
		setHasWork("Oui");
	}
	else {
		setHasWork("Non");
	}
	setProfession("Programmeur");
	setNationalite("Francais");
	setLovesAnimals(true);
	setAnimaux("Chien");
	setQualites("Poli");
	setDefauts("Maladroit");
}

int Profil::getAge()
{
	return age;
}

void Profil::setAge(int a)
{
	age = a;
}

int Profil::getTaille()
{
	return taille;
}

void Profil::setTaille(int t)
{
	taille = t;
}

std::string Profil::getDescription()
{
	return description;
}

void Profil::setDescription(std::string d)
{
	description = d;
}

bool Profil::getHasWork()
{
	return hasWork;
}

void Profil::setHasWork(bool w)
{
	hasWork = w;
}


Nationalite Profil::getNationalite()
{
	return nationaliteOrigine;
}

std::string Profil::getNationalite_ToString()
{
	switch (nationaliteOrigine) {		// ON VA SE faIRE CANCEL LETSGOO!!!
	case Nationalite::Francais:
		return "Francais";
	case Nationalite::Anglais:
		return "Anglais";
	case Nationalite::Espagnol:
		return "Espagnol";
	case Nationalite::Italien:
		return "Italien";
	case Nationalite::Asiate:
		return "Asiate";
	default:
		return "Francais";
	}
}

void Profil::setNationalite(Nationalite n)
{
	nationaliteOrigine = n;
}

void Profil::setNationalite(std::string userNationalite)
{
	if (userNationalite == "Francais") {
		nationaliteOrigine = Nationalite::Francais;
	}
	else if (userNationalite == "Anglais") {
		nationaliteOrigine = Nationalite::Anglais;
	}
	else if (userNationalite == "Espagnol") {
		nationaliteOrigine = Nationalite::Espagnol;
	}
	else if (userNationalite == "Italien") {
		nationaliteOrigine = Nationalite::Italien;
	}
	else if (userNationalite == "Asiate") {
		nationaliteOrigine = Nationalite::Asiate;
	}
	else {
		nationaliteOrigine = Nationalite::Francais;
	}
}

Profession Profil::getProfession()
{
	return professionTravail;
}

std::string Profil::getProfession_ToString()
{
	switch (professionTravail) {
	case Profession::Programmeur:
		return "Programmeur";
	case Profession::Musicien:
		return "Musicien";
	case Profession::Investisseur:
		return "Investisseur";
	default:
		return "Programmeur";
	}
}

void Profil::setProfession(Profession p)
{
	professionTravail = p;
}

void Profil::setProfession(std::string userProfession)
{
	if (userProfession == "Programmeur") {
		professionTravail = Profession::Programmeur;
	}
	else if (userProfession == "Musicien") {
		professionTravail = Profession::Musicien;
	}
	else if (userProfession == "Investisseur") {
		professionTravail = Profession::Investisseur;
	}
	else {
		professionTravail = Profession::Programmeur;
	}
}

Animaux Profil::getAnimaux()
{
	return Animaux();
}

std::string Profil::getAnimaux_ToString()
{
	switch (animalComp) {
	case Animaux::Chien:
		return "Chien";
	case Animaux::Chat:
		return "Chat";
	case Animaux::Tortue:
		return "Tortue";
	case Animaux::Aucun:
		return "Aucun";
	default:
		return "Chien";
	}
}

void Profil::setAnimaux(Animaux x)
{
	animalComp = x;
}

void Profil::setAnimaux(std::string userAnimaux)
{
	if (userAnimaux == "Chien") {
		animalComp = Animaux::Chien;
	}
	else if (userAnimaux == "Chat") {
		animalComp = Animaux::Chat;
	}
	else if (userAnimaux == "Tortue") {
		animalComp = Animaux::Tortue;
	}
	else if (userAnimaux == "Aucun") {
		animalComp = Animaux::Aucun;
	}
	else {
		animalComp = Animaux::Chien;
	}
}

Qualites Profil::getQualites()
{
	return Qualites();
}

std::string Profil::getQualites_ToString()
{
	switch (qualities) {
	case Qualites::Poli:
		return "Poli";
	case Qualites::Sociable:
		return "Sociable";
	case Qualites::Curieux:
		return "Curieux";
	case Qualites::Attentif:
		return "Attentif";
	case Qualites::Joyeux:
		return "Joyeux";
	case Qualites::Amical:
		return "Amical";
	default:
		return "Poli";
	}
}

void Profil::setQualites(Qualites q)
{
	qualities = q;
}

void Profil::setQualites(std::string userQualites)
{
	if (userQualites == "Poli") {
		qualities = Qualites::Poli;
	}
	else if (userQualites == "Sociable") {
		qualities = Qualites::Sociable;
	}
	else if (userQualites == "Curieux") {
		qualities = Qualites::Curieux;
	}
	else if (userQualites == "Attentif") {
		qualities = Qualites::Attentif;
	}
	else if (userQualites == "Joyeux") {
		qualities = Qualites::Joyeux;
	}
	else if (userQualites == "Amical") {
		qualities = Qualites::Amical;
	}
	else {
		qualities = Qualites::Poli;
	}
}

Defauts Profil::getDefauts()
{
	return Defauts();
}

std::string Profil::getDefauts_ToString()
{
	switch (defaults) {
	case Defauts::Impatient:
		return "Impatient";
	case Defauts::Maladroit:
		return "Maladroit";
	case Defauts::Raleur:
		return "Raleur";
	case Defauts::MauvaisPerdant:
		return "Mauvais Perdant";
	default:
		return "Impatient";
	}
}

void Profil::setDefauts(Defauts b)
{
	defaults = b;
}

void Profil::setDefauts(std::string userDefauts)
{
	if (userDefauts == "Impatient") {
		defaults = Defauts::Impatient;
	}
	else if (userDefauts == "Maladroit") {
		defaults = Defauts::Maladroit;
	}
	else if (userDefauts == "Raleur") {
		defaults = Defauts::Raleur;
	}
	else {
		defaults = Defauts::MauvaisPerdant;
	}
}

bool Profil::getLovesAnimals()
{
	return lovesAnimals;
}

void Profil::setLovesAnimals(bool l)
{
	lovesAnimals = l;
}
