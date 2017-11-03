#include "Board.h"



Vec2 Board::GetDrawStartPos() {
	return{
		Window::Center().x - width * Tile::Size / 2,
		Window::Center().y - height * Tile::Size / 2,
	};
}


Board::Board()
{
	init().shuffle(100);
}


Board::~Board()
{
}


Board &Board::init() {
	uint32 number = 1;
	uint32 index = 0;
	for (size_t y = 0; y < height; y++)
	{
		for (size_t x = 0; x < width; x++)
		{
			if (y == 0 || y == height - 1 || x == 0 || x == width - 1) {
				tiles[index] = Tile()
					.setNumber(-1)
					.setPos({ x,y });
			}
			else {
				tiles[index] = Tile()
					.setNumber(number == (width - 2) * (height - 2) ? 0 : number)
					.setPos({ x, y });
				number++;
			}
			index++;
		}
	}
	return *this;
}


Board &Board::shuffle(uint32 count) {
	for (size_t i = 0; i < count; i++) {
		auto target = emptyTile().getPos();
		switch (Random(0, 3))
		{
		case 0:
			target.x++;
			break;
		case 1:
			target.x--;
			break;
		case 2:
			target.y++;
			break;
		case 3:
			target.y--;
			break;
		default:
			break;
		}
		MoveTile(target);
	}
	return *this;
}


void Board::update() {
	for (size_t y = 0; y < height; y++)
	{
		for (size_t x = 0; x < width; x++)
		{
			if (getPointTile({ x, y }).rect(GetDrawStartPos()).leftClicked) MoveTile({ x,y });
		}
	}
	keyInput();
}


void Board::draw() {
	for (size_t y = 0; y < height; y++)
	{
		for (size_t x = 0; x < width; x++)
		{
			getPointTile({ x, y })
				.draw(GetDrawStartPos());
		}
	}
}


void Board::keyInput() {
	if (!(Input::KeyUp | Input::KeyDown | Input::KeyLeft | Input::KeyRight).clicked) return;
	auto target = emptyTile().getPos();
	if (Input::KeyUp.clicked) {
		target.y++;
	}
	if (Input::KeyDown.clicked) {
		target.y--;
	}
	if (Input::KeyLeft.clicked) {
		target.x++;
	}
	if (Input::KeyRight.clicked) {
		target.x--;
	}
	MoveTile(target);
}


Tile &Board::findTile(uint32 number) {
	for (size_t i = 0; i < size; i++)
	{
		if (tiles[i].getNumber() == number) return tiles[i];
	}
}


Tile &Board::getPointTile(Vec2 pos) {
	for (size_t i = 0; i < size; i++)
	{
		if (tiles[i].getPos() == pos) return tiles[i];
	}
}


Tile &Board::emptyTile() {
	return findTile(0);
}


bool Board::MoveTile(Vec2 pos) {
	if (!getPointTile(pos).isNumber()) return false;
	if (
		getPointTile({ pos.x,pos.y - 1 }).isEmpty() ||
		getPointTile({ pos.x,pos.y + 1 }).isEmpty() ||
		getPointTile({ pos.x - 1,pos.y}).isEmpty() ||
		getPointTile({ pos.x + 1,pos.y}).isEmpty()
		) {
		getPointTile(pos).setPos(emptyTile().getPos());
		emptyTile().setPos(pos);
		return true;
	}
	return false;
}