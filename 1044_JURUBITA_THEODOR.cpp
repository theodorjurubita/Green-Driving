#include <iostream>
#include<fstream>
#include<vector>


using namespace std;

class caracteristici
{
private:

	char* model;
	char* motor;
	float max_speed;
	float cap_cil;
	float cons_mediu_urban;
	float vit_medie_urban;
	float cons_mediu;
	float vit_medie;

public:

	caracteristici& operator++(int);
	caracteristici& operator++();
	caracteristici& operator+(float);
	caracteristici& operator-(float);
	caracteristici& operator--(int);
	caracteristici& operator--();

	caracteristici(char* model, char* motor, float max_speed, float cap_cil, float cons_mediu_urban, float vit_medie_urban, float cons_mediu, float vit_medie)
	{
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
		this->motor = new char[strlen(motor) + 1];
		strcpy(this->motor, motor);
		this->max_speed = max_speed;
		this->cap_cil = cap_cil;
		this->cons_mediu_urban = cons_mediu_urban;
		this->vit_medie_urban = vit_medie_urban;
		this->cons_mediu = cons_mediu;
		this->vit_medie = vit_medie;
	}

	caracteristici()
	{
		this->model = new char[strlen("Miata") + 1];
		strcpy(this->model, "Miata");
		this->motor = new char[strlen("Diesel") + 1];
		strcpy(this->motor, "Diesel");
		this->max_speed = 100;
		this->cap_cil = 1999;
		this->cons_mediu_urban = 7;
		this->vit_medie_urban = 40;
		this->cons_mediu = 6;
		this->vit_medie = 80;
	}

	char* get_model();
	void set_model(char*);
	char* get_motor();
	void set_motor(char*);
	float get_cap_cil();
	void set_cap_cil(float);
	float get_cons_mediu_urban();
	void set_cons_mediu_urban(float);
	float get_vit_medie_urban();
	void set_vit_medie_urban(float);
	float get_cons_mediu();
	void set_cons_mediu(float);
	float get_vit_medie();
	void set_vit_medie(float);

	~caracteristici()
	{
		delete[]model;
		delete[]motor;

	}

	caracteristici(const caracteristici &temp)
	{
		this->model = new char[strlen(temp.model) + 1];
		strcpy(this->model, temp.model);
		this->motor = new char[strlen(temp.motor) + 1];
		strcpy(this->motor, temp.motor);
		this->max_speed = temp.max_speed;
		cap_cil = temp.cap_cil;
		this->cons_mediu_urban = temp.cons_mediu_urban;
		this->vit_medie_urban = temp.vit_medie_urban;
		this->cons_mediu = temp.cons_mediu;
		this->vit_medie = temp.vit_medie;
	}

	caracteristici operator =(caracteristici temp)
	{
		if (this->model != NULL)
			delete[]this->model;
		this->model = new char[strlen(temp.model) + 1];
		strcpy(this->model, temp.model);
		if (this->motor != NULL)
			delete[]this->motor;
		this->motor = new char[strlen(temp.motor) + 1];
		strcpy(this->motor, temp.motor);
		this->max_speed = temp.max_speed;
		this->cap_cil = temp.cap_cil;
		this->cons_mediu_urban = temp.cons_mediu_urban;
		this->vit_medie_urban = temp.vit_medie_urban;
		this->cons_mediu = temp.cons_mediu;
		this->vit_medie = temp.vit_medie;

		return *this;
	}

	friend ostream& operator << (ostream&, caracteristici);
	friend istream& operator >> (istream&, caracteristici&);
	friend ifstream& operator>>(ifstream&, caracteristici&);
	friend ofstream& operator<<(ofstream&, caracteristici);



};

//implementation section for caracteristici

ofstream& operator<<(ofstream& out, caracteristici temp)
{
	out << temp.model << endl;
	out << temp.motor << endl;
	out << temp.max_speed << endl;
	out << temp.cap_cil << endl;
	out << temp.cons_mediu_urban << endl;
	out << temp.vit_medie_urban << endl;
	out << temp.cons_mediu << endl;
	out << temp.vit_medie << endl;

	return out;
}

ifstream& operator>>(ifstream &in, caracteristici &temp)
{
	char aux1[25];
	char aux2[25];
	char x[25];
	delete[]temp.model;
	in >> aux1;
	temp.model = new char[strlen(aux1) + 1];
	strcpy(temp.model, aux1);
	in.ignore();
	in >> x;
	in >> aux2;
	delete[]temp.motor;
	temp.motor = new char[strlen(aux2) + 1];
	strcpy(temp.motor, aux2);
	in >> x;
	in >> temp.max_speed;
	in >> x;
	in >> temp.cap_cil;
	in >> x;
	in >> temp.cons_mediu_urban;
	in >> x;
	in >> temp.vit_medie_urban;
	in >> x;
	in >> temp.cons_mediu;
	in >> x;
	in >> temp.vit_medie;

	return in;

}

caracteristici& caracteristici::operator--()
{
	float a;
	a = cons_mediu - 1;
	cons_mediu = a;
	return*this;
}

caracteristici& caracteristici::operator--(int)
{
	cons_mediu = cons_mediu - 1;
	return *this;
}

caracteristici& caracteristici::operator++()
{
	float a;
	a = cons_mediu + 1;
	cons_mediu = a;
	return*this;
}

caracteristici& caracteristici::operator++(int)
{

	cons_mediu = cons_mediu + 1;
	return *this;
}

caracteristici& caracteristici :: operator-(float a)
{
	cap_cil = cap_cil - a;
	return*this;
}

caracteristici& caracteristici :: operator+(float a)
{
	cap_cil = cap_cil + a;
	return *this;

}

ostream& operator << (ostream& out, caracteristici tem)
{

	out << "Modelul este:" << tem.model << endl;

	out << "Motorul este:" << tem.motor << endl;
	
	out << "Viteza maxima este: " << tem.max_speed << endl;

	out << "Capacitatea cilindrica este:" << tem.cap_cil << endl;

	out << "Consumul mediu urban este:" << tem.cons_mediu_urban << endl;

	out << "Viteza medie urban este:" << tem.vit_medie_urban << endl;

	out << "Consumul mediu este:" << tem.cons_mediu << endl;

	out << "Viteza medie este:" << tem.vit_medie << endl;

	return out;
}

istream& operator >> (istream& in, caracteristici &temp)
{
	delete[]temp.model;
	char aux[20];
	cout << "Adaugati modelul: ";
	in >> aux;
	temp.model = new char[strlen(aux) + 1];
	strcpy(temp.model, aux);

	delete[]temp.motor;
	char auxx[20];
	cout << endl << "Adaugati motorul: ";
	in >> auxx;
	temp.motor = new char[strlen(auxx) + 1];
	strcpy(temp.motor, auxx);

	cout << endl << "Adaugati viteza maxima: ";
	in>>temp.max_speed;

	cout << endl << "Adaugati capacitatea cilindrica: ";
	in >> temp.cap_cil;

	cout << endl << "Adaugati consumul mediu urban: ";
	in >> temp.cons_mediu_urban;

	cout << endl << "Adaugati viteza medie urbana: ";
	in >> temp.vit_medie_urban;

	cout << endl << "Adaugati consumul mediu: ";
	in >> temp.cons_mediu;

	cout << endl << "Adaugati viteza medie: ";
	in >> temp.vit_medie;

	return in;



}


char* caracteristici::get_model()
{
	return model;
}

char* caracteristici::get_motor()
{
	return motor;
}

float caracteristici::get_cap_cil()
{
	return cap_cil;
}
float caracteristici::get_cons_mediu_urban()
{
	return cons_mediu_urban;
}

float caracteristici::get_vit_medie_urban()
{
	return vit_medie_urban;
}

float caracteristici::get_cons_mediu()
{
	return cons_mediu;
}

float caracteristici::get_vit_medie()
{
	return vit_medie;
}

void caracteristici::set_model(char* model)
{
	if (strlen(model)>2)
	{
		delete[]this->model;
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
	}
}
void caracteristici::set_motor(char* motor)
{
	if (strlen(motor)>2)
	{
		delete[]this->motor;
		this->motor = new char[strlen(motor) + 1];
		strcpy(this->motor, motor);
	}
}
void caracteristici::set_cap_cil(float cap_cil)
{
	if (cap_cil>0)
		this->cap_cil = cap_cil;
}
void caracteristici::set_cons_mediu_urban(float cons_mediu_urban)
{
	if (cons_mediu_urban>0)
		this->cons_mediu_urban = cons_mediu_urban;
}
void caracteristici::set_vit_medie_urban(float vit_medie_urban)
{
	if (vit_medie_urban>0)
		this->vit_medie_urban = vit_medie_urban;
}
void caracteristici::set_cons_mediu(float cons_mediu)
{
	if (cons_mediu>0)
		this->cons_mediu = cons_mediu;
}
void caracteristici::set_vit_medie(float vit_medie)
{
	if (vit_medie>0)
		this->vit_medie = vit_medie;
}



class automobil
{

protected:

	char* nume;
	const int id_number;
	static int nr_automobile;

public:

	char* get_nume();
	void set_nume(char*);
	int get_id_number();
	static int get_nr_automobile();




	automobil() :id_number(1)
	{
		this->nume = new char[strlen("auto1") + 1];
		strcpy(this->nume, "auto1");
		nr_automobile++;
	}

	automobil(char* nume, int val_id_number) :id_number(val_id_number)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		nr_automobile++;
	}

	~automobil()
	{
		delete[]nume;
		nr_automobile--;

	}

	automobil(automobil &temp) :id_number(temp.id_number)
	{
		this->nume = new char[strlen(temp.nume) + 1];
		strcpy(this->nume, temp.nume);
		nr_automobile++;

	}


	automobil operator=(automobil temp)
	{
		if (nume != NULL)
			delete[]nume;
		this->nume = new char[strlen(temp.nume) + 1];
		strcpy(this->nume, temp.nume);
		return *this;
	}


	friend ostream& operator<<(ostream&, automobil);
	friend istream& operator>>(istream&, automobil&);




};

//implementation section for automobil


int automobil::nr_automobile = 0;





ostream& operator<<(ostream& out, automobil temp)
{
	out << "Id-ul automobilului este: " << temp.id_number << endl;
	out << "Numele automobilului este: " << temp.nume << endl;
	return out;
}
istream & operator>>(istream& in, automobil &temp)
{
	char aux[20];
	/*cout<<"Introduceti un id pentru automobil: ";
	in>>temp.id_number;*/
	//cout << "Introduceti un nume pentru automobil: ";
	delete[] temp.nume;
	in >> aux;
	temp.nume = new char[strlen(aux) + 1];
	strcpy(temp.nume, aux);
	return in;

}



int automobil::get_nr_automobile()
{
	return nr_automobile;
}

char* automobil::get_nume()
{
	return nume;
}

void automobil::set_nume(char*nume)
{
	if (strlen(nume)>2) {
		delete[]this->nume;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}
}

int automobil::get_id_number()
{
	return id_number;
}

class turism :public automobil
{
protected:
	char* tip_turism;
	int nr_locuri;

public:
	
	turism();
	turism(char *nume, int val_id_number, char* tip_turism, int nr_locuri);
	~turism();
	turism(turism &temp);

	friend istream& operator>>(istream&, turism&);
	friend ostream& operator<<(ostream&, turism);
};

ostream& operator<<(ostream& out, turism temp)
{
	out << "Id-ul autoturismului este: " << temp.id_number << endl;
	out << "Numele autoturismului este: " << temp.nume << endl;
	out << "Tipul autoturismului este : " << temp.tip_turism << endl;
	out << "Numarul de locuri al autoturismului este: " << temp.nr_locuri << endl;
	return out;
}

istream& operator>>(istream& in, turism &temp)
{
	char aux[25];
	cout << "Introduceti numele automoturismului: ";
	in >> aux;
	delete[]temp.nume;
	temp.nume = new char[strlen(aux) + 1];
	strcpy(temp.nume, aux);
	cout << "Introduceti tip-ul autoturismului: ";
	in >> aux;
	delete[]temp.tip_turism;
	temp.tip_turism = new char[strlen(aux) + 1];
	strcpy(temp.tip_turism, aux);
	cout << "Introduceti nr de locuri: ";
	in >> temp.nr_locuri;
	return in;
}

turism::turism()
{
	this->nume = new char[strlen("auto1") + 1];
	strcpy(this->nume, "auto1");
	nr_automobile++;
	this->tip_turism = new char[strlen("tip1") + 1];
	strcpy(this->tip_turism, "tip1");
	nr_locuri = 4;
}

turism::turism(char* nume, int val_id_number, char* tip_turism, int nr_locuri) :automobil(nume, val_id_number)
{
	this->nume = new char[strlen(nume) + 1];
	strcpy(this->nume, nume);
	nr_automobile++;
	this->tip_turism = new char[strlen(tip_turism) + 1];
	strcpy(this->tip_turism, tip_turism);
	this->nr_locuri = nr_locuri;

}

turism::turism(turism &temp)
{

	this->nume = new char[strlen(temp.nume) + 1];
	strcpy(this->nume, temp.nume);
	nr_automobile++;
	this->tip_turism = new char[strlen(temp.tip_turism) + 1];
	strcpy(this->tip_turism, temp.tip_turism);
	this->nr_locuri = temp.nr_locuri;

}

turism::~turism()
{
	delete[]this->tip_turism;
	nr_automobile--;
}


class locatie
{
private:
	char* nume;
	double timp_utc;
	float latitude;
	float longitude;
	float viteza;


public:

	locatie operator-=(float);
	locatie operator*(float);
	locatie operator/(float);
	locatie operator +=(float);
	locatie operator *=(float);
	locatie& operator()(char* ,double,float, float, float, float);

	locatie(char* nume ,double timp_utc,float lat, float longi, float viteza)
	{
		this->nume = nume;
		this->timp_utc = timp_utc;
		this->latitude = lat;
		this->longitude = longi;
		this->viteza = viteza;
	}

	locatie()
	{
		this->nume = new char[strlen("auto0") + 1];
		strcpy(this->nume, "auto0");
		this->timp_utc = 0;
		this->latitude = 45;
		this->longitude = 45;
		this->viteza = 50;
	}

	locatie operator =(locatie temp);

	locatie(const locatie &temp)
	{

		this->nume = new char[strlen(temp.nume) + 1];
		strcpy(this->nume, temp.nume);
		this->timp_utc = temp.timp_utc;
		this->latitude = temp.latitude;
		this->longitude = temp.longitude;
		this->viteza = temp.viteza;
	}


	float get_viteza();
	void set_viteza(float);

	float get_latitude();
	void set_latitude(float);

	float get_longitude();
	void set_longitude(float);

	char* get_nume();




	~locatie()
	{
		delete[]nume;
	}

	friend ostream& operator<<(ostream&, locatie);
	friend istream& operator>>(istream&, locatie&);
	friend ifstream& operator>>(ifstream&, locatie&);
	friend ofstream& operator<<(ofstream&, locatie);


};



//implementation section for location

char* locatie::get_nume()
{
	return this->nume;
}

ofstream &operator<<(ofstream&out, locatie temp)
{
	out << temp.nume << endl;
	out << temp.timp_utc << endl;
	out << temp.latitude << endl;
	out << temp.longitude << endl;
	out << temp.viteza << endl;

	return out;
}

ifstream &operator>>(ifstream&in, locatie& temp)
{
	char aux[25];
	delete[] temp.nume;
	in >> aux;
	temp.nume = new char[strlen(aux) + 1];
	strcpy(temp.nume ,aux);
	in.ignore();
	in >> temp.timp_utc;
	in >> temp.latitude;
	in >> temp.longitude;
	in >> temp.viteza;
	return in;
}

locatie& locatie::operator()(char* num,double timp_ut,float lat, float longi, float ore, float distanta)
{
	nume = num;
	timp_utc = timp_ut;
	latitude = lat;
	longitude = longi;
	viteza = distanta / ore;
	return *this;
}

locatie locatie::operator *=(float a)
{
	viteza = viteza*a;
	return *this;
}

locatie locatie::operator-=(float a)
{
	viteza = viteza - a;
	return *this;
}

locatie locatie::operator+=(float a)
{
	viteza = viteza + a;
	return *this;
}

locatie locatie ::operator*(float a)
{
	locatie temp;
	temp.latitude = latitude;
	temp.longitude = longitude;
	temp.viteza = viteza*a;
	return temp;

}
locatie locatie ::operator /(float a)
{
	locatie temp;
	temp.latitude = latitude;
	temp.longitude = longitude;
	temp.viteza = viteza / a;
	return temp;

}


locatie locatie::operator=(locatie temp)
{
	delete[]this->nume;
	this->nume = new char[strlen(temp.nume) + 1];
	strcpy(this->nume ,temp.nume);
	this->timp_utc = temp.timp_utc;
	this->latitude = temp.latitude;
	this->longitude = temp.longitude;
	this->viteza = temp.viteza;

	return *this;
}


ostream& operator<<(ostream& out, locatie temp)
{
	out << "Numele autovehiculului este :" << temp.nume << endl;
	out << "Timpul in format UTC este: " << temp.timp_utc << endl;
	out << "Valoarea latitudinala este: " << temp.latitude << endl;
	out << "valoarea longitudinala este: " << temp.longitude << endl;
	out << "Viteza este: " << temp.viteza << endl;
	return out;
}

istream& operator>>(istream& in, locatie &temp)
{
	char aux[25];
	delete[]temp.nume;
	cout << "Introduceti numele autovehiculului: ";
	in >> aux;
	temp.nume = new char[strlen(aux) + 1];
	strcpy(temp.nume, aux);
	cout << "Introduceti momentul de timp in format UTC: ";
	in >> temp.timp_utc;
	cout << "Introduceti valoarea latitudinala:";
	in >> temp.latitude;
	cout << "Introduceti valoarea longitudinala:";
	in >> temp.longitude;
	cout << "Introduceti viteza:";
	in >> temp.viteza;

	return in;
}


float locatie::get_viteza()
{
	return viteza;
}

void locatie::set_viteza(float val_vit)
{
	if (val_vit>0)
		viteza = val_vit;
	else
		cout << "valoarea vitezei trebuie sa fie pozitiva!" << endl;
}



void locatie::set_latitude(float val_lat)
{
	if (val_lat >= 0 && val_lat <= 90)
		latitude = val_lat;
	else
		cout << "valoarea latitudinala introdusa este incorecta!" << endl;
}

float locatie::get_latitude()
{
	return latitude;
}

void locatie::set_longitude(float val_long)
{
	if (val_long >= 0 && val_long <= 180)
		longitude = val_long;
	else
		cout << "valoarea longitudinala introdusa este incorecta!" << endl;
}
float locatie::get_longitude()
{
	return longitude;

}


class echipare
{
private:

	int id_niveluri_echipare[2];
	int nr_dotari;
	char **dotari;

public:

	echipare();

	echipare(int id_niveluri_echipare[], int nr_dotari, char **dotari);



	int get_nr_dotari();
	void set_nr_dotari(int);

	friend ostream& operator<<(ostream&, echipare);
	friend istream& operator>>(istream&, echipare&);
	echipare operator=(echipare);
	echipare& operator [](int);
	echipare(echipare &);
	~echipare();


};

echipare::echipare(echipare &temp)
{
	for (int i = 0; i<2; i++)
		this->id_niveluri_echipare[i] = temp.id_niveluri_echipare[i];


	this->nr_dotari = temp.nr_dotari;

	this->dotari = new char*[temp.nr_dotari];

	for (int j = 0; j<temp.nr_dotari; j++)
	{
		this->dotari[j] = new char[strlen(temp.dotari[j]) + 1];
		strcpy(this->dotari[j], temp.dotari[j]);
	}

}

echipare::echipare()
{
	id_niveluri_echipare[0] = 10;
	id_niveluri_echipare[1] = 15;
	nr_dotari = 3;

	dotari = new char*[nr_dotari];

	for (int i = 0; i<nr_dotari; i++)
	{

		dotari[i] = new char[strlen(" ") + 1];
		strcpy(dotari[i], " ");
	}

}

//implementation section for echipare

echipare& echipare::operator[](int a) //schimbarea numarului de dotari si inlocuirea datelor
{
	char** temp;
	char aux[25];
	if (nr_dotari<a)
	{

		temp = new char*[a];

		for (int i = 0; i < nr_dotari; i++)
		{
			temp[i] = new char[strlen(dotari[i]) + 1];
			strcpy(temp[i], dotari[i]);
		}

		for (int i = nr_dotari; i < a; i++)
		{
			cout << "Introduceti dotarea cu numarul " << i + nr_dotari - 1 << ":";
			cin >> aux;
			temp[i] = new char[strlen(aux) + 1];
			strcpy(temp[i], aux);
		}
		for (int i = 0; i < nr_dotari; i++)
			delete dotari[i];
		delete dotari;
		dotari = new char*[a];
		for (int i = 0; i < a; i++)
		{
			dotari[i] = new char[strlen(temp[i]) + 1];
			strcpy(dotari[i], temp[i]);
		}

		for (int i = 0; i < a; i++)
			delete temp[i];
		delete temp;
	}
	else
		if (a < nr_dotari)
		{
			for (int i = a; i < nr_dotari; i++)
				delete dotari[i];
		}

	nr_dotari = a;
	return *this;


}

echipare::echipare(int id_niveluri_echipare[], int nr_dotari, char **dotari)
{
	for (int i = 0; i<2; i++)
		this->id_niveluri_echipare[i] = id_niveluri_echipare[i];
	this->nr_dotari = nr_dotari;
	this->dotari = new char*[this->nr_dotari];
	for (int j = 0; j<this->nr_dotari; j++)
	{
		this->dotari[j] = new char[strlen(dotari[j]) + 1];
		strcpy(this->dotari[j], dotari[j]);
	}


}

int echipare::get_nr_dotari()
{
	return nr_dotari;
}
void echipare::set_nr_dotari(int nr_dotar)
{
	if (nr_dotari>1)
		this->nr_dotari = nr_dotar;
	else
		cout << "Introduceti cel putin o dotare! ";
}


ostream& operator<<(ostream& out, echipare temp)
{
	for (int i = 0; i<2; i++)
		out << "Id-ul Nivelului de echipare " << i + 1 << " este " << temp.id_niveluri_echipare[i] << endl;
	out << "Automobilul are " << temp.nr_dotari << " dotari " << endl;

	for (int j = 0; j<temp.nr_dotari; j++)
		out << "Dotarea cu numarul " << j + 1 << " este " << temp.dotari[j] << endl;
	return out;

}


istream& operator>>(istream& in, echipare &temp)
{
	char aux[25];

	for (int i = 0; i<temp.nr_dotari; i++)
		delete[]temp.dotari[i];
	delete[]temp.dotari;

	for (int i = 0; i<2; i++)
	{
		cout << "Introduceti id-ul nivelului de echipare cu numarul " << i + 1 << ":";
		in >> temp.id_niveluri_echipare[i];
	}
	cout << "Introduceti numarul de dotari: ";
	in >> temp.nr_dotari;
	temp.dotari = new char*[temp.nr_dotari];
	for (int j = 0; j<temp.nr_dotari; j++)
	{
		cout << "Introduceti dotarea cu numarul " << j + 1 << ":";
		in >> aux;
		temp.dotari[j] = new char[strlen(aux) + 1];
		strcpy(temp.dotari[j], aux);
	}
	return in;

}

echipare echipare::operator=(echipare temp)
{
	for (int i = 0; i<nr_dotari; i++)
	{
		delete[]this->dotari[i];
	}
	delete[]this->dotari;


	for (int i = 0; i<2; i++)
		this->id_niveluri_echipare[i] = temp.id_niveluri_echipare[i];


	this->nr_dotari = temp.nr_dotari;

	this->dotari = new char*[temp.nr_dotari];

	for (int j = 0; j<temp.nr_dotari; j++)
	{
		this->dotari[j] = new char[strlen(temp.dotari[j]) + 1];
		strcpy(this->dotari[j], temp.dotari[j]);
	}

	return *this;
}

echipare::~echipare()
{
	for (int i = 0; i<nr_dotari; i++)
		delete[]this->dotari[i];
	delete[]this->dotari;
}



class anvelope

{
private:
	char *producator;
	char *tip;
	int dimensiune;
public:
	anvelope();
	anvelope(char*, char*, int);
	int get_dimensiune();
	char* get_producator();
	char* get_tip();
	void set_dimensiune(int);
	void set_tip(char*);
	void set_producator(char*);
	friend ostream& operator<<(ostream&, anvelope);
	friend istream& operator>>(istream&, anvelope&);
	anvelope(anvelope&);
	anvelope operator=(anvelope);
	~anvelope();

};

//implementation section for anvelope
anvelope::anvelope(char* producator, char *tip, int dimensiune)
{
	this->producator = new char[strlen(producator) + 1];
	strcpy(this->producator, producator);
	this->tip = new char[strlen(tip) + 1];
	strcpy(this->tip, tip);
	this->dimensiune = dimensiune;
}

anvelope::anvelope(anvelope &temp)
{
	this->dimensiune = temp.dimensiune;
	this->producator = new char[strlen(temp.producator) + 1];
	strcpy(this->producator, temp.producator);
	this->tip = new char[strlen(temp.tip) + 1];
	strcpy(this->tip, temp.tip);
}

anvelope::anvelope()
{
	producator = new char[strlen("GoodYear") + 1];
	strcpy(producator, "GoodYear");
	tip = new char[strlen("Mixt") + 1];
	strcpy(tip, "Mixt");
	dimensiune = 16;
}


char* anvelope::get_producator()
{
	return producator;
}
void anvelope::set_producator(char* temp)
{
	if (strlen(temp)>2)
	{
		delete[]this->producator;
		this->producator = new char[strlen(temp) + 1];
		strcpy(this->producator, temp);
	}
}

char* anvelope::get_tip()
{
	return tip;
}
void anvelope::set_tip(char* temp)
{
	if (strlen(temp)>2)
	{
		delete[]this->tip;
		this->tip = new char[strlen(temp) + 1];
		strcpy(this->tip, temp);
	}
}
int anvelope::get_dimensiune()
{
	return dimensiune;
}
void anvelope::set_dimensiune(int temp)
{
	this->dimensiune = temp;
}

ostream& operator<<(ostream& out, anvelope temp)
{
	out << "Producatorul este: " << temp.producator << endl;
	out << "Tipul anvelopelor este: " << temp.tip << endl;
	out << "Dimensiunea anvelopelor este: " << temp.dimensiune << endl;

	return out;
}

istream& operator>>(istream& in, anvelope &temp)
{
	char aux1[20];
	char aux2[20];
	int dim;
	delete[]temp.producator;
	cout << "Introduceti producatorul: ";
	in >> aux1;
	temp.producator = new char[strlen(aux1) + 1];
	strcpy(temp.producator, aux1);
	delete[]temp.tip;
	cout << "Introduceti tipul anvelopei: ";
	in >> aux2;
	temp.tip = new char[strlen(aux2) + 1];
	strcpy(temp.tip, aux2);
	cout << "Introduceti dimensiunea anvelopei: ";
	in >> dim;
	temp.dimensiune = dim;

	return in;
}
anvelope anvelope::operator=(anvelope temp)
{
	if (producator != NULL)
		delete[]producator;
	if (tip != NULL)
		delete[]tip;
	this->dimensiune = temp.dimensiune;
	this->producator = new char[strlen(temp.producator) + 1];
	strcpy(this->producator, temp.producator);
	this->tip = new char[strlen(temp.tip) + 1];
	strcpy(this->tip, temp.tip);
	return *this;
}

anvelope::~anvelope()
{
	delete[]producator;
	delete[]tip;

}

class geofence
{
private :
	char* tip;
	char* rest;
	float lat;
	float longi;
	float lat2;
	float longi2;
	float rad;

public:
	geofence();
	geofence(char*, char*, float, float, float, float, float);
	geofence(const geofence&);
	~geofence();

	geofence operator=(geofence temp);
	
	friend istream& operator>>(istream&, geofence&);
	friend ostream& operator<<(ostream&, geofence);
	friend ifstream& operator>>(ifstream&, geofence&);
	friend ofstream& operator<<(ofstream&, geofence);

};

//implementation section for geofence

ofstream& operator<<(ofstream& out, geofence temp)
{
	out << temp.tip << " ";
	out << temp.rest << " ";
	out << temp.lat << " ";
	out << temp.longi << " ";
	out << temp.lat2 << " ";
	out << temp.longi2 << " ";
	out << temp.rad << endl;

	return out;
}

geofence::geofence(char* tip, char* rest, float lat, float longi, float lat2, float longi2, float rad)
{
	this->tip = new char[strlen(tip) + 1];
	strcpy(this->tip, tip);
	this->rest = new char[strlen(rest) + 1];
	strcpy(this->rest,rest);
	this->lat = lat;
	this->longi = longi;
	this->lat2 = lat2;
	this->longi2 = longi2;
	this->rad = rad;
}

geofence::geofence()
{
	tip = new char[strlen("cerc") + 1];
	strcpy(tip, "cerc");
	rest = new char[strlen("rosu") + 1];
	strcpy(rest, "rosu");
	lat = 0;
	longi = 0;
	lat2 = 0;
	longi2 = 0;
	rad = 0;
}

geofence::geofence(const geofence &temp)
{
	tip = new char[strlen(temp.tip) + 1];
	strcpy(tip, temp.tip);
	rest = new char[strlen(temp.rest) + 1];
	strcpy(rest, temp.rest);
	lat = temp.lat;
	longi = temp.longi;
	lat2 = temp.lat2;
	longi2 = temp.longi2;
	rad = temp.rad;
}

geofence geofence::operator=(geofence temp)
{
	delete[]tip;
	tip = new char[strlen(temp.tip) + 1];
	strcpy(tip, temp.tip);
	delete[]rest;
	rest = new char[strlen(temp.rest) + 1];
	strcpy(rest, temp.rest);
	lat = temp.lat;
	longi = temp.longi;
	lat2 = temp.lat2;
	longi2 = temp.longi2;
	rad = temp.rad;
	return *this;
}
istream& operator>>(istream &in, geofence &temp)
{
	char aux[25];
	delete[]temp.tip;
	in >> aux;
	temp.tip = new char[strlen(aux) + 1];
	strcpy(temp.tip,aux);
	delete[]temp.rest;
	in >> aux;
	temp.rest = new char[strlen(aux) + 1];
	strcpy(temp.rest, aux);
	in >> temp.lat;
	in >> temp.longi;
	in >> temp.rad;
	return in;
}

ostream& operator<<(ostream &out, geofence temp)
{
	out << temp.tip << " ";
	out << temp.rest << " ";
	out << temp.lat << " ";
	out << temp.longi << " ";
	out << temp.lat2 << " ";
	out << temp.longi2 << " ";
	out << temp.rad << endl;

	return out;
}

ifstream& operator>>(ifstream &in, geofence &temp)
{
	char verif[25];
	char a[25];
	char aux[25];
	char cir[25];
	char rect[25];
	strcpy(cir, "circle");
	strcpy(rect, "rectangle");
	in >> a;
	delete[]temp.tip;
	in >> verif;
	temp.tip = new char[strlen(verif) + 1];
	strcpy(temp.tip, verif);
	in >> a;
	delete[]temp.rest;
	in >> aux;
	temp.rest = new char[strlen(aux) + 1];
	strcpy(temp.rest, aux);
	in >> a;
	in >> temp.lat;
	in >> temp.longi;
	if (strcmp(verif,rect)==0)
	{
		in >> a;
		in >> temp.lat2;
		in >> temp.longi2;
	}
	else
	{
		temp.lat2 = 0;
		temp.longi2 = 0;
	}
	if (strcmp(verif, cir) == 0)
	{
		in >> a;
		in >> temp.rad;
	}
	else
	{
		temp.rad = 0;
	}
	
	return in;
}

geofence::~geofence()
{
	delete[]tip;
	delete[]rest;
}

void read_telematics(char a[], vector<locatie>&loc)
{
	ifstream infile;
	locatie l;
	infile.open(a);
	while (infile >> l)
	{
		loc.push_back(l);
	}
	infile.close();
}

void raport_telematics(char a[], vector<locatie>loc)
{
	
	ofstream outfile;
	outfile.open(a);
	outfile << "Raportul datelor telematice este :" << endl;
	for (unsigned count = 0; count < loc.size(); count++)
	{
		outfile << loc[count] << endl;
	}
	outfile.close();
}

void raport_auto(char a[], const vector<caracteristici>car)
{
	ofstream outfile;
	outfile.open(a);
	for (unsigned count = 0; count < car.size(); count++)
	{
		outfile << "Autoturismul cu numarul "<<count+1 << endl;
		outfile << car[count] << endl;

	}

	outfile.close();
}

void read_auto(char a[], vector<caracteristici>&car)
{
	ifstream infile;
	infile.open(a);
	caracteristici c;
	while (infile >> c)
	{
		car.push_back(c);
	}
	infile.close();
}

void read_geo(char a[], vector<geofence>&g)
{
	ifstream infile;
	infile.open(a);
	geofence ge;
	while (infile >> ge)
	{
		g.push_back(ge);
	}
	infile.close();
}

void raport_geo(char a[], const vector<geofence>g)
{
	ofstream outfile;
	outfile.open(a);
	outfile << "Lista regulilor geofence : " << endl;
	for (unsigned count = 0; count < g.size(); count++)
	{
		
		outfile << g[count] << endl;
	}

	outfile.close();
}

void raport_auto_b(char a[])
{
	ofstream outfile;
	outfile.open(a, ios::out | ios::binary);
	ifstream infile;
	infile.open("auto.txt");
	vector<caracteristici>car;
	caracteristici c;
	while (infile >> c)
	{
		car.push_back(c);
	}
	for (unsigned count = 0; count < car.size(); count++)
	{
		outfile.write(reinterpret_cast <const char*>(&car[count]), sizeof(car[count]));
	}
	infile.close();
	outfile.close();
}

void raport_geo_b(char a[])
{
	ifstream infile;
	infile.open("geofence.txt");
	ofstream outfile;
	outfile.open(a, ios::out | ios::binary);
	geofence ge;
	vector<geofence>g;
	while (infile >> ge)
	{
		g.push_back(ge);
	}
	for (unsigned count = 0; count < g.size(); count++)
	{
		outfile.write(reinterpret_cast <const char*>(&g[count]), sizeof(g[count]));
	}
	infile.close();
	outfile.close();
}

void raport_telematics_b(char a[])
{
	ifstream infile;
	infile.open("telematics.txt");
	ofstream outfile;
	outfile.open(a, ios::out | ios::binary);

	vector<locatie>loc;
	locatie l;

	while (infile >> l)
	{
		loc.push_back(l);
	}
	for (unsigned count = 0; count < loc.size(); count++)
	{
		outfile.write(reinterpret_cast <const char*>(&loc[count]), sizeof(loc[count]));
	}
	infile.close();
	outfile.close();
}

void distanta_parcursa(vector<locatie>loc,float v[6][2])
{
	
	char aux[25];
	int i = 1;
	int j = 0;
	v[0][0]=loc[0].get_latitude();
	v[0][1] = loc[0].get_longitude();
	int ok = 0;
	int ver = 0;
	strcpy(aux, loc[0].get_nume());
	for (unsigned count = 0; count < loc.size()&&ok==ver; count++)
	{
		if (strcmp(loc[count].get_nume(), aux) != 0)
		{
			v[i][j] = loc[count - 1].get_latitude();
			v[i][j+1] = loc[count - 1].get_longitude();

			i = i + 1;
			j = 0;

			v[i][j] = loc[count].get_latitude();
			v[i][j + 1] = loc[count].get_longitude();
			
			i = i + 1;
			j = 0;

			ok = i;
			ver = i;

			strcpy(aux, loc[count].get_nume());
		}
		else
			if (count+1 == loc.size())
			{
				v[i][j] = loc[count].get_latitude();
				v[i][j + 1] = loc[count].get_longitude();
			}
	}
}

void green_driving(vector<locatie>loc,float v[])
{
	
	float k[3];
	k[0] = 0; k[1] = 0; k[2] = 0;
	v[0] = 0; v[1] = 0; v[2] = 0;
	char a[25];
	int i = 0;
	strcpy(a, "auto1");
	for (unsigned count = 0; count < loc.size(); count++)
	{
		if (strcmp(a, loc[count].get_nume()) != 0)
		{
			i = i + 1;
			strcpy(a, loc[count].get_nume());
		}
		v[i] = v[i] + loc[count].get_viteza();
		k[i] = k[i] + 1;
	}

	for (i = 0; i < 3; i++)
		v[i] = v[i] / k[i];

}

void main()
{

	//testare comenzi !

	/*automobil a;
	automobil b;
	cin >> a;
	cin >> b;
	a = b;
	cout << a << endl;

	caracteristici c;
	caracteristici d;
	cin >> c;
	cin >> d;
	c = d;
	cout << c << endl;

	locatie l;
	locatie m;
	cin >> l;
	cin >> m;
	l = m;
	cout << l << endl;


	echipare e;
	echipare f;
	cin >> e;
	cin >> f;
	e = f;
	cout << e << endl;

	anvelope x;
	anvelope y;
	cin >> x;
	cin >> y;
	x = y;
	cout << x << endl;*/
	
	
	/*vector<caracteristici>automobile;
	caracteristici c;
	ifstream infile;
	infile.open("auto.txt");

	while (infile >> c)
		automobile.push_back(c);
	for (int i = 0; i < 3; i++)
		cout << automobile[i];
*/
	/*vector<geofence>geo;
	geofence g;
	ifstream infile;
	infile.open("geofence.txt");
	while (infile >> g)
		geo.push_back(g);
	for (int i = 0; i < 3; i++)
		cout << geo[i];
	infile.close();
	*/

	/*char a[25];
	char b[25];
	vector<locatie>loc;
	cout << "Numele fisierului de citit :";
	cin >> a;
	cout << "Numele fisierului in care printam raportul : ";
	cin >> b;
	read_telematics(a, loc);
	raport_telematics(b, loc);*/

	/*char a[25];
	vector<caracteristici>car;
	cin >> a;
	read_auto(a, car);
	cout << "Numele fisierului lista :";
	cin >> a;
	raport_auto(a, car);
*/
	/*char a[25];
	vector<geofence>geo;
	cin >> a;
	read_geo(a, geo);
	cout << "celalalt: ";
	cin >> a;
	raport_geo(a, geo);
*/
	/*char a[25];
	cin >> a;
	raport_telematics_b(a);*/

	/*float v[6][2];
	char a[25];
	cin >> a;
	vector<locatie>loc;
	read_telematics(a, loc);
	distanta_parcursa(loc, v);

	for (int i = 0; i < 6; i++)
	{
		
		if (i % 2 == 0)
			cout << endl;
		cout << v[i][0]<<" "<<v[i][1]<<endl;
	}
*/


	int a = 100;
	
	while (a != 0)
	{
		cout << "Apasati 0 daca vreti sa iesiti din aplicatie " << endl;
		cout << "Apasati 1 daca vreti sa cititi un automobil si sa testati operatorul = " << endl;
		cout << "Apasati 2 daca vreti sa cititi caracteristicile unui automobil si sa testati operatorul = " << endl;
		cout << "Apasati 3 daca vreti sa cititi locatia unui automobil si sa testati operatorul =  " << endl;
		cout << "Apasati 4 daca vreti sa cititi nivelurile de echipare ale unui automobil si sa testati operatorul =  " << endl;
		cout << "Apasati 5 daca vreti sa cititi anvelopele unui automobil si sa testati operatorul =  " << endl;
		cout << "Apasati 6 daca vreti sa cititi caracteristicile din fisierul text dat " << endl;
		cout << "Apasati 7 daca vreti sa cititi regulile geofence din fisierul text dat " << endl;
		cout << "Apasati 8 daca vreti sa cititi datele telematice din fisierul text dat " << endl;
		cout << "Apasati 9 daca vreti sa aflati si sa afisati coordonatele automobilelor in punctele de plecare si sosire(distanta) " << endl;
		cout << "Apasati 10 daca vreti sa aflati daca automobilele din documentul dat au condus in modul green driving " << endl;
		cout << "Apasati 11 daca vreti sa listati raportul in fisier text despre automobilele existente  " << endl;
		cout << "Apasati 12 daca vreti sa listati raportul in fisier text despre datele telematice existente  " << endl;
		cout << "Apasati 13 daca vreti sa listati raportul in fisier text despre regulile geofence existente  " << endl;
		cout << "Apasati 14 daca vreti sa listati raportul in fisier binar despre automobilele existente " << endl;
		cout << "Apasati 15 daca vreti sa listati raportul in fisier binar despre datele telematice existente " << endl;
		cout << "Apasati 16 daca vreti sa listati raportul in fisier binar despre regulile geofence existente " << endl;

		cin >> a;

		if (a == 1)
		{
			automobil a;
			automobil b;
			cin >> a;
			cin >> b;
			a = b;
			cout << a << endl;
		}

		if (a == 2)
		{
			caracteristici c;
			caracteristici d;
			cin >> c;
			cin >> d;
			c = d;
			cout << c << endl;
		}

		if (a == 3)
		{
			locatie l;
			locatie m;
			cin >> l;
			cin >> m;
			l = m;
			cout << l << endl;
		}

		if (a == 4)
		{
			echipare e;
			echipare f;
			cin >> e;
			cin >> f;
			e = f;
			cout << e << endl;
		}

		if (a == 5)
		{
			anvelope x;
			anvelope y;
			cin >> x;
			cin >> y;
			x = y;
			cout << x << endl;
		}

		if (a == 6)
		{
			vector<caracteristici>v;
			read_auto("auto.txt", v);
		}

		if (a == 7)
		{
			vector<geofence>geo;
			read_geo("geofence.txt", geo);

		}

		if (a == 8)
		{
			vector<locatie>loc;
			read_telematics("telematics.txt", loc);
		}

		if (a == 9)
		{
			cout << "Va rog asteptati... " << endl;
			float v[6][2];
			vector<locatie>loc;
			read_telematics("telematics.txt", loc);
			distanta_parcursa(loc, v);

			for (int i = 0; i < 6; i++)
			{

				if (i % 2 == 0)
					cout << endl;
				cout << v[i][0] << " " << v[i][1] << endl;
			}
		}

		if (a == 10)
		{
			cout << "Va rog asteptati... " << endl;
			float v[3];
			vector<locatie>loc;
			read_telematics("telematics.txt", loc);
			green_driving(loc, v);
			for (int i = 0; i < 3; i++)
				if (v[i]<110)
					cout << "Automobilul "<<i + 1<<" a condus in modul green driving "<<endl;
				else
					cout << "Automobilul " << i + 1 << " nu a condus in modul green driving "<<endl;


		}

		if (a == 11)
		{
			char aux[25];
			vector<caracteristici>car;
			read_auto("auto.txt", car);
			cout << "Introduceti numele documentului txt in care vreti sa listati ";
			cin >> aux;
			raport_auto(aux, car);
		}
		
		if (a == 12)
		{
			cout << "Va rog asteptati... " << endl;
			char aux[25];
			vector<locatie>loc;
			read_telematics("telematics.txt", loc);
			cout<< "Introduceti numele documentului txt in care vreti sa listati ";
			cin >> aux;
			raport_telematics(aux, loc);
		}

		if (a == 13)
		{
			char aux[25];
			vector<geofence>geo;
			read_geo("geofence.txt", geo);
			cout<< "Introduceti numele documentului txt in care vreti sa listati ";
			cin >> aux;
			raport_geo(aux,geo);
		}

		if (a == 14)
		{
			char aux[25];
			vector<caracteristici>car;
			read_auto("auto.txt", car);
			cout << "Introduceti numele documentului .dat in care vreti sa listati ";
			cin >> aux;
			raport_auto_b(aux);
		}

		if (a == 15)
		{
			cout << "Va rog asteptati... " << endl;
			char aux[25];
			vector<locatie>loc;
			read_telematics("telematics.txt", loc);
			cout << "Introduceti numele documentului .dat in care vreti sa listati ";
			cin >> aux;
			raport_telematics_b(aux);
		}

		if (a == 16)
		{
			char aux[25];
			vector<geofence>geo;
			read_geo("geofence.txt", geo);
			cout << "Introduceti numele documentului .dat in care vreti sa listati ";
			cin >> aux;
			raport_geo_b(aux);
		}


	}

	

}
