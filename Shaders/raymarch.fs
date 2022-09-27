#version 460 compatibility

#define MAX_STEPS 100
#define MAX_DIST 100.
#define SURF_DIST .01

float GetDist(vec3 p)
{
    vec4 s = vec4(0, 1, 6, 1);
    vec4 s2 = vec4(2, 1, 3, 1);

    float sphereDist = length(p-s.xyz)-s.w;
    float sphere2Dist = length(p-s2.xyz)-s2.w;
    float planeDist = p.y;

    float d = min(min(sphereDist, planeDist), sphere2Dist);
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
vec3 ro = vec3(0.0f, 2.0f, 0.0f);

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