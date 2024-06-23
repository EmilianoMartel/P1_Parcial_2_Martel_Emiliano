#include "Character.h"

Character::Character() 
{
    
}

Character::~Character() {

}

vector<string> Character::splitByNewline(const string& str) {
    vector<string> result;
    istringstream stream(str);
    string line;
    while (getline(stream, line)) {
        result.push_back(line);
    }
    return result;
}

void Character::move(Vector2 input) {
	position.X += input.X;
	position.Y += input.Y;
}

void Character::draw() {
    vector<string> tempView = splitByNewline(view);
    goToCoordinates(position.X, position.Y);

    for (size_t i = 0; i < tempView.size(); i++)
    {
        goToCoordinates(position.X, position.Y + i);
        cout << tempView[i];
    }
}