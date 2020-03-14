#ifndef FUNCTIONS
#define FUNCTIONS

	// +----> functions/healpers.c

	void newError(char *message);


	// +----> functions/progFunctions.c

	prog makeProg(char *name, int arrive, int exucution, int priority);
	void afficheProg(prog theProg);
	void afficheListProg(listProg *List);
	listProg *newListProg();
	int lenList(listProg *theList);


	// +----> graphic_gtk/basic_functions.c





#endif