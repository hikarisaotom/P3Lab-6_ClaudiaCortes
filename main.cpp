using namespace std;
#include <ncurses.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <vector>
#include "Bombas.h"
//#include "Normal.h"
#include "Espina.h"
#include "Jugador.h"
#include "V.h"
#include "Item.h"
#include "Escenario.h"
#include "Tren.h"
#include "Invisible.h"
void salir();
int menu();
int menu2();
int menu3();
string menunombre();
void movimiento();
void Juego();
int kbhit(void);
void Cargando();
int main(void)
{ /*#Normal 
Normal.o: Normal.h Normal.cpp Bombas.h
	g++ -c Normal.cpp*/
    Escenario * Tablero;
    int opcion = menu();
    int escenario;
    int bomba;
    switch (opcion)
    {
    case 1:
    {
        escenario = menu2();
        bomba = menu3();
        string nombre= menunombre();
         if (escenario == 1)
        {
            Tablero=new Invisible();
        }else{
            Tablero = new Tren(nombre,bomba);
        }
        Cargando();
        Juego();
        break;
    }
    case 2:
    { //Salir.
        salir();
        break;
    }
    } //Fin del switch
}

void Juego()
{
    erase();
    char ser = '*';
    int x, y;
    int cx = 1;
    int cy = 1;
    getmaxyx(stdscr, y, x);
    move(y / 2, x / 2 - 18);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    printw("->ENTER PARA INICIAR <-");
    move(y / 2 + 1, x / 2 - 29);
    printw("Nota: para Jugar utilice la combinacion de teclas W,A,S,D");
    refresh();
    attroff(COLOR_PAIR(1));
    //keypad(stdscr, TRUE);
    int tecla;
    tecla = getch();
    while (tecla != 10)
    {
        tecla = getch();
    }
    int direccion = 3;
    cx = x / 2;
    cy = y / 2;
    curs_set(0);
    erase();
    while (true)
    {
        if (kbhit())
        {
            tecla = getch();
            //ARRIBA
            if (tecla == 119)
            {
                direccion = 1;
            }
            //IZQUIERDA
            if (tecla == 97)
            {
                direccion = 2;
            }
            //DERECHA
            if (tecla == 100)
            {
                direccion = 3;
            }
            //ABAJO
            if (tecla == 115)
            {
                direccion = 4;
            }
        }
        if ((cx > 0 && cy > 0) && (cx < x && cy < y))
        {
            move(cy, cx);
            printw("*");
            refresh();
            usleep(1000000 / 5);
            if (direccion == 1)
            {
                cy = cy - 1;
                move(cy + 1, cx);
                printw(" ");
                refresh();
            }
            if (direccion == 2)
            {
                cx = cx - 1;
                move(cy, cx + 1);
                printw(" ");
                refresh();
            }
            if (direccion == 3)
            {
                cx = cx + 1;
                move(cy, cx - 1);
                printw(" ");
                refresh();
            }
            if (direccion == 4)
            {
                cy = cy + 1;
                move(cy - 1, cx);
                printw(" ");
                refresh();
            }
        }
        else
        {
            break;
        }
    }
    move(y / 2, (x / 2 - 4));
    printw("Has perdido, que mal :c lo siento ");
    refresh();
    //   keypad(stdscr, FALSE);
    usleep(1000000 / 2);
    curs_set(1);
}

int menu()
{
    initscr();
    int x, y;
    getmaxyx(stdscr, y, x);
    move(0, (x / 2 - 18));
    if (has_colors())
    {
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        attron(COLOR_PAIR(1));
        printw("<< MENU PRINCIPAL >>");
        attroff(COLOR_PAIR(1));
        init_pair(2, COLOR_CYAN, COLOR_BLACK);
        attron(COLOR_PAIR(2));
        move(1, 0);
        printw("Seleccione una opcion :\n");
        move(2, 1);
        printw("1)Iniciar Juego\n");
        move(3, 1);
        printw("2) Salir \n");
        printw("Usted selecciono: ");
        attroff(COLOR_PAIR(2));
    }
    int cx = 0;
    int cy = 2;
    int tecla;
    move(cy, cx);
    refresh();
    while (true)
    {
        noecho();
        tecla = getch();
        if (tecla == 10)
        {
            if (cy == 2)
            {
                return 1;
            }
            if (cy == 3)
            {
                return 2;
            }
        }
        else
        {
            //printw("%i",tecla);
            if (tecla == 65 && cy > 2)
            {
                //printw(" arriba");
                cy = cy - 1;
                move(cy, cx);
            }
            else if (tecla == 66 && cy <= 4)
            {
                //printw(" abajo");
                cy = cy + 1;
                move(cy, cx);
            }
            else
            {
                //No hara nada
            }
        }
        refresh();
    }
    echo();
    return 0;
}

void salir()
{
    int x, y;
    getmaxyx(stdscr, y, x);
    erase();
    if (has_colors)
    {
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        attron(COLOR_PAIR(1));
        move(y / 2, (x / 2 - 6));
        printw("Hasta la proxima :( ");
        refresh();
        usleep(1000000 / 2);
        printw(".");
        refresh();
        usleep(1000000 / 2);
        printw(".");
        refresh();
        usleep(1000000 / 2);
        printw(".");
        usleep(1000000 / 2);
        printw(":D");
        refresh();
        usleep(1000000 / 2);
        attroff(COLOR_PAIR(1));
    }
    endwin();
    exit(0);
}

void Cargando()
{
    int x, y;
    getmaxyx(stdscr, y, x);
    erase();
    if (has_colors)
    {
        start_color();
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        attron(COLOR_PAIR(1));
        move(y / 2, 15);
        printw("Espere mientras cargamos los elementos :D ");
        refresh();
        usleep(1000000 / 2);
        printw(".");
        refresh();
        usleep(1000000 / 2);
        printw(".");
        refresh();
        usleep(1000000 / 2);
        printw(".");
        usleep(1000000 / 2);
        printw("Cargado!");
        refresh();
        usleep(1000000 / 2);
        attroff(COLOR_PAIR(1));
    }
    endwin();
}

int kbhit(void)
{
    struct timeval timeout;
    fd_set readfds;
    int how;

    /* look only at stdin (fd = 0) */
    FD_ZERO(&readfds);
    FD_SET(0, &readfds);

    /* poll: return immediately */
    timeout.tv_sec = 0L;
    timeout.tv_usec = 0L;

    how = select(1, &readfds, (fd_set *)NULL, (fd_set *)NULL, &timeout);
    /* Change "&timeout" above to "(struct timeval *)0"       ^^^^^^^^
         * if you want to wait until a key is hit
         */

    if ((how > 0) && FD_ISSET(0, &readfds))
        return 1;
    else
        return 0;
}

int menu2()
{
    erase();
    initscr();
    int x, y;
    getmaxyx(stdscr, y, x);
    move(0, (x / 2 - 18));
    if (has_colors())
    {
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        attron(COLOR_PAIR(1));
        printw("<< TIPO DE MENU >>");
        attroff(COLOR_PAIR(1));
        init_pair(2, COLOR_CYAN, COLOR_BLACK);
        attron(COLOR_PAIR(2));
        move(1, 0);
        printw("Seleccione el tipo de escenario en el que desea jugar :\n");
        move(2, 1);
        printw("1)Invisible. \n");
        move(3, 1);
        printw("2) Tren  \n");
        printw("Tipo de escenario seleccionado: ");
        attroff(COLOR_PAIR(2));
    }
    int cx = 0;
    int cy = 2;
    int tecla;
    move(cy, cx);
    refresh();
    while (true)
    {
        noecho();
        tecla = getch();
        if (tecla == 10)
        {
            if (cy == 2)
            {
                return 1;
            }
            if (cy == 3)
            {
                return 2;
            }
        }
        else
        {
            //printw("%i",tecla);
            if (tecla == 65 && cy > 2)
            {
                //printw(" arriba");
                cy = cy - 1;
                move(cy, cx);
            }
            else if (tecla == 66 && cy <= 4)
            {
                //printw(" abajo");
                cy = cy + 1;
                move(cy, cx);
            }
            else
            {
                //No hara nada
            }
        }
        refresh();
    }
    echo();
    return 0;
}

int menu3()
{
    erase();
    initscr();
    int x, y;
    getmaxyx(stdscr, y, x);
    move(0, (x / 2 - 18));
    if (has_colors())
    {
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        attron(COLOR_PAIR(1));
        printw("<< TIPO DE BOMBAS >>");
        attroff(COLOR_PAIR(1));
        init_pair(2, COLOR_CYAN, COLOR_BLACK);
        attron(COLOR_PAIR(2));
        move(1, 0);
        printw("Seleccione el tipo de Bomba que desea utilizar:\n");
        move(2, 1);
        printw("1)Bomba Normal. \n");
        move(3, 1);
        printw("2)Bomba Espina \n");
        move(4, 1);
        printw("3)Bomba V   \n");
        printw("Tipo de escenario seleccionado: ");
        attroff(COLOR_PAIR(2));
    }
    int cx = 0;
    int cy = 2;
    int tecla;
    move(cy, cx);
    refresh();
    while (true)
    {
        noecho();
        tecla = getch();
        if (tecla == 10)
        {
            if (cy == 2)
            {
                return 1;
            }
            if (cy == 3)
            {
                return 2;
            }
            if (cy == 4)
            {
                return 3;
            }
        }
        else
        {
            //printw("%i",tecla);
            if (tecla == 65 && cy > 2)
            {
                //printw(" arriba");
                cy = cy - 1;
                move(cy, cx);
            }
            else if (tecla == 66 && cy <= 4)
            {
                //printw(" abajo");
                cy = cy + 1;
                move(cy, cx);
            }
            else
            {
                //No hara nada
            }
        }
        refresh();
    }
    echo();
    return 0;
}

string  menunombre()
{
    erase();
    initscr();
    int x, y;
    getmaxyx(stdscr, y, x);
    move(0, (x / 2 - 18));
    string Nombre;
    if (has_colors())
    {
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        attron(COLOR_PAIR(1));
        printw("<< DATOS DEL JUGADOR >>");
        attroff(COLOR_PAIR(1));
        init_pair(2, COLOR_CYAN, COLOR_BLACK);
        attron(COLOR_PAIR(2));
        move(1, 0);
        printw("Ingrese su nombre porfavor  :\n");
        string Nombre;
        char ch = getch();
        stringstream ss;
        while (ch != '\n')
        {
            Nombre.push_back(ch);
            ss << ch;
            ch = getch();
        }
        attroff(COLOR_PAIR(2));
    }
    
    echo();
    return Nombre;
}
