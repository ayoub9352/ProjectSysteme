#ifndef FUNCTIONS
#define FUNCTIONS

	#include <gtk/gtk.h>
	#include <cairo.h>

	// +----> functions/healpers.c

	void newError(const char *message);
	int lengthOfInt(long long x);
	char *intToString(long long x);


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

	void makeTextRectangle(cairo_t *cr,point2D pos, int unit, char *text, RGB_color color);
	void grantRectangle(cairo_t *cr, RGB_color color1, RGB_color color2);
	void makeOrthonormal(cairo_t *cr, gdouble dx);
	static gboolean on_draw (GtkWidget *widget, cairo_t *cr, gpointer user_data);
	static gboolean button_press_event_cb (GtkWidget *widget,GdkEventButton *event, gpointer data);
	static gboolean my_keypress_function(GtkWidget *widget, GdkEventKey *event, gpointer data);
	void intApp(int argc, char **argv);


	// +----> graphic_gtk/video-1.c

	static void appQuit(GtkWidget *widget, gpointer data);
	static gboolean button_click(GtkButton *button, gpointer user_data);
	static gboolean evnent_enter(GtkWidget *widget, GdkEvent *event, gpointer user_data);
	static gboolean evnent_press(GtkWidget *widget, GdkEvent *event, gpointer user_data);
	static gboolean evnent_scroll(GtkWidget *widget, GdkEvent *event, gpointer user_data);
	static gboolean evnent_keypress(GtkWidget *widget, GdkEventKey *event, gpointer data);
	void initApp();
	void ButtonConnect(GtkWidget *button);
	void WindowConnect(GtkWidget *window);
	GtkWidget *createWindow(const gint width, const gint height);




#endif