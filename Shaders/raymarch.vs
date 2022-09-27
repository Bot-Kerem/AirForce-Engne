#version 460 compatibility

const float len = 1.0f;
vec2 rectVertices[4] = vec2[](
    vec2(-len, len),
    vec2(-len, -len),
    vec2(len, len),
    vec2(len, -len)
);

out vec2 FragCoord;

void main(){
    gl_Position = vec4(rectVertices[gl_VertexID], 0.0f, 1.0f);
    FragCoord = rectVertices[gl_VertexID];
}