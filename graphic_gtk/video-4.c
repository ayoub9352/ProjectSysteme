#include "../tools/bib.h"

void createList(GtkWidget *window){
    GtkListStore* model;
    GtkTreeView*  view;
    GtkCellRenderer *renderer;
    GtkTreeViewColumn* article_column;
    GtkTreeViewColumn   *price_column;

    model = gtk_list_store_new(4, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);
    gtk_list_store_insert_with_values(model, NULL, -1,
                                      0, "test name 1",
                                      1, 0,
                                      2, 10,
                                      -1);
    gtk_list_store_insert_with_values(model, NULL, -1,
                                      0, "test name 2",
                                      1, 0,
                                      2, 10,
                                      -1);
    view = GTK_TREE_VIEW (gtk_tree_view_new_with_model (GTK_TREE_MODEL (model)));
    renderer = gtk_cell_renderer_text_new ();
    article_column = gtk_tree_view_column_new_with_attributes ("Article", renderer,
            "text", 0,
            NULL);
    gtk_tree_view_column_set_sort_column_id (article_column, 0);
    gtk_tree_view_append_column (view, article_column);
    gtk_widget_set_vexpand (GTK_WIDGET (view), TRUE);
    
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET (view));
}

void initAppV4(){
    GtkWidget *window;

    gtk_init(NULL, NULL);

    //Widget init
    window = createWindowV4(500, 500);
    createList(window);

    
    gtk_widget_show_all(window);
    gtk_main();

}

GtkWidget *createWindowV4(const gint width, const gint height){
    GtkWidget *window;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request(window, width, height);

    gtk_window_set_title(GTK_WINDOW(window), "VIDIO 4");

    //padding
    gtk_container_set_border_width(GTK_CONTAINER(window), 50);

    //connect
    g_signal_connect(window, "destroy", gtk_main_quit, NULL);

    return window;
}