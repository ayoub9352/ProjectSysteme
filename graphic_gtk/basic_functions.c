#include "../tools/bib.h"

void draw(){
  cairo_surface_t *surface;
  cairo_t *cr;

  surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 120, 120);
  cr = cairo_create (surface);
  cairo_set_line_width (cr, 0.1);
  cairo_set_source_rgb (cr, 0, 0, 0);
  cairo_rectangle (cr, 0.25, 0.25, 50, 50);
  cairo_stroke (cr);
}

static void activate (GtkApplication *app, gpointer user_data){
  GtkWidget *window;
  GtkWidget *frame;
  GtkWidget *drawing_area;

  //->set up the window
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Drawing Area");
  gtk_window_set_default_size (GTK_WINDOW (window), 500, 500);
  //gtk_window_fullscreen(GTK_WINDOW (window));

  draw();
 
  //->show the content  
  gtk_widget_show_all (window);
}

void initProg(int argc, char **argv){
    GtkApplication *app;
    int status;

    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);
}
