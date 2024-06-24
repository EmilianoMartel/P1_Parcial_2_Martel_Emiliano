#include "Enemy.h"

Enemy::Enemy() {
	view = " X \n/|\\\n/ \\\n";
	color = Color::RED;
    width = 3;
    height = 3;
}

Enemy::~Enemy() {

}

bool Enemy::collisionCheck(Entity* entity) {
    Player* player = dynamic_cast<Player*>(entity);
    if (player) {
        player->changeLife(-1);
        return true;
    }
    return false;
}