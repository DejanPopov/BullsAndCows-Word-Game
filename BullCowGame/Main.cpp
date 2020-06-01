/* This is the console executable taht make use of the BullCow class
This acts as the view of the MVC pattern , and is responsible for
all user interaction. For game logic see the FBullCowGame class.
*/
#pragma once

#include <iostream> 
#include <string>
#include "FBullCowGame.h"

// to make syntax Unreal friendly
using FText = std::string; 
using int32 = int;


//Function prototypes
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSUmmary();

FBullCowGame BCGame; // instantitate a new game, which we re-use all the time

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
	std::cout << "\n\Welcome to Bulls and Cows!\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();


	//loop asking for guess while the game is not won

	while (BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();

		// Submit valid guess to the game, and recieve the counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls << std::endl;
		std::cout << "Cows = " << BullCowCount.Cows << std::endl;
	}
	// TODO summarise game
	PrintGameSUmmary();
	return;
}



// loop continually until user get a valid guess
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		//get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";

		std::getline(std::cin, Guess);
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::OK:
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n";
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Lower_case:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		default:
			//assume guess is valid
			break;
		}
		std::cout << std::endl;
	} while (Status == EGuessStatus::OK); // Keep looping until we get no errors
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGameSUmmary() {
	if (BCGame.IsGameWon())
	{
		std::cout << "WELL DONE - YOU WIN!\n";
	}
	else
	{
		std::cout << "Better luck next time\n";
	}
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

//---------------------------------------------CONST-----------------------------------------------------------
//Const sluzi da se stavi u klasi kod metode koja je public i u konstruktoru
//Const znaci da ne mozemo da menjamo nista vise (Kao Final u Javi)
//Const ima drugacije znacenje kada se stavi ispred ili posle metode,ovo kada se ne menja nista stavlja se posle
//metode.
//---------------------------------------------CONST-----------------------------------------------------------

//---------------------------------------------CONSTRUCTOR-----------------------------------------------------
//U njega cemo da postavimo PRIVATE vrednosti koje smo pisali u klasi i onda cmeo da im dmao vrednost neku.
//---------------------------------------------CONSTRUCTOR-----------------------------------------------------

//---------------------------------------------TODO / TASK LIST - PSEUDOCODING---------------------------------
// Mozemo negde kao komentar napisati npr. //TODO need to add something.
// Kada odemo u View --> Task List izbacice nam dole Task Listu u koju su navedeni TODO i na njih mozemo 
//kliknuti da nas odvede do te linije koda u kojou smo stavili TODO i uradimo sta ssmo sebi stavili kao 
//podsetnik
//Pseudo programiranje moze najlakse biti u smislu komentara.Napisacemo sta nam treba i kako bi odradili
// u TODO i komentarima se ne pise programerski,nego recima izraziti sta zeliomo da uradimo ili objasnimo
// npr --->
//void PlayGame()
//{
//	BCGame.Reset();
//	int MaxTries = BCGame.GetMaxTries();
//
//
//	//loop for the number of turns asking for guesses
//	for (int count = 1; count <= MaxTries; count++)
//	{
//		FText Guess = GetGuess(); // TODO make loop checking valid guess
//
//		// Submit valid guess to the game
//		// Print number of bulls and cows
//
//
//		std::cout << "Your guess was: " << Guess << std::endl;
//		std::cout << std::endl;
//	}
//	// TODO summarise game
//}
//---------------------------------------------TODO / TASK LIST - PSEUDOCODING--------------------------------

//---------------------------------------------TYPE ALIASES FOR UNREAL ENGINE---------------------------------
// FString (ili string) ---> Je nesto sto je promenjlivo
// FText (isto string) ---> Je za user output / interaction
// int32 (ili int,integer) bio oznacavao kao da li je za x32bit OS ili za x64bit OS
// mozemo napisati gore ovako npr kod #include<>
// using FText = std::string;
// to ce nam gde kod da ima std::string zamenuti sa FText-om
//---------------------------------------------TYPE ALIASES FOR UNREAL ENGINE---------------------------------

//---------------------------------------------STRUCT---------------------------------------------------------
// Struct je isto sto i klasa ali su svi njeni elementi PUBLIC
//---------------------------------------------STRUCT---------------------------------------------------------

//---------------------------------------------IF / ELSE------------------------------------------------------
// if (condition1) {
//	statements;
//}else if (condition2) {
//	statements;
//}else {
//	statements;
//}
//
//---------------------------------------------IF / ELSE------------------------------------------------------

//---------------------------------------------DEBUGGING 101--------------------------------------------------
//
//---------------------------------------------DEBUGGING 101--------------------------------------------------

//---------------------------------------------SWITCH---------------------------------------------------------
// switch (expression)
// {
//	case statment1:
//		statement(s);
//		break;
//	case statment2:
//		statement(s);
//		break;
//	default:
//		statements(s);
//---------------------------------------------SWITCH---------------------------------------------------------




