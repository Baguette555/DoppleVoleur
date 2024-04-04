#pragma once
#include <iostream>

enum class Nationalite {		// Avant de poser des questions sur pourquoi il y a des énum,
	Francais,					// c'est simple : on a prévu de faire de l'aléatoire pour chaque
	Anglais,					// catégorie. On le garde au cas où, on ne sait jamais.
	Espagnol,
	Italien,
	Asiate
};

enum class Profession {
	Programmeur,
	Musicien,
	Investisseur
};

enum class Animaux {
	Chien,
	Chat,
	Tortue,
	Aucun
};

enum class Qualites {
	Poli,
	Sociable,
	Curieux,
	Attentif,
	Joyeux,
	Amical
};

enum class Defauts {
	Impatient,
	Maladroit,
	Raleur,
	MauvaisPerdant
};

class Profil
{
private:
	std::string description;		// Letter d - Description en une ligne du profil
	int age;						// Letter a
	int taille;						// Letter t
	Nationalite nationaliteOrigine; // Letter n
	bool hasWork;					// Letter w
	Profession professionTravail;	// Letter p - Seulement si hasWork = true
	bool lovesAnimals;				// Letter l - L
	Animaux animalComp;				// Letter x
	Qualites qualities;				// Letter q
	Defauts defaults;				// Letter b

public:
	Profil();

	std::string getDescription();
	void setDescription(std::string d);

	int getAge();
	void setAge(int a);

	int getTaille();
	void setTaille(int t);

	bool getHasWork();
	void setHasWork(bool w);

	Profession getProfession();
	std::string getProfession_ToString();
	void setProfession(Profession p);
	void setProfession(std::string userProfession);

	Nationalite getNationalite();
	std::string getNationalite_ToString();
	void setNationalite(Nationalite n);
	void setNationalite(std::string userNationalite);

	Animaux getAnimaux();
	std::string getAnimaux_ToString();
	void setAnimaux(Animaux x);
	void setAnimaux(std::string userAnimaux);

	Qualites getQualites();
	std::string getQualites_ToString();
	void setQualites(Qualites q);
	void setQualites(std::string userQualites);

	Defauts getDefauts();
	std::string getDefauts_ToString();
	void setDefauts(Defauts b);
	void setDefauts(std::string userDefauts);

	bool getLovesAnimals();
	void setLovesAnimals(bool l);
};
