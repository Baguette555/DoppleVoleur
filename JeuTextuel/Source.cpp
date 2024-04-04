#include <iostream>
#include "Profil.h"
#include <vector>
#include <string>
#include <ctime>
#include <thread>
#include <chrono>

#include <cstdlib>
using namespace std;

void pressEnter() {
	string enter;
	getline(cin, enter);
}


void afficherLentement(const string& message, chrono::milliseconds duree) {
	for (char c : message) {
		cout << c;
		this_thread::sleep_for(duree);
	}
}

int main()
{
	cout << "Vous incarnez x qui a tue y dans l'optique de vous approprier madame" << endl;
	cout << "Vous allez etre mis face au profil de y. Retenez le, et surtout ne ratez pas le repas." << endl;

	this_thread::sleep_for(chrono::seconds(10));
	cout << endl;

	Profil p1;

	cout << p1.getDescription() << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Age : " << p1.getAge() << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Taille : " << p1.getTaille() << " centimetres" << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "A-t-il une profession ? " << p1.getHasWork() << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Profession : " << p1.getProfession_ToString() << std::endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Nationalite : " << p1.getNationalite_ToString() << std::endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Aime-t-il les animaux ? " << p1.getLovesAnimals() << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Animal de compagnie : " << p1.getAnimaux_ToString() << std::endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Sa meilleure qualite : " << p1.getQualites_ToString() << std::endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Son pire defaut : " << p1.getDefauts_ToString() << std::endl << endl;
	this_thread::sleep_for(chrono::seconds(2));

	cout << "Lorsque vous serez pret-e-s :" << endl;
	cout << "Le jeu demarrera et le profil ne sera plus visible." << endl;
	cout << "Retenez les informations, et ensuite entrez dans la maison et faites vous passer pour Y." << endl;
	cout << "[ENTREE] pour débuter le jeu.";
	pressEnter();
	
	system("cls");
	cout << endl;

	afficherLentement("Montpellier, Place de la Comedie", chrono::milliseconds(125));
	this_thread::sleep_for(chrono::milliseconds(200));
	afficherLentement(" - 21h28", chrono::milliseconds(125));
	this_thread::sleep_for(chrono::seconds(1));
	cout << endl;
	cout << "Image de maison guys";
	afficherLentement("[ENTREE] pour rentrer dans la maison", chrono::milliseconds(32));
	pressEnter();

	return 0;
}