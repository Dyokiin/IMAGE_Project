#ifndef FRUSTRUM_H
#define FRUSTRUM_H

/************************************************************************************************
 * Implémentation des la classe Frustrum trouvée à :                                            *
 * http://www.lighthouse3d.com/tutorials/view-frustum-culling/geometric-approach-source-code/   *
 *                                                                                              *
 * Permet de calculer le frustrum actuel et en particulier                                      *
 * de savoir si un point est à l'interieur.                                                     *
 ***********************************************************************************************/

class Vec3  {
public:
	float x,y,z;


	Vec3(float x, float y, float z);
	Vec3(const Vec3 &v);
	Vec3();
	~Vec3();

	Vec3 operator +(const Vec3 &v);
	Vec3 operator -(const Vec3 &v);
	Vec3 operator *(Vec3 &v);
	Vec3 operator *(float t);
	Vec3 operator /(float t);
	Vec3 operator -(void);

	float length();
	void normalize();
	float innerProduct(Vec3  &v);
	void copy(const Vec3 &v);
	void set(float x,float y, float z);
	Vec3 scalarMult(float a);

	void print();
};

class Plane {
public:
	Vec3 normal,point;
	float d;

	Plane( Vec3 &v1,  Vec3 &v2,  Vec3 &v3);
	Plane(void);
	~Plane();

	void set3Points( Vec3 &v1,  Vec3 &v2,  Vec3 &v3);
	void setNormalAndPoint(Vec3 &normal, Vec3 &point);
	void setCoefficients(float a, float b, float c, float d);
	float distance(Vec3 &p);

	void print();
};

class FrustumG {
private:
	enum {
		TOP = 0, BOTTOM, LEFT,
		RIGHT, NEARP, FARP
	};
public:
	enum {OUTSIDE, INTERSECT, INSIDE};
	Plane pl[6];
	Vec3 ntl,ntr,nbl,nbr,ftl,ftr,fbl,fbr;
	float nearD, farD, ratio, angle,tang;
	float nw,nh,fw,fh;

	FrustumG();
	~FrustumG();

	void setCamInternals(float angle, float ratio, float nearD, float farD);
	void setCamDef(Vec3 &p, Vec3 &l, Vec3 &u);
	int pointInFrustum(Vec3 &p);
};

extern FrustumG frustrum;


#endif