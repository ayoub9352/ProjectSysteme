#ifndef FUNCTIONS
#define FUNCTIONS

	// +----> functions/casting.c

	char *TO_STRING(List *list, int pos);
	newType *TO_NEWTYPE(List *list, int pos);


	// +----> functions/healpers.c

	void newError(char *message);
	void changeColorText(char *color);
	void changeHeightLight(char *color);
	void CursorP(int x,int y);
	void printAtPos(int x, int y ,char *message);


	// +----> functions/listManagement.c

	List *listInit();
	int listLen(List *list);
	List *listGetAt(List *list, int pos);
	List *listAddAt(List *list, void *info, int pos);
	List *listDeleteAt(List *list, int pos);
	List *listAdd(List *list, void *info);
	List *listPush(List *list, void *info);
	List *listPop(List *list);
	List *listShift(List *list);


	// +----> functions/menu.c

	List *setUpList();
	void setBackground(int x, int y, int width, int height, char *color);
	void setUpMenu(int x, int y);




#endif