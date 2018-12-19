//including header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <gtk/gtk.h>   
//IPC
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHMSZ
//creating objects
GtkBuilder      *builder; 
GtkWidget       *main_page;
GtkWidget       *register_page;
GtkWidget       *register_page1;
GtkWidget       *client_page;

int main(int argc, char *argv[])
{
	
//IPC
 int shmit,i;
 key_t key;
 char *shm, *s;
 key = 1000;
 if((shm= shmget(key, SHMSZ, IPC_CREAT | 0666)) <0)
 {
 	perror("shmget");
 	exit(1);
 }
 if ((shm =shmat(shmid, NULL, 0)) ==(char *)-1)
 {
 	perror("shmat");
 	exit(1);
 }
*shm !="*";

shmid = shmdt(shm);
exit(0);
  gtk_init(&argc, &argv);

  //adding glade file to our builder
  builder = gtk_builder_new();
  gtk_builder_add_from_file (builder, "gui.glade", NULL);

  //assigning window widget with already defined glade file id window_main
  main_page = GTK_WIDGET(gtk_builder_get_object(builder, "main_page"));
  register_page = GTK_WIDGET(gtk_builder_get_object(builder, "register_page"));
  client_page = GTK_WIDGET(gtk_builder_get_object(builder, "client_page"));
  register_page1 = GTK_WIDGET(gtk_builder_get_object(builder, "register_page1"));
  gtk_builder_connect_signals(builder, NULL);

  g_object_unref(builder);

  gtk_widget_show(main_page);                
  gtk_main();

  return 0;
}

// called when window is closed
void on_window_main_destroy()
{
  gtk_main_quit();
}

void on_register_clicked()
{
    gtk_widget_hide(main_page);
    gtk_widget_show(register_page);  
}
void on_back_clicked()
{
	gtk_widget_hide(register_page);
	gtk_widget_show(main_page);
}
void on_user_clicked()
{
	gtk_widget_hide(main_page);
	gtk_widget_show(register_page1);
}
void on_back2_clicked()
{
	gtk_widget_hide(client_page);
	gtk_widget_show(main_page);
}
void on_register_click()
{
	gtk_widget_hide(register_page1);
	gtk_widget_show(client_page);
}
void on_back_back()
{
	gtk_widget_hide(register_page1);
	gtk_widget_show(main_page);
}
void on_back_main()
{
	gtk_widget_hide(client_page);
	gtk_widget_show(main_page);
}
