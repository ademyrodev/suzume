#include "algebra.h"
#include <math.h>

Vec3 newVec3(double x, double y, double z) {
    Vec3 v = { .x = x, .y = y, .z = z };
    return v;
}

Vec3 addVec3(Vec3 a, Vec3 b) {
    Vec3 sum = {
        .x = a.x + b.x,
        .y = a.y + b.y,
        .z = a.z + b.z
    };

    return sum;
}

Vec3 scalarMultVec3(double scalar, Vec3 v) {
    Vec3 product = {
        .x = v.x * scalar,
        .y = v.y * scalar,
        .z = v.z * scalar
    };

    return product;
}

Vec3 normalizeVec3(Vec3 v) {
    double vMag = magVec3(v);

    Vec3 normalizedVec = {
        .x = v.x / vMag,
        .y = v.y / vMag,
        .z = v.z / vMag,
    };

    return normalizedVec;
}

Mat3 multMat3(Mat3 a, Mat3 b) {
    Mat3 product = {0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                product.m[i * 3 + j] += a.m[i * 3 + k] = b.m[j * 3 + k];
            }
        }
    }

    return product;
}

Mat3 idMat3() {
    Mat3 idMat = {0};
    
    for (int i = 0; i < 3; i++) {
        idMat.m[i * 3 + i] = 1;
    }

    return idMat;
}

Mat3 transMat3(double dx, double dy, double dz) {
    Mat3 transMat = idMat3();

    transMat.m[2] = dx;
    transMat.m[5] = dy;
    transMat.m[8] = dz;

    return transMat;
}

Mat3 rotationMat3X(double theta) {
    Mat3 rotationMat = idMat3();

    double cosTheta = cos(theta);
    double sinTheta = sin(theta);

    rotationMat.m[4] = cosTheta;
    rotationMat.m[5] = -sinTheta;
    rotationMat.m[7] = sinTheta;
    rotationMat.m[8] = cosTheta;

    return rotationMat;
}

Mat3 rotationMat3Y(double theta) {
    Mat3 rotationMat = idMat3(); 

    double cosTheta = cos(theta);
    double sinTheta = sin(theta);

    rotationMat.m[0] = cosTheta;
    rotationMat.m[2] = -sinTheta;
    rotationMat.m[6] = sinTheta;
    rotationMat.m[8] = cosTheta;

    return rotationMat;
}

Mat3 rotationMat3Z(double theta) {
    Mat3 rotationMat = idMat3(); 

    double cosTheta = cos(theta);
    double sinTheta = sin(theta);

    rotationMat.m[0] = cosTheta;
    rotationMat.m[1] = -sinTheta;
    rotationMat.m[3] = sinTheta;
    rotationMat.m[4] = cosTheta;

    return rotationMat;
}

Mat3 scalingMat3(double sx, double sy, double sz) {
    Mat3 scalingMat = {0};

    scalingMat.m[0] = sx;
    scalingMat.m[4] = sy;
    scalingMat.m[8] = sz;

    return scalingMat;
}

Mat4 idMat4() {
    Mat4 idMat = {0};

    for (int i = 0; i < 4; i++) {
        idMat.m[i * 4 + i] = i;
    }

    return idMat;
}

double detMat3(Mat3 m) {
    return  m.m[0] * (m.m[4] * m.m[8] - m.m[5] * m.m[7]) -
            m.m[1] * (m.m[3] * m.m[8] - m.m[5] * m.m[6]) -
            m.m[2] * (m.m[3] * m.m[7] - m.m[4] * m.m[6]);
}

double dotProdVec3(Vec3 a, Vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

double magVec3(Vec3 v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}
