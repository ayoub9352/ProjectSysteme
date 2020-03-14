#ifndef FUNCTIONS
#define FUNCTIONS

	// +----> functions/healpers.c

	void newError(char *message);


	// +----> functions/listFunctions.c

	List *listInit();
	int listLen(List *theList);
	List *getItemAt(List *theList, int pos);
	List *listAddAt(List *theList, void *info, int pos);
	List *listDeleteAt(List *theList, int pos);
	List *listAdd(List *theList, void *info);
	List *listPush(List *theList, void *info);
	List *listPop(List *theList);
	List *listShift(List *theList);


	// +----> functions/progFunctions.c

	prog makeProg(char *name, int arrive, int exucution, int priority);
	void afficheProg(prog theProg);


	// +----> graphic_gtk/basic_functions.c





#endif