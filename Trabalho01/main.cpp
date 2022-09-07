#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

void inicializar (void)
{
    //Define a cor do Background
    glClearColor(0.0, 0.0, 0.0, 1.0);

    //Define a região aonde a imagem pode ser exibida.
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}

void roda(int x, int y)
{
    float th;
    glColor3f(0,0,0);

    glBegin(GL_POLYGON);
        for(int i=0;i<360;i++)
        {
           th=i*(3.1416/180);
           glVertex2i(x+30*cos(th),y+30*sin(th));
        }
    glEnd();

    glColor3f(1.0,1.0,1.0);


    glBegin(GL_POLYGON);
        for(int i=0;i<360;i++)
        {
           th=i*(3.1416/180);
           glVertex2i(x+20*cos(th),y+20*sin(th));
        }
    glEnd();

    glColor3i(0,0,0);
    glBegin(GL_POLYGON);
        for(int i=0;i<360;i++)
        {
           th=i*(3.1416/180);
           glVertex2i(x+15*cos(th),y+15*sin(th));
        }
    glEnd();
}

void desenhar(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    float th;

    //Carro
    //Cor do Carro

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_QUADS);
        glVertex2i(145,280);
        glVertex2i(150,340);
        glVertex2i(475,340);
        glVertex2i(475,280);

        glVertex2i(155,340);
        glVertex2i(295,380);
        glVertex2i(425,380);
        glVertex2i(475,340);
    glEnd();

    //Porta
    glColor3f(0,0,0);
    glBegin(GL_LINES);
        glVertex2i(240,285);
        glVertex2i(340,285);
        glVertex2i(340,375);
        glVertex2i(295,375);
        glVertex2i(340,285);
        glVertex2i(340,375);
        glVertex2i(240,285);
        glVertex2i(240,360);
        glVertex2i(240,360);
        glVertex2i(295,375);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(242,335);
        glVertex2i(337,335);
        glVertex2i(337,372);
        glVertex2i(294,372);
        glVertex2i(242,357);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2i(345,335);
        glVertex2i(480,335);
        glVertex2i(480,480);
        glVertex2i(345,480);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(345, 320);
        glVertex2i(480, 320);
    glEnd();

    for (int i = 0; i < 5; i++)
    {
        glBegin(GL_LINES);
            glVertex2i(315,330 - i+2);
            glVertex2i(335,330 - i+2);
        glEnd();
    }

    roda(205, 280);
    roda(425, 280);

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(600,600);
    glutCreateWindow("Limpeza de Tela");

    glutDisplayFunc(desenhar);
    inicializar();

    glutMainLoop();
    return 0;
}

