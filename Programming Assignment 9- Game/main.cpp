#include "Platform.h"
#include "Animation.h"

int main(void) {
	int masterValue = 0;
	do {
		
		while (masterValue == 0) {
			int selection = -1;

			cout << "	__________.__                      .__           .__       .___               " << endl;
			cout << "	\______   \  | _____    ____  ____ |  |__   ____ |  |    __| _/___________    " << endl;
			cout << "	 |     ___/  | \__  \ _/ ___\/ __ \|  |  \ /  _ \|  |   / __ |/ __ \_  __ \   " << endl;
			cout << "	 |    |   |  |__/ __ \\  \__\  ___/|   Y  (  <_> )  |__/ /_/ \  ___/|  | \/   " << endl;
			cout << "	 |____|   |____(____  /\___  >___  >___|  /\____/|____/\____ |\___  >__|      " << endl;
			cout << "						\/     \/    \/     \/                  \/    \/          " << endl;
			cout << "                                                                                 " << endl;
			cout << "								  By: Luke Schauble                               " << endl;
			cout << "						  1:Controls   2: Play    3:Quit                          " << endl;
			cin >> selection;
			if (selection == 1) {
				system("cls");
				masterValue = 1;
			}
			if (selection == 2) {
				system("cls");
				masterValue = 2;
			}
			if (selection == 3) {
				system("cls");
				masterValue = -1;
			}


		}
		while (masterValue == 1) {
			cout << "A: Move Left\nD:Move Right\n Space: Jump" << endl;
			system("pause");
			system("cls");
			masterValue = 0;
		}
		while (masterValue == 2) {
			sf::RenderWindow window(sf::VideoMode(1000, 500), "CPTS 122 Game", sf::Style::Close | sf::Style::Resize);
			sf::Texture backroundTexture;
			sf::Texture playerTexture;
			sf::Texture edgeTexture;
			sf::Texture platformTexture;
			backroundTexture.loadFromFile("backround.png");
			platformTexture.loadFromFile("platform.jpg");
			edgeTexture.loadFromFile("platform.jpg");
			playerTexture.loadFromFile("guy.png");
			Platform backround(&backroundTexture, sf::Vector2f(1000, 500), sf::Vector2f(500, 250));
			Player p1(&playerTexture, sf::Vector2u(6, 1), 0.2f, 200.0f, 100.f);



			vector<Platform> allPlatforms;
			allPlatforms.push_back(Platform(&platformTexture, sf::Vector2f(55.0f, 14.0f), sf::Vector2f(260.0f, 400.0f)));
			allPlatforms.push_back(Platform(&platformTexture, sf::Vector2f(55.0f, 14.0f), sf::Vector2f(450.0f, 350.0f)));
			allPlatforms.push_back(Platform(&platformTexture, sf::Vector2f(55.0f, 14.0f), sf::Vector2f(650.0f, 280.0f)));
			allPlatforms.push_back(Platform(&edgeTexture, sf::Vector2f(175, 200), sf::Vector2f(80, 440)));
			allPlatforms.push_back(Platform(&edgeTexture, sf::Vector2f(175, 200), sf::Vector2f(920, 440)));
			sf::Vector2f direction;

			Goal endGoal(12.f, sf::Color::Green, *(new sf::Vector2f(898, 305)));
			Goal endGoal2(10.f, sf::Color::Red, *(new sf::Vector2f(900, 307)));


			float dTime = 0.0f;
			sf::Clock clock;


			while (window.isOpen())
			{
				dTime = clock.restart().asSeconds();
				sf::Event move;
				while (window.pollEvent(move))
				{

					switch (move.type)
					{
					case sf::Event::Closed:
						window.close();
						break;
					}
				}

				p1.Update(dTime);

				for (int i = 0; i < allPlatforms.size(); i++) {

					Platform &platform = allPlatforms[i];
					if (platform.getCollision().checkCollision(p1.getColission(), direction, 1.0f)) {
						p1.canJumpAgain(direction);
					}
				}

				window.clear(sf::Color(0, 0, 128));
				backround.Draw(window);
				p1.draw(window);

				for (int i = 0; i < allPlatforms.size(); i++) {

					Platform &platform = allPlatforms[i];
					platform.Draw(window);
					platform.Draw(window);
					platform.Draw(window);
					platform.Draw(window);
					platform.Draw(window);
				}

				window.draw(endGoal);
				window.draw(endGoal2);
				window.display();


			}

			masterValue = 0;

		}



	}while (masterValue >= -1);

	return 0;
}