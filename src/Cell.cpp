#include "Cell.hpp"

/**
 * @brief return status of Cell
 * 
 * @return true Alive
 * @return false Dead
 */

bool Cell::getStatus() {
    return isAlive;
}

/**
 * @brief Change status of Cell
 * True = Alive
 * False = Dead
 * 
 * @param alive 
 */

void Cell::setStatus(bool alive) {
    this->isAlive = alive;
}