#ifndef FUNCTIONS
#define FUNCTIONS

	// +----> functions/a_healpers.c

	void newError(const char *message);
	int lengthOfInt(long long x);
	char *intToString(long long x);
	void CursorP(int x,int y);
	void printAtPos(int x, int y ,char *message);
	void changeTextColor(char *text_color);
	void heightLightColor(char *height_light_color);


	// +----> functions/b_listFunctions.c

	List *listInit();
	int listLen(List *theList);
	List *getItemAt(List *theList, int pos);
	List *listAddAt(List *theList, void *info, int pos);
	List *listDeleteAt(List *theList, int pos);
	List *listAdd(List *theList, void *info);
	List *listPush(List *theList, void *info);
	List *listPop(List *theList);
	List *listShift(List *theList);


	// +----> functions/c_progFunctions.c

	prog makeProg(char *name, int arrive, int exucution, int priority);
	void afficheProg(prog theProg);


	// +----> functions/d_videoGame.c

	List *setUpList();
	void setBackground(int x, int y, int width, int height, char *color);
	void setUpMenu(int x, int y);


	// +----> functions/e_casting.c

	char *TO_STRING(List *list, int pos);




#endif