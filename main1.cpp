#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

struct partecipante
{
  string nome;
  string cognome;
  int matricola;
  double x1;
  double y1;
  double x2;
  double y2;
  double distanza;
};

bool
confrontaPartecipanti (const partecipante & p1, const partecipante & p2)
{
  return p1.distanza > p2.distanza;
}

bool
confrontaPartecipantiFile (const partecipante & p1, const partecipante & p2)
{
  return p1.distanza > p2.distanza;
}

int
main ()
{
  srand (time (0));		// Inizializza il generatore di numeri casuali con il tempo corrente

  // Crea un file "partecipanti.txt" e lo apre in scrittura
  ofstream outFile ("partecipanti.txt");
  if (!outFile)
    {
      cout << "Impossibile creare il file." << endl;

      return 1;
    }

  // Crea un array di 4 partecipanti e inizializza i campi nome, cognome e matricola
  partecipante partecipanti[4];
  partecipanti[0] =
  {
  "Mario", "Rossi", 12345};
  partecipanti[1] =
  {
  "Luigi", "Verdi", 67890};
  partecipanti[2] =
  {
  "Paola", "Bianchi", 54321};
  partecipanti[3] =
  {
  "Giuseppe", "Neri", 98765};


  // Genera coordinate casuali per ogni partecipante e scrive il record nel file
  for (int i = 0; i < 4; i++)
    {
      partecipanti[i].x1 = rand () % 101;	// Genera un numero casuale tra 0 e 100
      partecipanti[i].x2 = rand () % 101;
      partecipanti[i].y1 = rand () % 101;
      partecipanti[i].y2 = rand () % 101;
// Funzione che calcola la distanza euclidea tra due punti
      partecipanti[i].distanza =
	sqrt (pow (partecipanti[i].x1 - partecipanti[i].x2, 2) +
	      pow (partecipanti[i].y1 - partecipanti[i].y2, 2));

      sort (partecipanti, partecipanti + 4, confrontaPartecipanti);
      sort (partecipanti, partecipanti + 4, confrontaPartecipantiFile);
      cout << "Classifica in base alla distanza percorsa:" << endl;
      outFile << "Classifica in base alla distanza percorsa: " << endl;
      for (int i = 0; i < 4; i++)
	{
	  cout << i +
	    1 << " - " << partecipanti[i].nome << " " << partecipanti[i].
	    cognome << " (" << partecipanti[i].
	    matricola << "): " << partecipanti[i].
	    distanza << " metri" << endl;
	}
      for (int i = 0; i < 4; i++)
	{
	  outFile << i +
	    1 << " - " << partecipanti[i].nome << " " << partecipanti[i].
	    cognome << " (" << partecipanti[i].
	    matricola << "): " << partecipanti[i].
	    distanza << " metri" << endl;
	}

      outFile.close ();		// Chiude il file

      // Legge i record dal file e li mette in un array
      ifstream inFile ("partecipanti.txt");
      if (!inFile)
	{
	  cout << "Impossibile aprire il file." << endl;
	  return 1;
	}
      partecipante partecipantiFile[4];
    }
}
