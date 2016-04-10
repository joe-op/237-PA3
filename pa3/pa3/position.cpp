#include "position.h"

/*
 * Default constructor for Position
 * Sets position to (0,0)
 * Input: None
 * Output: A Position object
 */
Position::Position() {
	xcoord = 0;
	ycoord = 0;
}
/*
 * Alternate constructor for Position
 * Input: two integers
 * Output: A Position object
 */
Position::Position(int xc, int yc) {
	xcoord = xc;
	ycoord = yc;
}
/*
 * Getter for x
 * Input: none
 * Output: integer
 */
int Position::x() const {
	return xcoord;
}
/*
 * Getter for y
 * Input: none
 * Output: integer
 */
int Position::y() const {
	return ycoord;
}
/*
 * Setter for x
 * Input: integer
 * Output: none
 */
void Position::set_x(int new_x) {
	xcoord = new_x;
}
/*
 * Setter for y
 * Input: integer
 * Output: none
 */
void Position::set_y(int new_y) {
	ycoord = new_y;
}
