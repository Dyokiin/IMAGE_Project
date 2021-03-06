/************************************************************************************************
 * Implémentation des la classe Frustrum trouvée à :                                            *
 * http://www.lighthouse3d.com/tutorials/view-frustum-culling/geometric-approach-source-code/   *
 *                                                                                              *
 * Permet de calculer le frustrum actuel et en particulier                                      *
 * de savoir si un point est à l'interieur.                                                     *
 ***********************************************************************************************/

#include "../include/frustrum.h"

#include <math.h>
#include <stdio.h>

#define ANG2RAD 3.14159265358979323846/180.0

Vec3::Vec3(float x, float y, float z) {

	this->x = x;
	this->y = y;
	this->z = z;

}

Vec3::Vec3(const Vec3 &v) {

	x = v.x;
	y = v.y;
	z = v.z;

}

Vec3::Vec3() {

	x = 0;
	y = 0;
	z = 0;

}

Vec3::~Vec3(){}

Vec3 Vec3::operator+(const Vec3 &v) {

	Vec3 res;

	res.x = x + v.x;
	res.y = y + v.y;
	res.z = z + v.z;

	return(res);
}

Vec3 Vec3::operator-(const Vec3 &v) {

	Vec3 res;

	res.x = x - v.x;
	res.y = y - v.y;
	res.z = z - v.z;

	return(res);
}

Vec3 Vec3::operator-(void) {

	Vec3 res;

	res.x = -x;
	res.y = -y;
	res.z = -z;

	return(res);
}

// cross product
Vec3 Vec3::operator*(Vec3 &v) {

	Vec3 res;

	res.x = y * v.z - z * v.y;
	res.y = z * v.x - x * v.z;
	res.z = x * v.y - y * v.x;

	return (res);
}

Vec3 Vec3::operator*(float t) {

	Vec3 res;

	res.x = x * t;
	res.y = y * t;
	res.z = z * t;

	return (res);
}

Vec3 Vec3::operator/(float t) {

	Vec3 res;

	res.x = x / t;
	res.y = y / t;
	res.z = z / t;

	return (res);
}

float Vec3::length() {

	return((float)sqrt(x*x + y*y + z*z));
}

void Vec3::normalize() {

	float len;

	len = length();
	if (len) {
		x /= len;;
		y /= len;
		z /= len;
	}
}

float Vec3::innerProduct(Vec3 &v) {

	return (x * v.x + y * v.y + z * v.z);
}

void Vec3::copy(const Vec3 &v) {

	x = v.x;
	y = v.y;
	z = v.z;
}

void Vec3::set(float x,float y, float z) {

	this->x = x;
	this->y = y;
	this->z = z;
}

Vec3 Vec3::scalarMult(float a) {

	Vec3 res;

	res.x = x * a;
	res.y = y * a;
	res.z = z * a;

	return res;
}

void Vec3::print() {
	printf("Vec3(%f, %f, %f)",x,y,z);
	
}


Plane::Plane( Vec3 &v1,  Vec3 &v2,  Vec3 &v3) {

	set3Points(v1,v2,v3);
}


Plane::Plane() {}

Plane::~Plane() {}


void Plane::set3Points( Vec3 &v1,  Vec3 &v2,  Vec3 &v3) {


	Vec3 aux1, aux2;

	aux1 = v1 - v2;
	aux2 = v3 - v2;

	normal = aux2 * aux1;

	normal.normalize();
	point.copy(v2);
	d = -(normal.innerProduct(point));
}

void Plane::setNormalAndPoint(Vec3 &normal, Vec3 &point) {

	this->normal.copy(normal);
	this->normal.normalize();
	d = -(this->normal.innerProduct(point));
}

void Plane::setCoefficients(float a, float b, float c, float d) {

	// set the normal vector
	normal.set(a,b,c);
	//compute the lenght of the vector
	float l = normal.length();
	// normalize the vector
	normal.set(a/l,b/l,c/l);
	// and divide d by th length as well
	this->d = d/l;
}


float Plane::distance(Vec3 &p) {

	return (d + normal.innerProduct(p));
}

void Plane::print() {

	printf("Plane(");normal.print();printf("# %f)",d);
}



FrustumG::FrustumG() {}

FrustumG::~FrustumG() {}

void FrustumG::setCamInternals(float angle, float ratio, float nearD, float farD) {

	this->ratio = ratio;
	this->angle = angle;
	this->nearD = nearD;
	this->farD = farD;

	tang = (float)tan(angle* ANG2RAD * 0.5) ;
	nh = nearD * tang;
	nw = nh * ratio; 
	fh = farD  * tang;
	fw = fh * ratio;


}

void FrustumG::setCamDef(Vec3 &p, Vec3 &l, Vec3 &u) {

	Vec3 dir,nc,fc,X,Y,Z;

	Z = p - l;
	Z.normalize();

	X = u * Z;
	X.normalize();

	Y = Z * X;

	nc = p - Z * nearD;
	fc = p - Z * farD;

	ntl = nc + Y * nh - X * nw;
	ntr = nc + Y * nh + X * nw;
	nbl = nc - Y * nh - X * nw;
	nbr = nc - Y * nh + X * nw;

	ftl = fc + Y * fh - X * fw;
	ftr = fc + Y * fh + X * fw;
	fbl = fc - Y * fh - X * fw;
	fbr = fc - Y * fh + X * fw;

	pl[TOP].set3Points(ntr,ntl,ftl);
	pl[BOTTOM].set3Points(nbl,nbr,fbr);
	pl[LEFT].set3Points(ntl,nbl,fbl);
	pl[RIGHT].set3Points(nbr,ntr,fbr);
	pl[NEARP].set3Points(ntl,ntr,nbr);
	pl[FARP].set3Points(ftr,ftl,fbl);
}

int FrustumG::pointInFrustum(Vec3 &p) {

	int result = 1;
	for(int i=0; i < 6; i++) {

		if (pl[i].distance(p) < 0)
			return 0;
	}
	return(result);

}