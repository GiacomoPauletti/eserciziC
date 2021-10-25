#include <stdio.h>
#define MAX_LUNG_TESTO 100
int main()
{
  char TestoA[MAX_LUNG_TESTO] = "alternativamente";
  char TestoB[MAX_LUNG_TESTO] = "eternita";
  /* i due testi da confrontare; notare che il testo dell'esercizio NON
   * richiedeva che i testi venissero immessi da tastiera */

  char TestoComune[MAX_LUNG_TESTO];
  /* il testo comune a TestoA e TestoB, da trovare */
  int CursoreA, CursoreB, CursoreComune;
  /* CursoreA e CursoreB sono usati per scorrere i caratteri dei due testi; 
	 * inoltre nella fase finale CursoreA e' usato per scorrere gli elementi di
	 * TestoA che costituiscono il testo comune. CursoreComune e' usato per
	 * scorrere gli elementi di TestoComune */
  int CursoreALocale, CursoreBLocale;
  /* per ogni coppia di posizioni di CursoreA e CursoreB scorrono i caratteri
   * successivi dei due testi per determinare se coincidono */
  int InizioTestoComune;
  /* indice (in TestoA) del carattere iniziale del testo comune più lungo
   * trovato finora */
  int MaxLunghezza;
  /* lunghezza del più lungo testo comune ai due testi originali finora
   * trovato */
  int LunghezzaLocale;
  /* lunghezza del frammento di testo comune attualmente in esame */

	/* Descrizione dell'algoritmo :
	 * scorriamo il testo A un carattere alla volta; per ogni carattere di A,
	 * scorriamo B per trovare lo stesso carattere; ogni volta che lo troviamo,
	 * procediamo parallelamente sui due testi, un carattere alla volta, per
	 * determinare quanto e' lungo il tratto coincidente; */

  MaxLunghezza = 0;
  CursoreA = 0;

  while ( '\0' != TestoA[CursoreA] )
  /* finché non si e' raggiunta la fine del testo A */
  {
    CursoreB = 0;

    while ( '\0' != TestoB[CursoreB] )
		/* finché non si e' raggiunta la fine del testo B */
		{
		  if ( TestoB[CursoreB] == TestoA[CursoreA] )
      /* se i caratteri correnti dei due testi sono uguali... */
      {
			  /* ...inizia il confronto dei caratteri successivi */
        LunghezzaLocale = 1;
        /* lo inizializziamo a 1 (e non a 0) poiché abbiamo già verificato
         * l'esistenza di un testo comune lungo 1 carattere */
        CursoreALocale = CursoreA+1;
        CursoreBLocale = CursoreB+1;
        /* posizioniamo i due cursori subito dopo il carattere comune già
         * trovato */

        while ( ('\0' != TestoA[CursoreALocale]) &&
        ('\0' != TestoB[CursoreBLocale]) &&
        (TestoA[CursoreALocale] == TestoB[CursoreBLocale]) )
        {
          ++LunghezzaLocale;
          ++CursoreALocale;
          ++CursoreBLocale;
        }
  			/* a questo punto LunghezzaLocale rappresenta la lunghezza del 
       	 * testo comune che parte da CursoreA (in TestoA) e CursoreB
       	 * (in TestoB) */
       	 
  			if ( LunghezzaLocale > MaxLunghezza)
	      /* se il testo comune appena trovato e' il più lungo trovato
	       * finora */
	      {
	        InizioTestoComune = CursoreA;
	        MaxLunghezza = LunghezzaLocale;
	      }
      }
			++CursoreB;
		}
	  ++CursoreA;
	}

  /* a questo punto InizioTestoComune indica il carattere iniziale (nel testo
   * A) del testo comune e MaxLunghezza e' la lunghezza del testo comune. Tale 
   * testo va copiato in TestoComune */

  /* inizio fase di copia del testo comune in TestoComune: */
  CursoreComune = 0;
  CursoreA = InizioTestoComune;

  while (CursoreA < InizioTestoComune + MaxLunghezza)
  {
    TestoComune[CursoreComune] = TestoA[CursoreA];
    ++CursoreA;
    ++CursoreComune;
  }

  TestoComune[CursoreComune] = '\0';
  /* inserisce il carattere di terminazione in TestoComune */

  /* Nota: il ciclo non e' stato eseguito se MaxLunghezza = 0, ovvero se non
   * esiste alcun testo comune. In tal caso TestoComune[0] = '\0', 
   * conformemente a quanto richiesto dall'esercizio: infatti in questa
   * situazione TestoComune deve contenere una stringa vuota */

  printf("\nIl testo comune e': '%s'\n\n", TestoComune);

  return(0);
}
