/**
 * @file main1.cpp
 * @author matteo scarale (matteoscaralej@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

/**
Struttura che rappresenta un partecipante
*/
struct partecipante
{
string nome; ///< Nome del partecipante
string cognome; ///< Cognome del partecipante
int matricola; ///< Numero di matricola del partecipante
double x1; ///< Coordinata x del punto 1
double y1; ///< Coordinata y del punto 1
double x2; ///< Coordinata x del punto 2
double y2; ///< Coordinata y del punto 2
double distanza; ///< Distanza tra i due punti
};
/**

Funzione che confronta due partecipanti in base alla distanza
@param p1 primo partecipante da confrontare
@param p2 secondo partecipante da confrontare
@return true se la distanza del primo partecipante è maggiore della distanza del secondo partecipante, false altrimenti
*/
bool
confrontaPartecipanti (const partecipante & p1, const partecipante & p2)
{
  return p1.distanza > p2.distanza;
}
/**

Funzione che confronta due partecipanti in base alla distanza per la scrittura su file
@param p1 primo partecipante da confrontare
@param p2 secondo partecipante da confrontare
@return true se la distanza del primo partecipante è maggiore della distanza del secondo partecipante, false altrimenti
*/
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
	      pow (partecipanti[i].y1 - partecipanti[i].y2, 2));//formula per calcolare la distanza tra due punti

      sort (partecipanti, partecipanti + 4, confrontaPartecipanti);
      sort (partecipanti, partecipanti + 4, confrontaPartecipantiFile);//funzione cghe mette in classifica i partecipanti
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
/**

@brief Chiude il file di output e legge i record dal file di input

La funzione chiude il file di output e legge i record dal file di input "partecipanti.txt",

inserendoli in un array di oggetti partecipante.

@return 1 se non è possibile aprire il file di input, altrimenti non restituisce nulla.
*/
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
