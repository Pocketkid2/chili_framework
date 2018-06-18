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

	float posx = 0.0;
	float posy = 0.0;

	if (state.IsConnected())
	{
		posx = state.thumbSticks.leftX * speed;
		posy = state.thumbSticks.leftY * -speed;
	}
	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		posy = -speed;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		posy = speed;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		posx = -speed;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		posx = speed;
	}

	x += posx;
	y += posy;
	if (x < float(size)) {
		x = float(size);
	}
	if (x > float(Graphics::ScreenWidth - (size + 1))) {
		x = float(Graphics::ScreenWidth - (size + 1));
	}
	if (y < float(size)) {
		y = float(size);
	}
	if (y > float(Graphics::ScreenHeight - (size + 1))) {
		y = float(Graphics::ScreenHeight - (size + 1));
	}
}

void Game::ComposeFrame()
{
	gfx.DrawCircle(int(x), int(y), size, Colors::Yellow);
}
