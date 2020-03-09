#include "plywa.h"
void plywa::rozkladanie(plywa &ship, plywa &shipD, plywa &shipS,  ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_EVENT &event, ALLEGRO_BITMAP* rysowanie_statek_funkcja, ALLEGRO_BITMAP* rysowanie_destroyer_funkcja, ALLEGRO_BITMAP* rysowanie_stateczek_funkcja, ALLEGRO_BITMAP* plansza, player &gracz,ALLEGRO_BITMAP* ruch)

	{
		int x, y; //wartosc do ktorej zostanie przechwycona z pozycji myszy
		x = 101;//zmiana na 101 aby drugi gracz nie znal ostatniej lokalizjacji pierwszego gracza
		y = 101;//zmiana na 101 aby drugi gracz nie znal ostatniej lokalizjacji pierwszego gracza
		bool rozkladanie = true;//wejscie w petle rozkladania
		while (rozkladanie) {


			if (gracz.getrozkladaniestatek() == true) {//sprawdzenie na ktory statek pora rozkladania
				al_draw_bitmap(plansza, 0, 0, 0);
				
				plywa::narysujstatek(rysowanie_statek_funkcja, ship);//rysowanie statku na planszy
				al_draw_bitmap(ruch, 400, 0, 0);//rysowanie komunikatu o kolejnosci gracza
				al_flip_display();
				do {

					if (ship.pozycjax == 9) {//nie mozna postawic bo statek wystaje za mape
						ship.pozycjax = 100;//zmiana wartosci po ktorej dalej oczekujemy na probe postawienie statku
					
						std::cout << "Nie mozna go tutaj polozyc" << std::endl;
					}

					al_wait_for_event(queue, &event);
					if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)//po wcisnieciu myszy zostanie wczytana wartosc x,y na ekranie
					{

						x = event.mouse.x;
						y = event.mouse.y;
					

						ship.pozycjax = x / 100;//ustawienie pozycji statku na wartosc x
						ship.pozycjay = y / 100;//ustawienie pozycji statku na wartosc y

					}
				} while (ship.pozycjax == 9);//sparwdzenie czy mozna postawic
				if (event.type == ALLEGRO_EVENT_KEY_DOWN)//po wcisnieciu klawisza zostanie zapisana pozycja statku i nastapi pora rozkladania drugiego statku
				{

					gracz.setrozkladaniestatek(false);
					gracz.setrozkladaniedestroyer(true);
					std::cout << "->destroyer" << std::endl;

				}
				al_flip_display();
			}

			if (gracz.getrozkladaniedestroyer() == true) {

				al_draw_bitmap(plansza, 0, 0, 0);
			
				plywa::narysujstatek(rysowanie_statek_funkcja, ship);
				plywa::narysujstatek(rysowanie_destroyer_funkcja, shipD);
				al_draw_bitmap(ruch, 400, 0, 0);
				al_flip_display();
				do
				{
					if (shipD.pozycjax == 8 || shipD.pozycjax == 9 || ((shipD.pozycjay == ship.pozycjay) && ((shipD.pozycjax == ship.pozycjax) || (shipD.pozycjax + 1 == ship.pozycjax) || (shipD.pozycjax + 2 == ship.pozycjax) || (shipD.pozycjax + 3 == ship.pozycjax))) || ((shipD.pozycjay + 1 == ship.pozycjay) && ((shipD.pozycjax == ship.pozycjax) || (shipD.pozycjax + 1 == ship.pozycjax) || (shipD.pozycjax + 2 == ship.pozycjax) || (shipD.pozycjax + 3 == ship.pozycjax))) || ((shipD.pozycjay - 1 == ship.pozycjay) && ((shipD.pozycjax == ship.pozycjax) || (shipD.pozycjax + 1 == ship.pozycjax) || (shipD.pozycjax + 2 == ship.pozycjax) || (shipD.pozycjax + 3 == ship.pozycjax))) || ((shipD.pozycjay == ship.pozycjay) && ((shipD.pozycjax == ship.pozycjax + 1) || (shipD.pozycjax + 1 == ship.pozycjax + 1) || (shipD.pozycjax == ship.pozycjax + 1) || (shipD.pozycjax == ship.pozycjax + 2))) || ((shipD.pozycjay + 1 == ship.pozycjay) && ((shipD.pozycjax == ship.pozycjax + 1) || (shipD.pozycjax + 1 == ship.pozycjax + 1) || (shipD.pozycjax + 2 == ship.pozycjax + 1) || (shipD.pozycjax == ship.pozycjax + 2)) || ((shipD.pozycjay - 1 == ship.pozycjay) && ((shipD.pozycjax == ship.pozycjax + 1) || (shipD.pozycjax + 1 == ship.pozycjax + 1) || (shipD.pozycjax + 2 == ship.pozycjax + 1) || (shipD.pozycjax == ship.pozycjax + 2)))))
					{//warunek aby drugi statek nie byl obok lub na innym statku oraz aby nie wychodzil poza pole mapy
						shipD.pozycjax = 100;
						std::cout <<"Nie mozna go tutaj polozyc" << std::endl;
					}
					al_wait_for_event(queue, &event);

					if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
					{

						x = event.mouse.x;
						y = event.mouse.y;
						

						shipD.pozycjax = x / 100;
						shipD.pozycjay = y / 100;




					}
				} while (shipD.pozycjax == 8 || shipD.pozycjax == 9|| ((shipD.pozycjay == ship.pozycjay) && ((shipD.pozycjax == ship.pozycjax) || (shipD.pozycjax + 1 == ship.pozycjax) || (shipD.pozycjax + 2 == ship.pozycjax) || (shipD.pozycjax + 3 == ship.pozycjax))) || ((shipD.pozycjay + 1 == ship.pozycjay) && ((shipD.pozycjax == ship.pozycjax) || (shipD.pozycjax + 1 == ship.pozycjax) || (shipD.pozycjax + 2 == ship.pozycjax) || (shipD.pozycjax + 3 == ship.pozycjax))) || ((shipD.pozycjay - 1 == ship.pozycjay) && ((shipD.pozycjax == ship.pozycjax) || (shipD.pozycjax + 1 == ship.pozycjax) || (shipD.pozycjax + 2 == ship.pozycjax) || (shipD.pozycjax + 3 == ship.pozycjax))) || ((shipD.pozycjay == ship.pozycjay) && ((shipD.pozycjax == ship.pozycjax + 1) || (shipD.pozycjax + 1 == ship.pozycjax + 1) || (shipD.pozycjax == ship.pozycjax + 1) || (shipD.pozycjax == ship.pozycjax + 2))) || ((shipD.pozycjay + 1 == ship.pozycjay) && ((shipD.pozycjax == ship.pozycjax + 1) || (shipD.pozycjax + 1 == ship.pozycjax + 1) || (shipD.pozycjax + 2 == ship.pozycjax + 1) || (shipD.pozycjax == ship.pozycjax + 2)) || ((shipD.pozycjay - 1 == ship.pozycjay) && ((shipD.pozycjax == ship.pozycjax + 1) || (shipD.pozycjax + 1 == ship.pozycjax + 1) || (shipD.pozycjax + 2 == ship.pozycjax + 1) || (shipD.pozycjax == ship.pozycjax + 2)))));

				if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
					gracz.setrozkladaniestateczek(true);
					gracz.setrozkladaniedestroyer(false);
					std::cout << "->stateczek" << std::endl;

				}
				al_flip_display();
			}

			if (gracz.getrozkladaniestateczek() == true) {

				al_flip_display();
				al_draw_bitmap(plansza, 0, 0, 0);
				
				plywa::narysujstatek(rysowanie_statek_funkcja, ship);
				plywa::narysujstatek(rysowanie_destroyer_funkcja, shipD);
				plywa::narysujstatek(rysowanie_stateczek_funkcja, shipS);
				al_draw_bitmap(ruch, 400, 0, 0);
				al_flip_display();
				do
				{
					if ((((shipS.pozycjay == ship.pozycjay) && ((shipS.pozycjax == ship.pozycjax) || (shipS.pozycjax == ship.pozycjax + 1) || (shipS.pozycjax == ship.pozycjax + 2) || (shipS.pozycjax == ship.pozycjax - 1)) || (shipS.pozycjay == shipD.pozycjay) && ((shipS.pozycjax == shipD.pozycjax) || (shipS.pozycjax == shipD.pozycjax + 1) || (shipS.pozycjax == shipD.pozycjax + 2) || (shipS.pozycjax == shipD.pozycjax + 3) || (shipS.pozycjax == shipD.pozycjax + -1))) || (((shipS.pozycjay - 1 == ship.pozycjay) && ((shipS.pozycjax == ship.pozycjax) || (shipS.pozycjax == ship.pozycjax + 1) || (shipS.pozycjax == ship.pozycjax + 2) || (shipS.pozycjax == ship.pozycjax - 1)) || (shipS.pozycjay - 1 == shipD.pozycjay) && ((shipS.pozycjax == shipD.pozycjax) || (shipS.pozycjax == shipD.pozycjax + 1) || (shipS.pozycjax == shipD.pozycjax + 2) || (shipS.pozycjax == shipD.pozycjax + 3) || (shipS.pozycjax == shipD.pozycjax - 1))) || (((shipS.pozycjay + 1 == ship.pozycjay) && ((shipS.pozycjax == ship.pozycjax) || (shipS.pozycjax == ship.pozycjax + 1) || (shipS.pozycjax == ship.pozycjax + 2) || (shipS.pozycjax == ship.pozycjax - 1)) || (shipS.pozycjay + 1 == shipD.pozycjay) && ((shipS.pozycjax == shipD.pozycjax) || (shipS.pozycjax == shipD.pozycjax + 1) || (shipS.pozycjax == shipD.pozycjax + 2) || (shipS.pozycjax == shipD.pozycjax + 3) || (shipS.pozycjax == shipD.pozycjax - 1)))))))
					{
						shipS.pozycjax = 100;
						std::cout <<"Nie mozna go tutaj polozyc" << std::endl;
					}
					al_wait_for_event(queue, &event);

					if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
					{

						x = event.mouse.x;
						y = event.mouse.y;
						

						shipS.pozycjax = x / 100;
						shipS.pozycjay = y / 100;


					}
				} while ((((shipS.pozycjay == ship.pozycjay) && ((shipS.pozycjax == ship.pozycjax) || (shipS.pozycjax == ship.pozycjax + 1) || (shipS.pozycjax == ship.pozycjax + 2) || (shipS.pozycjax == ship.pozycjax - 1)) || (shipS.pozycjay == shipD.pozycjay) && ((shipS.pozycjax == shipD.pozycjax) || (shipS.pozycjax == shipD.pozycjax + 1) || (shipS.pozycjax == shipD.pozycjax + 2) || (shipS.pozycjax == shipD.pozycjax + 3) || (shipS.pozycjax == shipD.pozycjax + -1))) || (((shipS.pozycjay - 1 == ship.pozycjay) && ((shipS.pozycjax == ship.pozycjax) || (shipS.pozycjax == ship.pozycjax + 1) || (shipS.pozycjax == ship.pozycjax + 2) || (shipS.pozycjax == ship.pozycjax - 1)) || (shipS.pozycjay - 1 == shipD.pozycjay) && ((shipS.pozycjax == shipD.pozycjax) || (shipS.pozycjax == shipD.pozycjax + 1) || (shipS.pozycjax == shipD.pozycjax + 2) || (shipS.pozycjax == shipD.pozycjax + 3) || (shipS.pozycjax == shipD.pozycjax - 1))) || (((shipS.pozycjay + 1 == ship.pozycjay) && ((shipS.pozycjax == ship.pozycjax) || (shipS.pozycjax == ship.pozycjax + 1) || (shipS.pozycjax == ship.pozycjax + 2) || (shipS.pozycjax == ship.pozycjax - 1)) || (shipS.pozycjay + 1 == shipD.pozycjay) && ((shipS.pozycjax == shipD.pozycjax) || (shipS.pozycjax == shipD.pozycjax + 1) || (shipS.pozycjax == shipD.pozycjax + 2) || (shipS.pozycjax == shipD.pozycjax + 3) || (shipS.pozycjax == shipD.pozycjax - 1)))))));

				if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
					rozkladanie = false;//koniec rozkladania
					std::cout << "KONIEC ROZKLADANIA" << std::endl;
					if (gracz.getnrgracza() == 1) {//jesli rozkladal gracz 1 to rozklada gracz 2 a jesli inaczej to pora na strzelanie
						std::cout << "nastepuje tura GRACZA2" << std::endl;
					}
					else std::cout << "pora na strzelanie" << std::endl;
				}
				al_flip_display();
			}
		}
	}
void plywa::narysujstatek(ALLEGRO_BITMAP* rysowanie_statek_funkcja, plywa ship)
	{
		al_draw_bitmap(rysowanie_statek_funkcja, ship.pozycjax * 100, ship.pozycjay * 100, 0);
		al_flip_display();
	}
void plywa::strzelanie(plywa& ship1, plywa& shipD1, plywa& shipS1, plywa& ship2, plywa& shipD2, plywa& shipS2, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_EVENT& event, ALLEGRO_BITMAP* rysowanie_statek_funkcja, ALLEGRO_BITMAP* rysowanie_destroyer_funkcja, ALLEGRO_BITMAP* rysowanie_stateczek_funkcja, ALLEGRO_BITMAP* plansza, ALLEGRO_BITMAP* xtraf, ALLEGRO_BITMAP* strzal, player& gracz11, player& gracz22, ALLEGRO_SAMPLE* piupiu, ALLEGRO_SAMPLE* trafiony,ALLEGRO_BITMAP*ruch1, ALLEGRO_BITMAP*ruch2)
{
	try {//wyjatki
		bool niekoniec = true;
		int g1strzal[10][10];
		int g2strzal[10][10];
		int g1x, g1y, g2x, g2y;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				g2strzal[i][j] = 0;
				g1strzal[i][j] = 0;
			}
		}
		//tablica w ktorej wszysktie pola sa rowne 0 



		while (niekoniec)
		{
			if (gracz11.gettura() == true)//sprawdzenie czyja tura
			{




				al_draw_bitmap(plansza, 0, 0, 0);
			
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						if (g1strzal[i][j] == 2) {
							al_draw_bitmap(xtraf, i * 100, j * 100, 0);

						}
						if (g1strzal[i][j] == 1) {
							al_draw_bitmap(strzal, i * 100, j * 100, 0);
						}

					}
				}
				//rozmieszczenie niebieskich i czerwonych X w zalesnoci od tego czy zostal tam tafiony czy nietrafiony statek


				al_wait_for_event(queue, &event);

				if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
				{

					g1x = event.mouse.x / 100;
					g1y = event.mouse.y / 100;
				
					if (g1strzal[g1x][g1y] != 1 && g1strzal[g1x][g1y] != 2)//jesli gracz tu jeszcze nie strzelil to:
					{
						g1strzal[g1x][g1y] = 1;




						if ((g1x == ship2.getpozycjax() && g1y == ship2.getpozycjay()) || (g1x == ship2.getpozycjax() + 1 && g1y == ship2.getpozycjay()))//sprawdzenie czy nie trafil w dany statek
						{
							ship2.setzycie(ship2.getzycie() - 1);//zabranie zycia danemu statkowi
							std::cout << "trafiony statek, pozostalo zyc: " << ship2.getzycie() << std::endl;
							g1strzal[g1x][g1y] = 2;//ustawienie wartosci na tablicy na trafiona
							al_play_sample(trafiony, 1.0, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);//odtworzenie dzwieku trafienie

						}
						else if ((g1x == shipD2.getpozycjax() && g1y == shipD2.getpozycjay()) || (g1x == shipD2.getpozycjax() + 1 && g1y == shipD2.getpozycjay()) || (g1x == shipD2.getpozycjax() + 2 && g1y == shipD2.getpozycjay()))
						{
							shipD2.setzycie(shipD2.getzycie() - 1);
							std::cout << "trafiony destroyer, pozostalo zyc: " << shipD2.getzycie() << std::endl;
							g1strzal[g1x][g1y] = 2;
							al_play_sample(trafiony, 1.0, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
						}
						else if ((g1x == shipS2.getpozycjax() && g1y == shipS2.getpozycjay()))
						{
							shipS2.setzycie(0);
							std::cout << "trafiony stateczek, zatopiony!" << std::endl;
							g1strzal[g1x][g1y] = 2;
							al_play_sample(trafiony, 1.0, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
						}
						gracz22.settura(true);//zmiana strzelajacego
						gracz11.settura(false);
						
						std::cout << "=>g2" << std::endl;

					}
					else {//jesli juz tu strzelil to:
						std::cout << "juz strzeliles";
					}
				}

				if (ship2.getzycie() + shipD2.getzycie() + shipS2.getzycie() == 0) { niekoniec = false; }//sprawdzenie zyc statkow
				al_draw_bitmap(ruch1, 400, 0, 0);
				al_flip_display();

			}
			if (gracz22.gettura() == true)
			{



				al_draw_bitmap(plansza, 0, 0, 0);
				
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						if (g2strzal[i][j] == 2) {
							al_draw_bitmap(xtraf, i * 100, j * 100, 0);

						}
						if (g2strzal[i][j] == 1) {
							al_draw_bitmap(strzal, i * 100, j * 100, 0);
						}
					}
				}

				al_wait_for_event(queue, &event);

				if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
				{
					g2x = event.mouse.x / 100;
					g2y = event.mouse.y / 100;
					//std::cout << g2x << g2y << std::endl;
					if (g2strzal[g2x][g2y] != 1 && g2strzal[g2x][g2y] != 2)
					{


						g2strzal[g2x][g2y] = 1;



						al_draw_bitmap(strzal, g2x * 100, g2y * 100, 0);
						if ((g2x == ship1.getpozycjax() && g2y == ship1.getpozycjay()) || (g2x == ship1.getpozycjax() + 1 && g2y == ship1.getpozycjay()))
						{
							ship1.setzycie(ship1.getzycie() - 1);
							std::cout << "trafiony statek, pozostalo zyc: " << ship1.getzycie() << std::endl;
							al_play_sample(trafiony, 1.0, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
							g2strzal[g2x][g2y] = 2;
						}
						else if ((g2x == shipD1.getpozycjax() && g2y == shipD1.getpozycjay()) || (g2x == shipD1.getpozycjax() + 1 && g2y == shipD1.getpozycjay()) || (g2x == shipD1.getpozycjax() + 2 && g2y == shipD1.getpozycjay()))
						{
							shipD1.setzycie(shipD1.getzycie() - 1);
							std::cout << "trafiony destroyer, pozostalo zyc: " << shipD1.getzycie() << std::endl;
							al_play_sample(trafiony, 1.0, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
							g2strzal[g2x][g2y] = 2;
						}
						else if ((g2x == shipS1.getpozycjax() && g2y == shipS1.getpozycjay()))
						{
							shipS1.setzycie(0);
							std::cout << "trafiony stateczek, zatopiony!" << std::endl;
							al_play_sample(trafiony, 1.0, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
							g2strzal[g2x][g2y] = 2;
						}
						gracz11.settura(true);
						gracz22.settura(false);
						std::cout << "=>g1" << std::endl;


					}
					else { std::cout << "juz tu strzeliles" << std::endl; }
				}
				if (ship1.getzycie() + shipD1.getzycie() + shipS1.getzycie() == 0) { niekoniec = false; }
				al_draw_bitmap(ruch2, 400, 0, 0);
				al_flip_display();

			}




		}


		if (ship1.getzycie() + shipD1.getzycie() + shipS1.getzycie() == 0) { throw - 1; }
		else { throw - 2; }//w zaleznosci od wygranej wyrzuca nam taka wartosc

		
		
	}
	catch (int code) { if (code == -1) { std::cout << "wygrywa gracz 2"; al_play_sample(piupiu, 1.0, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
	}
	if (code==-2) { std::cout << "wygrywa gracz 2"; al_play_sample(piupiu, 1.0, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
	}
	}//w zaleznosci od wygranego wyswietlana jest inna wiadomosc
	Sleep(10000);
	}