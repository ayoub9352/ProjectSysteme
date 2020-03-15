#ifndef FUNCTIONS
#define FUNCTIONS

	#include <gtk/gtk.h>

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

	static void clear_surface (void);
	static gboolean configure_event_cb (GtkWidget *widget,GdkEventConfigure *event, gpointer data);
	static gboolean draw_cb (GtkWidget *widget, cairo_t *cr, gpointer data);
	static void draw_brush (GtkWidget *widget, gdouble x, gdouble y);
	static gboolean button_press_event_cb (GtkWidget *widget, GdkEventButton *event, gpointer data);
	static gboolean motion_notify_event_cb (GtkWidget *widget, GdkEventMotion *event, gpointer data);
	static void close_window (void);
	static void activate (GtkApplication *app,gpointer user_data);
	void initProg(int argc, char **argv);




#endif