#include "GeneralFunctions.h"

const char* TITLE_ART =
R"(
 __          __  ______ 
 \ \        / / |  ____|
  \ \  /\  / /  | |__   
   \ \/  \/ /   |  __|  
    \  /\  /    | |     
     \/  \/     |_|     
                        
                        
)";

int drawTitle() {
	drawFrame(X_COORDINATE_INIT, Y_COORDINATE_INIT, X_COORDINATE_FINAL, Y_COORDINATE_FINAL);
	istringstream iss(TITLE_ART);
	string line;
	int indexer = 0;
	while (getline(iss, line)) {
		indexer++;
		goToCoordinates(41, indexer);
		cout << line << endl;
	}
	return indexer;
}

bool intCheacker(string input) {
	if (input.size() == 0) {
		return false;
	}
	for (char c : input) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}

bool floatCheacker(string input) {
	istringstream isFloat(input);
	float f;
	if (isFloat >> f && isFloat.eof()) {
		return true;
	}
	else {
		return false;
	}
}

float quiestionWithFloatReturn(string question, int x, int y) {
	string input;
	bool inputValid = false;
	goToCoordinates(x, y);
	do
	{
		cout << question << endl;
		goToCoordinates(x, y + 1);
		getline(cin, input);

		inputValid = floatCheacker(input);

		if (inputValid) {
			return stoi(input);
		}
		else {
			goToCoordinates(x, y + 2);
			cout << "Invalid input, try again." << endl;
		}
	} while (!inputValid);
	return 0.f;
}

int questionWithIntReturn(string question, int x, int y) {
	string input;
	bool inputValid = false;
	do
	{
		goToCoordinates(x, y);
		cout << question << endl;
		goToCoordinates(x, y + 1);
		getline(cin, input);

		inputValid = intCheacker(input);

		if (inputValid) {
			return stoi(input);
		}
		else {
			goToCoordinates(x, y + 2);
			cout << "Invalid input, try again." << endl;
		}
	} while (!inputValid);
	return 0;
}

bool questionWithBoolReturn(string question, int x, int y) {
	string input;
	bool inputValid = false;
	goToCoordinates(x, y);
	do
	{
		cout << question << endl;
		goToCoordinates(x, y + 1);
		getline(cin, input);

		if (input == "Y" || input == "y" || input == "N" || input == "n") {
			inputValid = true;
		}
		else {
			goToCoordinates(x, y + 2);
			cout << "Invalid input. Try again." << endl;
		}
	} while (!inputValid);

	if (input == "Y" || input == "y") {
		return true;
	}
	return false;
}

void printData(string& lines, int x, int* startY) {
	system("cls");
	int y = *startY;
	y = drawTitle();
	istringstream iss(lines);
	string line;
	while (getline(iss, line)) {
		goToCoordinates(x, y);
		cout << line << endl;
		y++;
	}
	*startY = y;
}