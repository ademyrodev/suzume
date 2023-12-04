#ifndef suzume_math_h
#define suzume_math_h

typedef struct {
    double x, y, z;
} Vec3;

typedef struct {
    double m[9];
} Mat3;

typedef struct {
    double m[12];
} Mat4;

Vec3 newVec3(double x, double y, double z);
Vec3 addVec3(Vec3 a, Vec3 b);
Vec3 scalarMultVec3(double scalar, Vec3 v);
Vec3 normalizeVec3(Vec3 v);

Mat3 multMat3(Mat3 a, Mat3 b);
Mat3 idMat3();
Mat3 transMat3(double dx, double dy, double dz);
Mat3 rotationMat3X(double theta);
Mat3 rotationMat3Y(double theta);
Mat3 rotationMat3Z(double theta);
Mat3 scalingMat3(double sx, double sy, double sz);
// should we have matrix inversion?

Mat4 idMat4();

double detMat3(Mat3 m);
double dotProdVec3(Vec3 a, Vec3 b);
double magVec3(Vec3 v);

#endif
