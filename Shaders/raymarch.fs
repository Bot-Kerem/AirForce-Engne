#version 460 compatibility

uniform int MAX_STEPS;
uniform float MAX_DIST;
#define SURF_DIST .01

struct Sphere
{
    vec3 Position;
    float Radius;
};

/*Scene*/

Sphere s1 = {vec3(0.0f, 0.0f, 6.0f), 1.0f};

/*Scene*/

float SphereSDF(Sphere sphere, vec3 p)
{
    return length(p - sphere.Position) - sphere.Radius;
}

float GetDist(vec3 p)
{
    vec4 s = vec4(0, 1, 6, 1);

    float sphereDist = SphereSDF(s1, p);
    float d = sphereDist; // min
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

in vec2 FragCoord;
uniform vec3 ro;

out vec4 FragColor;
void main()
{
    vec2 uv = vec2(1.0f, 1.0f) - FragCoord - 1.0f;
    vec3 rd = normalize(vec3(uv, 1.0f));

    float d = RayMarch(ro, rd);
    d /= 10.0f;
    vec3 col = vec3(d);

    FragColor = vec4(col, 1.0f);
}