#include "Tile.h"



const int32 Tile::Size = 48;


Tile::Tile()
{
}


Tile::Tile(int32 number) : number(number)
{
}


Tile::~Tile()
{
}



void Tile::draw(Vec2 start) {
	if (number < 0) return;
	Rect((start + drawPos).asPoint(), Size).draw().drawFrame(1,0,Palette::Black);
	if (number == 0) return;
	font(number).drawAt(start + drawPos + Vec2(Size,Size) / 2, Palette::Black);
}



Rect Tile::rect(Vec2 start) {
	return Rect((start + drawPos).asPoint(), Size);
}


int32 Tile::getNumber() {
	return number;
}


Tile &Tile::setNumber(int32 number) {
	this->number = number;
	return *this;
}


Vec2 Tile::getPos() {
	return pos;
}


Tile &Tile::setPos(Vec2 pos) {
	this->pos = pos;
	this->drawPos = pos * Size;
	return *this;
}


bool Tile::isEmpty() {
	return number == 0;
}


bool Tile::isNumber() {
	return number > 0;
}