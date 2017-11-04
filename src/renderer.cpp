#include "opengl_renderer.hpp"

Renderer::Renderer(SDL_GLContext& gl_context) {
    // making _renderer point to a copy of the renderer pointer.
    _gl_context = gl_context;

    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90, 800/600, 1, 500.0);
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    // Position of the light
    float gl_light_pos[] = {-2.0, 2.0, 1.0};
    // Diffuse light
    float diffuse_light[] = {1.0, 1.0, 1.0, 1.0};
    // Ambient light intensity
    float ambient_light[] = {0.2, 0.2, 0.2, 0.2};
    // Setting a light1
    glLightfv(GL_LIGHT0, GL_POSITION, gl_light_pos);
    //Setting the diffuse light
  	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
  	//Setting ambient light
  	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);

  	glTranslatef(0.0, 0.0, -3.0);
}

void Renderer::render_triangle() {
    glClearColor(0.2, 0.2, 0.2, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    	// x, y, z
    	glColor3f(1, 0, 0);
    	glVertex3f(0, 10, -20);
    	glColor3f(0, 1, 0);
    	glVertex3f(-2, -10, -20);
    	glColor3f(0, 0, 1);
    	glVertex3f(2, -10, -20);
    glEnd();
}

void Renderer::render_cube(int size) {
	glClearColor(0.3, 0.3, 0.3, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float material_light[] = {0.2, 0.2, 0.2, 0.2};

	glBegin(GL_QUADS);
		// front face
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, material_light);
		glNormal3f(0, 0, 1);
		glVertex3f(size/2,size/2,size/2);
		glVertex3f(-size/2,size/2,size/2);
		glVertex3f(-size/2,-size/2,size/2);
		glVertex3f(size/2,-size/2,size/2);

		// left face
		glNormal3f(-1, 0, 0);
		glVertex3f(-size/2,size/2,size/2);
		glVertex3f(-size/2,-size/2,size/2);
		glVertex3f(-size/2,-size/2,-size/2);
		glVertex3f(-size/2,size/2,-size/2);

		// back face
		glNormal3f(0, 0, -1);
		glVertex3f(size/2,size/2,-size/2);
		glVertex3f(-size/2,size/2,-size/2);
		glVertex3f(-size/2,-size/2,-size/2);
		glVertex3f(size/2,-size/2,-size/2);

		// right face
		glNormal3f(1, 0, 0);
		glVertex3f(size/2,size/2,size/2);
		glVertex3f(size/2,-size/2,size/2);
		glVertex3f(size/2,-size/2,-size/2);
		glVertex3f(size/2,size/2,-size/2);

		// top face
		glNormal3f(0, 1, 0);
		glVertex3f(size/2,size/2,size/2);
		glVertex3f(-size/2,size/2,size/2);
		glVertex3f(-size/2,size/2,-size/2);
		glVertex3f(size/2,size/2,-size/2);

		// bottom face
		glNormal3f(0, -1, 0);
		glVertex3f(size/2,-size/2,size/2);
		glVertex3f(-size/2,-size/2,size/2);
		glVertex3f(-size/2,-size/2,-size/2);
		glVertex3f(size/2,-size/2,-size/2);
    glEnd();
}

void Renderer::rotate(float angle, float x, float y, float z) {
	glRotatef(angle, x, y, z);
}

void Renderer::rotate(float angle, Vector3<float> v) {
    glRotatef(angle, v.m_x, v.m_y, v.m_z);
}