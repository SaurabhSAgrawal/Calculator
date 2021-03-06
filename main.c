
/*****************************************************************************
 * Copyright (C) Saurabh Agrawal saurabhagrawal1483@gmail.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
    
 *****************************************************************************/
 
#include <gtk/gtk.h>
#include "calculator.h" 
#include <ctype.h>
#include <stdlib.h>

//buffer to store the inputs in the text field
gchar text_field_buffer[200];
GtkWidget* text_field;

int main(int argc, char* argv[]) {
	gtk_init(&argc, &argv);

	GtkWidget *window, *button;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Calculator");
	gtk_window_set_default_size(GTK_WINDOW(window), 200, 240);
	
	GtkWidget* table;
	table = gtk_table_new(9, 5, FALSE);
	gtk_table_set_col_spacings(GTK_TABLE(table), 6);
	gtk_table_set_row_spacings(GTK_TABLE(table), 6);

	text_field = gtk_entry_new();
	gtk_table_attach_defaults(GTK_TABLE(table), text_field, 0, 3, 0, 1);

	button = gtk_button_new_with_label("AC");
	gtk_button_set_relief(GTK_BUTTON(button), GTK_RELIEF_HALF);
	gtk_table_attach_defaults(GTK_TABLE(table), button, 3, 4, 0, 1);
	g_signal_connect (G_OBJECT (button),  "clicked", G_CALLBACK (callback),  "AC");

	int i, j;
	gchar* button_label;
	for(i = 0; i < 7; ++i)
		for(j = 0; j < 4; j++) {
			button_label = return_button_label(10 * i + j);
			button = gtk_button_new_with_label(button_label);
			
			gtk_table_attach_defaults(GTK_TABLE(table), button, j, j + 1, i + 1, i + 1 + 1);
			//callback func here
			g_signal_connect (G_OBJECT (button),  "clicked", G_CALLBACK (callback),  button_label);
		}
	

	gtk_container_add(GTK_CONTAINER(window), table);
	gtk_widget_show_all(window);

	g_signal_connect(window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	// set an icon
	gtk_window_set_icon_from_file (GTK_WINDOW(window), "download.jpg", NULL);

	gtk_main();

	return 0;
}
