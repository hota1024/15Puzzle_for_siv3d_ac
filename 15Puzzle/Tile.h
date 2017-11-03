#pragma once
#include <Siv3D.hpp>

class Tile
{
	int32 number;
	Font font{ Size / 2 };
	Vec2 drawPos;
	Vec2 pos;
public:
	Tile();
	Tile(int32 number);
	~Tile();

	const static int32 Size;

	void draw(Vec2 start);
	Rect rect(Vec2 start);

	int32 getNumber();
	Tile &setNumber(int32 number);

	Vec2 getPos();
	Tile &setPos(Vec2 pos);

	bool isEmpty();
	bool isNumber();
};

