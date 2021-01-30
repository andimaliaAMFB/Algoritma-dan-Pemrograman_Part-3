/*sumber: https://codereview.stackexchange.com/questions/66481/snake-game-in-c
Andi malia Fadilah Bahari
1197050014
Praktikum F*/
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<dos.h>
#include<stdlib.h>

void title();
void run();
void printmap();
void initmap();
void move(int dx, int dy);
void update();
void ubaharah(char key);
void generateFood();
char getMapValue(int value);

//ukuran map
const int mw = 15;
const int mh = 30;
const int sizemap = mw*mh;

int map[sizemap];

// kepala ular
int poshx;
int poshy;
int arah;

// panjang badan ular
int food = 1;

//pernyataan untuk T/F di run 
bool running;


void title()
{
	system("color 70");
	printf("================================\n");
	printf("||            SNAKE           ||\n");
	printf("||============================||\n");
	printf("||by Andi Malia Fadilah Bahari||\n");
	printf("||         1197050014         ||\n");
	printf("||         Praktikum F        ||\n");
	printf("================================\n");
	printf("              PLAY\n");
	printf("           tekan 'ENTER'\n");
	getch();
	system("cls");
}

int main()
{
	title();
	system("color 07");//pengubah warna
    run();
    return 0;
}


// Main game function
void run()
{
    // Initialize the map
    initmap();
    running = true;
    while (running) 
	{
        // If a key is pressed
        if (kbhit()) 
		{
            // ubah arah
            ubaharah(getch());
        }
        // Upate map
        update();

        // Clear the screen
        system("cls");

        // Print map
        printmap();

        // wait 0.25 seconds
        _sleep(250);
    }
    
	system("color 70");
    // Print out game over text
    printf("\n\t!!!Game over!!!\n\tYour score is: %d",(food-1));

    // Stop console from closing instantly
    getch();
}

// Changes snake direction from input
void ubaharah(char key) {
    /*
      W
    A + D
      S

      1
    4 + 2
      3
    */
    switch (key) {
    case 'w':
        if (arah != 2)
			arah = 0;
        break;
    case 'd':
        if (arah != 3)
			arah = 1;
        break;
    case 's':
        if (arah != 4)
			arah = 2;
        break;
    case 'a':
        if (arah != 5)
			arah = 3;
        break;
    }
}

//perpindahan kepala
void move(int dx, int dy) 
{
    int newx = poshx + dx;
    int newy = poshy + dy;

    // Check makanan
    if (map[newx + newy * mw] == -2)
	{
        // +jumlah food(panjang badan)
        food++;

        // food baru
        generateFood();
    }

    // cek lokasi
    else if (map[newx + newy * mw] != 0)
	{
        running = false;
    }

    // posisi baru
    poshx = newx;
    poshy = newy;
    map[poshx + poshy * mw] = food + 1;

}


// food baru di map
void generateFood() {
    int x = 0;
    int y = 0;
    do {
        // lokasi food acak
        x = rand() % (mw - 2) + 1;
        y = rand() % (mh - 2) + 1;

        // If location is not free try again
    } while (map[x + y * mw] != 0);

    // Place new food
    map[x + y * mw] = -2;
}

// Updates the map
void update() {
    // Move in direction indicated
    switch (arah) {
    case 0: move(-1, 0);
        break;
    case 1: move(0, 1);
        break;
    case 2: move(1, 0);
        break;
    case 3: move(0, -1);
        break;
    }

    // Reduce snake values on map by 1
    for (int i = 0; i < sizemap; i++) {
        if (map[i] > 0) map[i]--;
    }
}

// Initializes map
void initmap()
{
    // Places the initual head location in middle of map
    poshx = mw / 2;
    poshy = mh / 2;
    map[poshx + poshy * mw] = 1;

    // atap dan alas map 
    for (int x = 0; x < mw; ++x) {
        map[x] = -1;
        map[x + (mh - 1) * mw] = -1;
    }

    // kanan-kiri
    for (int y = 0; y < mh; y++) {
        map[y * mw] = -1;
        map[(mw - 1) + y * mw] = -1;
    }

    // Generates first food
    generateFood();
}

// Prints the map to console
void printmap()
{
    //print peraturan
    printf("\t KONTROL ARAH\n");
    printf("\t       W\n\t     A S D\n");
    for (int x = 0; x < mw; ++x) {
        for (int y = 0; y < mh; ++y) {
            // Prints the value at current x,y location
            printf("%c", getMapValue(map[x + y * mw]));
        }
        printf("\n");
    }
}

// return part
char getMapValue(int value)
{
    // Returns a part of snake body
    if (value > 0)return 'o';

    switch (value) {
        // Return wall
    case -1: return 'X';
        // Return food
    case -2: return 'O';
    }
}
