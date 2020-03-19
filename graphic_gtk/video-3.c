#include "../tools/bib.h"

void createBox(GtkWidget *window){
    GtkWidget *box;
    GtkWidget *button1;
    GtkWidget *button2;

    box = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 12);
    gtk_container_set_border_width (GTK_CONTAINER (box), 0);

    button1 = gtk_button_new_with_mnemonic("Quit");
    //gtk_box_pack_start (child,gboolean expand,gboolean fill,guint padding);
    gtk_box_pack_start (GTK_BOX (box), button1, FALSE, FALSE, 0);

    button2 = gtk_button_new_with_mnemonic("Quit");
    gtk_box_pack_start (GTK_BOX (box), button2, FALSE, FALSE, 0);

    gtk_widget_show_all (box);
    gtk_container_add (GTK_CONTAINER (window), box);
}

void button_click_v3(GtkButton *button, gpointer user_data){
    g_print("Quit app from button\n");
    gtk_grid_remove_row ((GtkGrid *) user_data, 0);
}

void createGrid(GtkWidget *window){
    GtkWidget *grid;
    GtkWidget *button1;
    GtkWidget *child1;
    GtkWidget *child2;
    GtkWidget *child3;

    grid = gtk_grid_new();

    button1 = gtk_button_new_with_mnemonic("Quit");
    g_signal_connect(button1, "clicked", G_CALLBACK(button_click_v3), grid);

    child1 = gtk_grid_new();
    gtk_grid_attach ((GtkGrid *) grid, child1, 0, 0, 100, 100);
    //gtk_container_add (GTK_CONTAINER (grid), child1);
    gtk_container_add (GTK_CONTAINER (child1), button1);
    
    gtk_container_add (GTK_CONTAINER (window), grid);
}

void initAppV3(){
    GtkWidget *window;

    gtk_init(NULL, NULL);

    //Widget init
    window = createWindowV3(500, 500);
    //createBox(window);
    createGrid(window);
    
    gtk_widget_show_all(window);
    gtk_main();

}

GtkWidget *createWindowV3(const gint width, const gint height){
    GtkWidget *window;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request(window, width, height);

    gtk_window_set_title(GTK_WINDOW(window), "VIDIO 3");

    //padding
    gtk_container_set_border_width(GTK_CONTAINER(window), 50);

    //connect
    g_signal_connect(window, "destroy", gtk_main_quit, NULL);

    return window;
}