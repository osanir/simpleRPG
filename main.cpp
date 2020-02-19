#include <SFML/Graphics.hpp>
using namespace sf;
const int SPEED = 5;
int main(){
	RenderWindow window(VideoMode(800,600), "Hello");

	Texture texture;
	if(!texture.loadFromFile("resources/spriteWalk.png")){
		return EXIT_FAILURE;
	}
	
	Sprite player(texture);
	player.setPosition(window.getSize().x/2, window.getSize().y/2);
	player.setTextureRect(IntRect(0,0,64,64));
	int counter = 0;
	Vector2f movement;
	while(window.isOpen()){
		Event event;
		while(window.pollEvent(event)){
			if(event.type == Event::Closed){
				window.close();
			}
			if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape){
				window.close();
			}

			if(Keyboard::isKeyPressed(Keyboard::Left)){
				movement.x = -SPEED;
				player.setTextureRect(IntRect(counter++ * 64, 64 * 9,64,64));
			}
			if(Keyboard::isKeyPressed(Keyboard::Right)){
				movement.x = SPEED;
				player.setTextureRect(IntRect(counter++ * 64, 64 * 11,64,64));
			}
			if(Keyboard::isKeyPressed(Keyboard::Up)){
				movement.y = -SPEED;
				player.setTextureRect(IntRect(counter++ * 64, 64 * 8,64,64));
			}
			if(Keyboard::isKeyPressed(Keyboard::Down)){
				movement.y = SPEED;
				player.setTextureRect(IntRect(counter++ * 64, 64 * 10,64,64));
			}
			
		}
		if(counter >8){
			counter = 0;
		}
		player.move(movement);
		movement = {0,0};

		window.clear();
		window.draw(player);
		window.display();
	}

}