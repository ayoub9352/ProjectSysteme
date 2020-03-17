#include "../tools/bib.h"
//https://www.youtube.com/watch?v=uuTfKMubkZg&list=PLN_MPJUQgPVoXJoIi0jnSMa3LGbsarfhA&index=1

static void appQuit(GtkWidget *widget, gpointer data){
    g_print("Quit app");
    gtk_main_quit();
} 

static gboolean button_click(GtkButton *button, gpointer user_data){
    g_print("Quit app from button");
    gtk_main_quit();
    return FALSE;
}

static gboolean evnent_enter(GtkWidget *widget, GdkEvent *event, gpointer user_data){
    if(event->type == GDK_ENTER_NOTIFY){
        g_print("the mouse enter\n");
        return TRUE;
    }
    return FALSE;
}

static gboolean evnent_press(GtkWidget *widget, GdkEvent *event, gpointer user_data){
    if( event->type == GDK_BUTTON_PRESS ){
        g_print("the mouse press\n");
        return TRUE;
    }
    return FALSE;
}

static gboolean evnent_scroll(GtkWidget *widget, GdkEvent *event, gpointer user_data){
    if( event->type == GDK_SCROLL ){
        if(event->scroll.direction == GDK_SCROLL_DOWN){
            g_print("scroll down\n");
        }
        if(event->scroll.direction == GDK_SCROLL_UP){
            g_print("scroll up\n");
        }
        return FALSE;
    }
    return TRUE;
}

static gboolean evnent_keypress(GtkWidget *widget, GdkEventKey *event, gpointer data){
  if(event->keyval == GDK_KEY_a){
    printf("dfsdg\n");
    return TRUE;
  }
  return FALSE;
}


void initApp(){
    GtkWidget *window;
    GtkWidget *button;

    gtk_init(NULL, NULL);

    //Widget init
    window = createWindow(300, 300);
    button = gtk_button_new_with_mnemonic("Quit");

    //window container
    gtk_container_add(GTK_CONTAINER(window), button);

    //connect
    WindowConnect(window);
    ButtonConnect(button);

    //allow
    gtk_widget_add_events(button, GDK_SCROLL_MASK);
    gtk_widget_add_events(button, GDK_BUTTON_PRESS_MASK);

    //show
    gtk_widget_show_all(window);
    gtk_main();

}

void ButtonConnect(GtkWidget *button){
    g_signal_connect(button, "clicked", G_CALLBACK(button_click), NULL);
    g_signal_connect(button, "enter-notify-event", G_CALLBACK(evnent_enter), NULL);
    g_signal_connect(button, "button-press-event", G_CALLBACK(evnent_press), NULL);
    g_signal_connect(button, "scroll-event", G_CALLBACK(evnent_scroll), NULL);
    g_signal_connect(button, "key-press-event", G_CALLBACK(evnent_keypress), NULL);
    
}

void WindowConnect(GtkWidget *window){
    g_signal_connect(window, "destroy", G_CALLBACK(appQuit), NULL);
}

GtkWidget *createWindow(const gint width, const gint height){
    GtkWidget *window;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request(window, width, height);

    gtk_window_set_title(GTK_WINDOW(window), "VIDIO 1");
    //padding
    gtk_container_set_border_width(GTK_CONTAINER(window), 50);
    return window;
}