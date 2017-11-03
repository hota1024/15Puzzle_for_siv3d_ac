#include <Siv3D.hpp>
#include "Board.h"

void Main()
{
	Board board;

	while (System::Update())
	{
		board.update();
		board.draw();
	}
}
