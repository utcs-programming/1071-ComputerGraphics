#include <iostream>
#include <vector>
#include <GL/glut.h>
#include "cube.hpp"

Cube::Cube() {

}

Cube::~Cube() {
    for (auto v : vertices_) {
        delete v;
    }

    for (auto c : colors_) {
        delete c;
    }
}


std::vector<GLfloat*>& Cube::vertices() {
    return vertices_;
}

std::vector<GLfloat*>& Cube::colors() {
    return colors_;
}

float Cube::theta_x() {
    return theta_x_;
}

float Cube::theta_y() {
    return theta_y_;
}

float Cube::theta_z() {
    return theta_z_;
}

void Cube::RotateX(float theta_x) {
    theta_x_ += theta_x;
}

void Cube::RotateY(float theta_y) {
    theta_y_ += theta_y;
}

void Cube::RotateZ(float theta_z) {
    theta_z_ += theta_z;
}

void Cube::DrawPolygon(int a, int b, int c, int d) {
    glBegin(GL_POLYGON);
    
    glColor3fv(colors_[a]);
    glVertex3fv(vertices_[a]);
    
    glColor3fv(colors_[b]);
    glVertex3fv(vertices_[b]);
    
    glColor3fv(colors_[c]);
    glVertex3fv(vertices_[c]);
    
    glColor3fv(colors_[d]);
    glVertex3fv(vertices_[d]);

    glEnd();
}

void Cube::Draw() {
    DrawPolygon(0, 1, 3, 2);
    DrawPolygon(4, 5, 7, 6);
    DrawPolygon(2, 3, 7, 6);
    DrawPolygon(3, 1, 5, 7);
    DrawPolygon(0, 1, 5, 4);
    DrawPolygon(0, 2, 6, 4);
}
