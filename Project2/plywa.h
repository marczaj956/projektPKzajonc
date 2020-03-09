#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include<iostream>
#include <allegro5/allegro_acodec.h>
#include "plywa.h"
#include "player.h"
#include <Windows.h>

class plywa{
private:
	int pozycjax;
	int pozycjay;
protected:
	int zycie;
public:
	int getpozycjax() const { return pozycjax; }
	void setpozycjax(int pozycjax) { this->pozycjax = pozycjax; }
	int getpozycjay() const { return pozycjay; }
	void setpozycjay(int pozycjay) { this->pozycjay = pozycjay; }
	virtual int getzycie() { return 0; }
	void setzycie(int zycie) {
		this->zycie = zycie;
	}

	plywa(int pozycjax, int pozycjay) : pozycjax(pozycjax), pozycjay(pozycjay) {};

	static void narysujstatek(ALLEGRO_BITMAP* rysowanie_statek_funkcja, plywa ship);

	static void rozkladanie(plywa &ship, plywa &shipD, plywa &shipS,  ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_EVENT &event, ALLEGRO_BITMAP* rysowanie_statek_funkcja, ALLEGRO_BITMAP* rysowanie_destroyer_funkcja, ALLEGRO_BITMAP* rysowanie_stateczek_funkcja, ALLEGRO_BITMAP* plansza, player &gracz,ALLEGRO_BITMAP* ruch );

	static void strzelanie(plywa& ship1, plywa& shipD1, plywa& shipS1, plywa& ship2, plywa& shipD2, plywa& shipS2, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_EVENT& event, ALLEGRO_BITMAP* rysowanie_statek_funkcja, ALLEGRO_BITMAP* rysowanie_destroyer_funkcja, ALLEGRO_BITMAP* rysowanie_stateczek_funkcja, ALLEGRO_BITMAP* plansza, ALLEGRO_BITMAP* xtraf, ALLEGRO_BITMAP* strzal, player& gracz11, player& gracz22, ALLEGRO_SAMPLE* piupiu, ALLEGRO_SAMPLE* trafiony,ALLEGRO_BITMAP*ruch1, ALLEGRO_BITMAP*ruch2);
	
};
template<typename T>
class statek:public plywa
{
public:
	statek(T pozycjax, T pozycjay) : plywa(pozycjax, pozycjay) {this->zycie = 2;};
	int getzycie() override { return this->zycie; }
};
template<typename T>
class destroyer :public plywa
{
public:
	destroyer(T pozycjax, T pozycjay) : plywa(pozycjax,pozycjay) { this->zycie = 3; };
	int getzycie() override { return this->zycie ; }
};
template<typename T>
class stateczek :public plywa {
public:
	stateczek(T pozycjax, T pozycjay) : plywa(pozycjax, pozycjay) { this->zycie = 1; };
	int getzycie() override { return this->zycie; }
};

