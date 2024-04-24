#include <iostream>
#include "Profil.h"
#include <vector>
#include <string>
#include <ctime>
#include <thread>
#include <chrono>
#include <fstream> //affichage .txt
#include <cstdlib> //random

using namespace std;

int vieActuelle;

//----------------------------GESTION BARRE DE VIE------------------------------
void afficherBarreDeVie(int vieActuelle, int vieMax)
{
	int longueurBarre = 60;
	int longueurVie = (static_cast<float>(vieActuelle) / vieMax) * longueurBarre;

	//cout << "Sus-meter : [";
	cout << "[";

	for (int i = 0; i < longueurVie; ++i) {
		cout << "=";
	}

	for (int i = 0; i < (longueurBarre - longueurVie); ++i) {
		cout << " ";
	}

	cout << "] " << vieActuelle << "/" << vieMax << endl;
}
//----------------------------GESTION BARRE DE VIE------------------------------


//----------------------------GENERATION ALEATOIRE------------------------------
bool estDansListe(int liste[], int taille, int valeur); // Création d'un bool pour éviter les doublons dans les questions

int aleatoire(int questionsPosees[], int taille)
{
	int nouvelle;
	do {
		srand(time(0));
		nouvelle = rand() % 15 + 1;
	} while (estDansListe(questionsPosees, taille, nouvelle)); // Pour s'assurer que la nouvelle question est différente des questions précédentes
	return nouvelle;
}


bool estDansListe(int liste[], int taille, int valeur)
{
	for (int i = 0; i < taille; ++i)
	{
		if (liste[i] == valeur) {
			return true;
		}
	}
	return false;
}//----------------------------GENERATION ALEATOIRE------------------------------

void pressEnter() {
	string enter;
	getline(cin, enter);
}


void afficherLentement(const string& message, chrono::milliseconds duree) {			// Ce qui permet d'afficher le texte petit à petit
	for (char c : message) {
		cout << c;
		this_thread::sleep_for(duree);
	}
}


void intro() {
	afficherLentement("Bienvenue a DoppleVoleur, un jeu de memoire.", chrono::milliseconds(75));
	cout << endl;
	this_thread::sleep_for(chrono::milliseconds(500));
	afficherLentement("Le but du jeu est de vous faire passer pour une copie d'un copain que vous avez tue il y a peu.", chrono::milliseconds(75));
	cout << endl;
	this_thread::sleep_for(chrono::milliseconds(500));
	afficherLentement("Mais attention, la famille ne doit pas trop vous suspecter !", chrono::milliseconds(75));
	cout << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(500));
	cout << "Dopple-Voleur" << endl;
	cout << "Un jeu par Bastien, Maxime, Clara, Amandine, Esteban et Galaad." << endl;
	cout << "[ENTREE] pour debuter le jeu.";
	pressEnter();
	system("cls");

	cout << endl;
	cout << "Vous vous appretez a rentrer dans la maison de votre ''nouvelle'' copine." << endl;
	this_thread::sleep_for(chrono::seconds(3));
	cout << "Vous allez etre mis face au profil de l'ancien copain d'Alex. Retenez le, et surtout ne ratez pas le repas." << endl;
	this_thread::sleep_for(chrono::seconds(3));
	cout << endl;
	cout << "Comment jouer :" << endl;
	this_thread::sleep_for(chrono::seconds(3));
	cout << "Vous devez repondre a 15 questions pendant le repas." << endl;
	this_thread::sleep_for(chrono::seconds(3));
	cout << "A chaque mauvaise reponse, votre suspicionMeter peut augmenter jusqu'a +15." << endl;
	this_thread::sleep_for(chrono::seconds(3));
	cout << "A chaque bonne reponse, votre suspicionMeter diminue de 4." << endl;
	this_thread::sleep_for(chrono::seconds(3));
	cout << "A la fin du repas, votre score sera calcule pour determiner la chance de reussite." << endl;
	this_thread::sleep_for(chrono::seconds(3));
	cout << "Un plus gros score est egal a de plus grandes chances de perte !" << endl;
	cout << endl;
	this_thread::sleep_for(chrono::seconds(3));
	cout << "[ENTREE] pour debuter le jeu.";
	pressEnter();
	system("cls");

	afficherLentement("Affichage du profil : ", chrono::milliseconds(100));
	this_thread::sleep_for(chrono::seconds(2));
	cout << endl << endl;

	Profil p1;

	cout << p1.getDescription() << endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << endl;
	cout << "Age : " << p1.getAge() << endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Taille : " << p1.getTaille() << " centimetres" << endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "A-t-il une profession ? " << p1.getHasWork() << endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Profession : " << p1.getProfession_ToString() << std::endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Nationalite : " << p1.getNationalite_ToString() << std::endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Combien a-t-il d'animaux ? " << p1.getLovesAnimals() << endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Animal de compagnie : " << p1.getAnimaux_ToString() << std::endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Sa meilleure qualite : " << p1.getQualites_ToString() << std::endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Son pire defaut : " << p1.getDefauts_ToString() << std::endl;
	this_thread::sleep_for(chrono::seconds(2));

	cout << "Sa phobie : " << "Les araignees" << std::endl;				// Questions supplémentaires bonus
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Ce qu'il aime d'Alex : " << "Son organisation" << std::endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Ce qu'il aime faire avec Alex : " << "Lire des livres" << std::endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Hobby : " << "Jouer aux jeux-videos" << std::endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Type de films : " << "Films d'action" << std::endl;
	this_thread::sleep_for(chrono::seconds(2));


	cout << endl;

	cout << "Lorsque vous serez pret-e-s :" << endl;
	cout << "Le jeu demarrera et le profil ne sera plus visible." << endl;
	cout << "Retenez les informations, et ensuite entrez dans la maison et faites vous passer pour le copain d'Alex." << endl;
	cout << "[ENTREE] pour debuter le jeu.";
	pressEnter();
	
	system("cls");
	cout << endl;

	afficherLentement("Montpellier, pas tres loin de la Place de la Comedie", chrono::milliseconds(75));
	this_thread::sleep_for(chrono::milliseconds(200));
	afficherLentement(" - 21h28", chrono::milliseconds(100));
	this_thread::sleep_for(chrono::seconds(1));
	cout << endl;
	//cout << "Image de maison guys" << endl;
	afficherLentement("[ENTREE] pour rentrer dans la maison", chrono::milliseconds(32));
	pressEnter();
	system("cls");
}

//----------------------------QUESTION----------------------------------
void question1(int randomQuestion, int& vieActuelle)
{
	if (randomQuestion == 1) // si le chiffre du random sort 1 = alors on lit cette question
	{
		afficherBarreDeVie(vieActuelle, 100); // affichage barre de vie
		cout << endl;

		int reponse1;
		cout << "Quel age as-tu ?" << endl;
		cout << endl;
		cout << "1. 99 ans.\n2. Le meme age que Trump.\n3. 26 ans.\n4. 36 ans.\n";
		cin >> reponse1;

		switch (reponse1) // réponse aux questions + point gagné ou perdu
		{
		case 1:
			cout << "Eh bah ! On peut dire que tu as le sens de l'humour !" << endl << "(+15 suspicion -5 humour (= +10))" << endl;
			vieActuelle += 10;
			break;
		case 2:
			cout << "Ha. Ha. Tres drole..." << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15; // gagner 15 points ce qui fait monter le suspicious meter 
			break;
		case 3:
			cout << "Tu ne les fais pas !" << endl << "(-4 suspicion, bonne reponse)" << endl;
			vieActuelle -= 4; // perdre 4 points ce qui fait redescendre le suspicious meter
			break;
		default:
			cout << "C'est pas ce qu'a dit notre fille..." << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
		}
		this_thread::sleep_for(chrono::seconds(3));
		system("cls"); // clear console
	}
}

void question2(int randomQuestion, int& vieActuelle)
{
	if (randomQuestion == 2)
	{
		afficherBarreDeVie(vieActuelle, 100);
		cout << endl;

		int reponse2;
		cout << "Tu as un travail ?" << endl;
		cout << endl;
		cout << "1. Oui, je travaille !\n2. Pourquoi faire ?\n3. Non, je suis chomeur.\n4. En vrai... flemme.";
		cin >> reponse2;

		switch (reponse2)
		{
		case 1:
			cout << "Ah c'est super ca !" << endl << "(-4 suspicion, bonne reponse)" << endl;
			vieActuelle -= 4;
			break;
		case 2:
			cout << "Et bah pour gagner de l'argent neuneu" << endl << "(+15 suspicion +3 'neuneu' (= +18))" << endl;
			vieActuelle += 18;
			break;
		case 3:
			cout << "Notre fille nous avait pourtant dit le contraire ?" << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
			break;
		default:
			cout << "C'est ca ouais..." << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
		}
		this_thread::sleep_for(chrono::seconds(3));
		system("cls");
	}
}

void question3(int randomQuestion, int& vieActuelle)
{
	if (randomQuestion == 3)
	{
		afficherBarreDeVie(vieActuelle, 100);
		cout << endl;

		int reponse3;
		cout << "Tu fais quelle taille ?" << endl;
		cout << endl;
		cout << "1. 1 metre 80.\n2. 2 metres, bam !\n3. 1 metre 78.\n";
		cin >> reponse3;

		switch (reponse3) {
		case 1:
			cout << "C'est grand !" << endl << "(-4 suspicion, bonne reponse)" << endl;
			vieActuelle -= 4;
			break;
		case 2:
			cout << "C'est pas ce qu'elle nous a dit notre fille..." << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
			break;
		default:
			cout << "T'as retrecit ?" << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
		}
		this_thread::sleep_for(chrono::seconds(3));
		system("cls");
	}
}

void question4(int randomQuestion, int& vieActuelle)
{
	if (randomQuestion == 4)
	{
		afficherBarreDeVie(vieActuelle, 100);
		cout << endl;

		int reponse4;
		cout << "Tu as des freres ?" << endl;
		cout << endl;
		cout << "1. Oh non non non, trop chiant.\n2. Non, je suis fils unique.\n3. Oui, et j'en ai 10.\n4. Non, mais j'ai 2 soeurs !\n";
		cin >> reponse4;

		switch (reponse4)
		{
		case 1:
			cout << "Tu pourrais mieux parler quand meme" << endl << "(+15 suspicion +3 impoli (= +18))" << endl;
			vieActuelle += 18;
			break;
		case 2:
			cout << "Oh d'accord" << endl << "(-4 suspicion, bonne reponse)" << endl;
			vieActuelle -= 4;
			break;
		case 3:
			cout << "Ca fait beaucoup la nan ?" << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
			break;
		default:
			cout << "Elle nous avait pas dit ca..." << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
		}
		this_thread::sleep_for(chrono::seconds(3));
		system("cls");
	}
}

void question5(int randomQuestion, int& vieActuelle)
{
	if (randomQuestion == 5)
	{
		afficherBarreDeVie(vieActuelle, 100);
		cout << endl;

		int reponse5;
		cout << "Tu fais quel metier actuellement ?" << endl;
		cout << endl;
		cout << "1. Je suis Tueur a Gages\n2. Je suis Illustrateur !\n3. Je suis l'Informaticien du quartier.\n4. Je suis HOKAGUE !\n";
		cin >> reponse5;

		switch (reponse5)
		{
		case 1:
			cout << "Je trouve pas ca drole..." << endl << "(+18 grosse suspicion)" << endl;
			vieActuelle += 18;
			break;
		case 2:
			cout << "Pourtant notre fille nous a montre des dessins et c'etait franchement affreux" << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
			break;
		case 3:
			cout << "Oh super, j'ai un probleme avec mon ordinateur, tu pourras m'aider ahah" << endl << "(-4 suspicion, bonne reponse)" << endl;
			vieActuelle -= 4;
			break;
		default:
			cout << "Hoka quoi ????" << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
		}
		this_thread::sleep_for(chrono::seconds(3));
		system("cls");
	}
}

void question6(int randomQuestion, int& vieActuelle)
{
	if (randomQuestion == 6)
	{
		afficherBarreDeVie(vieActuelle, 100);
		cout << endl;

		int reponse6;
		cout << "Tu penses avoir quelle qualite" << endl;
		cout << endl;
		cout << "1. Je suis plutot poli.\n2. Je suis le ROI DES PIRATES !\n3. Je joue pas Pyke...\n4. Je fais attention aux petits details.\n";
		cin >> reponse6;

		switch (reponse6)
		{
		case 1:
			cout << "C'est une bonne qualitee !" << endl << "(-4 suspicion, bonne reponse)" << endl;
			vieActuelle -= 4;
			break;
		case 2:
			cout << "On est pas dans One Piece..." << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
			break;
		case 3:
			cout << "Les joueurs Pyke sont meme pas gold non ?" << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
			break;
		default:
			cout << "Notre fille nous a dit que tu etais vachement maladroit..." << endl << "(+10 petite suspicion)" << endl;
			vieActuelle += 10;
		}
		this_thread::sleep_for(chrono::seconds(3));
		system("cls");
	}
}

void question7(int randomQuestion, int& vieActuelle)
{
	if (randomQuestion == 7)
	{
		afficherBarreDeVie(vieActuelle, 100);
		cout << endl;

		int reponse7;
		cout << "Quel est ton plus gros defaut ?" << endl;
		cout << endl;
		cout << "1. J'aime TFT.\n2. Je suis plutot maladroit..\n3. Je suis perfectionniste !\n4. Je suis vachement jaloux..\n";
		cin >> reponse7;

		switch (reponse7)
		{
		case 1:
			cout << "C'est HONTEUX" << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
			break;
		case 2:
			cout << "Oh, je vois. Pas de vases pour toi alors !" << endl << "(-4 suspicion, bonne reponse)" << endl;
			vieActuelle -= 4;
			break;
		case 3:
			cout << "C'est un sacre defaut ca." << endl << "(+10 petite suspicion)" << endl;
			vieActuelle += 10;
			break;
		default:
			cout << "Et bah bravo..." << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
		}
		this_thread::sleep_for(chrono::seconds(3));
		system("cls");
	}
}

void question8(int randomQuestion, int& vieActuelle)
{
	if (randomQuestion == 8)
	{
		afficherBarreDeVie(vieActuelle, 100);
		cout << endl;

		int reponse8;
		cout << "Tu aimes les animaux ?" << endl;
		cout << endl;
		cout << "1. Oui j'adore !\n2. Bof...\n3. Non surtout pas ! Je suis allergique !\n4. Qui peut aimer ca !?\n";
		cin >> reponse8;

		switch (reponse8)
		{
		case 1:
			cout << "Oh super ! On en a plein !" << endl << "(-4 suspicion, bonne reponse)" << endl;
			vieActuelle -= 4;
			break;
		case 2:
			cout << "Ah d'accord..." << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
			break;
		case 3:
			cout << "Ah mince !!!" << endl << "(+5 suspicion, allergie issue)" << endl;
			vieActuelle += 5;
			break;
		default:
			cout << "Nous ?!!" << endl << "(+18 suspicion (provoc.))" << endl;
			vieActuelle += 18;
		}
		this_thread::sleep_for(chrono::seconds(3));
		system("cls");
	}
}

void question9(int randomQuestion, int& vieActuelle)
{
	if (randomQuestion == 9)
	{
		afficherBarreDeVie(vieActuelle, 100);
		cout << endl;

		int reponse9;
		cout << "Quel est le style de film que tu preferes ?" << endl;
		cout << endl;
		cout << "1. Je suis plutot films d'action.\n2. Les films sur les genocides.\n3. Les films Romantiques.\n4. Les films de Science-Fiction.\n";
		cin >> reponse9;

		switch (reponse9)
		{
		case 1:
			cout << "Oh nous aussi !" << endl << "(-4 suspicion, bonne reponse)" << endl;
			vieActuelle -= 4;
			break;
		case 2:
			cout << "Ouh la... un gout tres particulier..." << endl << "(+18 grosse suspicion)" << endl;
			vieActuelle += 18;
			break;
		case 3:
			cout << "Ho nooo CRINGE" << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
			break;
		default:
			cout << "Youhou les vaisseaux... piou piouuu" << endl << "(+8 tres petite suspicion)" << endl;
			vieActuelle += 8;
		}
		this_thread::sleep_for(chrono::seconds(3));
		system("cls");
	}
}

void question10(int randomQuestion, int& vieActuelle)
{
	if (randomQuestion == 10)
	{
		afficherBarreDeVie(vieActuelle, 100);
		cout << endl;

		int reponse10;
		cout << "Tu es de quelle Nationalite ?" << endl;
		cout << endl;
		cout << "1. Je suis purement Francais.\n2. Je viens de slovaquie lo\n3. Je suis Chinois.\n4. Je suis Anglais.\n";
		cin >> reponse10;

		switch (reponse10)
		{
		case 1:
			cout << "Un pur francais evidemment !" << endl << "(-4 suspicion, bonne reponse)" << endl;
			vieActuelle -= 4;
			break;
		case 2:
			cout << "C'est ou ?" << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
			break;
		case 3:
			cout << "Mhh mhh, j'allais dire pareil." << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
			break;
		default:
			cout << "Oui oui et moi j'suis La reine d'angleterre... (R.I.P)" << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
		}
		this_thread::sleep_for(chrono::seconds(3));
		system("cls");
	}
}

void question11(int randomQuestion, int& vieActuelle)
{
	if (randomQuestion == 11)
	{
		afficherBarreDeVie(vieActuelle, 100);
		cout << endl;

		int reponse11;
		cout << "Tu as des animaux ?" << endl;
		cout << endl;
		cout << "1. Oui mon ex.\n2. Oui j'ai un chien !\n3. Non je suis allergique..\n4. Jamais de la vie...\n";
		cin >> reponse11;

		switch (reponse11)
		{
		case 1:
			cout << ". . ." << endl << "(+18 suspicion (impoli))" << endl;
			vieActuelle += 18;
			break;
		case 2:
			cout << "Ah, tu aurais du l'amener !" << endl << "(-4 suspicion, bonne reponse)" << endl;
			vieActuelle -= 4;
			break;
		case 3:
			cout << "Oh zut !" << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
			break;
		default:
			cout << "Dommage..." << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
		}
		this_thread::sleep_for(chrono::seconds(3));
		system("cls");
	}
}

void question12(int randomQuestion, int& vieActuelle)
{
	if (randomQuestion == 12)
	{
		afficherBarreDeVie(vieActuelle, 100);
		cout << endl;

		int reponse12;
		cout << "Tu as un hobby ?" << endl;
		cout << endl;
		cout << "1. Frapper des vielles.\n2. Je fais du sport !\n3. J'aime rien, donc je fais rien.\n4. Oui jouer aux jeux videos !\n";
		cin >> reponse12;

		switch (reponse12)
		{
		case 1:
			cout << "Je ne vais rien dire..." << endl << "(+18 grosse suspicion)" << endl;
			vieActuelle += 18;
			break;
		case 2:
			cout << "Ca ne se voit pas... hum hum." << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
			break;
		case 3:
			cout << "Tous les memes c'est dingue les jeunes." << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
			break;
		default:
			cout << "C'est super !" << endl << "(-4 suspicion, bonne reponse)" << endl;
			vieActuelle -= 4;
		}
		this_thread::sleep_for(chrono::seconds(3));
		system("cls");
	}
}

void question13(int randomQuestion, int& vieActuelle)
{
	if (randomQuestion == 13)
	{
		afficherBarreDeVie(vieActuelle, 100);
		cout << endl;

		int reponse13;
		cout << "Vous aimez faire quoi ensemble ?" << endl;
		cout << endl;
		cout << "1. Des combats de sable laser !\n2. Lire des livres.\n3. Des unboxing de RAID SHADOW LEGENDS qui sponsorise le date d'aujourd'hui !\n4. Des balades en poney !\n";
		cin >> reponse13;

		switch (reponse13)
		{
		case 1:
			cout << "C'est assez particulier" << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
			break;
		case 2:
			cout << "Interessant, interessant..." << endl << "(-4 suspicion, bonne reponse)" << endl;
			vieActuelle -= 4;
			break;
		case 3:
			cout << "Avec le code promo ILOVERAID !!!!" << endl << "(+10 suspicion et + 1 code promo)" << endl;
			vieActuelle += 10;
			break;
		default:
			cout << "Ma fille n'aime pas les poneys..." << endl << "(+17 suspicion)" << endl;
			vieActuelle += 17;
		}
		this_thread::sleep_for(chrono::seconds(3));
		system("cls");
	}
}

void question14(int randomQuestion, int& vieActuelle)
{
	if (randomQuestion == 14)
	{
		afficherBarreDeVie(vieActuelle, 100);
		cout << endl;

		int reponse14;
		cout << "Quelle est la qualite que tu preferes chez notre fille ?" << endl;
		cout << endl;
		cout << "1. Son sens de l'organisation\n2. Sa devotion envers le Christ Cosmique ALIAS le grand Seigneur.\n3. Son humour plus que douteux..\n4. Sa magnifique barbe..?\n";
		cin >> reponse14;

		switch (reponse14)
		{
		case 1:
			cout << "C'est vrai qu'elle est plutot maniaque" << endl << "(-4 suspicion, bonne reponse)" << endl;
			vieActuelle -= 4;
			break;
		case 2:
			cout << "Encore lui ?" << endl << "(+12 suspicion (questionnement))" << endl;
			vieActuelle += 15;
			break;
		case 3:
			cout << "Comment ca ???" << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
			break;
		default:
			cout << "Tu veux qu'on en parle de la tienne ?" << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
		}
		this_thread::sleep_for(chrono::seconds(3));
		system("cls");
	}
}

void question15(int randomQuestion, int& vieActuelle)
{
	if (randomQuestion == 15)
	{
		afficherBarreDeVie(vieActuelle, 100);
		cout << endl;

		int reponse15;
		cout << "Quelle est la chose qui te terrifie le plus ?" << endl;
		cout << endl;
		cout << "1. Les araignees.\n2. La couleur noire.\n3. Alex !\n4. Etre oublie.\n";
		cin >> reponse15;

		switch (reponse15)
		{
		case 1:
			cout << "Oh c'est vrai que c'est flippant" << endl << "(-4 suspicion, bonne reponse)" << endl;
			vieActuelle -= 4;
			break;
		case 2:
			cout << "Tu as peur de la couleur noire ?" << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
			break;
		case 3:
			cout << "OHHH PARLE MIEUX DE NOTRE FILLE LA NON MAIS TU T'ES CRU OU ?!" << endl << "(+18 suspicion (provoc.))" << endl;
			vieActuelle += 18;
			break;
		default:
			cout << "Mhh.. d'aaaccooord...." << endl << "(+15 suspicion)" << endl;
			vieActuelle += 15;
		}
		this_thread::sleep_for(chrono::seconds(3));
		system("cls");
	}
}//----------------------------QUESTION----------------------------------

int main()
{
	intro();

	//------------------INITIALISATION--------------------------
	int vieMax = 100;
	int vieActuelle = 0; // initialisez la vie actuelle à 0
	int questionsPosees[15] = { 0 }; // tableau pour suivre les questions deja posees, initialisee a 0
	int questionCompteur = 0; // compteur pour savoir si victoire ou non
	string familleHeureuse = "Heureux.txt"; // initialisation .txt
	string SuspectMeter = "suspect-meter.txt"; // texte suspect meter
	//------------------INITIALISATION--------------------------

	while (vieActuelle > 0 && vieActuelle < 100)		// Est sensé bloquer à 0 et 100
	{
		if (vieActuelle < 0) {
			vieActuelle = 0;
		}
		else if (vieActuelle > 100) {
			vieActuelle = 100;
		}
	}

	for (int i = 0; i < 15; ++i)
	{
		questionsPosees[i] = 0; // verification pour savoir si la question a deja ete posee
	}
	do
	{
		int randomQuestion = aleatoire(questionsPosees, 15); // passer le tableau des questions deja posees et leur taille
		questionsPosees[randomQuestion - 1] = randomQuestion; // mettre à jour le tableau avec la nouvelle question

		////-------AFFICHAGE IMAGE----------
		//ifstream fichier(familleHeureuse);
		//string ligne;
		//while (getline(fichier, ligne))
		//{
		//	cout << ligne << endl;
		//}
		////-------AFFICHAGE IMAGE----------

		//-------AFFICHAGE IMAGE----------
		ifstream fichier(SuspectMeter);
		string ligneSusMeter;
		while (getline(fichier, ligneSusMeter))
		{
			cout << ligneSusMeter << endl;
		}
		//-------AFFICHAGE IMAGE----------
		cout << endl;

		question1(randomQuestion, vieActuelle);
		question2(randomQuestion, vieActuelle);
		question3(randomQuestion, vieActuelle);
		question4(randomQuestion, vieActuelle);
		question5(randomQuestion, vieActuelle);
		question6(randomQuestion, vieActuelle);
		question7(randomQuestion, vieActuelle);
		question8(randomQuestion, vieActuelle);
		question9(randomQuestion, vieActuelle);
		question10(randomQuestion, vieActuelle);
		question11(randomQuestion, vieActuelle);
		question12(randomQuestion, vieActuelle);
		question13(randomQuestion, vieActuelle);
		question14(randomQuestion, vieActuelle);
		question15(randomQuestion, vieActuelle);

		questionCompteur++;
		fichier.close(); // fermeture image

	} while (questionCompteur < 15); // continuer tant que la vie actuelle est inferieur a 100 OU on joue les 15 questions		// vieActuelle < vieMax &&

	//cout << "Vous etes cramer par la famille !" << endl; // defaite, on est suspect aupres de la famille (avant la fin des 15 questions)

	if (questionCompteur == 15) // si 15 questions ont ete poser, alors on regarde si le joueur gagne ou non, si son score est au dessus de 50, alors c'est win
	{
		if (vieActuelle < 0)		// Dernier check hors truc
		{
			vieActuelle = 0;
		}
		else if (vieActuelle > 100)
		{
			vieActuelle = 100;
		}

		srand(time(0));
		vieActuelle = rand() % 100; //random sur 100%



		if (vieActuelle < 50) // si ca ne depasse pas 50, c'est win
		{
			system("cls");
			cout << vieActuelle << " / 50" << endl;
			cout << "Vous avez reussi a voler l'identite de l'ancien copain, et vous etes passe inapercu, vous avez gagne !" << endl;
			return 0;
		}
		else // sinon c'est loose
		{
			system("cls");
			cout << vieActuelle << " / 50" << endl;
			cout << "Tu as ete trop suspect ! La famille s'est inquietee et a appele la police. Vous avez perdu !" << endl;
			return 0;
		}
	}


	// Message pour Remi, plus jamais un groupe comme ca :/ On a tout donner mais bon, on etait que 2 pour coder... (et lancer le groupe)
	return 0;
}