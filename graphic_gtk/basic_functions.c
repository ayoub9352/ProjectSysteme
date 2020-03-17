#include "../tools/bib.h"
#define WIDTH   1100
#define HEIGHT  600

#define UNIT 20
#define Height 1
#define TEXT_LENGTH 5.45
#define MARGIN_R 0.5
#define FOUNT 7.5

float ZOOM_X = 1.0;
float ZOOM_Y = 1.0;
float translate_x = 20;

void makeTextRectangle(cairo_t *cr,point2D pos, int unit, char *text, RGB_color color){
  float height;
  float width;
  float fount;
  point2D textPos;
  cairo_text_extents_t extents;

  pos.x += MARGIN_R;
  height = Height * UNIT;
  width = unit * UNIT - MARGIN_R;
  fount = FOUNT;


  cairo_set_source_rgba (cr, color.R, color.G, color.B, 1);
  cairo_rectangle(cr, pos.x, pos.y, width, height);
  cairo_fill(cr);

  /*write the text */
  cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);
  do{
    cairo_set_font_size (cr, fount);
    cairo_text_extents (cr, text, &extents);
    textPos.x = pos.x + (width / 2.0) -(extents.width/2 + extents.x_bearing);
    textPos.y = pos.y + (height / 2.0) - (extents.height/2 + extents.y_bearing);
    //printf("//--->(%f; %f)\n", textPos.x - pos.x, textPos.y - pos.y);
    fount = fount / 1.2;
  }while(textPos.x - pos.x <= 2);
  
  cairo_move_to(cr, textPos.x, textPos.y);
  cairo_show_text(cr, text);

}

void grantRectangle(cairo_t *cr, RGB_color color1, RGB_color color2){
  char *text;
  int unit;
  int p;

  prog pro1 = {"p1", 0, 2, 0};
  prog pro2 = {"p2", 0, 3, 0};
  prog pro3 = {"p3", 0, 5, 0};
  prog pro4 = {"p4", 0, 3, 0};

  point2D pos = {0, -41.5};

  prog listProg[] = {pro1, pro2, pro3, pro4};

  //i = list;
  p = 0;
  while(p < 4){
    text = listProg[p].name;
    unit = listProg[p].exucution;
    if(p % 2){
      makeTextRectangle(cr, pos, unit, text, color1);
    }else{
      makeTextRectangle(cr, pos, unit, text, color2);
    }
    pos.x += UNIT * unit;
    p++;
  }
}

void makeOrthonormal(cairo_t *cr, gdouble dx){
    point2D pos;
    cairo_text_extents_t extents;
    float i;

    cairo_set_line_width (cr, dx);
    //lines
    cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
    cairo_move_to(cr, 0, -20);
    cairo_line_to (cr, 70 * 20, -20);
    cairo_stroke (cr);

    //lines digite
    cairo_set_source_rgb (cr, 0.5, 0.5, 0.5);
    cairo_set_line_width (cr, 0.5);
    for (i = 0.01; i < 50; i++){
      cairo_move_to(cr, i * UNIT , -19.5);
      cairo_line_to (cr, i * UNIT, -15);
      cairo_stroke (cr);
    }

    //numbers
    cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
    for (i = 0.01; i < 50; i++){
      cairo_text_extents (cr, intToString(i), &extents);
      pos.x = i * UNIT;
      pos.y = -8;
      pos.x = pos.x +  -(extents.width/2 + extents.x_bearing);
      pos.y = pos.y +  - (extents.height/2 + extents.y_bearing);
      cairo_move_to(cr, pos.x, pos.y);
      cairo_show_text(cr, intToString(i));
    }
}

static gboolean on_draw (GtkWidget *widget, cairo_t *cr, gpointer user_data){
    GdkRectangle da;            /* GtkDrawingArea size */
    gdouble dx = 5.0, dy = 5.0; /* Pixels between each point */
    gdouble i;
    GdkWindow *window = gtk_widget_get_window(widget);

    /* Determine GtkDrawingArea dimensions */
    gdk_window_get_geometry (window, &da.x, &da.y, &da.width, &da.height);

    /* Draw on a black background */
    cairo_set_source_rgb (cr, 50.0, 50.0, 50.0);
    cairo_paint (cr);

    /* Change the transformation matrix */
    cairo_translate (cr, translate_x , da.height / 2);
    cairo_scale (cr, ZOOM_X, ZOOM_Y);

    cairo_device_to_user_distance (cr, &dx, &dy);
    

    /*------------------------------------*/
    RGB_color color1 = {0.15, 0.47, 0.84};
    RGB_color color2 = {0.0, 0.6, 0.4};
    
    makeOrthonormal(cr, dx);
    grantRectangle(cr, color1, color2);

    return FALSE;
}

static gboolean button_press_event_cb (GtkWidget *widget,GdkEventButton *event, gpointer data){
  /* paranoia check, in case we haven't gotten a configure event */
  
  if (event->button == 1){
      ZOOM_X *= 1.3;
      ZOOM_Y *= 1.3;
      printf("--> %lf ; %lf \n", event->x, event->y);
      //return FALSE;
  }
  else if (event->button == GDK_BUTTON_SECONDARY){
      ZOOM_X /= 1.3;
      ZOOM_Y /= 1.3;
      //return FALSE;
  }
  gtk_widget_queue_draw (widget);

  /* We've handled the event, stop processing */
  return TRUE;
}

static gboolean my_keypress_function(GtkWidget *widget, GdkEventKey *event, gpointer data){
  if(event->keyval == GDK_KEY_a){
    translate_x += 10;
    printf("left\n");
    gtk_widget_queue_draw (widget);
    return FALSE;
  }

  if(event->keyval == GDK_KEY_d){
    translate_x -= 10;
    printf("right\n");
    gtk_widget_queue_draw (widget);
    return FALSE;
  }
  return TRUE;
}

void intApp(int argc, char **argv){
    GtkWidget *window;
    GtkWidget *da;

    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size (GTK_WINDOW (window), WIDTH, HEIGHT);
    gtk_window_set_title (GTK_WINDOW (window), "Graph drawing");
    g_signal_connect (G_OBJECT (window), "destroy", gtk_main_quit, NULL);

    da = gtk_drawing_area_new ();
    //da = gtk_button_new_with_mnemonic("Quit");
    gtk_container_add (GTK_CONTAINER (window), da);

    g_signal_connect (G_OBJECT (da), "draw", G_CALLBACK (on_draw), NULL);
    g_signal_connect (G_OBJECT (da), "button-press-event",G_CALLBACK (button_press_event_cb), NULL);
    g_signal_connect (G_OBJECT (da), "key-press-event", G_CALLBACK (my_keypress_function), NULL);
    gtk_widget_set_events (da, 
          // GDK_EXPOSURE_MASK
			   //| GDK_LEAVE_NOTIFY_MASK
			    GDK_BUTTON_PRESS_MASK
			   //| GDK_POINTER_MOTION_MASK
			   //| GDK_POINTER_MOTION_HINT_MASK
          //GDK_KEY_PRESS_MASK   
       );
    //gtk_widget_set_events(da, GDK_KEY_PRESS_MASK);
    gtk_widget_set_can_focus(da, TRUE);
    gtk_widget_add_events(da, GDK_BUTTON_PRESS_MASK);
    gtk_widget_show_all (window);
    gtk_main ();
}