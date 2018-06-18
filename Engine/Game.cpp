/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	gamepad = std::make_unique<DirectX::GamePad>();
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	auto state = gamepad->GetState(0);

	if (state.IsConnected())
	{
		float posx = state.thumbSticks.leftX;
		float posy = state.thumbSticks.leftY * -1;
		if (x >= 5 && x <= Graphics::ScreenWidth) {
			x += posx;
		}
		if (y >= 5 && y <= Graphics::ScreenHeight) {
			y += posy;
		}
	}
}

void Game::ComposeFrame()
{
	gfx.PutPixel(int(x - 5), int(y), Colors::Yellow);
	gfx.PutPixel(int(x - 4), int(y), Colors::Yellow);
	gfx.PutPixel(int(x - 3), int(y), Colors::Yellow);

	gfx.PutPixel(int(x + 5), int(y), Colors::Yellow);
	gfx.PutPixel(int(x + 4), int(y), Colors::Yellow);
	gfx.PutPixel(int(x + 3), int(y), Colors::Yellow);

	gfx.PutPixel(int(x), int(y - 5), Colors::Yellow);
	gfx.PutPixel(int(x), int(y - 4), Colors::Yellow);
	gfx.PutPixel(int(x), int(y - 3), Colors::Yellow);

	gfx.PutPixel(int(x), int(y + 5), Colors::Yellow);
	gfx.PutPixel(int(x), int(y + 4), Colors::Yellow);
	gfx.PutPixel(int(x), int(y + 3), Colors::Yellow);
}
