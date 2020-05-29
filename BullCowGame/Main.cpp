#include <iostream> 
#include <string>
#include "FBullCowGame.h"


//Prototypes
void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

//The entry point of application
int main() 
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);
	return 0;
}

//Introduce the game
void PrintIntro()
{
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows!\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	int MaxTries = BCGame.GetMaxTries();


	//loop for the number of turns asking for guesses
	for (int count = 1; count <= MaxTries; count++)
	{
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

//Gets guess from player and repeat guess back to them
std::string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();

	//get a guess from the player
	std::cout << "Try: " << CurrentTry << "Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}









//#include <iostream> //# je preprocessor direktiva , #include dodaje druge kodove , <> se koristi za standardne biblioteke
//#include <string> // Ovo se dodaje za upis korisnika u racunar,ali radi cin >> i bez ovoga,mozda je staro

//using namespace std; //Ako ovde dodamo namespace onda ne moramo to kucati (Linija 19 primer)

/*Sintaksa funkcije C++*/

//int DoubleMe(int number) {
//	return number * 2;
//}

// <tip funkcije> _ <ime funkcije> (<tip funkcije + ime promenljive>) {
//  <statments>
//}

//int main()  // Main metoda kao u Javi!
//{
	//INTRODUCE THE GAME
	//constexpr int WORD_LENGTH = 5; //Ovo se koristi kada ne zelimo da menjamo nesto (Final int brojNeki = 5; --> Mislim da je ovako u Javi)

	//std::cout << "Welcome to Bulls and Cows!\n"; //std znaci standard namspace, cout je ispis na ekran , << znaci uzmi sta je sa desne strane i stavi u levu stranu.
	//std::cout << "Hello There!" << std::endl; //moze i ovako kao konaktenacija
	//cout << "Can you guess the " << WORD_LENGTH << " letter isogram?\n"; // Ovde smo iskoristili konstantu i ovako se vrsi konkatenacija (/n doesnt flush output buffer)
	//cout << endl;


	//GET A GUESS FROM THE PLAYER
	//cout << "Enter your guess";
	//string Guess = ""; //Definisemo promenljivu, a string je prazan jer nema guess value
	//cin >> Guess; //cin je kao Scanner iz Jave,omogucava da se upise nesto. Ovde se nece koristiti jer ako se ukuca Donkey Kong ucitace oba umesto prvi samo
	//getline(cin, Guess); //cin je odakle dobijamo informaciju a Guess je gde je stavljamo

	//REPEAT THE GUESS BACK TO THEM
	//cout << "Your guess was: " << Guess << endl;
	//cout << endl;
	//return 0;

	//GET A GUESS FROM THE PLAYER
	//cout << "Enter your guess";
	//getline(cin, Guess); 

	//REPEAT THE GUESS BACK TO THEM
	//cout << "Your guess was: " << Guess << endl;
	//cout << endl;
	//return 0;

	//Abstraction --->  Apstrakcija je tehnika za kompleksnost
	//Encapsulation ---> Pravljenje funkcije od ovakvog koda
//}


//---------------------------------------------FOR LOOP--------------------------------------------------------
// FOR LOOPS ---> Kada znamo koliko puta hocemo da se ponovi
// for (initialization; condition; increse)
//      promenljjiva; uslov; koliko puta se ponavlja;

// for (int count = 1; count <= limmit; count++) {
	// <the code you want to repeat>
// }
//---------------------------------------------FOR LOOP--------------------------------------------------------

//---------------------------------------------DO & WHILE LOOP-------------------------------------------------

// WHOLE LOOPS ---> Kada ne znamo koliko puta ce se ponovi nesto
// do {
//	<the code you want to repeat>
// }
// while (condition);
//---------------------------------------------DO & WHILE LOOP-------------------------------------------------

//---------------------------------------------BOOLEAN---------------------------------------------------------
// Pise se bool ---> Moze biti True ili False
// Primer ---> return (Response[0] == 'y') || (Response[0] == 'Y'); 0 ili 1 (true ili false) kazemo da su isto 
//sto i karakter kada se ukuca
//---------------------------------------------BOOLEAN---------------------------------------------------------


//---------------------------------------------CLASSES---------------------------------------------------------
// u Solution Exploreru --> Desni klik na skroz gore gde su dva plusica --> Add --> New Item --> Header file
// Header file za Unreal Engine nazivamo kako hocemo ali mora pocinjati sa slovom F da se oznaci da je klasa u 
//pitanju.
//npr. nece biti BullAndCowGame nego FBullAndCowGame!
//Header file je u sustini blueprint gde ce se definisati klase (kolko hocemo klasa) i metode koje cemo posle 
//da pozivamo u Main.cpp
//Klasa ima PUBLIC i PRIVATE funkcije
//PRIVATE promenjlive su ispomoc PUBLICS funkcijama
// using namespace NIKADA ne koristiti u HEADER File-ovima!  npr. ---> (using namespace std;)
//ovde u Main.cpp se koristi samo za lakse pisanje ali ne bi trebalo UOPSTE da se koristi
// u HEADER file-u kliknemo desnim klikom na neku metodu ---> Quick Actions and Refactoring ---> Create
// Definition of "" in FBullCowGame.cpp i to ce nam napreviti jos jedan file u Solution Explorer-u
//kod Main.cpp i zvace se FBullCowGame.cpp
//---------------------------------------------CLASSES---------------------------------------------------------




