#include "Pickable.h"

Pickable::Pickable() {

}

Pickable::~Pickable() {

}

void Pickable::interact(Player* player) {
    
}

void Pickable::draw() {
    setForegroundColor(color);
    goToCoordinates(position.X, position.Y);
    cout << view;
}

bool Pickable::collisionCheck(Entity* entity) {
    Player* player = dynamic_cast<Player*>(entity);
    if (player) {
        interact(player);
        return true;
    }
    return false;
}