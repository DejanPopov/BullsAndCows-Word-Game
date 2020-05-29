#include <iostream> 
#include <string>


using namespace std;

//Prototypes
void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
string GetGuess();

//The entry point of application
int main() 
{
	PrintIntro();
	PlayGame();
	AskToPlayAgain();
	return 0;
}

void PlayGame()
{
	//loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		string Guess = GetGuess();
		cout << "Your guess was: " << Guess << endl;
		cout << endl;
	}
}

bool AskToPlayAgain()
{
	cout << "DO you want to play again?";
	string Response = "";
	getline(cin, Response);
	cout << "First char" << (Response[0] == 'y');
	cout << endl;
	return false;
}

//Introduce the game
void PrintIntro() 
{
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows!\n";
	std::cout << "Hello There!" << std::endl;
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}

//Gets guess from player and repeat guess back to them
string GetGuess() 
{
	cout << "Enter your guess: ";
	string Guess = "";
	cin >> Guess; 
	getline(cin, Guess);
	return Guess;
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


//---------------------------------------------LOOPS-----------------------------------------------------------

// FOR LOOPS ---> Kada znamo koliko puta hocemo da se ponovi

// for (initialization; condition; increse)
//      promenljjiva; uslov; koliko puta se ponavlja;

// for (int count = 1; count <= limmit; count++) {
	// <the code you want to repeat>
// }



// WHOLE LOOPS ---> Kada ne znamo koliko puta ce se ponovi nesto

//---------------------------------------------LOOPS-----------------------------------------------------------

//---------------------------------------------BOOLEAN---------------------------------------------------------

// Pise se bool ---> Moze biti True ili False


//---------------------------------------------BOOLEAN---------------------------------------------------------

