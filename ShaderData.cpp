#include "ShaderData.h"
#include "ObjRenderer.h"

void ShaderDataPhong::send2shader(GLuint shaderProgID) const
{
    glUniform1ui(glGetUniformLocation(shaderProgID, "outputID"), 2);
    glUniform3fv(glGetUniformLocation(shaderProgID, "kd"), 
            1, (float*)&kd);
    glUniform3fv(glGetUniformLocation(shaderProgID, "ka"), 
            1, (float*)&ka);
    glUniform3fv(glGetUniformLocation(shaderProgID, "ks"), 
            1, (float*)&ks);
    glUniform1f(glGetUniformLocation(shaderProgID, "shiness"), s);
    ObjRenderer::useTexture("diffTex", diffTexID);
}

void ShaderDataPhong::loadData(const tinyobj::material_t& mat, 
        const std::string& mtl_base_path)
{
    ka = getVec<glm::vec3>(mat.ambient);
    kd = getVec<glm::vec3>(mat.diffuse);
    ks = getVec<glm::vec3>(mat.specular);
    s = mat.shininess;
    if(mat.diffuse_texname != "")
        diffTexID = ObjRenderer::getTexID(mtl_base_path+mat.diffuse_texname);
}

void ShaderDataBRDF::send2shader(GLuint shaderProgID) const
{
    glUniform1ui(glGetUniformLocation(shaderProgID, "outputID"), 3);
    
}

void ShaderDataBRDF::loadData(const tinyobj::material_t& mat, 
        const std::string& mtl_base_path)
{

}
