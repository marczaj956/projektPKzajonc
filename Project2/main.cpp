#include "plywa.h"
#include "player.h"
#include<Windows.h>

using namespace std;




int main()
{
	//stworzenie wskaŸników biblioteki graficznej aby mozna bylo dodac dzwieki obraz itd.
	ALLEGRO_DISPLAY* display; 
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_BITMAP* plansza1;
	ALLEGRO_BITMAP* rysujstatek;
	ALLEGRO_BITMAP* gracz1ruch;
	ALLEGRO_BITMAP*  gracz2ruch;
	ALLEGRO_BITMAP*  strzal;
	ALLEGRO_BITMAP*  rysujdestroyer;
	ALLEGRO_BITMAP* rysujstateczek;
	ALLEGRO_BITMAP* xtraf;
	ALLEGRO_EVENT event;
	ALLEGRO_SAMPLE* mlg = NULL;
	ALLEGRO_SAMPLE* bum = NULL;
	ALLEGRO_SAMPLE_INSTANCE* sampleInstance = NULL;

	al_init();
	display = al_create_display(1000, 1000);//stworzenie grafiki 1000x1000 pixeli
	queue = al_create_event_queue();//stworzenie kolejki dla biblioteki graficznej
	//istalacja oraz zarezerwowanie zmiennych dla danych obrazkow oraz dzwiekow
	al_install_mouse();
	al_install_audio();
	al_init_image_addon();
	al_install_keyboard();
	al_init_acodec_addon();
	al_reserve_samples(2);
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_mouse_event_source());
	plansza1 = al_load_bitmap("plansza.PNG");
	rysujstatek = al_load_bitmap("statek.PNG");
	rysujdestroyer = al_load_bitmap("destroyer.PNG");
	rysujstateczek = al_load_bitmap("stateczek.PNG");
	strzal = al_load_bitmap("x.JPG");
	xtraf = al_load_bitmap("xtraf.JPG");
	mlg = al_load_sample("mlg.wav");
	bum = al_load_sample("bum.wav");
	gracz1ruch = al_load_bitmap("gracz1.PNG");
	gracz2ruch = al_load_bitmap("gracz2.PNG");
	
	//stworzenie obiektow (statkow oraz gracza)
	statek<int> g1s1(100, 0);
	statek<int>  g2s1(100, 0);
	destroyer<int>  g1s2(200, 0);
	destroyer<int>  g2s2(200, 0);
	stateczek<int>  g1s3(300, 0);
	stateczek<int>  g2s3(300, 0);
	player gracz1(true, false, false, 1, true); //kolejnosc wartosci boolowskich odpowiada kolejnosci rozkladania statkow dla poszczegolnego gracza a wartosc na koncu mowi czyja jest kolej (zaczyna rozkladac gracz pierwszy od pierwszego statku)
	player gracz2(true, false, false, 2, false);
	al_draw_bitmap(plansza1, 0, 0, 0);//rysowanie planszy 
	al_flip_display();//wyrzucenie na ekran tego co zostalo narysowane
	al_wait_for_event(queue, &event);//oczekiwanie na wydarzenie (np wcisniecie myszki)
	cout << "g1->statek" << endl; //wyswietlenie do kosnoli pomocniczej co nastepuje
	plywa::rozkladanie(g1s1, g1s2, g1s3, queue, event, rysujstatek, rysujdestroyer, rysujstateczek, plansza1, gracz1, gracz1ruch);
	plywa::rozkladanie(g2s1, g2s2, g2s3,  queue, event, rysujstatek, rysujdestroyer, rysujstateczek, plansza1, gracz2, gracz2ruch);
	plywa::strzelanie(g1s1, g1s2, g1s3, g2s1, g2s2, g2s3, queue, event, rysujstatek, rysujdestroyer, rysujstateczek, plansza1, xtraf, strzal, gracz1, gracz2,mlg,bum,gracz1ruch,gracz2ruch);
	
	
}