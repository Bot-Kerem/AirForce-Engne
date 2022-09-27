#version 460 compatibility

uniform int MAX_STEPS;
uniform float MAX_DIST;
uniform float SURF_DIST;
uniform mat4 rotateCamera;
struct Sphere
{
    vec3 Position;
    float Radius;
};

/*Scene*/

Sphere s1 = {vec3(1.0f, 0.0f, 0.0f), 1.0f};
Sphere s2 = {vec3(-1.0f, 0.0f, 0.0f), 1.0f};

/*Scene*/

float smin( float a, float b, float k )
{
    float h = max( k-abs(a-b), 0.0 )/k;
    return min( a, b ) - h*h*k*(1.0/4.0);
}

float SphereSDF(Sphere sphere, vec3 p)
{
    return length(p - sphere.Position) - sphere.Radius;
}

float sph( ivec3 i, vec3 f, ivec3 c )
{
   // random radius at grid vertex i+c
   float rad = 0.2f;
   // distance to sphere at grid vertex i+c
   return length(f-vec3(c)) - rad; 
}

float sdBase( vec3 p )
{
   ivec3 i = ivec3(floor(p));
    vec3 f =       fract(p);
   // distance to the 8 corners spheres
   return min(min(min(sph(i,f,ivec3(0,0,0)),
                      sph(i,f,ivec3(0,0,1))),
                  min(sph(i,f,ivec3(0,1,0)),
                      sph(i,f,ivec3(0,1,1)))),
              min(min(sph(i,f,ivec3(1,0,0)),
                      sph(i,f,ivec3(1,0,1))),
                  min(sph(i,f,ivec3(1,1,0)),
                      sph(i,f,ivec3(1,1,1)))));
}

float GetDist(vec3 p)
{
    //float sphereDist = SphereSDF(s1, p);
    //float sphere2Dist = SphereSDF(s2, p);
    //float d = smin(sphereDist, sphere2Dist, k); // min
    float d = sdBase(p);
    return d;
}

float RayMarch(vec3 ro, vec3 rd)
{
    float dO = 0;
    
    for(int i = 0; i < MAX_STEPS; i++)
    {
        vec3 p = ro + rd*dO;
        float dS = GetDist(p);
        dO += dS;
        if(dO > MAX_DIST || dS < SURF_DIST) break;
    }
    return dO;
}

vec3 GetNormal(vec3 p)
{
    vec2 epsilon = vec2(0.01f, 0.0f);
    return normalize(vec3(GetDist(p + epsilon.xyy), GetDist(p + epsilon.yxy), GetDist(p + epsilon.yyx)));
}

float getLight(vec3 p)
{
    vec3 lightPos = vec3(0.0f, 3.0f, -5.0f);
    vec3 lightDir = normalize(p - lightPos);
    return -dot(GetNormal(p), lightDir);
}

in vec2 FragCoord;
uniform vec3 ro;

out vec4 FragColor;
void main()
{
    vec2 uv = vec2(1.0f, 1.0f) - FragCoord - 1.0f;
    vec3 rd = normalize(vec3(uv, 1.0f));

    //rd *= vec4(rotateCamera * vec4(rd, 1.0f)).xyz;

    float d = RayMarch(ro, rd);
    vec3 col = vec3(0);
    if(d < MAX_DIST)
    {
        vec3 pHit = ro + rd* d;
        col = getLight(pHit) * vec3(1.0f, 0.0f, 0.0f);
    }
    

    FragColor = vec4(col, 1.0f);
}