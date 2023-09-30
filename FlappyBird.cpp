#include <stdio.h>      
#include <stdlib.h>      
#include <time.h>       
#include "TextureBuilder.h"
#include <glut.h>
#include <string.h>

#define GLUT_KEY_SPACE 32
int Random=0;
int Z1 = 0;
int Z2 = 0;
int Set = 0;
int i = 1;
int Lives = 3;
int score = 0;
//GLuint texID;
float Yaxis = 300.00f;
float x = 700.00f;
int gameovert = 5;
BOOLEAN collision = false;
BOOLEAN powerup = false;

void Bird() {
    

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(160.0f, Yaxis+45, 0.0f);
    glVertex3f(190.0f, Yaxis+45, 0.0f);
    glVertex3f(190.0f, Yaxis+65, 0.0f);
    glVertex3f(160.0f, Yaxis+65, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(190.0f, Yaxis+45, 0.0f);
    glVertex3f(190.0f, Yaxis+60, 0.0f);
    glVertex3f(200.0f, Yaxis+55, 0.0f);
    glEnd();
   
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(160.0f, Yaxis+65, 0.0f);
    glVertex3f(160.0f, Yaxis+55, 0.0f);
    glVertex3f(170.0f, Yaxis+55, 0.0f);
    glVertex3f(170.0f, Yaxis+65, 0.0f);
    glEnd();
    

}
void Barriers1(float x) {
    if ((x - 400.0f <= 200 && x-360.0f>=200 && Yaxis + 45 <= 320.0 && Yaxis +45 >=300.0)) {
        powerup = true;
    }



    if (((x - 400.0f <= 200 && x-360>=200 && Yaxis + 45 <= 300.0) || (x - 400.0f <= 200 && x - 360 >= 200 && Yaxis + 65 >= 400.0)) && powerup == false) {
        collision = true;
        Lives--;
        Yaxis = 300.0f;
        
    }
   
    glBegin(GL_POLYGON);  //first down
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(x-400.0f, 0.0f, 0.0f);
    glVertex3f(x-360.0f, 0.0f, 0.0f);
    glVertex3f(x-360.0f, 300.0f, 0.0f);
    glVertex3f(x-400.0f, 300.0f, 0.0f);
    glEnd();
    
    glBegin(GL_POLYGON); //first up
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(x-400.0f, 700.0f, 0.0f);
    glVertex3f(x-360.0f, 700.0f, 0.0f);
    glVertex3f(x-360.0f, 400.0f, 0.0f);
    glVertex3f(x-400.0f, 400.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);  //first down line
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(x-400.0f, 290.0f, 0.0f);
    glVertex3f(x-360.0f, 290.0f, 0.0f);

    glEnd();

    glBegin(GL_LINES);  //first up line
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(x-400.0f, 410.0f, 0.0f);
    glVertex3f(x-360.0f, 410.0f, 0.0f);

    glEnd();


    glBegin(GL_POLYGON); //powerup
    glColor3f(255, 20, 147);
    glVertex3f(x - 400.0f, 300.0f, 0.0f);
    glVertex3f(x - 360.0f, 300.0f, 0.0f);
    glVertex3f(x - 360.0f, 320.0f, 0.0f);
    glVertex3f(x - 400.0f, 320.0f, 0.0f);
    glEnd();

    if (((x-250<=200 && x - 210 >= 200 && Yaxis+45<= 450) || (x-250<=200 && x - 210 >= 200 && Yaxis+65>=550)) && powerup == false) {
        collision = true;
        Lives--;
            Yaxis=300.0f;
           
    }

    glBegin(GL_POLYGON); //second down
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(x-250.0f, 0.0f, 0.0f);
    glVertex3f(x-210.0f, 0.0f, 0.0f);
    glVertex3f(x-210.0f, 450.0f, 0.0f);
    glVertex3f(x-250.0f, 450.0f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);  //second up
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(x-250.0f, 700.0f, 0.0f);
    glVertex3f(x-210.0f, 700.0f, 0.0f);
    glVertex3f(x-210.0f, 550.0f, 0.0f);
    glVertex3f(x-250.0f, 550.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);  //second down line
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(x-250.0f, 440.0f, 0.0f);
    glVertex3f(x-210.0f, 440.0f, 0.0f);

    glEnd();

    glBegin(GL_LINES);  //second up line
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(x-250.0f, 560.0f, 0.0f);
    glVertex3f(x-210.0f, 560.0f, 0.0f);

    glEnd();

    if (((x - 100 <= 200 && x - 60 >= 200 && Yaxis + 45 <= 300) || (x - 100 <= 200 && x - 60 >= 200 && Yaxis + 65 >= 400)) && powerup == false) {
        collision = true;
        Lives--;
        Yaxis = 300.0f;
        
    }
     glBegin(GL_POLYGON);  //third down
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(x-100.0f, 0.0f, 0.0f);
    glVertex3f(x - 60.0f, 0.0f, 0.0f);
    glVertex3f(x - 60.0f, 300.0f, 0.0f);
    glVertex3f(x - 100.0f, 300.0f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON); //third up
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(x - 100.0f, 700.0f, 0.0f);
    glVertex3f(x - 60.0f, 700.0f, 0.0f);
    glVertex3f(x - 60.0f, 400.0f, 0.0f);
    glVertex3f(x - 100.0f, 400.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);  //third down line
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(x - 100.0f, 290.0f, 0.0f);
    glVertex3f(x-60.0f, 290.0f, 0.0f);

    glEnd();

    glBegin(GL_LINES);  //third up line
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(x - 100.0f, 410.0f, 0.0f);
    glVertex3f(x - 60.0f, 410.0f, 0.0f);

    glEnd();

}
void Barriers2(float x) {
    if ((x - 400 <= 200 && x - 360 >= 200 && Yaxis + 45 <= 450) || (x - 400 <= 200 && x - 360 >= 200 && Yaxis + 65 >= 550) ) {
        collision = true;
        Lives--;
        Yaxis = 300.0f;
        
    }


    glBegin(GL_POLYGON);  //first down
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(x - 400.0f, 0.0f, 0.0f);
    glVertex3f(x - 360.0f, 0.0f, 0.0f);
    glVertex3f(x - 360.0f, 450.0f, 0.0f);
    glVertex3f(x - 400.0f, 450.0f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON); //first up
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(x - 400.0f, 700.0f, 0.0f);
    glVertex3f(x - 360.0f, 700.0f, 0.0f);
    glVertex3f(x - 360.0f, 550.0f, 0.0f);
    glVertex3f(x - 400.0f, 550.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);  //first down line
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(x - 400.0f, 440.0f, 0.0f);
    glVertex3f(x - 360.0f, 440.0f, 0.0f);

    glEnd();

    glBegin(GL_LINES);  //first up line
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(x - 400.0f, 560.0f, 0.0f);
    glVertex3f(x - 360.0f, 560.0f, 0.0f);

    glEnd();


    if ((x - 250 <= 200 && x - 210 >= 200 && Yaxis + 45 <= 350) || (x - 250 <= 200 && x - 210 >= 200 && Yaxis + 65 >= 450) ) {
        collision = true;
        Lives--;
        Yaxis = 300.0f;
        
    }
    glBegin(GL_POLYGON); //second down
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(x - 250.0f, 0.0f, 0.0f);
    glVertex3f(x - 210.0f, 0.0f, 0.0f);
    glVertex3f(x - 210.0f, 350.0f, 0.0f);
    glVertex3f(x - 250.0f, 350.0f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);  //second up
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(x - 250.0f, 700.0f, 0.0f);
    glVertex3f(x - 210.0f, 700.0f, 0.0f);
    glVertex3f(x - 210.0f, 450.0f, 0.0f);
    glVertex3f(x - 250.0f, 450.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);  //second down line
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(x - 250.0f, 340.0f, 0.0f);
    glVertex3f(x - 210.0f, 340.0f, 0.0f);

    glEnd();

    glBegin(GL_LINES);  //second up line
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(x - 250.0f, 460.0f, 0.0f);
    glVertex3f(x - 210.0f, 460.0f, 0.0f);

    glEnd();
    if ((x - 100 <= 200 && x - 60 >= 200 && Yaxis + 45 <= 300) || (x - 250 <= 200 && x - 60 >= 200 && Yaxis + 65 >= 400) ) {
        collision = true;
        Lives--;
        Yaxis = 300.0f;
        
    }

    glBegin(GL_POLYGON);  //third down
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(x - 100.0f, 0.0f, 0.0f);
    glVertex3f(x - 60.0f, 0.0f, 0.0f);
    glVertex3f(x - 60.0f, 300.0f, 0.0f);
    glVertex3f(x - 100.0f, 300.0f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON); //third up
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(x - 100.0f, 700.0f, 0.0f);
    glVertex3f(x - 60.0f, 700.0f, 0.0f);
    glVertex3f(x - 60.0f, 400.0f, 0.0f);
    glVertex3f(x - 100.0f, 400.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);  //third down line
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(x - 100.0f, 290.0f, 0.0f);
    glVertex3f(x - 60.0f, 290.0f, 0.0f);

    glEnd();

    glBegin(GL_LINES);  //third up line
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(x - 100.0f, 410.0f, 0.0f);
    glVertex3f(x - 60.0f, 410.0f, 0.0f);

    glEnd();

}
void Barriers3(float x) {
    if ((x - 400 <= 200 && x - 360 >= 200 && Yaxis + 45 <= 250) || (x - 400 <= 200 && x - 360 >= 200 && Yaxis + 65 >= 350)) {
        collision = true;
        Lives--;
        Yaxis = 300.0f;
        
    }

    glBegin(GL_POLYGON);  //first down
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(x - 400.0f, 0.0f, 0.0f);
    glVertex3f(x - 360.0f, 0.0f, 0.0f);
    glVertex3f(x - 360.0f, 250.0f, 0.0f);
    glVertex3f(x - 400.0f, 250.0f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON); //first up
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(x - 400.0f, 700.0f, 0.0f);
    glVertex3f(x - 360.0f, 700.0f, 0.0f);
    glVertex3f(x - 360.0f, 350.0f, 0.0f);
    glVertex3f(x - 400.0f, 350.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);  //first down line
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(x - 400.0f, 240.0f, 0.0f);
    glVertex3f(x - 360.0f, 240.0f, 0.0f);

    glEnd();

    glBegin(GL_LINES);  //first up line
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(x - 400.0f, 360.0f, 0.0f);
    glVertex3f(x - 360.0f, 360.0f, 0.0f);

    glEnd();

    if ((x - 250 <= 200 && x - 210 >= 200 && Yaxis + 45 <= 452) || (x - 250 <= 200 && x - 210 >= 200 && Yaxis + 65 >= 552) ) {
        collision = true;
        Lives--;
        Yaxis = 300.0f;
        
    }

    glBegin(GL_POLYGON); //second down
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(x - 250.0f, 0.0f, 0.0f);
    glVertex3f(x - 210.0f, 0.0f, 0.0f);
    glVertex3f(x - 210.0f, 452.0f, 0.0f);
    glVertex3f(x - 250.0f, 452.0f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);  //second up
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(x - 250.0f, 700.0f, 0.0f);
    glVertex3f(x - 210.0f, 700.0f, 0.0f);
    glVertex3f(x - 210.0f, 552.0f, 0.0f);
    glVertex3f(x - 250.0f, 552.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);  //second down line
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(x - 250.0f, 442.0f, 0.0f);
    glVertex3f(x - 210.0f, 442.0f, 0.0f);

    glEnd();

    glBegin(GL_LINES);  //second up line
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(x - 250.0f, 562.0f, 0.0f);
    glVertex3f(x - 210.0f, 562.0f, 0.0f);

    glEnd();

    if ((x - 100 <= 200 && x - 60 >= 200 && Yaxis + 45 <= 300) || (x - 100 <= 200 && x - 60 >= 200 && Yaxis + 65 >= 400)) {
        collision = true;
        Lives--;
        Yaxis = 300.0f;
        
    }

    glBegin(GL_POLYGON);  //third down
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(x - 100.0f, 0.0f, 0.0f);
    glVertex3f(x - 60.0f, 0.0f, 0.0f);
    glVertex3f(x - 60.0f, 300.0f, 0.0f);
    glVertex3f(x - 100.0f, 300.0f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON); //third up
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(x - 100.0f, 700.0f, 0.0f);
    glVertex3f(x - 60.0f, 700.0f, 0.0f);
    glVertex3f(x - 60.0f, 400.0f, 0.0f);
    glVertex3f(x - 100.0f, 400.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);  //third down line
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(x - 100.0f, 290.0f, 0.0f);
    glVertex3f(x - 60.0f, 290.0f, 0.0f);

    glEnd();

    glBegin(GL_LINES);  //third up line
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(x - 100.0f, 410.0f, 0.0f);
    glVertex3f(x - 60.0f, 410.0f, 0.0f);

    glEnd();

}
void print(int x, int y, char* string)
{
    int len, i;

    //set the position of the text in the window using the x and y coordinates
    glRasterPos2f(x, y);

    //get the length of the string to display
    len = (int)strlen(string);

    //loop to display character by character
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
    }
}
void time2(int val)//timer animation function, allows the user to pass an integer valu to the timer function.
{
    score++;
    glutPostRedisplay();						// redraw 		
    glutTimerFunc(1000, time2, 0);					//recall the time function after 1000 ms and pass a zero value as an input to the time func.
    
}
void time3(int val)//timer animation function, allows the user to pass an integer valu to the timer function.
{       
    if (Lives == 0) {
        gameovert--;
    }
        glutPostRedisplay();						// redraw 		
        glutTimerFunc(1000, time3, 0);					//recall the time function after 1000 ms and pass a zero value as an input to the time func.
    
}


void Display() {
    glClear(GL_COLOR_BUFFER_BIT);
    if (Yaxis + 45 < 0) {
        Lives--;
        Yaxis = 300.0f;
    }
    if (Yaxis + 75 > 700) {
        Lives--;
        Yaxis = 300.0f;
    }
    glColor3f(1, 0, 0);
    char* p0s[20];
    
        sprintf((char*)p0s, "Lives: %d", Lives);

        print(100, 600, (char*)p0s);

        
       

        sprintf((char*)p0s, "Scores: %d", score);

        print(200, 600, (char*)p0s);


        if (Lives == 0) {
            glColor3f(128, 0, 128);
            sprintf((char*)p0s, "GAME OVER");
           
            if (gameovert == 0) {
                exit(EXIT_SUCCESS);
            }
            print(350, 350, (char*)p0s);

        }


    
  
    if (Random == 1){
       
        Barriers1(x);
    }
    else if (Random == 2) {
       
        Barriers2(x);
    }
    else {
        Barriers3(x);
    }
    Bird();
    if (x - 60.0 > 0.00f) {
        x -= 0.09f;
    }
    else {
        x = 1100.00f;
        Random = rand() % 3 + 1;
    }
    if (collision) {
        x = 1100;
        score -= 5;
        collision = false;
    }
    if (score < 0) {
        score = 0;
    }
       
    
    Yaxis -= 0.1;
   Sleep(1);
    glFlush();

}



void Keyboard(unsigned char key, int x, int y) {
    if (key == GLUT_KEY_SPACE)
        Yaxis += 7;

}



void main(int argc, char** argv) {
    glutInit(&argc, argv);
    
    srand(time(NULL));
    Random = rand() % 3 + 1;

    glutInitWindowSize(700, 700);
    glutInitWindowPosition(50, 50);

    glutCreateWindow("flappybird");

    glutDisplayFunc(Display);
    glutIdleFunc(Display);
    glutTimerFunc(0, time2, 0);
    
        glutTimerFunc(0, time3, 0); //gameover timer
    

    glutKeyboardFunc(Keyboard);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glClearColor(0.52f, 0.80f, 0.92f, 0.0f);



    gluOrtho2D(0, 700, 0, 700);



    glutMainLoop();
}