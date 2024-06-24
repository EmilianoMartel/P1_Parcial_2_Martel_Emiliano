#include <iostream>
#include "AwesomeLibrary.h"
#include "GameManager.h"
using namespace std;

int main()
{
	GameManager gameManager = GameManager("Emiliano Martel", 25, 70, 10, 5);

	gameManager.Game();
}