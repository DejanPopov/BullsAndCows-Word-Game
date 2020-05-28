#include <iostream> //# je preprocessor direktiva , #include dodaje druge kodove , <> se koristi za standardne biblioteke
#include <string> // Ovo se dodaje za upis korisnika u racunar,ali radi cin >> i bez ovoga,mozda je staro

using namespace std; //Ako ovde dodamo namespace onda ne moramo to kucati (Linija 19 primer)

/*Sintaksa funkcije C++*/

//int DoubleMe(int number) {
//	return number * 2;
//}

// <tip funkcije> _ <ime funkcije> (<tip funkcije + ime promenljive>) {
//  <statments>
//}

int main()  // Main metoda kao u Javi!
{
	//INTRODUCE THE GAME
	constexpr int WORD_LENGTH = 5; //Ovo se koristi kada ne zelimo da menjamo nesto (Final int brojNeki = 5; --> Mislim da je ovako u Javi)

	std::cout << "Welcome to Bulls and Cows!\n"; //std znaci standard namspace, cout je ispis na ekran , << znaci uzmi sta je sa desne strane i stavi u levu stranu.
	std::cout << "Hello There!" << std::endl; //moze i ovako kao konaktenacija
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram?\n"; // Ovde smo iskoristili konstantu i ovako se vrsi konkatenacija (/n doesnt flush output buffer)
	cout << endl;


	//GET A GUESS FROM THE PLAYER
	cout << "Enter your guess";
	string Guess = ""; //Definisemo promenljivu, a string je prazan jer nema guess value
	cin >> Guess; //cin je kao Scanner iz Jave,omogucava da se upise nesto

	//REPEAT THE GUESS BACK TO THEM
	cout << "Your guess was: " << Guess << endl;
	cout << endl;
	return 0;
}



