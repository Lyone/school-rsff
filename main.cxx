#include "core.hxx"
#include "pathfinder.hxx"
#include "drawing.hxx"
#include <GL/freeglut.h>

static int window;
void initGL()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 1000); 

    window = glutCreateWindow("RSFF-VMAMZ");
}

void drawScene()
{
    Drawing dwg(window);
    dwg.MoveTo(Point3D(0.2, 0.2, 2.0));
    dwg.Cube(0.1);
    dwg.MoveTo(Point3D(0.2, -0.2, 2.0));
    dwg.Cube(0.1);
    //dwg.MoveTo(Point3D(0.2, -0.2, 3.f));
    //dwg.Cube(0.1);
    //dwg.MoveTo(Point3D(0.2, -0.2, 4.f));
    //dwg.Cube(0.1);

    dwg.MoveTo(Point3D(0.f,     1.f,    2.f));
    dwg.LineTo(Point3D(0.f,     -1.f,   2.f));
    dwg.MoveTo(Point3D(1.f,     0.f,    2.f));
    dwg.LineTo(Point3D(-1.f,    0.f,    2.f));

    //dwg.MoveTo(Point3D(0.2f, 0.2f, 2.0f));
    //dwg.LineTo(Point3D(0.2, -0.2, 3.f));
    //dwg.MoveTo(Point3D(0.0, 0.0, 0.0));
    //dwg.LineTo(Point3D(0.0, 0.5, 20.0));
}

void initRendering()
{
	//initModel();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	// lighting
	//initLight();

	// blending
	//initBlending();

	glClearColor(.25f, .25f, 1.f, 1.f);
}

void initGL2()
{
	glutSetCursor(GLUT_CURSOR_NONE);

	glutDisplayFunc(drawScene);
	//glutKeyboardFunc(handleKeypress);
	//glutMouseFunc(handleMouse);
	//glutPassiveMotionFunc(doRotate);
	//glutMotionFunc(doRotate);
	//glutReshapeFunc(handleResize);
	//glutKeyboardUpFunc(handleKeyRelease);

	//glutTimerFunc(25, update, 0);
}

int main(int argc, char* argv[])
{
    Path p = Pathfinder::ComputePath();
    Point3D PP(0, 0, 0);

    glutInit(&argc, argv);
    initGL();
    initRendering();
    initGL2();

    glutMainLoop();

    return 0;
}