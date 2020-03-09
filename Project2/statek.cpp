#include "statek.h"

static void statek::narysujstatek(ALLEGRO_BITMAP* rysowanie_statek_funkcja, statek ship)
{
	al_draw_bitmap(rysowanie_statek_funkcja, ship.pozycjax * 100, ship.pozycjay * 100, 0);
	al_flip_display();
}
static void statek::rozkladanie(statek &ship, statek &shipD, statek &shipS, int x, int y, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_EVENT &event, ALLEGRO_BITMAP* rysowanie_statek_funkcja, ALLEGRO_BITMAP* rysowanie_destroyer_funkcja, ALLEGRO_BITMAP* rysowanie_stateczek_funkcja, ALLEGRO_BITMAP* plansza, player &gracz)

{
	bool rozkladanie = true;
	while (rozkladanie) {


		if (gracz.rozkladaniestatek == true) {
			al_draw_bitmap(plansza, 0, 0, 0);
			statek::narysujstatek(rysowanie_statek_funkcja, ship);
			al_flip_display();
			do {

				if (ship.pozycjax == 9) {
					ship.pozycjax = 100;
					std::cout << "podaj poprawna wartosc x" << std::endl;
				}

				al_wait_for_event(queue, &event);
				if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
				{

					x = event.mouse.x;
					y = event.mouse.y;
					std::cout << x / 100 << y / 100 << std::endl;

					ship.pozycjax = x / 100;
					ship.pozycjay = y / 100;

				}
			} while (ship.pozycjax == 9);
			if (event.type == ALLEGRO_EVENT_KEY_DOWN)
			{

				gracz.rozkladaniestatek = false;
				gracz.rozkladaniedestroyer = true;
				std::cout << "->destroyer" << std::endl;

			}
			al_flip_display();
		}

		if (gracz.rozkladaniedestroyer == true) {

			al_draw_bitmap(plansza, 0, 0, 0);
			statek::narysujstatek(rysowanie_statek_funkcja, ship);
			statek::narysujstatek(rysowanie_destroyer_funkcja, shipD);
			al_flip_display();
			do
			{
				if (shipD.pozycjax == 8 || ((shipD.pozycjay == ship.pozycjay) && ((shipD.pozycjax == ship.pozycjax) || (shipD.pozycjax + 1 == ship.pozycjax) || (shipD.pozycjax + 2 == ship.pozycjax))) || ((shipD.pozycjay == ship.pozycjay) && ((shipD.pozycjax == ship.pozycjax + 1) || (shipD.pozycjax + 1 == ship.pozycjax + 1) || (shipD.pozycjax + 2 == ship.pozycjax + 1))))
				{
					shipD.pozycjax = 100;
					std::cout << "podaj poprawna wartosc x" << std::endl;
				}
				al_wait_for_event(queue, &event);

				if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
				{

					x = event.mouse.x;
					y = event.mouse.y;
					std::cout << x / 100 << y / 100 << std::endl;

					shipD.pozycjax = x / 100;
					shipD.pozycjay = y / 100;




				}
			} while (shipD.pozycjax == 8 || ((shipD.pozycjay == ship.pozycjay) && ((shipD.pozycjax == ship.pozycjax) || (shipD.pozycjax + 1 == ship.pozycjax) || (shipD.pozycjax + 2 == ship.pozycjax))) || ((shipD.pozycjay == ship.pozycjay) && ((shipD.pozycjax == ship.pozycjax + 1) || (shipD.pozycjax + 1 == ship.pozycjax + 1) || (shipD.pozycjax + 2 == ship.pozycjax + 1))));


			if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
				gracz.rozkladaniestateczek = true;
				gracz.rozkladaniedestroyer = false;
				std::cout << "->stateczek" << std::endl;

			}
			al_flip_display();
		}

		if (gracz.rozkladaniestateczek == true) {

			al_flip_display();
			al_draw_bitmap(plansza, 0, 0, 0);
			statek::narysujstatek(rysowanie_statek_funkcja, ship);
			statek::narysujstatek(rysowanie_destroyer_funkcja, shipD);
			statek::narysujstatek(rysowanie_stateczek_funkcja, shipS);
			al_flip_display();
			do
			{
				if ((((shipS.pozycjay == ship.pozycjay) && ((shipS.pozycjax == ship.pozycjax) || (shipS.pozycjax == ship.pozycjax + 1))) || (shipS.pozycjay == shipD.pozycjay) && ((shipS.pozycjax == shipD.pozycjax) || (shipS.pozycjax == shipD.pozycjax + 1) || (shipS.pozycjax == shipD.pozycjax + 2))))
				{
					shipS.pozycjax = 100;
					std::cout << "podaj poprawna wartosc x" << std::endl;
				}
				al_wait_for_event(queue, &event);

				if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
				{

					x = event.mouse.x;
					y = event.mouse.y;
					std::cout << x / 100 << y / 100 << std::endl;

					shipS.pozycjax = x / 100;
					shipS.pozycjay = y / 100;


				}
			} while ((((shipS.pozycjay == ship.pozycjay) && ((shipS.pozycjax == ship.pozycjax) || (shipS.pozycjax == ship.pozycjax + 1))) || (shipS.pozycjay == shipD.pozycjay) && ((shipS.pozycjax == shipD.pozycjax) || (shipS.pozycjax == shipD.pozycjax + 1) || (shipS.pozycjax == shipD.pozycjax + 2))));

			if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
				rozkladanie = false;
				std::cout << "KONIEC ROZKLADANIA" << std::endl;;
				if (gracz.nrgracza == 1) {
					std::cout << "nastepuje tura GRACZA2" << std::endl;
				}
				else std::cout << "pora na strzelanie" << std::endl;
			}
			al_flip_display();
		}






	}
}

