#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
#include <string.h>

#include<vector>
#include<algorithm>

using namespace std;

class camera {
public:
	int main_camera;
	int front_camera;
public:
	camera();
	camera(int main_camer);
	camera(int main, int front);
	~camera();
	void input();
	void print();


};
camera::camera() {}
camera::camera(int main)
{
	this->main_camera = main;
}
camera::camera(int main, int front) {
	this->main_camera = main;
	this->front_camera = front;
}
camera::~camera() = default;
void camera::input() {
	cout << "Камера(Мп)" << endl << "Введите разрешение главной камеры: ";
	cin >> main_camera;
	cout << "Введите разрешение фронтальной камеры: ";
	cin >> front_camera;
}
void camera::print() {
	cout << "Разрешение гл. камеры - " << main_camera << " Мп, фронтальной - " << front_camera << " Мп.\n";
}



class battery
{
public:
	int capacity;
	string type;
	string types[3] = { "Li-Ion","NIMH", "NiCd" };

	battery();
	battery(int v);
	battery(int v, string type);
	~battery();

	void input();
	void print();

};
battery::battery() {}
battery::battery(int v)
{
	this->capacity = v;
}
battery::battery(int v, string t) {
	this->capacity = v;
	this->type = t;
}
battery::~battery() = default;
void battery::input() {
	cout << "Батарея(мАч)" << endl << "Введите емкость батареи: ";
	cin >> capacity;
	cout << "Введите тип батареи: ";
	cin >> type;
}
void battery::print() {
	cout << "Емкость батареи - " << capacity << " мАч, тип батареи - " << type << "." << endl;
}



class memory
{
private:
	int ram;
	int rom;
public:
	memory();
	memory(int rom);
	memory(int ram, int rom);
	~memory();
	void input();
	void print();
};
memory::memory() {}
memory::memory(int rom) { this->rom = rom; }
memory::memory(int ram, int rom) { this->ram = ram; this->rom = rom; }
memory::~memory() = default;
void memory::input() {
	cout << "Память(Гб)" << endl << "Введите объем основной памяти: ";
	cin >> rom;
	cout << "Введите объем оперативной памяти: ";
	cin >> ram;
}
void memory::print() {
	cout << "Объем основной памяти - " << ram << " Гб, объем основной памяти - " << rom << " Гб." << endl;
}



class screen {
public:
	float diagonal;
	string type;
	string types[3] = { "IPS","AMOLED","OLED" };

	screen();
	screen(float dia);
	screen(float dia, string type);
	~screen();
	void input();
	void print();
};
screen::screen() {}
screen::screen(float dia) {
	this->diagonal = dia;
}
screen::screen(float dia, string type) {
	this->diagonal = dia;
	this->type = type;
}
screen::~screen() = default;
void screen::input() {
	cout << "Экран" << endl << "Введите диагональ экрана(Дм): ";
	cin >> diagonal;
	cout << "Введите тип экрана: ";
	cin >> type;
}
void screen::print() {
	cout << "Диагональ экрана - " << diagonal << " Дм, тип экрана - " << type << "." << endl;
}



class systema
{
private:
	string name;
	int version;
public:
	systema();
	systema(string name);
	systema(string name, int version);
	~systema();
	void input();
	void print();
};
systema::systema() {}
systema::systema(string name) { this->name = name; }
systema::systema(string name, int version) {
	this->name = name;
	this->version = version;
}
systema::~systema() = default;
void systema::input() {
	cout << "Операционая система" << endl << "Введите название системы: ";
	cin >> name;
	cout << "Введите версию о.системы: ";
	cin >> version;
}
void systema::print() {
	cout << "ОС - " << name << ", версия - " << version << "." << endl;
}



class smartphone {
protected:
	string name;
	camera camera_get;
	battery battery_get;
	memory memory_get;
	screen screen_get;
	systema system_get;
	static int number;
public:
	smartphone();
	smartphone(systema system_get);
	smartphone(string name, camera camera_get, battery battery_get, memory memory_get, screen screen_get, systema system_get);
	~smartphone();
	virtual void input();
	virtual void print();
	virtual void reset();
	void MaxCamera(int* max, smartphone s); void MinCamera(int& min, smartphone s); // Возвращение значения через указатель и ссылку
	void static num();
	void battery_status(smartphone s);
	void check(smartphone s);
	friend void PrintName(smartphone s);
};
int smartphone::number = 0;
smartphone::smartphone() {

	this->reset();

}
smartphone::smartphone(systema system_get) {
	this->system_get = system_get;
}
smartphone::smartphone(string name, camera camera_get, battery battery_get, memory memory_get, screen screen_get, systema system_get) {
	this->name = name;
	this->camera_get = camera_get;
	this->battery_get = battery_get;
	this->memory_get = memory_get;
	this->screen_get = screen_get;
	this->system_get = system_get;
}
smartphone::~smartphone() = default;
void smartphone::num() {
	cout << "Количество телефонов на складах = " << number << endl;
}
void smartphone::reset() {
	this->name = "";
	camera _camera = camera(0, 0);
	battery _battery = battery(0, "");
	memory _memory = memory(0, 0);
	screen _screen = screen(0, "");
	systema _system = systema("", 0);
	this->camera_get = _camera;
	this->battery_get = _battery;
	this->memory_get = _memory;
	this->screen_get = _screen;
	this->system_get = _system;
	if (number != 0)number--;
}
void smartphone::MaxCamera(int* max, smartphone s) {
	if (*max < this->camera_get.main_camera)*max = this->camera_get.main_camera;
}
void smartphone::MinCamera(int& min, smartphone s) {
	if (min == -1)min = s.camera_get.main_camera;
	if (min > s.camera_get.main_camera && s.camera_get.main_camera != 0)min = s.camera_get.main_camera;
}
void smartphone::input() {
	cout << "Введите данные!" << endl;
	cout << "Введите название: ";
	cin >> name;
	camera_get.input();
	battery_get.input();
	memory_get.input();
	screen_get.input();
	system_get.input();
	number++;
}
void smartphone::print() {
	cout << "Название модели - " << name << endl;
	camera_get.print();
	battery_get.print();
	memory_get.print();
	screen_get.print();
	system_get.print();
}
void smartphone::battery_status(smartphone s) {
	int month;
	cout << "Проверка емкости батареи." << endl << " Сколько месяцев прошло с покупки: ";
	cin >> month;
	cout << "Примерная емкость батареи - " << (this->battery_get.capacity - (this->battery_get.capacity / 100 * month)) << endl;
}
void smartphone::check(smartphone s) {
	printf("\nПроверка."); int choice; if (this->battery_get.type.compare("") == 0 && this->screen_get.type.compare("") == 0) {}
	else {
		if (this->battery_get.type.compare(this->battery_get.types[0]) == 0 || this->battery_get.type.compare(this->battery_get.types[1]) == 0 || this->battery_get.type.compare(this->battery_get.types[2]) == 0) {
		}
		else {
			cout << "Тип батареи не соответствует Li-Ion, NiCd, NIMH.\n Оставить(0) или изменить(1) тип: ";
			cin >> choice;
			if (choice) {
				cout << "Введите тип батареи:";
				cin >> this->battery_get.type;
			}
		}
		if (this->screen_get.type.compare(this->screen_get.types[0]) == 0 || this->screen_get.type.compare(this->screen_get.types[1]) == 0 || this->screen_get.type.compare(this->screen_get.types[2]) == 0) {}
		else {
			cout << "Тип экрана не соответствует IPS, AMOLED, OLED." << endl << " Оставить(0) или изменить(1) тип: ";
			cin >> choice;
			if (choice) {
				cout << "Введите тип экрана:";
				cin >> this->screen_get.type;
			}
		}
	}
	printf("Проверка завершена!\n");

}

class flagman { 
public:
	int price;
	int year;
	flagman(){}
	flagman(int price, int year) { this->price = price; this->year = year; }
	~flagman() {};
	void input() {
		cout << "Цена: " << endl;
		cin >> price;
		cout << "Год изготовления:" << endl;
		cin >> year;
	}
	void print() {
		cout << "Цена: " << price <<endl;
		cout << "Год изготовления:" <<year<< endl;

	}

};

class shop :public smartphone {
public:
	flagman fl;
	shop(flagman fl, string name, camera camera_get, battery battery_get, memory memory_get, screen screen_get, systema system_get) {
		this->fl = fl;
		this->name = name;
		this->camera_get = camera_get;
		this->battery_get = battery_get;
		this->memory_get = memory_get;
		this->screen_get = screen_get;
		this->system_get = system_get;

	}
	shop() {
		flagman _fl = flagman(0,0);
		reset();
		this->fl = _fl;
	}
	~shop() = default;

	void input() {
		cout << "Введите данные!" << endl;
		cout << "Введите название: ";
		cin >> name;
		camera_get.input();
		battery_get.input();
		memory_get.input();
		screen_get.input();
		system_get.input();
		fl.input();
		number++;
	}
	void print() {
		cout << "Название модели - " << name << endl;
		camera_get.print();
		battery_get.print();
		memory_get.print();
		screen_get.print();
		system_get.print();
		fl.print();

	}

};


void PrintName(smartphone s) {
	cout << s.name << endl;
}

int main() {
	vector<smartphone*>v;
	setlocale(LC_ALL, "ru");
	int n, max = 0, min = -1;

	do {
		cout << "Введите количество телефонов на складе(n>0): ";
		cin >> n;
	} while (n < 1);
	smartphone* sklad;
	for (int i = 0; i < n; i++) {
		sklad = new smartphone;
		cout << "Введите характеристики " << i + 1 << " модели:" << endl;
		sklad->input();
		v.push_back(sklad);
	}
	
	do {
		cout << "Введите количество телефонов в магазине(n>0): ";
		cin >> n;
	} while (n < 1);
	shop* mag;
	for (int i = 0; i < n; i++) {
		mag = new shop;
		cout << "Введите характеристики " << i + 1 << " модели:" << endl;
		mag->input();
		v.push_back(mag);
	}

	vector<smartphone*>::iterator it;
	for (it = v.begin(); it != v.end(); ++it)
	{
		(*it)->print();
	}

	cout << "Происходит сортировка!" << endl;

	sort(v.begin(), v.end());

	for (it = v.begin(); it != v.end(); ++it)
	{
		(*it)->print();
	}






}
