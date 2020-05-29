#include <iostream> 
#include <string>


using namespace std;

//Prototypes
void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

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
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
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

//Gets guess from player and repeat guess back to them
string GetGuess()
{
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again? (y/n)";
	string Response = "";
	getline(cin, Response);
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

// Primer ---> return (Response[0] == 'y') || (Response[0] == 'Y'); 0 ili 1 (true ili false) kazemo da su isto sto i karakter kada se ukuca


//---------------------------------------------BOOLEAN---------------------------------------------------------


