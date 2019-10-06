#include "Game.h"
//// author Dion Buckley
//
//#include "Game.h"
//#include <iostream>
//
//
//
//Game::Game() :
//	m_exitGame{false} //when true game will exit
//{
//	m_pressed = -1;
//	m_previousPressed = -1;
//	setupFontAndText(); // load font 
//	setupSprite(m_pressed);
//}
//
//
//Game::~Game()
//{
//}
//
///// <summary>
///// simple game loop to try to accomodate lag between elapsed time and time since update
///// </summary>
//void Game::run()
//{
//	sf::Clock clock;
//	sf::Time timeSinceLastUpdate = sf::Time::Zero;
//	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
//	while (m_window.isOpen())
//	{
//		processEvents(); // often as possible
//		timeSinceLastUpdate += clock.restart();
//		while (timeSinceLastUpdate > timePerFrame)
//		{
//			timeSinceLastUpdate -= timePerFrame;
//			processEvents(); // at least 60 fps
//			update(timePerFrame); //60 fps
//		}
//		render(); // often as possible
//	}
//}
///// <summary>
///// handle user and system events/ input
///// get key presses/ mouse moves etc. from OS
///// and user :: Don't do game update here
///// </summary>
//void Game::processEvents()
//{
//	sf::Event event;
//	while (m_window.pollEvent(event))
//	{
//		if ( sf::Event::Closed == event.type) // window message
//		{
//			m_window.close();
//		}
//		if (sf::Event::KeyPressed == event.type)
//		{
//			if (sf::Keyboard::Escape == event.key.code)
//			{
//				m_exitGame = true;
//			}
//
//			switch (event.key.code)
//			{
//			case sf::Keyboard::A:
//				m_pressed = 0;
//				break;
//			case sf::Keyboard::D:
//				m_pressed = 1;
//				break;
//			case sf::Keyboard::W:
//				m_pressed = 2;
//				break;
//			case sf::Keyboard::E:
//				m_pressed = 3;
//				break;
//			case sf::Keyboard::Q:
//				m_pressed = 4;
//				break;
//			case sf::Keyboard::Space:
//				m_pressed = 5;
//				break;
//			default:
//				break;
//			}
//		}
//		if (sf::Event::KeyReleased == event.type)
//		{
//			if (m_previousState.A)
//			{
//				m_pressed = 0;
//			}
//			else if (m_previousState.D)
//			{
//				m_pressed = 1;
//			}
//			else if (m_previousState.W)
//			{
//				m_pressed = 2;
//			}
//			else if (m_previousState.Q)
//			{
//				m_pressed = 4;
//			}
//			else if (m_previousState.E)
//			{
//				m_pressed = 3;
//			}
//		}
//	}
//}
//
///// <summary>
///// Update the game world
///// </summary>
///// <param name="t_deltaTime">time interval per frame</param>
//void Game::update(sf::Time t_deltaTime)
//{
//	/// <summary>
//	/// All of this is simply so I could be very specific as to when we are idle or not
//	/// And also to hold previous state for multiple key presses
//	/// </summary>
//	/// <param name="t_deltaTime"></param>
//	m_previousState = m_currentState;
//	m_currentState.A = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
//	m_currentState.D = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
//	m_currentState.W = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
//	m_currentState.Q = sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
//	m_currentState.E = sf::Keyboard::isKeyPressed(sf::Keyboard::E);
//	m_currentState.Space = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
//	if (!m_currentState.A && !m_currentState.D && !m_currentState.E && !m_currentState.Q && !m_currentState.Space && !m_currentState.W)
//	{
//		m_pressed = -1;
//	}
//	///////////////////////////////////////////////////////
//	
//	switch (m_pressed)
//	{
//	case 0:
//		fsm.walking();
//		break;
//	case 1:
//		fsm.walking();
//		break;
//	case 2:
//		fsm.jumping();
//		break;
//	case 3:
//		fsm.shovelling();
//		break;
//	case 4:
//		fsm.hammering();
//		break;
//	case 5:
//		fsm.swording();
//		break;
//	case -1:
//		fsm.idle();
//		break;
//	default:
//		break;
//	}
//	setupSprite(m_pressed); // load texture
//
//
//	if (m_exitGame)
//	{
//		m_window.close();
//	}
//}
//
///// <summary>
///// draw the frame and then switch bufers
///// </summary>
//void Game::render()
//{
//	m_window.clear(sf::Color::White);
//	m_window.draw(m_welcomeMessage);
//	m_window.draw(m_playerSprite);
//	m_window.display();
//}
//
///// <summary>
///// load the font and setup the text message for screen
///// </summary>
//void Game::setupFontAndText()
//{
//	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
//	{
//		std::cout << "problem loading arial black font" << std::endl;
//	}
//	m_welcomeMessage.setFont(m_ArialBlackfont);
//	m_welcomeMessage.setString("FSM:\nW to Jump\nA for Left\nD for Right\nQ for Hammer\nE for Shovel\nSpaceBar for Sword");
//	m_welcomeMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
//	m_welcomeMessage.setPosition(40.0f, 40.0f);
//	m_welcomeMessage.setCharacterSize(40);
//	m_welcomeMessage.setOutlineColor(sf::Color::Red);
//	m_welcomeMessage.setFillColor(sf::Color::Black);
//	m_welcomeMessage.setOutlineThickness(3.0f);
//
//}
//
///// <summary>
///// load the texture and setup the sprite for the logo
///// </summary>
////void Game::setupSprite(int t_pressed)
////{
////	switch (t_pressed)
////	{
////	case 0:
////		if (!m_playerTexture.loadFromFile("ASSETS\\IMAGES\\WALKING_LEFT.png"))
////		{
////			// simple error message if previous call fails
////			std::cout << "problem loading walking texture" << std::endl;
////		}		
////		break;
////	case 1:
////		if (!m_playerTexture.loadFromFile("ASSETS\\IMAGES\\WALKING_RIGHT.png"))
////		{
////			// simple error message if previous call fails
////			std::cout << "problem loading walking texture" << std::endl;
////		}
////		break;
////	case 2:
////		if (!m_playerTexture.loadFromFile("ASSETS\\IMAGES\\JUMPING.png"))
////		{
////			// simple error message if previous call fails
////			std::cout << "problem loading walking texture" << std::endl;
////		}
////		break;		
////	case 3:
////		if (!m_playerTexture.loadFromFile("ASSETS\\IMAGES\\SHOVELLING.png"))
////		{
////			// simple error message if previous call fails
////			std::cout << "problem loading SHOVELLING texture" << std::endl;
////		}
////		break;
////	case 4:
////		if (!m_playerTexture.loadFromFile("ASSETS\\IMAGES\\HAMMERING.png"))
////		{
////			// simple error message if previous call fails
////			std::cout << "problem loading HAMMERING texture" << std::endl;
////		}
////		break;
////	case 5:
////		if (!m_playerTexture.loadFromFile("ASSETS\\IMAGES\\SWORDING.png"))
////		{
////			// simple error message if previous call fails
////			std::cout << "problem loading SWORDING texture" << std::endl;
////		}
////		break;
////	case -1:
////		if (!m_playerTexture.loadFromFile("ASSETS\\IMAGES\\IDLE.png"))
////		{
////			// simple error message if previous call fails
////			std::cout << "problem loading idle texture" << std::endl;
////		}		
////		break;
////	default:
////		break;
////	}
////	m_playerSprite.setTexture(m_playerTexture);
////
////
////}

Game::Game()
{
}

Game::~Game()
{
}

void Game::run()
{
}
